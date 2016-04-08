/* 
 * File:   newmain.c
 * Author: Dmitry Sakharov
 *
 * Created on 15 березня 2016, 0:40
 * Compiled with gcc(cygwin)
 */

int power(int base,int pow)

{
	int d,rez=1;
        for(d=0;d<pow;d++)
		rez=rez*base;
        return rez;
}
