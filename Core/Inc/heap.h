/*
 * heap.h
 *
 *  Created on: Mar 12, 2026
 *      Author: dg
 */

#ifndef INC_HEAP_H_
#define INC_HEAP_H_

#include "main.h"
#include "fmc.h"
#include "arena.h"

#define SCREEN_HEAP_SIZE	(480 * 800 * 3)
#define SCREEN_TOTAL_SIZE	(SCREEN_HEAP_SIZE * 2)

#define HEAP_HEADER_LENGTH 	(0x100)
#define HEAP_START_ADDR		(RAM_START_ADDR + HEAP_HEADER_LENGTH)

#define ARENA_MAX_ARENAS	(256)
#define ARENA_DEFAULT_SIZE 	(32768)

typedef enum {
	HEAP_OK = 0,
	HEAP_ERROR_ALLOCATION_TOO_LARGE,
	HEAP_ERROR_MEMORY_OVERFLOW,
	HEAP_ERROR_TOO_MANY_ARENAS
} Heap_Status;

int32_t heap_init();
void* alloc(int32_t bytes);


#endif /* INC_HEAP_H_ */
