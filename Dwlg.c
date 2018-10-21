#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lg.h"

typedef struct {
    int a;
    int b;
} dret;


// At row 'i' in the matrix, copy from ch to m
// I think this should just be strncpy from ch to m[i]
void put(char m[100][100], char ch[100], int i) {
    int j;

    // calculate strlen(ch) once
    for(j=0; j<strlen(ch); j++) {
        m[i][j] = ch[j];
    }
}

// Read from file into a 100x100 matrix. They must've been praying that lines
// are no longer than 100 characters (incl. null).
int vider(FILE* fich, char m[100][100]) {
    int i=0;
    int j=0;

    do {
        j=0;
        do {
            m[i][j] = fgetc(fich);
            j++;
        } while ( (m[i][j-1] != EOF) && (m[i][j-1] != '\n') );

        if (m[i][j-1] =='\n') {
            m[i][j-1] = '\0';
        }

        i++;

    } while (m[i-1][j-1] != EOF);

    m[i-1][j-1]='\0';

    fclose(fich);

    return i;
}


int insert(char m[100][100]) {
    int i=0;
    char ch[100];
    char sh[100];
    char mode;

    do {
        printf("*[press "GRN"1"RESET" ] you have an input file\n*[press "GRN"2"RESET" ] insert them one by one\n\n your choice :   ");
        mode = getchar();
    } while( (mode!='1') && (mode!='2') );

    switch (mode) {
        case ('1'): {
            FILE* ftxt = NULL;

            do {
                do {
                    printf(GRN"\n(Input_folder)"RESET" /../filename.txt :   ");
                    scanf("%s",sh);
                } while(!fopen(sh,"r+"));
                ftxt = fopen(sh,"r+");
            } while(!ftxt);
            i = vider(ftxt, m);
            return i;
        } break;

        case('2'): {
            printf("\nwrite your guesses , at the END write "GRN"w&q "RESET);
            do {
                do {
                    printf("\nN°[%d] : ",i+1);
                    scanf("%s",ch);
                } while (ch[0]=='\n');
                if ( (ch[0]!='w') || (ch[1]!='&') || (ch[2]!='q') || (ch[3]!='\0') ) {
                    put(m,ch,i);
                    i++;
                } else return (i);

            } while (( (ch[0]!='w') || (ch[1]!='&') || (ch[2]!='q') || (ch[3]!='\0') ));

        }
        break;
    }
    return i;
}



dret maker(FILE* f, char txt[100][100], int t[100], int k, int lmin, int lmax, int n) {
    int i, j;
    char ch1[100], ch[100];
    dret r;

    r.b = 1;

    ch[0] = '\0';

    for (i=0; i<k+1; i++) {
        j=0;
        do {
            ch1[j]=txt[t[i]][j];
            j++;
        } while ((ch1[j-1] != '\0'));
        strcat(ch, ch1); /* safe? */
    }

    if ((strlen(ch)>=lmin) && (strlen(ch)<=lmax)) {
        fprintf(f,"%s\n",ch);
        printf("%s\n",ch);
        r.a = 1;
    } else if (strlen(ch) > lmax) {
        r.a=-1 ;
    } else {
        r.a=1;
    }

    if (t[0] == (n-1)) {
        r.b=0;
    }

    return r;
}






int full(int t[100], int k, int n, double x, double fac, int h) {
    int i=0,j=0,b=0,v=0;

    if( (k==n) && (t[0]==(n-1)) && (t[n-1]==0) && (x>=fac) ) {
        return -11; // the end.
    } else if(k==n) {
        return -2; // back 2 steps
    } else {
        i = -1;

        do {
            i++;
            b = 0;

            for (j=0; j<k; j++) {
                if (i==t[j]) {
                    b=1;
                }
            }

            if (t[k]>=0) {
                if ((b==0) && (i<=t[k]) ) {
                    b=1;
                    v++;
                }
            }

        } while (b==1);

        if (v < n-k) {
            return i;
        } else if (v >= n-k+h) {
            return (-1);
        }

    }

// XXX: return 0 here?
}

double factorial(int n) {
    if (n>1) {
        return n*factorial(n-1);
    }
    return 1;
}


void caller(char txt[100][100], int t[100], int n, FILE* f, int lmin, int lmax) {
    int i=0,e=0;
    double fac,x=1;
    dret s;

    for(i=0; i<n; i++){
        t[i]=i;
        maker(f, txt, t, i, lmin, lmax, n);
    }

    fac = factorial(n);

    do {
        if ((t[0]!=n-1) || (i!=0) || (n==999)) {
            t[i] = full(t,i,n,x,fac,0);
        } else {
            t[i] = full(t,i,n,x,fac,1);
        }

        if(t[i] == -1) {
            i--;
        } else if (t[i] == -2) {
            x++;
            t[i-1]=-1;
            i=i-2;
        } else if (t[i]>=0) {
            s = maker(f,txt,t,i,lmin,lmax,n);
            i = i + s.a;
            if (s.b == 0) {
                e=1;
            }
        }

        if ((e==1) && (t[0]!=n-1)) {
            t[i] = -11;
        }

    } while (t[i] != -11);
}


int lstrlen(char txt[100][100], int n) {
    int i, j;
    char ch1[100], ch[100];

    ch[0] = '\0';

    for (i=0; i<n; i++) {
        j=0;
        do {
            ch1[j]=txt[i][j];
            j++;
        } while ((ch1[j-1] != '\0'));

        strcat(ch, ch1);
    }

    return (strlen(ch));
}


dret contsz(int l) {
    dret a;
    char c[2];

    a.a=0;
    a.b=999;

    printf("\ncontrol password length [Y/y] (default N) ? :  ");

    scanf("%s", &c);


    if ((c[0]=='y') || (c[0]=='Y')) {
        do {
            printf("minimum password length  (max= %d) :  ",l);
            scanf("%d",&a.a);
        } while ((a.a<0) || (a.a>l));


        do {
            printf("maximum password length  (max= %d) :  ",l);
            scanf("%d",&a.b);
        } while ((a.b<0) || (a.b>l) || (a.b<a.a));
    }

    return a;
}


int main() {
    int n,l,lmin=0,lmax=999;
    char txt[100][100],sh[100];
    int t[100];
    dret sz;
    sz.a=0;
    sz.b=999;
    FILE* f= NULL;
    logo();

    n=insert(txt);
    l=lstrlen(txt,n);
    sz=contsz(l);

    do {
        printf(GRN"\n(output_folder)"RESET" /../filename.txt :   ");
        scanf("%s",sh);
    } while (!fopen(sh,"w+"));
    f = fopen(sh,"w+");


    caller(txt, t, n, f, sz.a, sz.b);


    fclose(f);

    printf(YEL"\n%s "RESET"was successfully generated\n\n",sh);

    return 0;
}

// vim: et ts=4
