 ///////////////////////////modififcari facute in fisierul bd.c
void listare_dupa_salariu()
{
    Persoana *q;
    float min=20000000;
    char text[30];
    while(bd)
    {
        for(q=bd;q;q=q->urm)
        {
            if((q->salariu)<min)
            {
                min=q->salariu;
                strcpy(text,q->nume);
            }

        }
        printf("%s : %f",text,min);
        sterge(text);
    }
}
