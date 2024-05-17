#include <stdlib.h>
#include <stdio.h>

void mystcpy(char* dest, char* src)
{
    while(*src != '\0')
        *dest++ = *src++;//even though dest & src pointer incrementing they return to
        //start pos outside function due to return by value. char array values retained
        //as still pointing to same mem location. Check Ref
}

int main()
{
    char* a = "Hello World";
    char* b = (char*)malloc(100);
    
    mystcpy(b,a);
    
    char* x = b;
    
    while (*x != '\0')
        printf("%c",*(x++));
    free(b);
    return 0;
}

//Ref: https://stackoverflow.com/questions/22748603/why-is-moving-pointer-forward-not-affecting-outside-function
