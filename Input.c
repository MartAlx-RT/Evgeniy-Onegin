#include "Input.h"
//const int MAX_STR_LEN = 100;
//const int MAX_STR_NUM = 100;

//struct lenght, pointer to start

char **ReallocEnterText(const char *const FilePath, unsigned int *const NumOfLines)
{
    assert(FilePath != NULL);
    assert(NumOfLines != NULL);

    FILE *InputFile = fopen(FilePath, "r");
    // if error -> error message

    char **Text = (char **)calloc(1, sizeof(char));
    // check for null
    assert(Text != NULL);

    unsigned int UselessLen = 0;

    *NumOfLines = 1;

    while(GetLine(Text + *NumOfLines - 1, &UselessLen, InputFile) > 0)
    {
        //printf("line(before realloc) %d\n", *NumOfLines);

        assert(Text + *NumOfLines - 1 != NULL);

        Text = (char **)realloc(Text, sizeof(char *) * (++(*NumOfLines)+10));//+10

        //printf("line(after realloc) %d\n", *NumOfLines);

        assert(Text != NULL);
        assert(*Text != NULL);
    }

    fclose(InputFile);
    
    if(*NumOfLines==1)
        return NULL;

    //printf("after close, Numoflines=%d\n", *NumOfLines);
    (*NumOfLines)--;

    return Text;
}



char *CreateStrBuffer(const char *const FilePath)
{
    assert(FilePath != NULL);
    //assert(NumOfLines != NULL);

    FILE *InFileStream = fopen(FilePath, "r");
    if(InFileStream==NULL)
    {
        printf("Error! Wrong file path\n");

        return NULL;
    }

    struct stat FileInfo = {0};
    stat(FilePath, &FileInfo);
    unsigned const int BufferLen = FileInfo.st_size;


    char *StrBuffer = (char *)calloc(BufferLen + 2, sizeof(char));//discuss +2 with a mentor

    

    assert(StrBuffer != NULL);

    assert(
        fread(StrBuffer, sizeof(char), BufferLen, InFileStream) == BufferLen);//NULL

    
    
    fclose(InFileStream);


    StrBuffer[BufferLen] = StrBuffer[BufferLen + 1] = '\0';


    return StrBuffer;
}

//unsigned int ReplaceAllChar()

//make version that can skip spaces

TableOfContent *CreateTOC(char *InStrBuffer, unsigned int *NumOfLines, const char Separator)//use len
{
    assert(Separator > 'z' || Separator < 'A');

    char *StrBuffer = InStrBuffer;

    if (StrBuffer == NULL)
    {
        printf("Warning! String buffer is empty\n");

        return NULL;
    }

    assert(Separator >= 0);
    assert(NumOfLines != NULL);

    TableOfContent *TOC = (TableOfContent *)calloc(1, sizeof(TableOfContent));

    *NumOfLines = 0;

    

    while (StrBuffer)
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


//unfortunately isnt safe
void WriteToFileFollowingTOC(const char* FilePath, TableOfContent* TOC, const unsigned int NumOfLines)
{
    assert(FilePath != NULL);
    assert(TOC != NULL);
    //assert(Separator > 'z' || Separator < 'A');


    FILE *OutFileStream = fopen(FilePath, "w");
    if (OutFileStream==NULL)
    {
        printf("Wrong file path\n");

        exit(1);
    }

    for (int i = 0; i < NumOfLines; i++)
    {
        fwrite(TOC[i].Line, TOC[i].Length, 1, OutFileStream);
    }
}