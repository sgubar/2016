/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Дмитро Сахаров
 *
 * Created on 9 березня 2016, 22:31
 */
#include "check.h"
#include "convert.h"
#include <stdio.h>
#include <math.h>



char* symb_array = "0123456789ABCDEF";

int main(int argc, char** argv) {
    //analyzing arguments
    if(argc!=4)
    {
        printf("Incorrect request\n");
        printf("Input format should be next:\n\t number_convertation.exe [base from][base to][number]\n");
        printf("Example: number_convertation.exe 10 16 512");
              
         return 1;
    }
    
    char* input = argv[3];
    int b_f = atoi(argv[1]);
    int b_t = atoi(argv[2]);
    
       
    if(b_f<2 || b_f>16||b_t<2 || b_t>16){
        printf("Base of system must be in range of 2-16");
        return 1;
    }
    //checking if number we want translate is corresponds
    if(!check(input,b_f)){
        printf("%s is not correct format for the %d system",input,b_f);
        return 1;
    }
    
    
    char* output_string = convert(input,b_f,b_t);
    printf(output_string);
    return (0);
}



