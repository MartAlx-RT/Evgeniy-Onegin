#include "Input.h"
#include "Output.h"
#include "SortLib.h"
#include "Comparators.h"
#include "TableOfContent.h"

int main(void)
{
    int NumOfLines = 0;

    char *Buffer = CreateStrBuffer("EvgeniyOnegin.txt"); //Input File path
    assert(Buffer != NULL && "Error! Buffer cannot be created");

    TableOfContent *TOC = CreateTOC(Buffer, &NumOfLines, '\n');
    assert(TOC != NULL && "Error! TOC cannot be created");

    /*
    See more at the "Comparators.c"
    ------------------------------------------------------------------
    StrictSort - like as strcmp

    ByFirstLetters - by first letters except start non-letter characters

    ByFirstOnlyLetters - by first letters except all non-letter characters in a string

    ByLastLetters - by last letters except last non-letter characters

    ByLastOnlyLetters - by last letters except all non-letter characters in a string
    */

    printf("Processed %d lines\n", NumOfLines);
    
    QuickSort(TOC, NumOfLines, sizeof(TableOfContent), ByLastLetters);

    FILE *Output = WriteToFileFollowingTOC("Output.txt", TOC, NumOfLines, "\n\n"); //Output file path & Separator string
    assert(Output != NULL && "Error! Output file cannot be created");

    free(Buffer);
    free(TOC);
    fclose(Output);

    return 0;
}

