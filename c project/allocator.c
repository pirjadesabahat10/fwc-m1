#include <unistd.h>
#include "heap.h"
block_t *head = NULL;
int gid = 1;
int strategy_mode = 0;
block_t *find_first_fit(size_t size)
{
    block_t *t = head;
    while(t)
    {
        if(t->free && t->size >= size)
            return t;
        t = t->next;
    }
    return NULL;
}
block_t *find_best_fit(size_t size)
{
    block_t *t = head;
    block_t *best = NULL;
    while(t)
    {
        if(t->free && t->size >= size)
        {
            if(best == NULL || t->size < best->size)
                best = t;
        }
        t = t->next;
    }
    return best;
}
void *my_malloc(size_t size)
{
    block_t *reuse = NULL;
    if(strategy_mode == 0)
        reuse = find_first_fit(size);
    else
        reuse = find_best_fit(size);
    if(reuse)
    {
        reuse->free = 0;
        reuse->size = size;
        return reuse->addr;
    }
    block_t *block = sbrk(size + sizeof(block_t));
    if(block == (void*)-1)
        return NULL;
    block->id = gid++;
    block->size = size;
    block->free = 0;
    block->addr = (void*)(block + 1);
    block->next = NULL;
    if(!head)
        head = block;
    else
    {
        block_t *t = head;
        while(t->next) t = t->next;
        t->next = block;
    }
    return block->addr;
}
void my_free_id(int id)
{
    block_t *t = head;
    while(t)
    {
        if(t->id == id)
        {
            t->free = 1;
            return;
        }
        t = t->next;
    }
}
void auto_defrag()
{
    block_t *t = head;
    while(t && t->next)
    {
        if(t->free && t->next->free)
        {
            t->size += t->next->size;
            t->next = t->next->next;
        }
        else
            t = t->next;
    }
}
void reset_heap()
{
    head = NULL;
    gid = 1;
}
int count_used()
{
    int c=0; block_t *t=head;
    while(t){ if(!t->free)c++; t=t->next; }
    return c;
}
int count_free()
{
    int c=0; block_t *t=head;
    while(t){ if(t->free)c++; t=t->next; }
    return c;
}
int count_total()
{
    int c=0; block_t *t=head;
    while(t){ c++; t=t->next; }
    return c;
}
int total_bytes()
{
    int s=0; block_t *t=head;
    while(t){ s+=t->size; t=t->next; }
    return s;
}
int free_bytes()
{
    int s=0; block_t *t=head;
    while(t){ if(t->free)s+=t->size; t=t->next; }
    return s;
}

