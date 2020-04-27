/**
 * 
 * Scrieți un program care copiază conținutul unui fișier sursă într-un fișier destinație. Numele fișierelor se citesc din linia de comandă. Pentru eficiența copierii, programul va citi câte un bloc de maxim 4096 de octeți, pe care îl va scrie în destinație.
Exemplu: ./copiere src.dat dst.dat                    -> copiază src.dat în dst.dat

*/



#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>

void copiere(char source[],char dest[])
{
    FILE *fin, *fout;
    char buffer[32769];
    fin=fopen(source,"r");
    if(fin==NULL){
        perror("eroare deschidere fisier citire");
        return errno;
    }
    fout=fopen(dest,"w");
    if(fout==NULL){
        perror("eroare deschidere fisier scriere");
        return errno;
    }
    while(1)
    {
        if(fread(buffer,sizeof(char),32768,fin)==0){              /// pot face bufferul mai eficient cumva cu alocare dinamica, pentru a nu il lua de 32768 de caractere?
            fclose(fin);
            fclose(fout);
            return ;
        }
        else{
            printf("%s",buffer);
            fwrite(buffer,sizeof(char),strlen(buffer),fout);
        }
    }
    
}

int main( int argc, char *argv[])
{
    copiere(argv[1],argv[2]);
    return 0;
}
