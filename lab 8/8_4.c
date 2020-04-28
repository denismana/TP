#include<stdlib.h>
#include<stdio.h>
#include<stdarg.h>

int crescator (int n, char tip,...)
{
    double max,x;
    va_list va;
    va_start(va,tip);
    if(tip=='d'){
        max=va_arg(va,int);
    }
    else{
        max=va_arg(va,double);
    }
    n--;
    while(n)
    {
        if(tip=='d'){
            x=va_arg(va,int);
        }
        else
        {
            x=va_arg(va,double);
        }
        if(max>x){
            return 0;
        }
        n--;
    }
    return 1;
}
    
int main()
{
    if(crescator(3,'d',8,7,9)==1){
        printf("e crescator");
    }
    else{
        printf("nu e crescator");
        
    }
    return 0;
}
