#include "Input.h"
#include "Output.h"
#include "SortLib.h"
#include "Comparators.h"
#include "TableOfContent.h"

int main(void)
{
    int NumOfLines = 0;

    char *Buffer = CreateStrBuffer("EvgeniyOnegin.txt");
    assert(Buffer != NULL);

    TableOfContent *TOC = CreateTOC(Buffer, &NumOfLines, ' ');
    assert(TOC != NULL);

    QuickSort(TOC, NumOfLines, sizeof(TableOfContent), ByLastOnlyLetters);

    WriteToFileFollowingTOC("Output.txt", TOC, NumOfLines, '\n');

    return 0;
}

