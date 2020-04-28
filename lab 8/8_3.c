#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<math.h>


void absN(int n,...)
{
    double *p;
    va_list va;
    va_start(va,n);
    while(n)
    {
        p=va_arg(va,double*);
        *p=fabs(*p);
        n--;
    }
    va_end(va);
}

int main()
{
    double x=-2, y=3;
    absN(2,&x,&y);
    printf("%f %f",x,y);          ////////de ce nu face modulul cand declar variabilele float?
    
    /////////// daca le declar double programul functioneaza 
    return 0;
}
