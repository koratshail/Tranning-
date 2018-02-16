//#define _OPEN_THREADS                                                           
#include <stdio.h>                                                              
#include <pthread.h>                                                            
                                                                                
int main()                                                                      
{                                                                               
   pthread_attr_t attr;                                                         
   size_t size;                                                                 
                                                                                
   if (pthread_attr_init(&attr) == -1) {                                        
      perror("error in pthread_attr_init");                                     
      exit(1);                                                                  
   }                                                                            
                                                                                
   if (pthread_attr_getstacksize(&attr, &size) == -1) {                         
     perror("error in pthread_attr_getstackstate()");                           
     exit(2);                                                                   
   }                                                                            
   printf("The stack size is %d.\n", (int) size);                               
                                                                                
   if (pthread_attr_destroy(&attr) == -1) {                                     
      perror("error in pthread_attr_destroy");                                  
      exit(2);                                                                  
   }                                                                            
   exit(0);                                                                     
} 
