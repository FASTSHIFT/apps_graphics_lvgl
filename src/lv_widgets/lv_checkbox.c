/**
 * @file lv_cb.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_checkbox.h"
#if LV_USE_CHECKBOX != 0

#include "../lv_misc/lv_debug.h"
#include "../lv_core/lv_group.h"
#include "../lv_themes/lv_theme.h"
#include "lv_label.h"

/*********************
 *      DEFINES
 *********************/
#define LV_OBJX_NAME "lv_checkbox"

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void lv_checkbox_constructor(lv_obj_t * obj, lv_obj_t * parent, const lv_obj_t * copy);
static void lv_checkbox_destructor(lv_obj_t * obj);
static lv_drawer_res_t lv_checkbox_drawer(lv_obj_t * obj, const lv_area_t * clip_area, lv_drawer_mode_t mode);
static lv_res_t lv_checkbox_signal(lv_obj_t * obj, lv_signal_t sign, void * param);

/**********************
 *  STATIC VARIABLES
 **********************/
const lv_obj_class_t lv_checkbox = {
    .constructor = lv_checkbox_constructor,
    .destructor = lv_checkbox_destructor,
    .signal_cb = lv_checkbox_signal,
    .drawer_cb = lv_checkbox_drawer,
    .instance_size = sizeof(lv_checkbox_t),
    .base_class = &lv_obj
};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Create a check box objects
 * @param par pointer to an object, it will be the parent of the new check box
 * @param copy pointer to a check box object, if not NULL then the new object will be copied from it
 * @return pointer to the created check box
 */
lv_obj_t * lv_checkbox_create(lv_obj_t * parent, const lv_obj_t * copy)
{
    return lv_obj_create_from_class(&lv_checkbox, parent, copy);
}

/*=====================
 * Setter functions
 *====================*/

/**
 * Set the text of a check box. `txt` will be copied and may be deallocated
 * after this function returns.
 * @param cb pointer to a check box
 * @param txt the text of the check box. NULL to refresh with the current text.
 */
void lv_checkbox_set_text(lv_obj_t * obj, const char * txt)
{
    lv_checkbox_t * cb = (lv_checkbox_t *) obj;
#if LV_USE_ARABIC_PERSIAN_CHARS
    size_t len = _lv_txt_ap_proc(txt);
#else
    size_t len = strlen(txt);
#endif

    if(!cb->static_txt) cb->txt = lv_mem_realloc(cb->txt, len + 1);
    else  cb->txt = lv_mem_alloc(len + 1);
#if LV_USE_ARABIC_PERSIAN_CHARS
    _lv_txt_ap_proc(txt, cb->txt);
#else
    strcpy(cb->txt, txt);
#endif

    cb->static_txt = 0;

    _lv_obj_handle_self_size_chg(obj);
}

/**
 * Set the text of a check box. `txt` must not be deallocated during the life
 * of this checkbox.
 * @param cb pointer to a check box
 * @param txt the text of the check box. NULL to refresh with the current text.
 */
void lv_checkbox_set_text_static(lv_obj_t * obj, const char * txt)
{
    lv_checkbox_t * cb = (lv_checkbox_t *) obj;

    if(!cb->static_txt) lv_mem_free(cb->txt);

    cb->txt = (char*)txt;
    cb->static_txt = 1;

    _lv_obj_handle_self_size_chg(obj);
}

/*=====================
 * Getter functions
 *====================*/

/**
 * Get the text of a check box
 * @param cb pointer to check box object
 * @return pointer to the text of the check box
 */
