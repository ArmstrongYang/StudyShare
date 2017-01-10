/****************************
输出用户的名字
*****************************/
#include <stdio.h>
#include <malloc.h>


extern void output_name ( char *p ) ;

void main(void )
{
    char  *name;
    name = malloc(11);
    if (name !=NULL) output_name(name);
    free(name);
    printf("name=%s",name);  
    
}

void output_name ( char *p )  
{   
    char *temp;  
 
    int i, j, k;
    char name[11] = "Joe Jakeson";  

    temp = p;
    k = 0;
	j = 0;
    
    for( i = 0; i < 12; i++)
    {  
         if(name[i]!='\0')
         {
            temp[k] = name[i];
            k++;
         }
         else if(name[i]='\0')
         {
            temp[k] = '\0';
         }
         else
         {
             break;  
         }
    }
 
}  

