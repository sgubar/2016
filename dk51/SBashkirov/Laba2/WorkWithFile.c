//
//  WorkWithFile.c
//  Laba 2
//
//  Created by Stanislav Bashkirov on 3/26/16.
//  Copyright © 2016 Stanislav Bashkirov. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WorkWithFile.h"
#include "SingleList.h"


ReadTheFile(char *FileName, IntList *aList)
{
	FILE *ReadingFile;
	ReadingFile = fopen(FileName,"r");
	char RString[200], *Number,*last;
	while (NULL != fgets(RString, 200, ReadingFile))
	{
		Number = strtok_s(RString, " ", &last);
		NodeAdd(aList, atof(Number));
		while(NULL!=Number)
		{
			Number = strtok_s(NULL, " ", &last);
			if (NULL != Number)
				NodeAdd(aList, atof(Number));
		}
	}
	fclose(ReadingFile);
	return aList;
}