const char * lv_checkbox_get_text(const lv_obj_t * obj)
{
    lv_checkbox_t * cb = (lv_checkbox_t *) obj;
    return cb->txt;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void lv_checkbox_constructor(lv_obj_t * obj, lv_obj_t * parent, const lv_obj_t * copy)
{
    LV_LOG_TRACE("lv_checkbox create started");

    lv_obj_construct_base(obj, parent, copy);

    lv_checkbox_t * cb = (lv_checkbox_t *) obj;
    /*Create the ancestor basic object*/

    /*Init the new checkbox object*/
    if(copy == NULL) {
        cb->txt = "Check box";
        cb->static_txt = 1;
        lv_obj_add_flag(obj, LV_OBJ_FLAG_CLICKABLE);
        lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
        lv_obj_set_size(obj, LV_SIZE_AUTO, LV_SIZE_AUTO);
    }
    else {
//        const lv_checkbox_t * copy_ext = (const lv_checkbox_t *)copy;
    }

    LV_LOG_INFO("lv_checkbox created");
}

static void lv_checkbox_destructor(lv_obj_t * obj)
{
//    lv_checkbox_t * bar = obj;
//
//    _lv_obj_reset_style_list_no_refr(obj, LV_PART_INDICATOR);
//#if LV_USE_ANIMATION
//    lv_anim_del(&bar->cur_value_anim, NULL);
//    lv_anim_del(&bar->start_value_anim, NULL);
//#endif

//    bar->class_p->base_p->destructor(obj);
}

/**
 * Handle the drawing related tasks of the check box
 * @param cb pointer to a check box object
 * @param clip_area the object will be drawn only in this area
 * @param mode LV_DRAWER_COVER_CHK: only check if the object fully covers the 'mask_p' area
 *                                  (return 'true' if yes)
 *             LV_DRAWER_DRAW: draw the object (always return 'true')
 *             LV_DRAWER_DRAW_POST: drawing after every children are drawn
 * @param return an element of `lv_drawer_res_t`
 */
static lv_drawer_res_t lv_checkbox_drawer(lv_obj_t * obj, const lv_area_t * clip_area, lv_drawer_mode_t mode)
{
    /* A label never covers an area */
    if(mode == LV_DRAWER_MODE_COVER_CHECK)
        return lv_obj.drawer_cb(obj, clip_area, mode);
    else if(mode == LV_DRAWER_MODE_MAIN_DRAW) {
        /*Draw the background*/
        lv_obj.drawer_cb(obj, clip_area, mode);

        lv_checkbox_t * cb = (lv_checkbox_t *) obj;

        const lv_font_t * font = lv_obj_get_style_text_font(obj, LV_PART_MAIN);
        lv_coord_t font_h = lv_font_get_line_height(font);

        lv_coord_t bg_topp = lv_obj_get_style_pad_top(obj, LV_PART_MAIN);
        lv_coord_t bg_leftp = lv_obj_get_style_pad_left(obj, LV_PART_MAIN);
        lv_coord_t bg_colp = lv_obj_get_style_pad_column(obj, LV_PART_MAIN);

        lv_coord_t marker_leftp = lv_obj_get_style_pad_left(obj, LV_PART_MARKER);
        lv_coord_t marker_rightp = lv_obj_get_style_pad_right(obj, LV_PART_MARKER);
        lv_coord_t marker_topp = lv_obj_get_style_pad_top(obj, LV_PART_MARKER);
        lv_coord_t marker_bottomp = lv_obj_get_style_pad_bottom(obj, LV_PART_MARKER);

        lv_coord_t transf_w = lv_obj_get_style_transform_width(obj, LV_PART_MARKER);
        lv_coord_t transf_h = lv_obj_get_style_transform_height(obj, LV_PART_MARKER);

        lv_draw_rect_dsc_t marker_dsc;
        lv_draw_rect_dsc_init(&marker_dsc);
        lv_obj_init_draw_rect_dsc(obj, LV_PART_MARKER, &marker_dsc);
        lv_area_t marker_area;
        marker_area.x1 = obj->coords.x1 + bg_leftp;
        marker_area.x2 = marker_area.x1 + font_h + marker_leftp + marker_rightp - 1;
        marker_area.y1 = obj->coords.y1 + bg_topp;
        marker_area.y2 = marker_area.y1 + font_h + marker_topp + marker_bottomp - 1;

        lv_area_t marker_area_transf;
        lv_area_copy(&marker_area_transf, &marker_area);
        marker_area_transf.x1 -= transf_w;
        marker_area_transf.x2 += transf_w;
        marker_area_transf.y1 -= transf_h;
        marker_area_transf.y2 += transf_h;
        lv_draw_rect(&marker_area_transf, clip_area, &marker_dsc);

        lv_coord_t line_space = lv_obj_get_style_text_line_space(obj, LV_PART_MAIN);
        lv_coord_t letter_space = lv_obj_get_style_text_letter_space(obj, LV_PART_MAIN);

        lv_point_t txt_size;
        _lv_txt_get_size(&txt_size, cb->txt, font, letter_space, line_space, LV_COORD_MAX, LV_TEXT_FLAG_NONE);

        lv_draw_label_dsc_t txt_dsc;
        lv_draw_label_dsc_init(&txt_dsc);
        lv_obj_init_draw_label_dsc(obj, LV_PART_MAIN, &txt_dsc);

        lv_coord_t y_ofs = (lv_area_get_height(&marker_area) - font_h) / 2;
        lv_area_t txt_area;
        txt_area.x1 = marker_area.x2 + bg_colp;
        txt_area.x2 = txt_area.x1 + txt_size.x;
        txt_area.y1 = obj->coords.y1 + bg_topp + y_ofs;
        txt_area.y2 = txt_area.y1 + txt_size.y;

        lv_draw_label(&txt_area, clip_area, &txt_dsc, cb->txt, NULL);

    } else {
        lv_obj.drawer_cb(obj, clip_area, mode);
    }

    return LV_DRAWER_RES_OK;
}
/**
 * Signal function of the check box
 * @param cb pointer to a check box object
 * @param sign a signal type from lv_signal_t enum
 * @param param pointer to a signal specific variable
 * @return LV_RES_OK: the object is not deleted in the function; LV_RES_INV: the object is deleted
 */
static lv_res_t lv_checkbox_signal(lv_obj_t * obj, lv_signal_t sign, void * param)
{
    lv_res_t res;
    /* Include the ancient signal function */
    res = lv_obj.signal_cb(obj, sign, param);
    if(res != LV_RES_OK) return res;

    if (sign == LV_SIGNAL_GET_SELF_SIZE) {
        lv_point_t * p = param;
        lv_checkbox_t * cb = (lv_checkbox_t *) obj;

        const lv_font_t * font = lv_obj_get_style_text_font(obj, LV_PART_MAIN);
        lv_coord_t font_h = lv_font_get_line_height(font);
        lv_coord_t line_space = lv_obj_get_style_text_line_space(obj, LV_PART_MAIN);
        lv_coord_t letter_space = lv_obj_get_style_text_letter_space(obj, LV_PART_MAIN);

        lv_point_t txt_size;
        _lv_txt_get_size(&txt_size, cb->txt, font, letter_space, line_space, LV_COORD_MAX, LV_TEXT_FLAG_NONE);


        lv_coord_t bg_colp = lv_obj_get_style_pad_column(obj, LV_PART_MAIN);
        lv_coord_t marker_leftp = lv_obj_get_style_pad_left(obj, LV_PART_MARKER);
        lv_coord_t marker_rightp = lv_obj_get_style_pad_right(obj, LV_PART_MARKER);
        lv_coord_t marker_topp = lv_obj_get_style_pad_top(obj, LV_PART_MARKER);
        lv_coord_t marker_bottomp = lv_obj_get_style_pad_bottom(obj, LV_PART_MARKER);
        lv_point_t marker_size;
        marker_size.x = font_h + marker_leftp + marker_rightp;
        marker_size.y = font_h + marker_topp + marker_bottomp;

        p->x = marker_size.x + txt_size.x + bg_colp;
        p->y = LV_MATH_MAX(marker_size.y, txt_size.y);
    }
    else if(sign == LV_SIGNAL_REFR_EXT_DRAW_PAD) {
        lv_coord_t *s = param;
        lv_coord_t m = _lv_obj_get_draw_rect_ext_pad_size(obj, LV_PART_MARKER);
        *s = LV_MATH_MAX(*s, m);
    }

    return res;
}

#endif
