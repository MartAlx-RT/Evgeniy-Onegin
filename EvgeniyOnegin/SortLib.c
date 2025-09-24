#include "SortLib.h"


static inline void* Offset(void* Arr, int Index, size_t SizeOfElement)
{
    assert(Arr != NULL);

    return (void *)((size_t)Arr + Index * SizeOfElement);
}

static inline void Swap(void *a, void *b, size_t Size)
{
    assert(a != NULL);
    assert(b != NULL);

    char *c = (char *)calloc(Size, sizeof(char));

    assert(c != NULL);

    
    memcpy(c, (char*)a, Size);
    memcpy((char*)a, (char*)b, Size);
    memcpy((char*)b, c, Size);

    free(c);

    c = NULL;
}

void _QuickSort(void *Arr, int LeftInd, int RightInd, size_t SizeOfElement, int (*Comp) (const void *, const void *))
{
    assert(Arr != NULL);
    assert(Comp != NULL);

    if (LeftInd >= RightInd)
        return;

    char *Pivot = (char *)calloc(SizeOfElement, sizeof(char));
    assert(Pivot != NULL);

    memcpy(Pivot, (char *)Offset(Arr, (LeftInd + RightInd) / 2, SizeOfElement), SizeOfElement);

    //void *Pivot = Offset(Arr, (LeftInd + RightInd) / 2, SizeOfElement);

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

    free(Pivot);

    Pivot = NULL;

    _QuickSort(Arr, StartInd, RightInd, SizeOfElement, Comp);
    _QuickSort(Arr, LeftInd, EndInd, SizeOfElement, Comp);
}

void QuickSort(void *Arr, int NumOfElements, size_t SizeOfElement, int (*Comp) (const void *, const void *))
{
    assert(Arr != NULL);
    assert(Comp != NULL);

    
    _QuickSort(Arr, 0, NumOfElements - 1, SizeOfElement, Comp);
}


