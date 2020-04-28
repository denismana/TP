#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#ifndef IMPLICIT
    #define IMPLICIT 0
#endif

double abs_real(double x)
{
    if(IMPLICIT)
    {
        return fabs(x);
    }
    else
    {
        if(x>=0)
        {
            return x;
        }
        else
        {
            return (-1)*x;
        }
    }
}

int main()
{
    double x;
    printf("Introduceti un numar");
    scanf("%lf",&x);
    printf("%lf",abs_real(x));
    return 0;
}
        
        
