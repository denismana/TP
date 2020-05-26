/**

Aplicația 10.2: La exemplul 1 să se adauge operația de inserare a unui cuvânt. Pentru aceasta se cere un cuvânt de inserat și un cuvânt succesor. Dacă succesorul există în propoziție, cuvântul de inserat va fi inserat înaintea sa. Dacă succesorul nu există în lista, cuvântul de inserat va fi adăugat la sfârșitul listei.

*/


/**
Să se modifice exemplul 1 astfel încât el să numere de câte ori apare fiecare cuvânt în propoziție. Pentru aceasta, cuvintele vor fi adăugate doar cu litere mici și fiecare cuvânt va avea asociat un contor. Dacă un cuvânt nou nu există în propoziție, el va fi adăugat. Altfel, dacă el există deja, doar se va incrementa contorul cuvântului existent. La afișare, pentru fiecare cuvânt se va afișa și contorul său.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cuvant{
    char text[16];
    struct Cuvant *pred;
    struct Cuvant *urm;
    }Cuvant;

Cuvant *Cuvant_nou(const char *text)
{
    Cuvant *c=(Cuvant*)malloc(sizeof(Cuvant));
    if(!c){
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
        }
    strcpy(c->text,text);
    return c;
}

typedef struct{
    Cuvant *prim;
    Cuvant *ultim;
    }Propozitie;

void Propozitie_init(Propozitie *p)
{
    p->prim=p->ultim=NULL;
}

void Propozitie_adauga(Propozitie *p,Cuvant *c)
{
    c->pred=p->ultim;
    if(p->ultim){
        p->ultim->urm=c;
        }else{
        p->prim=c;
        }
    p->ultim=c;
    c->urm=NULL;
}


Cuvant *Propozitie_cauta(Propozitie *p,const char *text)
{
    Cuvant *c;
    for(c=p->prim;c;c=c->urm){
        if(!strcmp(c->text,text))return c;
        }
    return NULL;
}


void Propozitie_sterge(Propozitie *p,Cuvant *c)
{
    if(c->pred){
        c->pred->urm=c->urm;
    }
    else{
        p->prim=c->urm;
    }
    if(c->urm){
        c->urm->pred=c->pred;
    }
    else{
        p->ultim=c->pred;
    }
    free(c);
}

void Propozitie_elibereaza(Propozitie *p)
{
    Cuvant *c,*urm;
    for(c=p->prim;c;c=urm){
        urm=c->urm;
        free(c);
        }
    Propozitie_init(p);
}

int main()
{
    Propozitie p;
    int op;
    char text[16],text1[16],text2[16];
    Cuvant *c;

    Propozitie_init(&p);
    do{
        printf("1 - propozitie noua\n");
        printf("2 - afisare\n");
        printf("3 - stergere cuvant\n");
        printf("4 - inserare cuvant\n");
        printf("5 - iesire\n");
        printf("optiune: ");scanf("%d",&op);
        switch(op){
            case 1:
                Propozitie_elibereaza(&p);
                for(;;){
                    scanf("%s",text);
                    if(!strcmp(text,"."))break;
                    Cuvant *c=Cuvant_nou(text);
                    Propozitie_adauga(&p,c);

                    }
                break;
            case 2:
                for(c=p.prim;c;c=c->urm)printf("%s ",c->text);
                printf("\n");
                break;
            case 3:
                printf("cuvant de sters:");scanf("%s",text);
                c=Propozitie_cauta(&p,text);
                if(c){
                    Propozitie_sterge(&p,c);
                    }else{
                    printf("cuvantul \"%s\" nu se gaseste in propozitie\n",text);
                    }
            break;
            case 4:
                printf("cuvant de inserat:");
                scanf("%s",text1);
                printf("cuvant succesor celui inserat:");
                scanf("%s",text2);
                c=Propozitie_cauta(&p,text2);
                Cuvant *c2=Cuvant_nou(text1);
                if(!c)
                {
                    Propozitie_adauga(&p,c2);
                }
                if(c)
                {
                    Cuvant *pred=c->pred;
                    c2->urm=c;
                    pred->urm=c2;
                    c2->pred=pred;
                    c->pred=c2;

                }

            case 5:break;
            default:printf("optiune invalida");
            }
        }while(op!=5);
    return 0;
}

