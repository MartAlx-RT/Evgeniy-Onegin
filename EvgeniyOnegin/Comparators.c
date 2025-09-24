#include "Comparators.h"

//#define _SQ(x) ((x)*(x))

int StrictSort(const void *TOC_1, const void *TOC_2)
{
    assert(TOC_1 != NULL);
    assert(TOC_2 != NULL);

    return strcmp(((TableOfContent *)TOC_1)->Line, ((TableOfContent *)TOC_2)->Line);
}

int ByFirstOnlyLetters(const void *TOC_1, const void *TOC_2)
{
    assert(TOC_1 != NULL);
    assert(TOC_2 != NULL);

    unsigned int Len1 = ((TableOfContent *)TOC_1)->Length;
    unsigned int Len2 = ((TableOfContent *)TOC_2)->Length;

    char *Str1 = ((TableOfContent *)TOC_1)->Line;
    char *Str2 = ((TableOfContent *)TOC_2)->Line;

    assert(Str1 != NULL);
    assert(Str2 != NULL);

    unsigned int i1 = 0, i2 = 0;

    while (i1 <= Len1 && i2 <= Len2)
    {
        while(!(bool)isalpha(Str1[i1]) && i1 < Len1)
            i1++;

        while(!(bool)isalpha(Str2[i2]) && i2 < Len2)
            i2++;

        if(Str1[i1] - ((bool)islower(Str1[i1])) * ('a'-'A') == Str2[i2] - ((bool)islower(Str2[i2])) * ('a'-'A'))
        {
            i1++;
            i2++;
            continue;
        }

        if(Str1[i1] - ((bool)islower(Str1[i1])) * ('a'-'A') < Str2[i2] - ((bool)islower(Str2[i2])) * ('a'-'A'))
            return -1;

        return 1;
    }

    return 0;
}

int ByFirstLetters(const void *TOC_1, const void *TOC_2)
{

    assert(TOC_1 != NULL);
    assert(TOC_2 != NULL);

    unsigned int Len1 = ((TableOfContent *)TOC_1)->Length;
    unsigned int Len2 = ((TableOfContent *)TOC_2)->Length;

    char *Str1 = ((TableOfContent *)TOC_1)->Line;
    char *Str2 = ((TableOfContent *)TOC_2)->Line;

    assert(Str1 != NULL);
    assert(Str2 != NULL);

    unsigned int i1 = 0, i2 = 0;

    while(!(bool)isalpha(Str1[i1]) && i1 < Len1)
        i1++;

    while(!(bool)isalpha(Str2[i2]) && i2 < Len2)
        i2++;
    
    while (i1 <= Len1 && i2 <= Len2)
    {

        if(Str1[i1] - ((bool)islower(Str1[i1])) * ('a'-'A') == Str2[i2] - ((bool)islower(Str2[i2])) * ('a'-'A'))
        {
            i1++;
            i2++;
            continue;
        }

        if(Str1[i1] - ((bool)islower(Str1[i1])) * ('a'-'A') < Str2[i2] - ((bool)islower(Str2[i2])) * ('a'-'A'))
            return -1;

        return 1;
    }

    return 0;
}

int ByLastLetters(const void *TOC_1, const void *TOC_2)
{
    assert(TOC_1 != NULL);
    assert(TOC_2 != NULL);

    char *Str1 = ((TableOfContent *)TOC_1)->Line;
    char *Str2 = ((TableOfContent *)TOC_2)->Line;

    assert(Str1 != NULL);
    assert(Str2 != NULL);

    int i1 = ((TableOfContent *)TOC_1)->Length - 1;
    int i2 = ((TableOfContent *)TOC_2)->Length - 1;

    while(!(bool)isalpha(Str1[i1]) && i1 > 0)
        i1--;

    while(!(bool)isalpha(Str2[i2]) && i2 > 0)
        i2--;
    
    while (i1 >= 0 && i2 >= 0)
    {

        if(Str1[i1] - ((bool)islower(Str1[i1])) * ('a'-'A') == Str2[i2] - ((bool)islower(Str2[i2])) * ('a'-'A'))
        {
            i1--;
            i2--;
            continue;
        }

        if(Str1[i1] - ((bool)islower(Str1[i1])) * ('a'-'A') < Str2[i2] - ((bool)islower(Str2[i2])) * ('a'-'A'))
            return -1;

        return 1;
    }

    if(i1 < 0 && i2 < 0)
        return 0;
    
    if(i1 < 0)
        return -1;

    return 1;
}

int ByLastOnlyLetters(const void *TOC_1, const void *TOC_2)
{
    assert(TOC_1 != NULL);
    assert(TOC_2 != NULL);

    char *Str1 = ((TableOfContent *)TOC_1)->Line;
    char *Str2 = ((TableOfContent *)TOC_2)->Line;

    assert(Str1 != NULL);
    assert(Str2 != NULL);

    int i1 = ((TableOfContent *)TOC_1)->Length - 1;
    int i2 = ((TableOfContent *)TOC_2)->Length - 1;

    while(!(bool)isalpha(Str1[i1]) && i1 > 0)
        i1--;

    while(!(bool)isalpha(Str2[i2]) && i2 > 0)
        i2--;
    
    while (i1 >= 0 && i2 >= 0)
    {
        while(!(bool)isalpha(Str1[i1]) && i1 > 0)
            i1--;

        while(!(bool)isalpha(Str2[i2]) && i2 > 0)
            i2--;

        if(Str1[i1] - ((bool)islower(Str1[i1])) * ('a'-'A') == Str2[i2] - ((bool)islower(Str2[i2])) * ('a'-'A'))
        {
            i1--;
            i2--;
            continue;
        }

        if(Str1[i1] - ((bool)islower(Str1[i1])) * ('a'-'A') < Str2[i2] - ((bool)islower(Str2[i2])) * ('a'-'A'))
            return -1;

        return 1;
    }

    if(i1 < 0 && i2 < 0)
        return 0;
    
    if(i1 < 0)
        return -1;

    return 1;
}

