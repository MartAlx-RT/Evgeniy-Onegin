#include "Output.h"


void WriteBufferToFile(const char* FilePath, const char* StrBuffer, unsigned int NumOfLines)
{
    assert(StrBuffer != NULL);
    assert(FilePath != NULL);

    FILE *OutputFile = fopen(FilePath, "w");

    fprintf(OutputFile, "%s", StrBuffer);

    fclose(OutputFile);
}

FILE* WriteToFileFollowingTOC(const char* FilePath, TableOfContent* TOC, const unsigned int NumOfLines, const char Separator)
{
    assert(FilePath != NULL);
    assert(TOC != NULL);
    //assert(Separator > 'z' || Separator < 'A');
    assert(Separator < 'A');

    FILE *OutFileStream = fopen(FilePath, "w");
    if (OutFileStream==NULL)
    {
        

        return NULL;
    }

    for (int i = 0; i < NumOfLines; i++)
    {
        //fprintf(OutFileStream, "Line %d:", i);
        
        fwrite(TOC[i].Line, TOC[i].Length - 1, 1, OutFileStream);

        fputc(Separator, OutFileStream);
    }

    return OutFileStream;
}
