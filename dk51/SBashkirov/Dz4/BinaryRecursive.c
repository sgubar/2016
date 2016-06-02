
#include <stdio.h>
#include "BinaryRecursive.h"
#include "ordArray.h"

int findCenter(int Left, int Right)
{
	int Result = (Left + Right) / 2;
	return Result;
}

unsigned BinaryFound(ordArrayPtr theArray, int number, int LeftBorder, int RightBorder)
{
	if (theArray == NULL & number == NULL & LeftBorder == NULL & RightBorder == NULL) return NULL;

	if (LeftBorder > RightBorder)
	{
		LeftBorder += RightBorder;
		RightBorder = LeftBorder - RightBorder;
		LeftBorder -= RightBorder;
	}

	int center = findCenter(LeftBorder, RightBorder);
	if (center != LeftBorder)
	{
		if (number == theArray->storage[center]) return center;
		if (number > theArray->storage[center]) LeftBorder = center;
		else RightBorder = center;
		return BinaryFound(theArray, number, LeftBorder, RightBorder);
	}
	else
		if (number != theArray->storage[center])
			if (number != theArray->storage[center + 1])
				return NULL;
			else return center + 1;
		else return center;
}