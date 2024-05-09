/*The POSIX thread libraries are a C/C++ thread API based on standards. It enables the creation of a new concurrent process flow. 
It works well on multi-processor or multi-core systems, where the process flow may be scheduled to execute on another processor, 
increasing speed through parallel or distributed processing. 

PThreads is a highly concrete multithreading system that is the UNIX system’s default standard. PThreads is an abbreviation for 
POSIX threads, and POSIX is an abbreviation for Portable Operating System Interface, which is a type of interface that the 
operating system must implement. PThreads in POSIX outline the threading APIs that the operating system must provide.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
void *print_message_function( void *ptr );
 
int main()
{
     pthread_t GeeksforGeeks1, GeeksforGeeks2;
     char *message1 = "GeeksforGeeks 1";
     char *message2 = "GeeksforGeeks 2";
     //int  geeky1, geeky2;
 
     //geeky1 = pthread_create( &GeeksforGeeks1, NULL, print_message_function, (void*) message1);
     //geeky2 = pthread_create( &GeeksforGeeks2, NULL, print_message_function, (void*) message2);
     pthread_create( &GeeksforGeeks1, NULL, print_message_function, (void*) message1);
     pthread_create( &GeeksforGeeks2, NULL, print_message_function, (void*) message2);
 
     pthread_join( GeeksforGeeks1, NULL);
     pthread_join( GeeksforGeeks2, NULL); 
 
     //printf("GeeksforGeeks 1 returns: %d\n",geeky1);
     //printf("GeeksforGeeks 2 returns: %d\n",geeky2);
     exit(0);
}
 
void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}
