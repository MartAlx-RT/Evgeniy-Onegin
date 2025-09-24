#pragma once

#include <stdio.h>
//#include "../MyStringLib/StringFunctions.h"

#include "TableOfContent.h"
#include <assert.h>
#include <stdlib.h>

void WriteBufferToFile(const char *FilePath, const char *StrBuffer, unsigned int NumOfLines);

void WriteToFileFollowingTOC(const char *FilePath, TableOfContent *TOC, const unsigned int NumOfLines, const char Separator);