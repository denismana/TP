#include<stdio.h>
#include<stdlib.h>

#define MAX2(a,b)  ((a)>(b)?(a):(b))

#define MAX3(a,b,c) ((MAX2((a),(b)))>(c)?(MAX2((a),(b))):(c))

int main(int argc, char *argv[])

{

    int a,b,c;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    printf("%d",MAX3(a,b,c));
    return 0;
}
