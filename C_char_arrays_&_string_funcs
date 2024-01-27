#include <string.h>
#include <iostream>
using namespace std;

void strtok(char ip[], char delim, char (*op)[1024])
{
    size_t i = 0, pos = 0, len = 1, ctr = 0;
    while (ip[i++])
    {
       ++len;
       if (ip[i] == delim)
       {
           strncpy(op[ctr],ip+pos,len-1);
           pos = i+1,len = 0,++ctr;
       }
    }
    strncpy(op[ctr],ip+pos,++len);
}

int main() {
    char input[] = "Hello World I am back";//allocates 12 CONSECUTIVE bytes of memory for 11 chars + '/0'
    //input = "Yello World";//this will fail. its a constant pointer. string assignment not possible
    size_t i = 0;
    input[i] = 'X';//gets/strcopy/scanf also work
    /*cout<<input+1<<endl;//ello World
    cout<<*input<<endl;//X
    cout<<*(input+1)<<endl;//e

    while (input[i])
    {
        cout<<input[i++];
    }*/
    //cout<<endl<<endl;/*Xello World*/
    char output[1024][1024];// = {"1234567890", "Wo"};
    //output[0] = "X";//gets/strcopy/scanf also work
    //cout<<output[0]<<endl;
    //cout<<output[1]<<endl;
    //cout<<output[2]<<endl;
    strtok(input,' ',output);
    
    /*cout<<output+1<<endl;//0x7ffdce9c8e88
    cout<<*output<<endl;//X
    cout<<*(output+1)<<endl;//World
    i = 0;*/
    for (size_t i = 0; i < sizeof(output) / sizeof(output[0]); i++)
    {
       if (strlen(output[i])) cout<<output[i]<<";"<<endl;
    }
    
    char *p = "Hello World";//allocates 12 CONSECUTIVE bytes + 4 EXTRA BYTES for pointer variable p
    p = "Yello Werld";//this works. char pointer can take any address
    //p[0] = 'H'; this will give segmentation fault//gets, scanf, strcopy, strcat also fail
    p = &input[0];

    /*while (*p)
    {
        cout<<p<<" "<<*(p++)<<endl;
    }
    Xello World X
    ello World e
    llo World l
    lo World l
    o World o
     World  
    World W
    orld o
    rld r
    ld l
    d d*/
    return 0;
}
