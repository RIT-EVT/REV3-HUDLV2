/*
 * frame.c
 *
 *  Created on: Mar 11, 2026
 *      Author: dg
 */
#include "frame.h"
#include "ltdc.h"

color* fb = (color*) 0xC0000000;

uint32_t framebuffer_indexer(uint16_t row, uint16_t col) {
	return row * 480 + col;
}

void fill_background(color* c) {
	HAL_GPIO_WritePin(DISP_EN_GPIO_Port, DISP_EN_Pin, GPIO_PIN_RESET);
	color* ptr = fb;
	for (uint32_t i = 0; i < SCREEN_AREA; i++) {
		*ptr = *c;
		ptr++;
	}
	HAL_GPIO_WritePin(DISP_EN_GPIO_Port, DISP_EN_Pin, GPIO_PIN_SET);
}

void draw_point(point* p, color* c) {

}

void draw_frame() {
	color background = {0xFF, 0, 0};

//	point a = {0,0,0};
//	color r = {255,255,255};

//	HAL_Delay(500);
	fill_background(&background);
//	draw_point(&a, &r);
}
