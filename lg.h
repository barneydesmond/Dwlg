#include <time.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void logo(){
int a;
srand(time(NULL));
    a = (rand() % (4 - 1 + 1)) + 1;

    switch(a){
case(1):{
printf(CYN "\n       CCCf.                                           ;LCCC       ");
printf("\n       tCCCCCCCL                                  ;CCCCCCCC        ");
printf("\n        CCt  ;CCCCCt                           CCCCC;  ;CC1        ");
printf("\n         CC      :CCCC,                     LCCC:      CCC         ");
printf("\n         .CC        ,CCCt                 CCC,        LCC          ");
printf("\n          .CC          CCC.             CCC          fCC           ");
printf("\n            CC          ,CCC           CC.          LCf            ");
printf("\n             tCL          CCCCCCCCCCCCCC           CC              ");
printf("\n               CCi        .CCCCCCCCCCCC.         CC;               ");
printf("\n                 LCC       CCCCCCCCCCCC        CC,                 ");
printf("\n                    CCC   CCCCCCCCCCCCCC    CCf                    ");
printf("\n                       .,CCCCCCCCCCCCCCCCt .                       ");
printf("\n                      ;CCC:   iCCCCC    CCCL                       ");
printf("\n                    CCCCCCC:   LCCC . .CCCCCCC.                    ");
printf("\n                       fCCCCC   CCC  CCCCCf                        ");
printf("\n                           ::   CC;  ::                            ");
printf("\n                                CC                                 "RESET);
printf("\n\n");

}break;

case(2):{
printf(RED"\n                                                        ");
printf("\n                                                        ");
printf("\n                                          1             ");
printf("\n                                         ,L    L.       ");
printf("\n                                         LL  .LL.       ");
printf("\n                                        LLL 1LLL,       ");
printf("\n                                       tLL LLLLL,       ");
printf("\n                                      ,Lf LLLLLL.       ");
printf("\n                                      L::LLLLLLL        ");
printf("\n                                     L fLLLLLLL,        ");
printf("\n                                    1 LLLLLLLL.         ");
printf("\n                                    .LLLLLLLi           ");
printf("\n                                   :ff111iii            ");
printf("\n                                 .LL:.LLLi              ");
printf("\n                                .LfLLLL ;t              ");
printf("\n                                      iLLi              ");
printf("\n         :LLLLLLLL1                 .LLLLL              ");
printf("\n       LLLLLLLLLLLLLL1             1LLLLLL,             ");
printf("\n     ;LLLLLLLLLLLLLLLLL;          tLLLLLLLL:            ");
printf("\n     LLLLLLLLLffLLLLLLLLL        :LLLLLLLLLLf           ");
printf("\n    :LLLLLL        fLLLLLL:      LLLLLLLLLLLLt          ");
printf("\n     LLLLL.          :LLLLLf     LLLLLLLLLLLLL          ");
printf("\n     fLLLL;            .LLLLL.   iLLLLLLLLLLLi          ");
printf("\n      ,LLLLf              :LLLL:  ,LLLLLLLLL:           ");
printf("\n         tLLLL1               :LLLL: :LLLL:         \n\n"RESET);
}
break;

case (3):
    {

printf(RED "\n                       ,1tLLLft;.                       ");
printf("\n                 tCCCCCCCCCCCCCCCCCCCC,                 ");
printf("\n             :CCCCCCCCtffffti.   .tCCCCCCC              ");
printf("\n           CCCCCCCCCCCCCCCCCCCCCCCC   .CCCCCi           ");
printf("\n         CCCCCCCCCCCCCCCCCCCCCCCCCCCCC   .CCCCt         ");
printf("\n       LCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC    CCCC        ");
printf("\n      CCCCfCCCCCCC:            CCCCCCCCCC.   ,CCCt      ");
printf("\n     CCC1 fCCCCCCC:              tCCCCCCCC.    CCCL     ");
printf("\n    CCC;  fCCCCCCC:               ,CCCCCCCC     CCCf    ");
printf("\n   CCCL   fCCCCCCC:                CCCCCCCCL     CCC.   ");
printf("\n  .CCC    fCCCCCCC:                :CCCCCCCC     1CCC   ");
printf("\n  tCCL    fCCCCCCC:         :tLCCCCCCti,. .;    ,;1tf   " RESET);
printf(RED"\n  CCC;    fCCCCCCC: ;CCCCCCCt " BLU "    :.00000000            ");
printf(RED"\n  CCC:    fCCCCCCCCCCCC.  "BLU"  :8f    ,00000000         :  ");
printf(RED"\n  LCC1    fCCCCCCCt    "BLU" 108.       800000008            ");
printf(RED"\n  ;CCC    fCCCC     "BLU" 808           00000000i        8   ");
printf(RED"\n   CCC:   fL    "BLU" .800.            800000008        0f   ");
printf(RED"\n   ,CCC       "BLU" 800C              000000000        C8    ");
printf(RED"\n    tC,    "BLU" t00000:           G0000000000        80     ");
printf("\n          80000000000000000000000000000f        00      ");
printf("\n       .00000000000000000000000000000f        000       ");
printf("\n        00000000000000000000000000t         000,        ");
printf("\n          00000:                         i000i          ");
printf("\n            t000000.                 ;80008             ");
printf("\n               i800000008800088800000000                ");
printf("\n                    t8000000000008G:                    "RESET);
printf("\n\n");
    }
break;

case 4:{
printf("\n");
printf(GRN"\n                                 ;G.                  CL    ");
printf(YEL"\n                                 ;CCG               LGCL      ");
printf(BLU"\n                                 ;CCCCf           iGCCCL   ");
printf(MAG"\n                                 ;CCCCCC;       ,GCCCCCL      ");
printf(CYN"\n                                 ;CCCCCCCCCCCCCCCCCCCCCL     ");
printf(WHT"\n                                 ;CCCCCCCCCCCCCCCCCCCCCL   ");
printf(RED"\n                                 ;CCCCCCCCCCCCCCCGGCCCCL      ");
printf(GRN"\n                                 ;CCCt,C,LCCCCG1,C,LCCCL    ");
printf(GRN"\n                                 ;CCCGGGGGCCCCCGGCCCCCCL        ");
printf(BLU"\n                                 ;CCCCCCCCG...GCCCCCCCCL               ");
printf(MAG"\n                          1GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGL       "RESET);
printf("\n\n");
}break;

}
}
