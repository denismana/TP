#include<stdlib.h>
#include<stdio.h>
#define MAX 20
int V,v[MAX],w[MAX],Volum,sol,n;
void citire()
{
    int i;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&w[i]);
    }
    scanf("%d",&V);
}
void afisare(int k)
{
    int i;
    sol++;
    printf("Solutia:%d\n",sol);
    for(i=1;i<=k;i++)
    {
        if(v[i])
            printf("%d ",w[v[i]]);
    }
    printf("\n");
}
void BK(int k)
{
    int i;
    for(i=1;i<=n;i++)
    {
        v[k]=i;
        if(valid(k)==1)
        {
            if(solutie()==1)
                afisare(k);
            else
                BK(k+1);

        }
    }
}
int valid(int k)
{
    int i;
    Volum=0;
    for(i=1;i<=k;i++)
        Volum+=w[v[i]];
    if((Volum<=V)&&(k<=n))
        return 1;
    return 0;
}
int solutie()
{
    if(Volum==V)
        return 1;
    return 0;
}

int main()
{
    citire();
    BK(1);
    return 0;
}
