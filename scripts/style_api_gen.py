props = [
{'name': 'RADIUS', 										'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'CLIP_CORNER', 							'style_type': 'num', 	'var_type': 'bool' },
{'name': 'TRANSFORM_WIDTH', 					'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'TRANSFORM_HEIGHT', 					'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'TRANSFORM_ZOOM', 						'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'TRANSFORM_ANGLE', 					'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'OPA', 											'style_type': 'num', 	'var_type': 'lv_opa_t' },
{'name': 'COLOR_FILTER_CB', 					'style_type': 'func', 	'var_type': 'lv_color_filter_cb_t' },
{'name': 'COLOR_FILTER_OPA', 					'style_type': 'num', 	'var_type': 'lv_opa_t' },
{'name': 'ANIM_TIME', 					      'style_type': 'num', 	'var_type': 'uint32_t' },
{'name': 'TRANSITION', 							  'style_type': 'ptr', 	'var_type': 'const lv_style_transition_t *' },
{'name': 'SIZE', 						    			'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'BLEND_MODE', 						    'style_type': 'num', 	'var_type': 'lv_blend_mode_t' },
{'name': 'PAD_TOP', 									'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'PAD_BOTTOM', 								'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'PAD_LEFT', 									'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'PAD_RIGHT', 								'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'PAD_ROW', 								  'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'PAD_COLUMN', 								'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'BG_COLOR', 									'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'BG_COLOR_FILTERED', 				'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'BG_OPA', 										'style_type': 'num', 	'var_type': 'lv_opa_t' },
{'name': 'BG_GRAD_COLOR', 						'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'BG_GRAD_COLOR_FILTERED', 		'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'BG_GRAD_DIR', 							'style_type': 'num', 	'var_type': 'lv_grad_dir_t' },
{'name': 'BG_MAIN_STOP', 							'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'BG_GRAD_STOP', 							'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'BG_IMG_SRC', 							'style_type': 'ptr', 'var_type': 'const void *' },
{'name': 'BG_IMG_OPA', 										'style_type': 'num', 	'var_type': 'lv_opa_t' },
{'name': 'BG_IMG_RECOLOR', 							'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'BG_IMG_RECOLOR_FILTERED', 			'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'BG_IMG_RECOLOR_OPA', 					'style_type': 'num', 	'var_type': 'lv_opa_t' },
{'name': 'BG_IMG_TILED', 							'style_type': 'num', 'var_type': 'bool' },
{'name': 'BORDER_COLOR', 							'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'BORDER_COLOR_FILTERED', 		'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'BORDER_OPA', 								'style_type': 'num', 	'var_type': 'lv_opa_t' },
{'name': 'BORDER_WIDTH', 							'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'BORDER_SIDE', 							'style_type': 'num', 	'var_type': 'lv_border_side_t' },
{'name': 'BORDER_POST', 							'style_type': 'num', 	'var_type': 'bool' },
{'name': 'TEXT_COLOR', 								'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'TEXT_COLOR_FILTERED', 			'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'TEXT_OPA', 									'style_type': 'num', 	'var_type': 'lv_opa_t' },
{'name': 'TEXT_FONT', 								'style_type': 'ptr', 	'var_type': 'const lv_font_t *' },
{'name': 'TEXT_LETTER_SPACE', 				'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'TEXT_LINE_SPACE', 					'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'TEXT_DECOR', 								'style_type': 'num', 	'var_type': 'lv_text_decor_t' },
{'name': 'TEXT_ALIGN', 								'style_type': 'num', 	'var_type': 'lv_text_align_t' },
{'name': 'IMG_OPA', 									'style_type': 'num', 	'var_type': 'lv_opa_t' },
{'name': 'IMG_RECOLOR', 							'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'IMG_RECOLOR_FILTERED', 			'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'IMG_RECOLOR_OPA', 					'style_type': 'num', 	'var_type': 'lv_opa_t' },
{'name': 'OUTLINE_WIDTH', 						'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'OUTLINE_COLOR', 						'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'OUTLINE_COLOR_FILTERED',   	'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'OUTLINE_OPA', 							'style_type': 'num', 	'var_type': 'lv_opa_t' },
{'name': 'OUTLINE_PAD', 							'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'SHADOW_WIDTH', 							'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'SHADOW_OFS_X', 							'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'SHADOW_OFS_Y', 							'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'SHADOW_SPREAD', 						'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'SHADOW_COLOR', 							'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'SHADOW_COLOR_FILTERED', 		'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'SHADOW_OPA', 								'style_type': 'num', 	'var_type': 'lv_opa_t' },
{'name': 'LINE_WIDTH', 								'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'LINE_DASH_WIDTH', 					'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'LINE_DASH_GAP', 						'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'LINE_ROUNDED', 							'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'LINE_COLOR', 								'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'LINE_COLOR_FILTERED', 			'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'LINE_OPA', 									'style_type': 'num', 	'var_type': 'lv_opa_t' },
{'name': 'CONTENT_TEXT', 							'style_type': 'ptr', 	'var_type': 'const char *' },
{'name': 'CONTENT_ALIGN', 						'style_type': 'num', 	'var_type': 'lv_align_t' },
{'name': 'CONTENT_OFS_X', 						'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'CONTENT_OFS_Y', 						'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'CONTENT_OPA', 							'style_type': 'num', 	'var_type': 'lv_opa_t' },
{'name': 'CONTENT_FONT', 							'style_type': 'ptr', 	'var_type': 'const lv_font_t *' },
{'name': 'CONTENT_COLOR', 								'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'CONTENT_COLOR_FILTERED', 								'style_type': 'color', 'var_type': 'lv_color_t' },
{'name': 'CONTENT_LETTER_SPACE', 			'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'CONTENT_LINE_SPACE', 				'style_type': 'num', 	'var_type': 'lv_coord_t' },
{'name': 'CONTENT_DECOR', 						'style_type': 'num', 	'var_type': 'lv_text_decor_t' },
]

def obj_style_get(i):
	print("static inline " + props[i]['var_type'] + " lv_obj_get_style_" + props[i]['name'].lower() +"(const struct _lv_obj_t * obj, uint32_t part) {")
	print("  lv_style_value_t v = lv_obj_get_style_prop(obj, part, LV_STYLE_" + props[i]['name'] + "); return (" + props[i]['var_type'] + ") v." + props[i]['style_type'] + "; }")
	print("") 	
	
	
def style_set(i):
  print("static inline void lv_style_set_" + props[i]['name'].lower() +"(lv_style_t * style, "+ props[i]['var_type'] +" value) {")
  print("  lv_style_value_t v = {." + props[i][			'style_type'] +" = value}; lv_style_set_prop(style, LV_STYLE_" + props[i]['name'] +", v); }")
  print("")


	
for i in range(len(props)): 
  style_set(i)
  
  
  
  
