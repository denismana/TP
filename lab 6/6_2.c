#include<stdio.h>
#include<stdlib.h>

#define FN_SORTARE(TIP)
    void sortare__##TIP( TIP p[],int n)
    {
        int i,j,aux;
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                if(p[i]<p[j])
                {
                    aux=p[i];
                    p[i]=p[j];
                    p[j]=aux;
                }
            }
        }
    }

FN_SORTARE(int)

int main(int argc,char *argv[])
{
    int n,v[5];
    printf("Introduceti numarul de elemente");
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    sortare__int(v,n);
    for(i=0;i<n;i++)
    {
        printf("%d ",v[i]);
    }
    return 0;
}
    
                    
            
