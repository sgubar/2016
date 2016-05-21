#ifndef convertation_H
#define convertation_H

long int convertationDecimalToInt(char *string);
long int convertationBinaryToInt(char *string);
long int convertationOctalToInt(char *string);
long int convertationHexadecimalToInt(char *string);
void convertationIntToBinary(long int number, char *string);
void convertationIntToDecimal(long int number, char *string);
void convertationIntToOctal(long int number, char *string);
void convertationIntToHexadecimal(long int number, char *string);

#endif
