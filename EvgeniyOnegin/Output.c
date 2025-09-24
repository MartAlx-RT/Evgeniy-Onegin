#include "Output.h"


void WriteBufferToFile(const char* FilePath, const char* StrBuffer, unsigned int NumOfLines)
{
    assert(StrBuffer != NULL);
    assert(FilePath != NULL);

    FILE *OutputFile = fopen(FilePath, "w");

    fprintf(OutputFile, "%s", StrBuffer);

    fclose(OutputFile);
}

void WriteToFileFollowingTOC(const char* FilePath, TableOfContent* TOC, const unsigned int NumOfLines, const char Separator)
{
    assert(FilePath != NULL);
    assert(TOC != NULL);
    //assert(Separator > 'z' || Separator < 'A');
    assert(Separator < 'A');

    FILE *OutFileStream = fopen(FilePath, "w");
    if (OutFileStream==NULL)
    {
        printf("Wrong file path\n");

        exit(1);
    }

    for (int i = 0; i < NumOfLines; i++)
    {
        fwrite(TOC[i].Line, TOC[i].Length - 1, 1, OutFileStream);

        fputc(Separator, OutFileStream);
    }

    fclose(OutFileStream);
}
