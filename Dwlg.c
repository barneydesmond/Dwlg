#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"lg.h"
typedef struct
{
    int a;
    int b;

}dret;




void put(char m[100][100],char ch[100],int i){
int j ;

for(j=0;j<strlen(ch);j++){
    m[i][j]=ch[j];
}


}


int vider(FILE* fich , char m[100][100]){


int j=0,i=0;

    do{
           j=0;
         do
        {
          m[i][j]=fgetc(fich);
            j++;
         } while ((m[i][j-1] != EOF)&&(m[i][j-1] !='\n'));

      if (m[i][j-1] =='\n'){m[i][j-1]='\0';}

    i++;

    }while (m[i-1][j-1] != EOF);

m[i-1][j-1]='\0';

fclose(fich);

return i;


}


int insert(char m[100][100]){
int i=0 ;
char ch[100],c,sh[100];

printf("do you have an input file (default : N) ? [y/Y] : ");
scanf("%c",&c);
if((c=='Y')||(c=='y')){
           FILE* ftxt = NULL;
           do{
           do{
            printf(" (Input_folder) /../filename.txt :   ");
            scanf("%s",sh);
           } while(!fopen(sh,"r+"));
           ftxt = fopen(sh,"r+");
           }while(!ftxt);
           i=vider(ftxt,m);
           return (i);

}
else{
        printf("\nwrite your guesses , in the end write w&q ");
do{
    do{
    printf("\nN°[%d] : ",i+1);
    scanf("%s",ch);
     }while(ch[0]=='\n');
    if((ch[0]!='w')||(ch[1]!='&')||(ch[2]!='q')||(ch[3]!='\0')){
        put(m,ch,i);
        i++;
    }else return (i);

}while(((ch[0]!='w')||(ch[1]!='&')||(ch[2]!='q')||(ch[3]!='\0')));

}

}



dret maker(FILE* f , char txt[100][100],int t[100],int k,int lmin ,int lmax,int n){
int j,i;
char ch1[100],ch[100];
dret r;

r.b=1;

ch[0]='\0';

for(i=0;i<k+1;i++){
    j=0;
   do{
     ch1[j]=txt[t[i]][j];
    j++;
 }while((ch1[j-1]!='\0'));

    strcat(ch,ch1);
}

if((strlen(ch)>=lmin)&&(strlen(ch)<=lmax)){
fprintf(f,"%s\n",ch);
printf("%s\n",ch);
r.a=1;
}else if(strlen(ch)>lmax){ r.a=-1 ;
}else{ r.a=1; }

if(t[0]==(n-1)){ r.b=0;}

return r;


}






int full(int t[100],int k,int n ,double x ,double fac,int h){
int i=0,j=0,b=0,v=0;

if((k==n)&&(t[0]==(n-1))&&(t[n-1]==0)&&(x>=fac)){
    return -11; //the end.
}else if(k==n){
    return -2; // back 2 steps
}else {

i=-1;

do{ i++; b=0;

    for(j=0;j<k;j++){ if(i==t[j]){b=1;} }

       if(t[k]>=0){ if((b==0)&&(i<=t[k])){b=1;v++;} }

}while((b==1));

if (v<n-k){return i;} else if(v>=n-k+h) {return (-1);}

}

}

double factor(int n){

            if (n>1) return n*factor(n-1);

            else return 1;

        }




void caller(char txt[100][100],int t[100], int n , FILE* f,int lmin,int lmax){

int i=0,e=0;
double fac,x=1;
dret s;

for(i=0;i<n;i++){
    t[i]=i;
    maker(f,txt,t,i,lmin,lmax,n);
}

fac=factor(n);

do{


       if((t[0]!=n-1)||(i!=0)||(n==999)){
        t[i]=full(t,i,n,x,fac,0);
       }else{  t[i]=full(t,i,n,x,fac,1);   }

    if(t[i]==-1){
     i=i-1;
    }else if(t[i]==-2){
        x++;
        t[i-1]=-1;
        i=i-2;
       }else if(t[i]>=0) { s=maker(f,txt,t,i,lmin,lmax,n);
                           i=i+s.a;
                            if(s.b==0){
                                     e=1;
                                     }
                          }
if((e==1)&&(t[0]!=n-1)){t[i]=-11;}

}while(t[i]!=-11);

}


int lstrlen(char txt[100][100],int n ){

int j,i;
char ch1[100],ch[100];

ch[0]='\0';

for(i=0;i<n;i++){
    j=0;
   do{
     ch1[j]=txt[i][j];
    j++;
 }while((ch1[j-1]!='\0'));

    strcat(ch,ch1);
}

return (strlen(ch));

}




int main()
{
int n,l,lmin=0,lmax=999;
char txt[100][100],c,sh[100];
int t[100];
FILE* f= NULL;
logo();


n=insert(txt);



    printf("\ncontrol password length [Y/y] (default N) ? :  ");

    scanf(" %c", &c);


if((c=='y')||(c=='Y')){

    l=lstrlen(txt,n);

    do{
        printf("minimum password length  (max= %d) :  ",l);
        scanf("%d",&lmin);
    }while((lmin<0)||(lmin>l));


    do{
        printf("maximum password length  (max= %d) :  ",l);
        scanf("%d",&lmax);
    }while((lmax<0)||(lmax>l)||(lmax<lmin));

}


          do{
            printf("\n (output_folder) /../filename.txt :   ");
            scanf("%s",sh);
           } while((sh[0]!='/')||(strlen(sh)<6));
           f = fopen(sh,"w+");



caller(txt,t,n,f,lmin,lmax);


fclose(f);

printf("\n%s was successfully generated\n\n",sh);

    return 0;
}
