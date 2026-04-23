#ifndef HEAP_H
#define HEAP_H
#include <stddef.h>
typedef struct block {
    int id;
    size_t size;
    int free;
    void *addr;
    struct block *next;
} block_t;
extern block_t *head;
extern int strategy_mode;
void *my_malloc(size_t size);
void my_free_id(int id);
void reset_heap();
void auto_defrag();
int count_used();
int count_free();
int count_total();
int total_bytes();
int free_bytes();
#endif

