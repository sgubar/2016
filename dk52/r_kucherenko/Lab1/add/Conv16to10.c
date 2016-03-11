//
//  Conv16to10.c
//  add_to_lab1
//
//  Created by Ruslan Kucherenko on 10/03/16.
//  Copyright (C) 2016 Ruslan Kucherenko. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	int val;
	char hex_val[20];

	printf("Enter the number:\n");
	
	gets(hex_val);	
	val = hex_to_dec(hex_val);
	printf("%d\n",val);
	return 0;
}

int hex_to_dec(char* hex){
	int sum = 0;
	int i;
	for(i =0;i<strlen(hex);i++){
		if(hex[i]<='9' && hex[i]>='0')
			sum = sum*16+hex[i]-'0';
		else if(hex[i]>='A' && hex[i]<='F')
			sum = sum*16+hex[i]-'A'+10;
	}
	return sum;
}
