#include "shellSort.h"

void shellSort(int EnterA[], int CurS)
{
	int In = 0;
	int i = 0;
	int H = 1; // start h = 1

				  //1. Calculate start value of h
	while (H <= CurS / 3)
	{
		H = H * 3 + 1; // 1, 4, 13, 40, 121, ....
	}

	//2. Sequental decrease h to 1
	while (H > 0)
	{
		for (i = H; i < CurS; i++)
		{
			int T = EnterA[i];
			In = i;

			// the first sub-array {0, 4, 8}
			while (In > H - 1 && EnterA[In - H] >= T)
			{
				EnterA[In] = EnterA[In - H];
				In -= H;
			}

			EnterA[In] = T;
		}

		H = (H - 1) / 3; //decrease h
	}
}
