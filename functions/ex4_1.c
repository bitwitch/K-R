#include <stdio.h>
#define MAXLINE 1000

int strrindex(char s[], char t[]);

int main() 
{
    char str1[] = "Tabithabitha";
    char str2[] = "bit";

    int index = strrindex(str1, str2);

    if (index == -1) 
        printf("The word %s does not appear in the word %s.\n", str2, str1); 
    else
        printf("The word %s appears in the word %s at rightmost index %i.\n", str2, str1, index);

    return 0; 
}

int strrindex(char s[], char t[])
{
    int c1 = 0;
    int c2 = 0;
    int index = -1;
    int i = 0; 

    for (i=0; s[i] != '\0'; i++)
    {
        if (s[i] == t[0])
        {
            for (c1=i, c2=0; s[c1] == t[c2]; c1++, c2++)
                ;
            if (t[c2] == '\0')
                index = i;
        }
    }

    return index; 
}