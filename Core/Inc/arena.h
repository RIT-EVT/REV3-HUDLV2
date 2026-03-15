/*
 * arena.h
 *
 *  Created on: Mar 12, 2026
 *      Author: dg
 */

#ifndef INC_ARENA_H_
#define INC_ARENA_H_

#include "main.h"

typedef struct {
	void* start_addr;
	void* next_free;
	int32_t reference_counter;
	int32_t length;
} Arena;

int32_t arena_init(Arena* a, void* start_addr, int32_t length);
uint32_t get_free_bytes(Arena* a);
void* arena_alloc(Arena* a, uint32_t size);
void arena_dealloc(Arena* a);


#endif /* INC_ARENA_H_ */
