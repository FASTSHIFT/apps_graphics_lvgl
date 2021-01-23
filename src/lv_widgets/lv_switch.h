/**
 * @file lv_sw.h
 *
 */

#ifndef LV_SWITCH_H
#define LV_SWITCH_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../lv_conf_internal.h"

#if LV_USE_SWITCH != 0

/*Testing of dependencies*/
#if LV_USE_SLIDER == 0
#error "lv_switch: lv_slider is required. Enable it in lv_conf.h (LV_USE_SLIDER  1)"
#endif

#include "../lv_core/lv_obj.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    lv_obj_t obj;
}lv_switch_t;


extern const lv_obj_class_t lv_switch;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a switch objects
 * @param parent pointer to an object, it will be the parent of the new switch
 * @param copy DEPRECATED, will be removed in v9.
 *             Pointer to an other switch to copy.
 * @return pointer to the created switch
 */
lv_obj_t * lv_switch_create(lv_obj_t * parent, const lv_obj_t * copy);

/**********************
 *      MACROS
 **********************/

#endif /*LV_USE_SWITCH*/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_SWITCH_H*/
