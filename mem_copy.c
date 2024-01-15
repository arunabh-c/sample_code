#include <stdio.h>

void* mem_copy(void* to, const void* from, size_t numbytes)
{
    const char* src = from;
    char* dest = to;
    if((dest!= NULL) && (src!= NULL))
    {  while (numbytes--)
       {
        *dest++ = *src++;
       }
    }
    return to;
}

int main()
{
    char src[20] = "How Are you ?"; //Source String
    char dst[20] = {0}; //dst buffer
    printf("before copy dst = %s\n", dst);
    mem_copy(dst,src,sizeof(src));
    printf("after copy dst = %s\n", dst);

    return 0;
}
