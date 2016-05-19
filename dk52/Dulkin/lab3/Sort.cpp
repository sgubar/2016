#include "Sort.h"

void bubble(int EnterA[], int CurS)
{
	for (int i = CurS - 1; i > 1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (EnterA[j] > EnterA[j + 1])
			{
				int T = EnterA[j];
				EnterA[j] = EnterA[j + 1];
				EnterA[j + 1] = T;
			}
		}
	}
}

void Tsort(int EnterA[], int CurS)
{
	for (int i = 0; i < CurS - 1; i++)
	{
		int Min = i;

		for (int j = i + 1; j < CurS; j++)
		{
			if (EnterA[j] < EnterA[Min])
			{
				Min = j;
			}
		}

		int T = EnterA[i];
		EnterA[i] = EnterA[Min];
		EnterA[Min] = T;
	}
}

void Psort(int EnterA[], int CurS)
{
	for (int i = 1; i < CurS; i++)
	{
		int T = EnterA[i];
		int j = i;

		while (j > 0 && EnterA[j - 1] >= T)
		{
			EnterA[j] = EnterA[j - 1];
			--j;
		}

		EnterA[j] = T;
	}
}
