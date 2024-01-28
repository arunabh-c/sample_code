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
    //X - X mod A = INT(X / A) * A = X & ~(A - 1)
    void** p2 = (void**)(((size_t)p1 + offset) & ~(allignment-1));//makes sure starting address is multiple of allignment
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
