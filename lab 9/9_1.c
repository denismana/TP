/**Aplicația 9.1: Să se scrie o funcție care primește două liste și returnează 1 dacă ele sunt identice, altfel 0.

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
    int n;
    struct elem *urm;
    }elem;

elem *nou(int n,elem *urm)
{
    elem *e=(elem*)malloc(sizeof(elem));
    if(!e){
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
        }
    e->n=n;
    e->urm=urm;
    return e;
}

typedef struct{
    elem *prim;
    elem *ultim;
    }Lista;

void init(Lista *lista)
{
    lista->prim=NULL;
    lista->ultim=NULL;
}

void adaugaInceput(Lista *lista,int n)
{
    elem *prim=lista->prim;
    lista->prim=nou(n,prim);
    if(!prim){
        lista->ultim=lista->prim;
        }
}

void adaugaSfarsit(Lista *lista,int n)
{
    elem *e=nou(n,NULL);
    if(lista->ultim){
        lista->ultim->urm=e;
        }else{
        lista->prim=e;
        }
    lista->ultim=e;
}

void afisare(Lista *lista)
{
    elem *crt;
    for(crt=lista->prim;crt;crt=crt->urm){
        printf("%d ",crt->n);
        }
    putchar('\n');
}

void eliberare(Lista *lista)
{
    elem *p,*crt=lista->prim;
    while(crt){
        p=crt->urm;
        free(crt);
        crt=p;
        }
}
void citire(Lista *lista,int n)
{
    int i,x;
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        adaugaSfarsit(lista,x);
    }
}
int solve(Lista *lista1,Lista *lista2)
{
    elem *q1,*q2;
    q2=lista2->prim;
    for(q1=lista1->prim;q1;q1=q1->urm)
    {
        if((q1->n)!=(q2->n))
            return 0;
        q2=q2->urm;

    }
    return 1;
}
int main()
{
    Lista lista1,lista2;
    int n1,n2;
    init(&lista1);
    init(&lista2);
    printf("Introduceti nr de elemente pentru lista 1:");
    scanf("%d",&n1);
    printf("Introduceti nr de elemente pentru lista 2:");
    scanf("%d",&n2);
    if(n1!=n2){
        printf("listele nu pot fi identice deoarece au numar diferit de elemete");
        return 0;
    }
    printf("Introduceti elementele primei liste\n");
    citire(&lista1,n1);
    printf("Introduceti elementele celei de-a doua liste\n");
    citire(&lista2,n2);
    afisare(&lista1);
    afisare(&lista2);
    if(solve(&lista1,&lista2)==0)
    {
        printf("listele NU sunt identice");
    }
    else{
        printf("listele sunt identice");
    }
    eliberare(&lista1);
    eliberare(&lista2);
    return 0;
}



