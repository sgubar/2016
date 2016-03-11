/*
 *returns true, if input is correspond to base
 */
char check(char * input, int base_from){
    int i;
    char* symb_array = "0123456789ABCDEF";
    //going throught the input array
    for(i=0; i<strlen(input); i++){
        //input is not allowing to have :;<=>?@ symbols
        if(input[i]>'9' && input[i]<'A')
            return 0;
            
        //checks if element is in the correct range according to base_from
        if(input[i]<'0' || input[i]>symb_array[base_from-1])
            //value of input is not in correct range
            return 0;
    }
    //all right check is done
    return 1;
}