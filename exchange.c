#include<stdio.h>
 
int main()
{
    int a = 5;
    int b = 6;
    int temp;
    temp = a ;
    a = b ;
    b = temp ;
    printf("a = %d\nb = %d\n",a,b);
    return 0 ;
}