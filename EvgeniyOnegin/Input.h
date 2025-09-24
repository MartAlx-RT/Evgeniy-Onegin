#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
//#include "../MyStringLib/StringFunctions.h"

#include <string.h>
//#include <stdlib.h>
#include <sys/stat.h>
#include "TableOfContent.h"


char *CreateStrBuffer(const char *const FilePath);

TableOfContent *CreateTOC(char *StrBuffer, unsigned int *NumOfLines, const char Separator);

