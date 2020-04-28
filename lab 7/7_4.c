#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#if defined(DEBUG) || defined(_DEBUG)
    #define DBG(...)        fprintf(stderr,__VA_ARGS__)
#else
    #define DBG(...)
#endif

int test(double *v, int n , double x)
{
    int i;
    double m=0;
    for(i=0;i<n;i++)
    {
        if(m<v[i])
            m=v[i];
    }
    if(m==x)
        return 1;
    return 0;
}

double vmax(double *v,int n)
{
    int i;
    double m=v[0];
    
    for(i=1;i<n;i++){
        if(m<v[i])m=v[i];
        }
    return m;
}


int main()
{
    double *v;
    int i,n;
    printf("n=");
    scanf("%d",&n);
    if((v=(double*)malloc(n*sizeof(double)))==NULL)
    {
        printf("eroare alocare dinamica");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<n;i++)
    {
        printf("v[%d]=",i);
        scanf("%lf",&v[i]);
    }
    assert((test(v,n,(vmax(v,n))))==1);
    printf("maximul este %lf",vmax(v,n));
    free(v);
    return 0;
}
