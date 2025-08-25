#include <stdio.h>
#include <stdlib.h>

void* aligned_malloc(size_t size, size_t allignment)
{
    size_t offset = allignment - 1 + sizeof(void*);
    void* p1 = malloc(size + offset);
    /*if ((p1 = (void*)malloc(required_bytes + offset)) == NULL)
    {
       return NULL;
    }*/
    //X - X mod A = INT(X / A) * A = X & ~(A - 1)//doing the remainder function instead of boolean op
    // boolean op only applies to alignment that are powers of 2
    void** p2 = (void**)(((size_t)p1 + offset) - ((size_t)p1 + offset)%allignment);//need double pointer for line 17: p2[-1] = p1; 
    //makes sure starting address is multiple of allignment to understand better, remember size will 
    //be much greater than allignment
    p2[-1] = p1;//store original malloc start address to be fed to aligned_free
    
    return p2;
}

void aligned_free(void *ptr)
{
    free(((void **)ptr)[-1]);
}

int main()
{
    int* x = aligned_malloc(100,16);
    printf("x adress is %p\n",x);
    aligned_free(x);
    x = NULL;
    printf("x adress is %p\n",x);
    return 0;
}
//Ref: https://stackoverflow.com/questions/38088732/explanation-to-aligned-malloc-implementation
