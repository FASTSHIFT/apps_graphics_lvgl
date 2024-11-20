/**
 * @file lv_chart.h
 *
 */

#ifndef LV_CHART_H
#define LV_CHART_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../lv_conf_internal.h"

#if LV_USE_CHART != 0

#include "../lv_core/lv_obj.h"
#include "lv_line.h"

/*********************
 *      DEFINES
 *********************/

/**Default value of points. Can be used to not draw a point*/
#define LV_CHART_POINT_DEF (LV_COORD_MIN)

LV_EXPORT_CONST_INT(LV_CHART_POINT_DEF);
LV_EXPORT_CONST_INT(LV_CHART_TICK_LENGTH_AUTO);

/**********************
 *      TYPEDEFS
 **********************/

/** Chart types*/
enum {
    LV_CHART_TYPE_NONE     = 0x00, /**< Don't draw the series*/
    LV_CHART_TYPE_LINE     = 0x01, /**< Connect the points with lines*/
    LV_CHART_TYPE_COLUMN   = 0x02, /**< Draw columns*/
};
typedef uint8_t lv_chart_type_t;

/** Chart update mode for `lv_chart_set_next`*/
enum {
    LV_CHART_UPDATE_MODE_SHIFT,     /**< Shift old data to the left and add the new one o the right*/
    LV_CHART_UPDATE_MODE_CIRCULAR,  /**< Add the new data in a circular way*/
};
typedef uint8_t lv_chart_update_mode_t;


enum {
    LV_CHART_AXIS_PRIMARY_Y,    /*Y axis should be the first to allow indexing arrays with the values*/
    LV_CHART_AXIS_SECONDARY_Y,
    LV_CHART_AXIS_X,
    _LV_CHART_AXIS_LAST,
};
typedef uint8_t lv_chart_axis_t;

typedef struct {
    lv_coord_t * points;
    lv_color_t color;
    uint16_t start_point;
    uint8_t ext_buf_assigned : 1;
    uint8_t hidden : 1;
    lv_chart_axis_t y_axis  : 1;
} lv_chart_series_t;

typedef struct {
    lv_point_t point;
    lv_color_t color;
    lv_dir_t axes  : 4;
} lv_chart_cursor_t;

typedef void (*lv_chart_tick_label_cb_t)(const lv_obj_t * obj, lv_chart_axis_t axis,  uint32_t tick_id, char buf[], size_t buf_len);

typedef struct {
    lv_obj_t obj;
    lv_ll_t series_ll;    /*Linked list for the data line pointers (stores lv_chart_series_t)*/
    lv_ll_t cursors_ll;    /*Linked list for the cursor pointers (stores lv_chart_cursor_t)*/
    lv_chart_tick_label_cb_t tick_label_cb;
    lv_coord_t ymin[2];
    lv_coord_t ymax[2];
    lv_coord_t ext_size;
    uint8_t hdiv_cnt;     /*Number of horizontal division lines*/
    uint8_t vdiv_cnt;     /*Number of vertical division lines*/
    uint8_t sub_tick_cnt[_LV_CHART_AXIS_LAST];
    uint16_t point_cnt;   /*Point number in a data line*/
    lv_chart_type_t type; /*Line, column or point chart (from 'lv_chart_type_t')*/
    uint16_t x_zoom;
    uint16_t y_zoom;
    uint8_t update_mode : 1;
}lv_chart_t;

extern const lv_obj_class_t lv_chart;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a chart background objects
 * @param par pointer to an object, it will be the parent of the new chart background
 * @param copy pointer to a chart background object, if not NULL then the new object will be copied
 * from it
 * @return pointer to the created chart background
 */
lv_obj_t * lv_chart_create(lv_obj_t * par, const lv_obj_t * copy);

/*======================
 * Add/remove functions
 *=====================*/

/**
 * Allocate and add a data series to the chart
 * @param chart pointer to a chart object
 * @param color color of the data series
 * @return pointer to the allocated data series
 */
lv_chart_series_t * lv_chart_add_series(lv_obj_t * chart, lv_color_t color);

/**
 * Deallocate and remove a data series from a chart
 * @param chart pointer to a chart object
 * @param series pointer to a data series on 'chart'
 */
void lv_chart_remove_series(lv_obj_t * chart, lv_chart_series_t * series);

/**
 * Add a cursor with a given color
 * @param chart pointer to chart object
 * @param color color of the cursor
 * @param dir direction of the cursor. `LV_DIR_RIGHT/LEFT/TOP/BOTTOM/HOR/VER/ALL`
 * @return pointer to the created cursor
 */
lv_chart_cursor_t * lv_chart_add_cursor(lv_obj_t * chart, lv_color_t color, lv_dir_t dir);

/**
 * Clear the point of a series
 * @param chart pointer to a chart object
 * @param series pointer to the chart's series to clear
 */
void lv_chart_clear_series(lv_obj_t * chart, lv_chart_series_t * series);

