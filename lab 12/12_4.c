/**Aplicația 12.4: La un campionat iau parte n jucători, fiecare definit prin nume (max 15 caractere) și valoare (int). Jucătorii sunt distribuiți în m grupe, n divizibil cu m. Distribuția jucătorilor în grupe se face după valoarea lor, astfel încât cei mai valoroși m jucători să fie fiecare în altă grupă, apoi următorii m cei mai valoroși rămași să fie și ei în grupe diferite și tot așa, până când toți jucătorii sunt distribuiți. Să se afișeze împărțirea jucătorilor pe grupe, pentru valori citite dintr-un fișier.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    char nume[16];
    int valoare;
}jucator;

void sortare(jucator v[],int n)
{
    int i,j,aux;
    char auxc[20];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(v[i].valoare<v[j].valoare){
                strcpy(auxc,v[i].nume);
                strcpy(v[i].nume,v[j].nume);
                strcpy(v[j].nume,auxc);
                aux=v[i].valoare;
                v[i].valoare=v[j].valoare;
                v[j].valoare=aux;
            }
        }
    }
}
void echipe(jucator v[],int n,int m)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        printf("echipa %d:",i);
        for(j=i;j<n;j+=m)
        {
            printf("%s %d; ",v[j].nume,v[j].valoare);
        }
        printf("\n");
    }
}
void citire(jucator v[],int n)
{
    int i;
    for(i=0;i<n;i++){
        scanf("%s",v[i].nume);
        scanf("%d",&v[i].valoare);
    }
}
int main()
{
    int n,m;
    jucator v[20];
    printf("introduceti numarul de jucatori");
    scanf("%d",&n);
    printf("introduceti numarul de echipe");
    scanf("%d",&m);
    citire(v,n);
    sortare(v,n);
    echipe(v,n,m);

    return 0;
}
