#include <stdio.h>
#include <stdlib.h>

extern int reverseTimeValueA (int num);
int reverseTimeValue (int num);
void printBinary(char stringPtr[]);

int convert(int dec)
{
    if (dec == 0)
    {
        return 0;
    }
    else
    {
        return (dec % 2 + 10 * convert(dec / 2));
    }
}

int main()
{
    // convert a number to binary (unsigned)
    printf("%d\n", convert(9));

    // hex to binary
    printBinary("FFA57B7A7433206");

    // reverses integer digits
    printf("%d\n", reverseTimeValue(12345));

    // reverses integer digits in x86 assembly
    printf("%d\n", reverseTimeValueA(12345));

    return 0;
}

int reverseTimeValue (int num)
{
    int reverseNum = 0;
    while(num > 0)
    {
        reverseNum = reverseNum*10 + num%10;
        num = num/10;
    }
    return reverseNum;
}

void printBinary(char stringPtr[])
{
    char* strPtr = &stringPtr[0];
    while(*strPtr)
    {
        for(int i = 0; i < 2 && *strPtr; i++)
        {
            switch(toupper(*(strPtr++)))
            {
                case '0': printf("0000"); break;
                case '1': printf("0001"); break;
                case '2': printf("0010"); break;
                case '3': printf("0011"); break;
                case '4': printf("0100"); break;
                case '5': printf("0101"); break;
                case '6': printf("0110"); break;
                case '7': printf("0111"); break;
                case '8': printf("1000"); break;
                case '9': printf("1001"); break;
                case 'A': printf("1010"); break;
                case 'B': printf("1011"); break;
                case 'C': printf("1100"); break;
                case 'D': printf("1101"); break;
                case 'E': printf("1110"); break;
                case 'F': printf("1111"); break;
            }
        }
        printf(" ");
    }
    printf("\n");
}
