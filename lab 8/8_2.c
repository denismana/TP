#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>

float *allocVec(int n,...)
{
    float *v,x;
    int k=0;
    va_list va;
    if((v=(float*)malloc(n*sizeof(float)))==NULL)
    {

        exit(EXIT_FAILURE);
    }
    va_start(va,n);
    while(n)
    {
        x=va_arg(va,double);
        v[k]=x;
        n--;
        k++;
    }
    va_end(va);
    return v;
}

int main()
{
    float *v;
    int i;
    v=allocVec(3,7.2,(-1),0);   \\\\\\\\de ce imi afiseaza la iesire 7.2 inf 0 ?
    for(i=0;i<3;i++)
        printf("%f ",v[i]);
    return 0;
}

        
