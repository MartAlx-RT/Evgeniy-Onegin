#pragma once

//#include "../MyStringLib/StringFunctions.h"
//#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stddef.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
//#include <string.h>
//#include <math.h>

//void QuickStringsSort(char **TOC, int NumOfLines, const char Separator, bool (*CompStr)(char *, char *));

void QuickSort(void *Arr, int NumOfElements, size_t SizeOfElement, int (*Comp)(const void *, const void *));

