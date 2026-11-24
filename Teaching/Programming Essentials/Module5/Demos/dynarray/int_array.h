#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <stddef.h>
typedef struct IntArray IntArray;

IntArray* int_array_create(int);
void int_array_destroy(IntArray*);

size_t int_array_size(const IntArray*);
size_t int_array_capacity(const IntArray*);

void int_array_push(IntArray*, int);
bool int_array_get_at(const IntArray*, size_t, int*);
bool int_array_set_at(IntArray*, size_t, int);

void int_array_sort(IntArray*);

bool int_array_find(const IntArray*, int, size_t*);

#endif
