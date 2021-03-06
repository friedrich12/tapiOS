#ifndef _TAPIOS_PMM_H_
#define _TAPIOS_PMM_H_

#include <stdint.h>
#include <util/util.h>

#define BITMAP_SIZE 32768
typedef uintptr_t physaddr_t;

uint32_t bitmap[BITMAP_SIZE];

void setup_bitmap(void);
bool is_free_page(physaddr_t addr);
physaddr_t kalloc_page_frame();
void kfree_page_frame(physaddr_t ptr);
physaddr_t kalloc_page_frame_at(physaddr_t addr);

#endif
