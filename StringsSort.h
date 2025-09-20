#pragma once

#include "../MyStringLib/StringFunctions.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
//#include <math.h>

#define SQ(x) ((x)*(x))

//void QuickStringsSort(char **TOC, int NumOfLines, const char Separator, bool (*CompStr)(char *, char *));

void QuickSort(void *Arr, int NumOfElements, size_t SizeOfElement, int (*Comp)(void *, void *));

