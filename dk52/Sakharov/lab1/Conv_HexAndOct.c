/* 
 * File:   newmain.c
 * Author: Dmitry Sakharov
 *
 * Created on 15 березня 2016, 0:40
 * Compiled with gcc(cygwin)
 */

int Conv_HexToDec(int number[],int size)//works
{
    int i=size-1,k=0;
    long dec=0;   
        //hex to decimal cycle 
        for(i;i>=0;--i)
	{
            dec=dec+number[i]*power(16,k);
            k++;//pow incrementation
	}
    
   return dec;
}

void Conv_DecToOct(int decimal)//works
{
    
 int bin[15]; 
 int k=0;
 //converting decimal to binary
	while(decimal>0)
	{
		k++;
		if(decimal%2==0)
			bin[k]=0;
		else
			bin[k]=1;
		decimal =decimal/2;		
	}
	
 //here the part that converts binary to octal (made because of return pointers problem)
int i=0,s,oct[15],triad=0;
//converting to oct using triads
for(i=0;i<sizeof(oct)/sizeof(int);i++)
oct[i]=0;    
i=0;
for(s=1;s<=k;++s)
    {        
      if(triad==3)
        {
            i++;
            triad=0;
        }
        oct[i]+=bin[s]*power(2,triad);
        triad++;
    }

for(i;i>=0;i--)
    printf("%d",oct[i]);
}

int Conv_OctToDec(int number[],int size)//works
{
    int i=size-1,k=0;
    long dec=0;    
        for(i;i>=0;--i)
	{
            dec+=number[i]*power(8,k);//
            k++;//pow incrementation
	}
    
   return dec;
}

void Conv_DecToHex(int decimal)//works
{    
 int bin[15];
char Nums[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
 int k=0;
 //converting decimal to binary
	while(decimal>0)
	{
            k++;
            if(decimal%2==0)
                    bin[k]=0;
            else
                    bin[k]=1;
            decimal =decimal/2;		
	}
	//here the part that converts binary to hex (made because of pointers return problem)

 int i=0,s,hex[15],tetrad=0;
//zeroing our output array
for(i=0;i<sizeof(hex)/sizeof(int);i++)
    hex[i]=0;    
i=0;
//using tetrades way of converting
for(s=1;s<=k;++s)
    {        
      if(tetrad==4)
        {
            i++;
            tetrad=0;
        }
        hex[i]+=bin[s]*power(2,tetrad);
        tetrad++;        
    }
for(i;i>=0;i--)
    printf("%c",Nums[hex[i]]);//printing in hexadecimal form
}