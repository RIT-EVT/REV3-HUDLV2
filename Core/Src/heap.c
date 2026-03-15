/*
 * heap.c
 *
 *  Created on: Mar 12, 2026
 *      Author: dg
 */

#include "heap.h"

// Private Types
typedef struct {
	Arena manager;
	Arena a[ARENA_MAX_ARENAS];
} Heap_Manager;

// Private Functions
static Arena* add_arena(int32_t arena_index, int32_t size_needed);

// Private variables
Heap_Manager heap_man = {0};


int32_t heap_init() {
	MX_FMC_Init(); // YIPPPEEE

	arena_init(&(heap_man.manager), (void*)RAM_START_ADDR, RAM_SIZE_BYTES);

	return 0;
}

void* alloc(int32_t bytes) {
	if (bytes == 0) { // No need to allocate 0 bytes
		return (void*)-1;
	}
	bytes = bytes + (4 - bytes % 4); // want multiples of 4
	if (get_free_bytes(&(heap_man.manager)) < bytes) {
		return NULL;
	}

	uint8_t alloc_found = 0;
	uint8_t arena_index;
	for (arena_index = 0; arena_index < heap_man.manager.reference_counter; arena_index++) {
		if (get_free_bytes(&(heap_man.a[arena_index])) >= bytes) {
			alloc_found = 1;
			break;
		}
	}

	if (!alloc_found) {
		add_arena(arena_index, bytes);
	}
	return arena_alloc(&(heap_man.a[arena_index]), bytes);
}

void dealloc(void* to_dealloc) {
	if (((uint32_t)to_dealloc & 0xF0000000) != (uint32_t)RAM_START_ADDR) {
		return;
	}
	uint32_t upper = (uint32_t)heap_man.manager.reference_counter;
	uint32_t lower = 0;
	uint32_t mid = upper / 2;
	Arena* a;
	while (upper - lower > 0) {
		a = &(heap_man.a[mid]);
		int32_t distance = ((int32_t) (to_dealloc - a->start_addr));
		if (distance < 0) {
			upper = mid;
		} else if (distance < a->length) {
			break;
		} else {
			lower = mid;
		}
		mid = upper - lower / 2;
	}

	arena_dealloc(a);
}

static Arena* add_arena(int32_t arena_index, int32_t size_needed) {
	Arena* a = &(heap_man.a[arena_index]);
	size_needed = (size_needed > ARENA_DEFAULT_SIZE) ? size_needed : ARENA_DEFAULT_SIZE ;
	if (arena_alloc(&(heap_man.manager), size_needed) != NULL) {
		arena_init(a, heap_man.manager.next_free, size_needed);
	}
	return a;
}
