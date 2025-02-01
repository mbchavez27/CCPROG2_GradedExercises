#include <stdio.h>

void del1(int key, int A[], int *pElem)
{
    int i = 0;
    int isFound = 0;

    for (i = 0; i < *pElem; i++)
    {
        if (A[i] == key && !isFound)
        {
            A[i] = A[*pElem - 1];
            *pElem -= 1;
            isFound = 1;
        }
    }
}

void del2(int key, int A[], int *pElem)
{
    int i = 0;
    int isFound = 0;
    int indexDeleted;

    for (i = 0; i < *pElem; i++)
    {
        if (A[i] == key && !isFound)
        {
            A[i] = 0;
            indexDeleted = i;
            *pElem -= 1;
            isFound = 1;
            for (i = indexDeleted; i < *pElem; i++)
            {
                A[i] = A[i + 1];
            }
        }
    }
}

void del3(int key, int *A, int *pElem)
{
    int i = 0;
    int isFound = 0;
    int indexDeleted;

    for (i = 0; i < *pElem; i++)
    {
        if (A[i] == key && !isFound)
        {
            *(A + i) = 0;
            indexDeleted = i;
            *pElem -= 1;
            isFound = 1;
            for (i = indexDeleted; i < *pElem; i++)
            {
                *(A + i) = *(A + (i + 1));
            }
        }
    }
}

void del4(int key, int A[], int *pElem)
{
    int i = 0;
    int indexDeleted;

    for (i = 0; i < *pElem; i++)
    {
        if (A[i] == key)
        {
            A[i] = 0;
            indexDeleted = i;
            int copyofIndexDeleted = indexDeleted;
            *pElem -= 1;
            for (i = indexDeleted; i < *pElem; i++)
            {
                A[i] = A[i + 1];
            }
            i = copyofIndexDeleted;
        }
    }
}
