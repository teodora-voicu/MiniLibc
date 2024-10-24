// SPDX-License-Identifier: BSD-3-Clause


#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>



void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
     void *allocated_memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

    if (allocated_memory == MAP_FAILED) {
        return NULL;
    }
    return allocated_memory;
}



void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t total_size = nmemb * size;
    void *ptr = malloc(total_size);

    if (ptr != NULL) {
        memset(ptr, 0, total_size);
    }

    return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr != NULL) {
        // Obținem dimensiunea totală alocată din header.
        size_t total_size = *((size_t *)ptr - 1);

        // Eliberăm memoria folosind munmap.
        munmap((void *)((size_t *)ptr - 1), total_size);
    }
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
    (void)ptr;
    (void)size;
	return NULL;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
    (void)ptr;
    (void)nmemb;
    (void)size;
	return NULL;
}
