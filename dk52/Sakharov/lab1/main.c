/* 
 * File:   main.c
 * Author: Dmitry Sakharov
 *
 * Created on 20 березня 2016, 1:40
 * Compiled with gcc(cygwin)
 */

#include <stdio.h>
#include <stdlib.h>
#include"inputFunc.h"
/*
 * 
 */
int main(int argc, char** argv) {
  char* innum = argv[1];
  char* base_from = argv[2];
  char* base_to = argv[3];
  
  int bs_fr=atoi(base_from);
  int bs_to=atoi(base_to);
  
  inputFunc(innum,bs_fr,bs_to);

    return 0;   
}

