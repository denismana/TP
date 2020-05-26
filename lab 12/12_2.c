/**
Se cere un n strict pozitiv și patru valori reale: ma, mb, m, d. ma și mb reprezintă masele a două corpuri situate la distanța d unul de celălalt. m este masa unui corp care pornește din a și ajunge în b, din n pași egali. Să se calculeze în fiecare punct al traseului lui m forța F de atracție gravitațională care acționează asupra lui. F va fi cu semn: negativ înseamnă că m este atras către ma, iar pozitiv către mb. Formula atracției gravitaționale dintre două corpuri m1 și m2, situate la distanța d unul de celălalt este: F=G*m1*m2/d2, unde G=6.674e-11. Masele sunt exprimate în kilograme, distanțele în metri, iar forțele în newtoni.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define G 6.674*pow(10,-11)
int main()                                      //nu inteleg enuntul
{
    int i,n;
    double f,ma,mb,m,d;
    printf("introduceti m=");
    scanf("%lf",&m);
    printf("introduceti ma=");
    scanf("%lf",&ma);
    printf("introduceti mb=");
    scanf("%lf",&mb);
    printf("introduceti d=");
    scanf("%lf",&d);
    for(i=0;i<n;i++)
    {
        f=(G*ma*mb)/pow(d,2);
        if(ma>mb)
            f=f*(-1);
        printf("%lf\n",f);

    }
    return 0;
}
