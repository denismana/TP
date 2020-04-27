/**
 * Se citesc m și n de la tastatură, iar apoi o matrice a[m][n] cu elemente de tip întreg. Să se scrie matricea într-un fișier binar, prima oară scriindu-se m și n, iar apoi elementele, așa cum sunt dispuse ele în memorie. Să se citească matricea din fișier într-o variabilă b și să se afișeze.
 * 
 */
 

#include<stdlib.h>
#include<stdio.h>
#include<errno.h>

int g_n,g_m;

void eliberare (int **a ,int *k)
{
    int i;
    for(i=0;i<*k;i++)
    {
        free(a[i]);
    }
    free(a);
}

        

int ** citire_si_creare_fisier_binar (char fis[])
{
    FILE *fout;
    int **a,i,j;
    printf("Introduceti nr de linii m=");
    scanf("%d",&g_m);
    printf("Introduceti nr de coloane n=");
    scanf("%d",&g_n);
    fout=fopen(fis,"w");
    if(fout==NULL)
    {
        perror("deschidere fisier nereusita");
        return errno;
    }
    a=(int **)malloc (g_m*sizeof(int));
    if(a==NULL){
        perror("alocare memorie nereusita");
        return errno;
    }
    for(i=0;i<g_m;i++)
    {
        a[i]=(int *) malloc(g_n*sizeof(int));
        if(a[i]==NULL)
        {
            eliberare(a,&i);
            perror("alocare memorie coloane nereusita");
            return errno;
        }
    }
    for(i=0;i<g_m;i++)
    {
        for(j=0;j<g_n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    fwrite(&g_m,sizeof(int),1,fout);
    fwrite(&g_n,sizeof(int),1,fout);
    for(i=0;i<g_m;i++)
    {
        for(j=0;j<g_n;j++)
        {
            fwrite(&a[i][j],sizeof(int),1,fout);
        }
    }
    fclose(fout);
    return a;
    
}

int ** recitire_din_fisier_si_afisare(char fis[])
{
    FILE *fin;
    fin=fopen(fis,"r");
    int i,j,m,n,**b;
    if(fread(&m,sizeof(int),1,fin)==0){
        perror("citirea lui m din fisier binar nereusita");
        return errno;
    }
    if(fread(&n,sizeof(int),1,fin)==0){
        perror("citirea lui n din fisier binar nereusita");
        return errno;
    }
    b=(int**) malloc(sizeof(int) * m);
    if(b==NULL){
        perror("alocare dinamica nereusita din fisier binar");
        return errno;
    }
    for(i=0;i<m;i++)
    {
        b[i]=(int *)malloc(sizeof(int)*n);
        if(b[i]==NULL)
        {
            eliberare(b,&i);
            perror("alocare dinamica a coloanelor nereusita din fisier binar");
            return errno;
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(fread(&b[i][j],sizeof(int),1,fin)==0)
            {
                eliberare(b,&m);
                perror("eroare la citire din fisier binar a matricei");
                return errno;
            }
        }
    }
    printf("%d %d\n",m,n);
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    fclose(fin);

    return b;
    
}

    

int main (int argc, int *argv[])
{
    
    int **a,**b;
    a=citire_si_creare_fisier_binar(argv[1]);
    b=recitire_din_fisier_si_afisare(argv[1]);
    eliberare(a,&g_m);
    eliberare(b,&g_m);
    return 0;

    
}
    
