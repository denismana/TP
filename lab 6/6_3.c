#include <stdio.h>
 
 #define VAL(v)     ((v)>='a'&&(v)<='z'?1:0)

#define VAL2(v)     ((v)>='A'&&(v)<='Z'?1:0)

#define VAL3(v)     ((v)>='0'&&(v)<='9'?1:0)

 
 
 #define LINIE(baza)    VAL(16*baza+0),VAL(16*baza+1),VAL(16*baza+2),VAL(16*baza+3),    \
                                      VAL(16*baza+4),VAL(16*baza+5),VAL(16*baza+6),VAL(16*baza+7),    \
                                      VAL(16*baza+8),VAL(16*baza+9),VAL(16*baza+10),VAL(16*baza+11),    \
                                      VAL(16*baza+12),VAL(16*baza+13),VAL(16*baza+14),VAL(16*baza+15)
 
                                      #define LINIE2(baza)    VAL2(16*baza+0),VAL2(16*baza+1),VAL2(16*baza+2),VAL2(16*baza+3),    \
                                      VAL2(16*baza+4),VAL2(16*baza+5),VAL2(16*baza+6),VAL2(16*baza+7),    \
                                      VAL2(16*baza+8),VAL2(16*baza+9),VAL2(16*baza+10),VAL2(16*baza+11),    \
                                      VAL2(16*baza+12),VAL2(16*baza+13),VAL2(16*baza+14),VAL2(16*baza+15)
 
                                      #define LINIE3(baza)    VAL3(16*baza+0),VAL3(16*baza+1),VAL3(16*baza+2),VAL3(16*baza+3),    \
                                      VAL3(16*baza+4),VAL3(16*baza+5),VAL3(16*baza+6),VAL3(16*baza+7),    \
                                      VAL3(16*baza+8),VAL3(16*baza+9),VAL3(16*baza+10),VAL3(16*baza+11),    \
                                      VAL3(16*baza+12),VAL3(16*baza+13),VAL3(16*baza+14),VAL3(16*baza+15)
 
const char tabela[]={
    LINIE(0),LINIE(1),LINIE(2),LINIE(3),
    LINIE(4),LINIE(5),LINIE(6),LINIE(7),
    LINIE(8),LINIE(9),LINIE(10),LINIE(11),
    LINIE(12),LINIE(13),LINIE(14),LINIE(15)
    };
 const char tabela2[]={
    LINIE2(0),LINIE2(1),LINIE2(2),LINIE2(3),
    LINIE2(4),LINIE2(5),LINIE2(6),LINIE2(7),
    LINIE2(8),LINIE2(9),LINIE2(10),LINIE2(11),
    LINIE2(12),LINIE2(13),LINIE2(14),LINIE2(15)
    };
const char tabela3[]={
    LINIE3(0),LINIE3(1),LINIE3(2),LINIE3(3),
    LINIE3(4),LINIE3(5),LINIE3(6),LINIE3(7),
    LINIE3(8),LINIE3(9),LINIE3(10),LINIE3(11),
    LINIE3(12),LINIE3(13),LINIE3(14),LINIE3(15)
    };
#define ISLOWER(c)  (tabela[(unsigned char)(c)])
#define ISUPPER(c)  (tabela2[(unsigned char)(c)])
#define ISDIGIT(c)  (tabela3[(unsigned char)(c)])
    
 
int main()
{
    printf("%d\n",ISLOWER('\n'));         // => 0
    printf("%d\n",ISLOWER('a'));    // => 1
    printf("%d\n",ISLOWER('A'));    // => 0
    printf("%d",ISDIGIT('1'));
    return 0;
}
