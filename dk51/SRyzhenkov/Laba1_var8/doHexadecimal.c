//
// Laba. 1 var. 8
//
//  Created by Ryzhenkov Serhii on 08/03/16.
//  Copyright © 2016 Ryzhenkov Serhii. All rights reserved.

int doHexadecimal();
int doHexadecimal()
{
    int result, iter = 0;
    int output[100];
    int i;
    char hex[16] = "0123456789ABCDEF";

    printf("Enter the number: ");
    scanf("%d", &result);

    while(result>=16){
        output[iter] = result%16;
        result /= 16;
        iter++;
    }
    output[iter] = result;

    for(i = iter; i>=0; i--){
        printf("%c", hex[output[i]]);
    }
}
