void incarca()
{
    elibereaza();
    FILE *fis=fopen("bd.txt","rb");
    // daca nu s-a putut deschide fisierul nu este eroare,
    // deoarece este posibil sa fie prima rulare a programului
    if(!fis)return;
    char linie[MAX_NUME+32];    
    // citeste linie cu linie
    while(fgets(linie,MAX_NUME+32,fis)){
        char *sep=strchr(linie,';');        		
        if(!sep)continue;    			
        int nNume=sep-linie;       	
        if(nNume>=MAX_NUME)nNume=MAX_NUME-1;   
        char nume[MAX_NUME];
        memcpy(nume,linie,nNume);
        nume[nNume]='\0';       
        memcpy(sex,linie,1);                    ///////////modificare pentru adaugarea sexului        
        float salariu=(float)atof(sep+1);
        adauga(nume,sex,salariu);
        }
    fclose(fis);
    
    void salveaza()
{
    FILE *fis=fopen("bd.txt","wb");
    if(!fis)err("nu se poate crea bd.txt");
    Persoana *p;
    for(p=bd;p;p=p->urm){
        // fiecare persoana este salvata in fisier pe cate o linie,
        // cu ';' ca separator intre nume si salariu
        fprintf(fis,"%s;%c;%g\n",p->nume,p->sex,p->salariu);         //////////modificare pentru adaugarea sexului
        }
    fclose(fis);
}

static Persoana *nou(const char *nume,char sex,float salariu, Persoana *urm)
{
    Persoana *p=(Persoana*)malloc(sizeof(Persoana));
    if(!p)err("memorie insuficienta");
    strcpy(p->nume,nume);
    p->sex=sex;                     ////////////////modificare pentru adaugarea sexului
    p->salariu=salariu;
    p->urm=urm;
    return p;
}

void adauga(const char *nume,char sex,float salariu) ////////////////modificare pentru adaugarea sexului
{
    Persoana *pred=NULL;        
    Persoana *crt;                        	
    // itereaza toate numele din bd
    for(crt=bd;crt;pred=crt,crt=crt->urm){
        if(strcmp(crt->nume,nume)>=0)break;
        }
    if(pred){        			
        pred->urm=nou(nume,sex,salariu,crt);    ////////////////modificare pentru adaugarea sexului
        }else{       		
        bd=nou(nume,sex,salariu,crt);   ////////////////modificare pentru adaugarea sexului
        }
}
///////////////// in main.c
case 1:
                getchar();
                citesteText("nume",nume,MAX_NUME);
                citesteText("sex",sex,1);              ////////////////modificare pentru adaugarea sexului
                salariu=citesteFloat("salariu");
                adauga(nume,sex,salariu);
                break;
            case 2:
                getchar();
                citesteText("nume",nume,MAX_NUME);
                if(sterge(nume)){
                    printf("%s a fost sters din baza de date\n",nume);
                    }else{
                    printf("%s nu exista in baza de date\n",nume);
                    }
                break;
            case 3:
                for(p=bd;p;p=p->urm){
                    printf("%s\t%c\t%g\n",p->nume,p->sex,p->salariu);      ////////////////modificare pentru adaugarea sexului
                    }
                break;
