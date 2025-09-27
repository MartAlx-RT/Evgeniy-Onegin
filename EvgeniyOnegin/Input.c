#include "Input.h"


char *CreateStrBuffer(const char *const FilePath)
{
    assert(FilePath != NULL);

    FILE *InFileStream = fopen(FilePath, "r");
    if(InFileStream==NULL)
    {

        return NULL;
    }

    struct stat FileInfo = {0};
    if(stat(FilePath, &FileInfo))
        return NULL;
    
    unsigned const int BufferLen = FileInfo.st_size;


    char *StrBuffer = (char *)calloc(BufferLen + 2, sizeof(char));

    assert(StrBuffer != NULL);

    if(fread(StrBuffer, sizeof(char), BufferLen, InFileStream) != BufferLen)
        return NULL;

    fclose(InFileStream);


    StrBuffer[BufferLen] = StrBuffer[BufferLen + 1] = '\0';


    return StrBuffer;
}


TableOfContent *CreateTOC(char *StrBuffer, unsigned int *NumOfLines, const char Separator)
{
    assert(Separator < 'A');

    //char *StrBuffer = InStrBuffer;

    if (StrBuffer == NULL)
    {
        //printf("Warning! String buffer is empty\n");

        return NULL;
    }

    assert(Separator >= 0);
    assert(NumOfLines != NULL);

    TableOfContent *TOC = (TableOfContent *)calloc(1, sizeof(TableOfContent));
    assert(TOC != NULL);

    *NumOfLines = 0;

    StrBuffer--;

    while (StrBuffer != NULL && *(++StrBuffer) != '\0')
    {
        //printf("line=%d\n", *NumOfLines);
        static unsigned int TocLen = 1;

        while (*StrBuffer==Separator)
            StrBuffer++;
        
        if(TocLen <= *NumOfLines)
        {
            TocLen *= 2;

            TOC = (TableOfContent *)realloc(TOC, TocLen * sizeof(TableOfContent));//skip line *2
            assert(TOC != NULL);
        }

        TOC[*NumOfLines].Line = StrBuffer;

        StrBuffer = strchr(StrBuffer, Separator);

        TOC[*NumOfLines].Length = StrBuffer - TOC[*NumOfLines].Line + 1;

        (*NumOfLines)++;
    }

    TOC[*NumOfLines - 1].Length = strlen(TOC[*NumOfLines - 1].Line);
    TOC[*NumOfLines].Line = NULL;
    TOC[*NumOfLines].Length = 0;

    return TOC;
}


