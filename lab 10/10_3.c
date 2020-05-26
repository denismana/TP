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

#define LISTAD_NUME         Propozitie      	// numele TDA
#define LISTAD_ELEMENT   Cuvant      	// tipului unui element din lista
#include "listad.h"

Cuvant *Propozitie_cauta(Propozitie *p,const char *text)
{
    Cuvant *c;
    for(c=p->prim;c;c=c->urm){
        if(!strcmp(c->text,text))return c;
        }
    return NULL;
}

int main()
{
    Propozitie p;
    int op;     // optiune
    char text[16];
    char text1[16];
    char text2[16];
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
                printf(".\n");
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
                Propozitie_inserare(&p,c,c2);
                break;
            case 5:break;
            default:printf("optiune invalida");
            }
        }while(op!=5);
    return 0;
}
