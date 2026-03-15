/*
 * arena.c
 *
 *  Created on: Mar 12, 2026
 *      Author: dg
 */
#include "arena.h"

int32_t arena_init(Arena* a, void* start_addr, int32_t length) {
	a->start_addr = start_addr;
	a->next_free = start_addr;
	a->length = length;
	a->reference_counter = 0;

	return 0;
}

uint32_t get_free_bytes(Arena* a) {
	return a->length - ((uint32_t)(a->next_free - a->start_addr));
}

void* arena_alloc(Arena* a, uint32_t size) {
	if (get_free_bytes(a) < size) {
		return NULL;
	}
	a->reference_counter++;
	void* addr = a->next_free;
	a->next_free += size;
	return addr;
}

void arena_dealloc(Arena* a) {
	if (a->reference_counter > 0) {
		a->reference_counter--;
	}
	if (a->reference_counter <= 0) {
		a->reference_counter = 0;
		a->next_free = a->start_addr;
	}
}

