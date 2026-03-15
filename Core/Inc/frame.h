/*
 * frame.h
 *
 *  Created on: Mar 11, 2026
 *      Author: dg
 */

#ifndef INC_FRAME_H_
#define INC_FRAME_H_

#include <stdint.h>

typedef struct {
	uint16_t total_height;
	uint16_t total_width;
	void* address;
} Frame;

typedef struct {
	uint8_t blue;
	uint8_t green;
	uint8_t red;
} color;

//color red = {0,0,255};
//color green = {0,255,0};
//color blue = {255,0,0};

typedef struct {
	int16_t x;
	int16_t y;
	int16_t z;
} point;

typedef struct {
	point* points;
	uint8_t num_points;
} object;

extern color* fb;

#endif /* INC_FRAME_H_ */
