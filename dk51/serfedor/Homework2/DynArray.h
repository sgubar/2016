#ifndef DYNARRAY_H_INCLUDED
#define DYNARRAY_H_INCLUDED

typedef struct _DAInt;
struct __DAInt
{
    int aSize;
    int anIndex;
    int anValue;
}DAInt;
DaInt *createDAInt(int aSize);

int ValueIndex(int anIndex);

void setValueIndex(int anValue,int anIndex);

void freeDAInt(DAInt *anArray)
{
    if(NULL != anArray)
    {
        free (anArray);
    }
}

#endif // DYNARRAY_H_INCLUDED
