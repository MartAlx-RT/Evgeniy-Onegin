#pragma once

#include "Input.h"

#include <ctype.h>
#include <stdbool.h>

int StrictSort(const void *TOC_1, const void *TOC_2);

int ByFirstLetters(const void *TOC_1, const void *TOC_2);

int ByFirstOnlyLetters(const void *TOC_1, const void *TOC_2);

int ByLastLetters(const void *TOC_1, const void *TOC_2);

int ByLastOnlyLetters(const void *TOC_1, const void *TOC_2);

