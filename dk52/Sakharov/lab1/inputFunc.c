/* 
 * File:   newmain.c
 * Author: Dmitry Sakharov
 *
 * Created on 15 березня 2016, 0:40
 * Compiled with gcc(cygwin)
 */

#include "Conv_HexAndOct.h"
#include "Conv_DecAndBin.h"

int inputFunc(char* innum, int bs_fr, int bs_to)
{
    int i,decimal;
    int number[10];
    //converting char array to int
    for(i=0;i<strlen(innum);i++)
    {
        
        if(innum[i]>='0'&& innum[i]<='9')
        {
            number[i]=innum[i]-'0';
        }
        else if(innum[i]>='A'&& innum[i]<='F')
        {
            number[i]=innum[i]-'A'+10;
        }
        else if(number[i]>=bs_fr||number[i]<0)//check if number and its basement corresponds
        {
            printf("Input number basement should correspond base_from!");
            printf("\nConverting types available:\n10 2\n"
            "2  10\n"
            "16 8\n"
            "8  16\n"
            "8  10\n"
            "16 10\n");
            return 1;
            break;
        }
        else
        {
            printf("number format error");//case when we have entered wrong number
            return 1;
            break;
        }
    }
 // cases routine          
if(bs_fr == 10 && bs_to ==2)
{
    Conv_DecToBin(number,strlen(innum));
}
else if(bs_fr == 2 && bs_to==10)
{
    Conv_BinToDec(number,strlen(innum));
}
else if (bs_fr== 8 && bs_to == 16)
{
    decimal=Conv_OctToDec(number,strlen(innum));
    Conv_DecToHex(decimal);
}
else if (bs_fr == 16 && bs_to == 8)
{
    decimal=Conv_HexToDec(number,strlen(innum));
    Conv_DecToOct(decimal);    
}
else if (bs_fr == 16 && bs_to == 10)
{
    printf("%d",Conv_HexToDec(number,strlen(innum)));    
}    
else if (bs_fr == 8 && bs_to == 10)
{
    printf("%d",Conv_OctToDec(number,strlen(innum)));
}
else//case when converting directions are wrong 
{
    printf("Input parameters are wrong\nExample convert_9var.exe 255 10 2");
    printf("\nConverting types available:\n10 2\n"
        "2  10\n"
        "16 8\n"
        "8  16\n"
        "8  10\n"
        "16 10\n");
}
}