/**
 * Hide/Unhide a single series of a chart.
 * @param chart pointer to a chart object.
 * @param series pointer to a series object
 * @param hide true: hide the series
 */
void lv_chart_hide_series(lv_obj_t * chart, lv_chart_series_t * series, bool hide);


/*=====================
 * Setter functions
 *====================*/


/**
 * Set the number of horizontal and vertical division lines
 * @param chart pointer to a graph background object
 * @param hdiv number of horizontal division lines
 * @param vdiv number of vertical division lines
 */
void lv_chart_set_div_line_count(lv_obj_t * chart, uint8_t hdiv, uint8_t vdiv);

/**
 * Set the minimal and maximal y values on an axis
 * @param chart pointer to a graph background object
 * @param axis `LV_CHART_AXIS_PRIMARY_Y` or `LV_CHART_AXIS_SECONDARY_Y`
 * @param ymin y minimum value
 * @param ymax y maximum value
 */
void lv_chart_set_y_range(lv_obj_t * chart, lv_chart_axis_t axis, lv_coord_t ymin, lv_coord_t ymax);

/**
 * Set a new type for a chart
 * @param chart pointer to a chart object
 * @param type new type of the chart (from 'lv_chart_type_t' enum)
 */
void lv_chart_set_type(lv_obj_t * chart, lv_chart_type_t type);

/**
 * Set the number of points on a data line on a chart
 * @param chart pointer r to chart object
 * @param point_cnt new number of points on the data lines
 */
void lv_chart_set_point_count(lv_obj_t * chart, uint16_t point_cnt);

/**
 * Initialize all data points with a value
 * @param chart pointer to chart object
 * @param ser pointer to a data series on 'chart'
 * @param y the new value  for all points
 */
void lv_chart_init_points(lv_obj_t * chart, lv_chart_series_t * ser, lv_coord_t y);

/**
 * Set the value of points from an array
 * @param chart pointer to chart object
 * @param ser pointer to a data series on 'chart'
 * @param y_array array of 'lv_coord_t' points (with 'points count' elements )
 */
void lv_chart_set_points(lv_obj_t * chart, lv_chart_series_t * ser, lv_coord_t y_array[]);

/**
 * Shift all data right and set the most right data on a data line
 * @param chart pointer to chart object
 * @param ser pointer to a data series on 'chart'
 * @param y the new value of the most right data
 */
void lv_chart_set_next(lv_obj_t * chart, lv_chart_series_t * ser, lv_coord_t y);

/**
 * Set update mode of the chart object.
 * @param chart pointer to a chart object
 * @param update mode
 */
void lv_chart_set_update_mode(lv_obj_t * chart, lv_chart_update_mode_t update_mode);

/**
 * Set the length of the tick marks on the x axis
 * @param chart pointer to the chart
 * @param major_tick_len the length of the major tick or `LV_CHART_TICK_LENGTH_AUTO` to set automatically
 *                       (where labels are added)
 * @param minor_tick_len the length of the minor tick, `LV_CHART_TICK_LENGTH_AUTO` to set automatically
 *                       (where no labels are added)
 */
void lv_chart_set_x_tick_length(lv_obj_t * chart, uint8_t major_tick_len, uint8_t minor_tick_len);

/**
 * Set the length of the tick marks on the y axis
 * @param chart pointer to the chart
 * @param major_tick_len the length of the major tick or `LV_CHART_TICK_LENGTH_AUTO` to set automatically
 *                       (where labels are added)
 * @param minor_tick_len the length of the minor tick, `LV_CHART_TICK_LENGTH_AUTO` to set automatically
 *                       (where no labels are added)
 */
void lv_chart_set_y_tick_length(lv_obj_t * chart, uint8_t major_tick_len, uint8_t minor_tick_len);

/**
 * Set the length of the tick marks on the secondary y axis
 * @param chart pointer to the chart
 * @param major_tick_len the length of the major tick or `LV_CHART_TICK_LENGTH_AUTO` to set automatically
 *                       (where labels are added)
 * @param minor_tick_len the length of the minor tick, `LV_CHART_TICK_LENGTH_AUTO` to set automatically
 *                       (where no labels are added)
 */
void lv_chart_set_secondary_y_tick_length(lv_obj_t * chart, uint8_t major_tick_len, uint8_t minor_tick_len);

/**
 * Set the x-axis tick count and labels of a chart
 * @param chart             pointer to a chart object
 * @param list_of_values    list of string values, terminated with \n, except the last
 * @param num_tick_marks    if list_of_values is NULL: total number of ticks per axis
 *                          else number of ticks between two value labels
 * @param options           extra options
 */
void lv_chart_set_tick_label_cb(lv_obj_t * chart, lv_chart_tick_label_cb_t tick_label_cb, lv_coord_t ext_size);

