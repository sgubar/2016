/* 
 * File:   newmain.c
 * Author: Dmitry Sakharov
 *
 * Created on 15 березня 2016, 0:40
 * Compiled with gcc(cygwin)
 */
#include"PowerFunc.h"
#include"stdio.h"
void Conv_DecToBin(int number[],int size)//works
{
    
 int bin[15]; 
 int k=0,i=size-1,decimal=0;
 //cycle that converts input int array of numbers into decimal number 
 for(i;i>=0;--i)
 {
    decimal+=number[i]*power(10,k);
    ++k;        
 }            
 k=0;
 //division with ostacha(?) check
 while(decimal>0)
    {
        k++;
        if(decimal%2==0)
            bin[k]=0;
        else
            bin[k]=1;
        decimal =decimal/2;
		
    }
 //printing binary array from and to beginning
for(k;k>0;--k)
    {
        printf("%d",bin[k]);		
    }
}

void Conv_BinToDec(int number[],int size)
{    
    int i,decimal=0,k=0;
    for(i=size-1;i>=0;i--)
    {        
        decimal+=number[i]*power(2,k);//just convering with pow incrementation
        k++;
    }    
    printf("%d",decimal);		
        
}