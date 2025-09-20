#include "StringsSort.h"

static inline void* Offset(void* Arr, int Index, size_t SizeOfElement)
{
    return (void *)((size_t)Arr + Index * SizeOfElement);
}

static inline void Swap(void *a, void *b, size_t Size)
{
    char *c = (char *)calloc(Size, sizeof(char));

    a = (char *)a;
    b = (char *)b;

    memcpy(c, a, Size);
    memcpy(a, b, Size);
    memcpy(b, c, Size);

    free(c);

    c = NULL;
}

void _QuickSort(void *Arr, int LeftInd, int RightInd, size_t SizeOfElement, int (*Comp) (void *, void *))
{
    assert(Arr != NULL);

    if (LeftInd >= RightInd)
        return;

    void *Pivot = Offset(Arr, (LeftInd + RightInd) / 2, SizeOfElement);

    int StartInd = LeftInd, EndInd = RightInd;

    while (LeftInd <= RightInd)
    {
        while (Comp(Pivot, Offset(Arr, LeftInd, SizeOfElement)) > 0)
            LeftInd++;
        
        while (Comp(Pivot, Offset(Arr, RightInd, SizeOfElement)) < 0)
            RightInd--;
        
        if (LeftInd <= RightInd)
            Swap(Offset(Arr, LeftInd++, SizeOfElement),
                Offset(Arr, RightInd--, SizeOfElement),
                SizeOfElement);
    }

    _QuickSort(Arr, StartInd, RightInd, SizeOfElement, Comp);
    _QuickSort(Arr, LeftInd, EndInd, SizeOfElement, Comp);
}

void QuickSort(void *Arr, int NumOfElements, size_t SizeOfElement, int (*Comp) (void *, void *))
{
    _QuickSort(Arr, 0, NumOfElements - 1, SizeOfElement, Comp);
}