/**
 * Set the index of the x-axis start point in the data array
 * @param chart             pointer to a chart object
 * @param ser               pointer to a data series on 'chart'
 * @param id                the index of the x point in the data array
 */
void lv_chart_set_x_start_point(lv_obj_t * chart, lv_chart_series_t * ser, uint16_t id);

/**
 * Set an external array of data points to use for the chart
 * NOTE: It is the users responsibility to make sure the point_cnt matches the external array size.
 * @param chart             pointer to a chart object
 * @param ser               pointer to a data series on 'chart'
 * @param array             external array of points for chart
 */
void lv_chart_set_ext_array(lv_obj_t * chart, lv_chart_series_t * ser, lv_coord_t array[], uint16_t point_cnt);

/**
 * Set an individual point value in the chart series directly based on index
 * @param chart             pointer to a chart object
 * @param ser               pointer to a data series on 'chart'
 * @param value             value to assign to array point
 * @param id                the index of the x point in the array
 */
void lv_chart_set_point_id(lv_obj_t * chart, lv_chart_series_t * ser, lv_coord_t value, uint16_t id);

/**
 * Set the Y axis of a series
 * @param chart pointer to a chart object
 * @param ser pointer to series
 * @param axis `LV_CHART_AXIS_PRIMARY_Y` or `LV_CHART_AXIS_SECONDARY_Y`
 */
void lv_chart_set_series_axis(lv_obj_t * chart, lv_chart_series_t * ser, lv_chart_axis_t axis);

/**
 * Set the coordinate of the cursor with respect
 * to the origin of series area of the chart.
 * @param chart pointer to a chart object.
 * @param cursor pointer to the cursor.
 * @param point the new coordinate of cursor relative to the series area
 */
void lv_chart_set_cursor_point(lv_obj_t * chart, lv_chart_cursor_t * cursor, lv_point_t * point);


/*=====================
 * Getter functions
 *====================*/

/**
 * Get the type of a chart
 * @param chart pointer to chart object
 * @return type of the chart (from 'lv_chart_t' enum)
 */
lv_chart_type_t lv_chart_get_type(const lv_obj_t * chart);

/**
 * Get the data point number per data line on chart
 * @param chart pointer to chart object
 * @return point number on each data line
 */
uint16_t lv_chart_get_point_count(const lv_obj_t * chart);

/**
 * get the current index of the x-axis start point in the data array
 * @param ser               pointer to a data series on 'chart'
 * @return                  the index of the current x start point in the data array
 */
uint16_t lv_chart_get_x_start_point(lv_chart_series_t * ser);

/**
 * Get an individual point value in the chart series directly based on index
 * @param chart             pointer to a chart object
 * @param ser               pointer to a data series on 'chart'
 * @param id                the index of the x point in the array
 * @return                  value of array point at index id
 */
lv_coord_t lv_chart_get_point_id(lv_obj_t * chart, lv_chart_series_t * ser, uint16_t id);

/**
 * Get the Y axis of a series
 * @param chart pointer to a chart object
 * @param ser pointer to series
 * @return `LV_CHART_AXIS_PRIMARY_Y` or `LV_CHART_AXIS_SECONDARY_Y`
 */
lv_chart_axis_t lv_chart_get_series_axis(lv_obj_t * chart, lv_chart_series_t * ser);

/**
 * Get the coordinate of the cursor with respect
 * to the origin of series area of the chart.
 * @param chart pointer to a chart object
 * @param cursor pointer to cursor
 * @return coordinate of the cursor as lv_point_t
 */
lv_point_t lv_chart_get_cursor_point(lv_obj_t * chart, lv_chart_cursor_t * cursor);

/**
 * Get the nearest index to an X coordinate
 * @param chart pointer to a chart object
 * @param coord the coordination of the point relative to the series area.
 * @return the found index
 */
uint16_t lv_chart_get_nearest_index_from_coord(lv_obj_t * chart, lv_coord_t x);

/**
 * Get the x coordinate of the an index with respect
 * to the origin of series area of the chart.
 * @param chart pointer to a chart object
 * @param ser pointer to series
 * @param id the index.
 * @return x coordinate of index
 */
lv_coord_t lv_chart_get_x_from_index(lv_obj_t * chart, lv_chart_series_t * ser, uint16_t id);

/**
 * Get the y coordinate of the an index with respect
 * to the origin of series area of the chart.
 * @param chart pointer to a chart object
 * @param ser pointer to series
 * @param id the index.
 * @return y coordinate of index
 */
lv_coord_t lv_chart_get_y_from_index(lv_obj_t * chart, lv_chart_series_t * ser, uint16_t id);

/*=====================
 * Other functions
 *====================*/

/**
 * Refresh a chart if its data line has changed
 * @param chart pointer to chart object
 */
void lv_chart_refresh(lv_obj_t * chart);

/**********************
 *      MACROS
 **********************/

#endif /*LV_USE_CHART*/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_CHART_H*/
