#include <stdio.h>
int main(void)
{
    int x =12 ;
    

    float y;
    y = 3.14;
    char* s;
    s= "hello world!";

    printf("x = %d, y is %7.6f \n" ,  x , y );
    printf("%s \n", s );

    for (int i = 0; i < 5; i++) {
        printf("%d x 5 = %d \n", i , i*5 );
    }

    return 0;
}


