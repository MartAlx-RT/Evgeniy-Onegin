#pragma once


#include <stdbool.h>
#include <ctype.h>
#include <stddef.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>

void QuickSort(void *Arr, int NumOfElements, size_t SizeOfElement, int (*Comp)(const void *, const void *));

