#include<stdio.h>
#include<stdlib.h>

#define CITIRE(A,TIP,X,MIN,MAX)                 ///de ce imi cere inainte de define o paranteza sau ceva?
    {
        printf(A);
        scanf("%#TIP",&X);
        while(X<MIN && X>MAX)
        {
            printf(A);
            scanf("%#TIP",&X);
        }
    }
int main(int argc, char *argv[])
{
    int x;
    CITIRE("x=",d,x,0,100);
    return 0;
}
