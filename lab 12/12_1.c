/**
 Se cere un n<100, iar apoi coordonatele reale (x,y) a n puncte din plan. Fiecare punct reprezintă poziția unde va trebui dată o gaură într-o placă. Bormașina se află inițial la locația (0,0). Să se afișeze ordinea de dat găuri, astfel încât întotdeauna bormașina să fie mutată la punctul cel mai apropiat de ea.
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef  struct
 {
     double x;
     double y;
 }coord;
void citire(coord p[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%lf",&p[i].x);
        scanf("%lf",&p[i].y);
    }
}
 int main()
 {

     coord pct[100];
     int n,i,pozitie;
     double minim=20000000,pct_curent_x=0,pct_curent_y=0,cx,cy,dist;
     printf("Introduceti numarul de elemente:");
     scanf("%d",&n);
     citire(pct,n);
     while(n)
     {
        minim=20000000;
        for(i=0;i<n;i++)
        {
            dist=sqrt(pow(pct[i].x-pct_curent_x,2)+pow(pct[i].y-pct_curent_y,2));
            if(dist<minim){
                minim=dist;
                cx=pct[i].x;
                cy=pct[i].y;
                pozitie=i;
            }
        }
        printf("punctul urmator este: (%lf,%lf) \n",cx,cy);
        pct[pozitie]=pct[n-1];
        pct_curent_x=cx;
        pct_curent_y=cy;
        n--;
     }
    return 0;
 }
