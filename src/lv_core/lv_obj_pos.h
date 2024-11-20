/**
 * @file lv_obj_pos.h
 *
 */

#ifndef LV_OBJ_POS_H
#define LV_OBJ_POS_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../lv_misc/lv_area.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
struct _lv_obj_t;

typedef void (*lv_layout_update_cb_t)(struct _lv_obj_t * cont, struct _lv_obj_t * item);

/**
 * The base of all layouts descriptor.
 * Every custom layout descriptor needs to extend this struct
 * by adding `lv_layout_dsc_t` as the first element.
 */
typedef struct {
    lv_layout_update_cb_t update_cb;
}lv_layout_dsc_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Set the relative the position of an object (relative to the parent's top left corner)
 * @param obj: pointer to an object
 * @param x:   new distance from the left side of the parent plus the parent's left padding
 * @param y:   new distance from the top side of the parent  plus the parent's right padding
 */
void lv_obj_set_pos(struct _lv_obj_t * obj, lv_coord_t x, lv_coord_t y);

/**
 * Set the x coordinate of a object
 * @param obj: pointer to an object
 * @param x:   new distance from the left side from the parent plus the parent's left padding
 */
void lv_obj_set_x(struct _lv_obj_t * obj, lv_coord_t x);

/**
 * Set the y coordinate of a object
 * @param obj: pointer to an object
 * @param y:   new distance from the top of the parent  plus the parent's top padding
 */
void lv_obj_set_y(struct _lv_obj_t * obj, lv_coord_t y);

/**
 * Set the size of an object.
 * @param obj: pointer to an object
 * @param w: new width in pixels or `LV_SIZE_AUTO` to set the size to involve all children
 * @param h: new height in pixels or `LV_SIZE_AUTO` to set the size to involve all children
 */
void lv_obj_set_size(struct _lv_obj_t * obj, lv_coord_t w, lv_coord_t h);

/**
 * Set the width of an object
 * @param obj: pointer to an object
 * @param w:   new width in pixels or `LV_SIZE_AUTO` to set the size to involve all children
 */
void lv_obj_set_width(struct _lv_obj_t * obj, lv_coord_t w);

/**
 * Set the height of an object
 * @param obj: pointer to an object
 * @param h: new height in pixels or `LV_SIZE_AUTO` to set the size to involve all children
 */
void lv_obj_set_height(struct _lv_obj_t * obj, lv_coord_t h);

/**
 * Set the width reduced by the left and right padding.
 * @param obj: pointer to an object
 * @param w:   the width without paddings in pixels
 */
void lv_obj_set_content_width(struct _lv_obj_t * obj, lv_coord_t w);

/**
 * Set the height reduced by the top and bottom padding.
 * @param obj: pointer to an object
 * @param h:   the height without paddings in pixels
 */
void lv_obj_set_content_height(struct _lv_obj_t * obj, lv_coord_t h);

/**
 * Set a layout for an object
 * @param obj:    pointer to an object
 * @param layout: pointer to a layout descriptor to set
 */
void lv_obj_set_layout(struct _lv_obj_t * obj, const void * layout);

/**
 * Test whether the and object is positioned by a layout or not
 * @param obj: pointer to an object to test
 * @return true: positioned by a layout; false: not positioned by a layout
 */
bool lv_obj_is_layout_positioned(const struct _lv_obj_t * obj);

/**
 * Update the layout of an object.
 * @param cont: pointer to an object whose children needs to be updated
 * @param item: pointer to a child object that triggered the update. Set to `NULL` is not known.
 *              If not `NULL` the update process should make some optimization
 *              to update only the required parts of the layout
 */
void lv_obj_update_layout(struct _lv_obj_t * cont, struct _lv_obj_t * item);


/**
 * Align an object to an other object.
 * @param obj:   pointer to an object to align
 * @param base:  pointer to an other object (if NULL `obj`s parent is used). 'obj' will be aligned to it.
 * @param align: type of alignment (see 'lv_align_t' enum)
 * @param x_ofs: x coordinate offset after alignment
 * @param y_ofs: y coordinate offset after alignment
 */
void lv_obj_align(struct _lv_obj_t * obj, const struct _lv_obj_t * base, lv_align_t align, lv_coord_t x_ofs, lv_coord_t y_ofs);

/**
 * Copy the coordinates of an object to an area
 * @param obj:        pointer to an object
 * @param coords: pointer to an area to store the coordinates
 */
void lv_obj_get_coords(const struct _lv_obj_t * obj, lv_area_t * coords);

/**
 * Get the x coordinate of object.
 * @param obj: pointer to an object
 * @return distance of `obj` from the left side of its parent plus the parent's left padding
 * @note Zero return value means the object is on the left padding of the parent, and not on the left edge.
 * @note Scrolling of the parent doesn't change the returned value.
 * @note The returned value is always the distance from the parent even if `obj` is positioned by a layout.
 */
lv_coord_t lv_obj_get_x(const struct _lv_obj_t * obj);

/**
 * Get the y coordinate of object.
 * @param obj: pointer to an object
 * @return distance of `obj` from the top side of its parent plus the parent's top padding
 * @note Zero return value means the object is on the top padding of the parent, and not on the top edge.
 * @note Scrolling of the parent doesn't change the returned value.
 * @note The returned value is always the distance from the parent even if `obj` is positioned by a layout.
 */
lv_coord_t lv_obj_get_y(const struct _lv_obj_t * obj);

/**
 * Get the width of an object
 * @param obj pointer to an object
 * @return the width in pixels
 */
lv_coord_t lv_obj_get_width(const struct _lv_obj_t * obj);

/**
 * Get the height of an object
 * @param obj pointer to an object
 * @return the height in pixels
 */
lv_coord_t lv_obj_get_height(const struct _lv_obj_t * obj);

/**
 * Get that width reduced by the left and right padding.
 * @param obj: pointer to an object
 * @return the width which still fits into the container without causing overflow (making the object scrollable)
 */
lv_coord_t lv_obj_get_width_fit(const struct _lv_obj_t * obj);

/**
 * Get that height reduced by the top an bottom padding.
 * @param obj: pointer to an object
 * @return the height which still fits into the container without causing overflow (making the object scrollable)
 */
lv_coord_t lv_obj_get_height_fit(const struct _lv_obj_t * obj);

/**
 * Get the width occupied by the "parts" of the widget. E.g. the width of all columns of a table.
 * @param obj: pointer to an objects
 * @return the width of the virtually drawn content
 * @note This size independent from the real size of the widget.
 *       It just tells how large the internal ("virtual") content is.
 */
lv_coord_t lv_obj_get_self_width(struct _lv_obj_t * obj);

/**
 * Get the height occupied by the "parts" of the widget. E.g. the height of all rows of a table.
 * @param obj: pointer to an objects
 * @return the width of the virtually drawn content
 * @note This size independent from the real size of the widget.
 *       It just tells how large the internal ("virtual") content is.
 */
lv_coord_t lv_obj_get_self_height(struct _lv_obj_t * obj);

/**
 * Handle if the size of the internal ("virtual") content of an object has changed.
 * @param obj: pointer to an object
 * @return false: nothing happened; true: refresh happened
 */
bool lv_obj_handle_self_size_chg(struct _lv_obj_t * obj);


/**
 * Mark an area of an object as invalid.
 * The area will be truncated to the object's area and marked for redraw.
 * @param obj:  pointer to an object
 * @param area: the area to redraw
 */
void lv_obj_invalidate_area(const struct _lv_obj_t * obj, const lv_area_t * area);

/**
 * Mark the object as invalid to redrawn its area
 * @param obj: pointer to an object
 */
void lv_obj_invalidate(const struct _lv_obj_t * obj);

/**
 * Tell whether an area of an object is visible (even partially) now or not
 * @param obj:  pointer to an object
 * @param area: the are to check. The visible part of the area will be written back here.
 * @return true: visible; false: not visible (hidden, out of parent, on other screen, etc)
 */
bool lv_obj_area_is_visible(const struct _lv_obj_t * obj, lv_area_t * area);

/**
 * Tell whether an object is visible (even partially) now or not
 * @param obj pointer to an object
 * @return true: visible; false: not visible (hidden, out of parent, on other screen, etc)
 */
bool lv_obj_is_visible(const struct _lv_obj_t * obj);

/**
 * Set the size of an extended clickable area
 * If `LV_USE_EXT_CLICK_AREA == LV_EXT_CLICK_AREA_TINY` in `lv_conf.h`,
 *  only the graetes value will be used.
 * @param obj pointer to an object
 * @param left extended clickable are on the left [px]
 * @param right extended clickable are on the right [px]
 * @param top extended clickable are on the top [px]
 * @param bottom extended clickable are on the bottom [px]
 */
void lv_obj_set_ext_click_area(struct _lv_obj_t * obj, lv_coord_t left, lv_coord_t right, lv_coord_t top, lv_coord_t bottom);

/**
 * Get the an area where to object can be clicked.
 * It's the object's normal area plus the extended click area.
 * @param obj: pointer to an object
 * @param area: store the result area here
 */
void lv_obj_get_click_area(const struct _lv_obj_t * obj, lv_area_t * area);

/**
 * Hit-test an object given a particular point in screen space.
 * @param obj object to hit-test
 * @param point screen-space point (absolute coordinate)
 * @return true: if the object is considered under the point
 */
bool lv_obj_hit_test(const struct _lv_obj_t * obj, const lv_point_t * point);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_OBJ_POS_H*/
