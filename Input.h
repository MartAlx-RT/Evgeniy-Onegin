#pragma once

#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "../MyStringLib/StringFunctions.h"

#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

typedef struct
{
    size_t Length;
    char *Line;
} TableOfContent;

char **ReallocEnterText(const char *const FilePath, unsigned int *const NumOfLines);

char *CreateStrBuffer(const char *const FilePath);

TableOfContent *CreateTOC(char *StrBuffer, unsigned int *NumOfLines, const char Separator);

void WriteToFileFollowingTOC(const char *FilePath, TableOfContent *TOC, const unsigned int NumOfLines);