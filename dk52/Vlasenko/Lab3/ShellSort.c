#include "ShellSort.h"

void ShellSort(int Array[], int N)		// The function of Shell sorting
{
	int theInner = 0;
	int theOuter = 0;
	int theH = 1;
	
	while (theH <= N/3)
	{
		theH = theH*3 + 1;
	}

	while (theH > 0)
	{
		for (theOuter = theH; theOuter < N; theOuter ++)
		{
			int theTmp = Array[theOuter];
			theInner = theOuter;
		
			while (theInner > theH-1 && Array[theInner - theH] >= theTmp)
			{
				Array[theInner] = Array[theInner - theH];
				theInner -= theH;
			}
		
			Array[theInner] = theTmp;
		}
	
		theH = (theH - 1) / 3;
	}
}
