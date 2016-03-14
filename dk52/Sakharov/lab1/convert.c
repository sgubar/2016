/*
 *Converts bas_from format to base_to format 
 */
char* convert(char* arg,int base_from,int base_to) {
    int i;
    long number = 0;
    char* symb_array = "0123456789ABCDEF";
    //converting number from char sequence to long
    for(i = 0; i < strlen(arg); i++){
        //in case of digit lying in range 0..9
        if(arg[i]>='0' && arg[i]<='9')
            number = number * base_from + arg[i] - '0';
        else if(arg[i]>='A' && arg[i]<='F')
            number = number * base_from + arg[i] - 'A' + 10;
    }
    
    //calculating the size of the string(also index of lower digits)
    //formula equals to lOG_base_to of number + 1(value itself)
    //+1 null string terminator
    int current_index = (int) (log(number)/log(base_to)) + 2;
    
    char* output_string = (char*)malloc(current_index*sizeof(char));
    output_string[--current_index] = '\0';
    //converting from int to output format
    while(number>0){    
        int digit = number % base_to;
        output_string[--current_index] = symb_array[digit];
        number =number /base_to;
    } 
    return output_string;
}