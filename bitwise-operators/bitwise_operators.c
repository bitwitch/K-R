#include <stdio.h>

/* print a variable's binary representation, assumes little endian */
void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

/* getbits: get n bits from position p */ 
unsigned getbits(unsigned x, int p, int n) 
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

/* setbits: sets n bits at position p to the rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, int y)
{   
    x &= ~(~(~0 << n) << (p+1-n));
    x |= getbits(y, n-1, n) << (p+1-n); 
    return x;
}

/* invert: returns x with the n bits that begin at position p inverted */
unsigned invert(unsigned x, int p, int n) 
{   
    unsigned bits   = getbits(x,p,n);
    unsigned result = setbits(x,p,n,~bits); 
    return result; 
}

/* rightrot: returns the value of x rotated to the right by n bit positions  */
unsigned rightrot(x,n) 
{
    return x >> n; 
}

void exercise2_6()
{   
    puts("\n\nExercise 2-6:\n");

    int number  = 55; 
    int number2 = 999; 
    int p       = 5; 
    int length  = 3; 
    unsigned number1bits = getbits(number, p, length);
    unsigned number2bits = getbits(number2, length-1, length); 
    unsigned sbresult    = setbits(number, p, length, number2); 

    printf("The number %i in binary is:\n", number); 
    printBits(sizeof(number), &number);

    printf("\nThe %i bits in position %i of %i are:\n", length, p, number);
    printBits(sizeof(number1bits), &number1bits);

    printf("\nThe number %i in binary is:\n", number2); 
    printBits(sizeof(number2), &number2);
    
    printf("\nThe rightmost %i bits of  %i are:\n", length, number2);
    printBits(sizeof(number2bits), &number2bits);

    printf("\nCalling setbits result is:\n");
    printBits(sizeof(sbresult), &sbresult);
}

void exercise2_7()
{
     puts("\n\nExercise 2-7:\n");

    int number  = 3874; 
    int p       = 5; 
    int length  = 3;
    unsigned number1bits = getbits(number, p, length);
    unsigned result = invert(number, p, length); 

    printf("The number %i in binary is:\n", number); 
    printBits(sizeof(number), &number);

    printf("\nThe %i bits in position %i of %i are:\n", length, p, number);
    printBits(sizeof(number1bits), &number1bits);

    printf("\nThe result of inverting these bits is:\n");
    printBits(sizeof(result), &result);
}

void exercise2_8()
{
     puts("\n\nExercise 2-8:\n");

    int number   = 3874; 
    int rotation = 3;
    unsigned result = rightrot(number, rotation); 

    printf("The number %i in binary is:\n", number); 
    printBits(sizeof(number), &number);

    printf("\n%i rotated to the right by %i bit positions is:\n", number, rotation);
    printBits(sizeof(result), &result);    
}

int main() {
    exercise2_6(); 
    exercise2_7(); 
    exercise2_8(); 
    puts("\n\n\n");
    return 0; 
}

/*
    10010010110010
 &  00000000111111 
 =  00000000110010

    10010010110010
 |  00000000111111 
 =  10010010111111

    10010010110010
 ^  00000000111111 
 =  10010010001101

*/
