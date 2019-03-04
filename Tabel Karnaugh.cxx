#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int ocasuta(int i,int j){
switch(i){
    case 0:
    printf("ab");
    break;
    case 1:
    printf("aB");
    break;
    case 2:
    printf("AB");
    break;
    case 3:
    printf("Ab");
    break;
    }
switch(j){
    case 0:
    printf("cd");
    break;
    case 1:
    printf("cD");
    break;
    case 2:
    printf("CD");
    break;
    case 3:
    printf("Cd");
    break;
    }
return 0;}

int casuteorizontal2(int i, int k){
switch(i){
case 0:
    printf("ab");
    break;
case 1:
    printf("aB");
    break;
case 2:
    printf("AB");
    break;
case 3:
    printf("Ab");
    break;
}
switch(k){
case 0:
    printf("c");
    break;
case 1:
    printf("D");
    break;
case 2:
    printf("C");
    break;
case 3:
    printf("d");
    break;
}
return 0;}

int casutevertical2(int i, int k){
switch(i){
case 0:
    printf("a");
    break;
case 1:
    printf("B");
    break;
case 2:
    printf("A");
    break;
case 3:
    printf("b");
    break;
}
switch(k){
case 0:
    printf("cd");
    break;
case 1:
    printf("cD");
    break;
case 2:
    printf("CD");
    break;
case 3:
    printf("Cd");
    break;
}
return 0;}


int casutepatrat4(int i, int k){
switch(i){
case 0:
    printf("a");
    break;
case 1:
    printf("B");
    break;
case 2:
    printf("A");
    break;
case 3:
    printf("b");
    break;
}
switch(k){
case 0:
    printf("c");
    break;
case 1:
    printf("D");
    break;
case 2:
    printf("C");
    break;
case 3:
    printf("d");
    break;
}
return 0;
}

int afisaretabel(int V[4][4]){
int i,j;
printf("\n\n");
for(i=-1;i<4;i++){//afisarea tabelului pentru functia initiala
        for(j=-1;j<4;j++){
            if(i==-1)
                switch(j){
                case -1:
                    printf(" AB\\CD_");
                break;
                case 0:
                    printf("00_");
                break;
                case 1:
                    printf("__01_");
                break;
                case 2:
                    printf("__11_");
                break;
                case 3:
                    printf("__10|");
                break;
                }
            if(j==-1)
                switch(i){
                case -1:
                break;
                case 0:
                    printf("  00|");
                break;
                case 1:
                    printf("  01|");
                break;
                case 2:
                    printf("  11|");
                break;
                case 3:
                    printf("  10|");
                break;
                }
            if(i>=0&&j>=0)
            printf("___%d|",V[i][j]);
        }
        if(i<3)
    printf("\n");
    }
    return 0;
}

int main(){//functia main
int F[20],E[20][5],TK[4][4],i,j,k,l,m,nr,ni,nz,ab,cd,abcd,cif,ok;
char Fn[20][4];

for(i=0;i<20;i++)
    for(j=0;j<5;j++)
    E[i][j]=0;
for(i=0;i<4;i++)
    for(j=0;j<4;j++)
    TK[i][j]=0;
i=1;
nr=0;
printf("Introduceti valori intre 0 si 15 inclusiv pentru termenii expresiei boolene.\nDaca ati terminat, introduceti valoarea -1.\nF[0]=");
scanf("%d",&F[0]);
if(F[0]!=-1)
while(F[0]>15||F[0]<0){
    printf("\nValoarea nu poate depasi 15 si nu poate fi negativa.\nF[0]=");
    scanf("%d",&F[0]);
}
if(F[0]!=-1)
    nr++;
while(F[i-1]!=-1&&i<19){//se introduc valori de la tastatura
    printf("F[%d]=",i);
    scanf("%d",&F[i]);
    if(F[i]!=-1)
    while(F[i]>15||F[i]<0){
    if(F[i]==-1)
    break;
    printf("Valoarea nu poate depasi 15 si nu poate fi negativa.\nF[%d]=",i);
    scanf("%d",&F[i]);
}
    i++;
nr++;
}
if(nr<20)
nr--;

for(i=0;i<nr;i++)//eliminam dublurile de termeni, idempotenta.
    for(j=i+1;j<nr;j++)
        if(F[i]==F[j]){
        for(l=j;l<nr;l++)
            F[l]=F[l+1];
            j--;
            nr--;
        }

    for (i = 0; i < nr; i++)//sortare elemente in ordine crescatoare
        for (j = i+1; j < nr; j++)
            if(F[i]>F[j]){
                m=F[i];
                F[i]=F[j];
                F[j]=m;
                }

printf("\n\nf=");
for(i=0;i<nr;i++){//valorile se convertesc in binar pentru a determina expresia
    nz=F[i];
    j=3;
    E[i][4]=F[i];

    while(nz!=0&&j>=0){//algoritm de impartiri succesive
                E[i][j]=nz%2;
                nz=nz/2;
                j--;

                }
    for(j=0;j<4;j++)
        switch(j){
        case 0:
            if(E[i][j]==1)
            printf("A");
            else
            printf("a");
        break;
        case 1:
            if(E[i][j]==1)
            printf("B");
            else
            printf("b");
        break;
        case 2:
            if(E[i][j]==1)
            printf("C");
            else
            printf("c");
        break;
        case 3:
            if(E[i][j]==1)
            printf("D");
            else
            printf("d");
        break;
            }
    if (i<nr-1)
        printf(" + ");
}

for(i=0;i<4;i++){//transformarea functiei in tabel Karnaugh
        switch(i){
            case 0:
            ab=00;
            break;
            case 1:
            ab=01;
            break;
            case 2:
            ab=11;
            break;
            case 3:
            ab=10;
            break;
            }
    for(j=0;j<4;j++){
        switch(j){
            case 0:
            cd=00;
            break;
            case 1:
            cd=01;
            break;
            case 2:
            cd=11;
            break;
            case 3:
            cd=10;
            break;
            }
            abcd=ab*100+cd;
        for(k=0;k<nr;k++){
                if(abcd==E[k][0]*1000+E[k][1]*100+E[k][2]*10+E[k][3])
                TK[i][j]=1;
            }
        }
        }

printf("\n\nTabelul Karnaugh al functiei este:");
    afisaretabel(TK);

int TK2[4][4],ok2,ok3;
ok3=0;

for(i=0;i<4;i++)//initializarea unui tabel ajutator
    for(j=0;j<4;j++)
    if(TK[i][j]==1)
    TK2[i][j]=0;
    else
    TK2[i][j]=2;

printf("\nExpresia booleana simplificata este\nf=");


for(i=0;i<4;i=i+2){//verificcare cate 8 casute alaturate dispuse orizontal, cu i par
    ok=0;
    ok2=1;
    for(k=i;k<i+2;k++){
        for(j=0;j<4;j++){
            if(TK2[k%4][j%4]==2){
                ok2=0;
                break;}
            if(TK2[k%4][j%4]==0)
            ok=1;}
        if(ok2==0)
            break;
        }
    if(ok2==1&&ok==1){
            if(ok3==1)
                printf(" + ");
            ok3=1;
            switch(i){
            case 0:
            printf("a");
            break;
            case 2:
            printf("A");
            break;
            }
            for(k=i;k<i+2;k++)
                for(j=0;j<4;j++)
                TK2[k%4][j%4]=1;
    }
    }

for(i=1;i<4;i=i+2){//verificcare cate 8 casute alaturate dispuse orizontal, cu i impar
    ok=0;
    ok2=1;
    for(k=i;k<i+2;k++){
        for(j=0;j<4;j++){
            if(TK2[k%4][j%4]==2){
                ok2=0;
                break;}
            if(TK2[k%4][j%4]==0)
            ok=1;}
        if(ok2==0)
            break;
        }
    if(ok2==1&&ok==1){
            if(ok3==1)
                printf(" + ");
            ok3=1;
            switch(i){
            case 1:
            printf("B");
            break;
            case 3:
            printf("b");
            break;
            }
            for(k=i;k<i+2;k++)
                for(j=0;j<4;j++)
                TK2[k%4][j%4]=1;
    }
    }

for(i=0;i<4;i=i+2){//verificcare cate 8 casute alaturate dispuse vertical, cu i par
    ok=0;
    ok2=1;
    for(k=i;k<i+2;k++){
        for(j=0;j<4;j++){
            if(TK2[j%4][k%4]==2){
                ok2=0;
                break;}
            if(TK2[j%4][k%4]==0)
            ok=1;}
        if(ok2==0)
            break;
        }
    if(ok2==1&&ok==1){
            if(ok3==1)
                printf(" + ");
            ok3=1;
            switch(i){
            case 0:
            printf("c");
            break;
            case 2:
            printf("C");
            break;
            }
            for(k=i;k<i+2;k++)
                for(j=0;j<4;j++)
                TK2[j%4][k%4]=1;
    }
    }

for(i=1;i<4;i=i+2){//verificcare cate 8 casute alaturate dispuse vertical, cu i impar
    ok=0;
    ok2=1;
    for(k=i;k<i+2;k++){
        for(j=0;j<4;j++){
            if(TK2[j%4][k%4]==2){
                ok2=0;
                break;}
            if(TK2[j%4][k%4]==0)
            ok=1;}
        if(ok2==0)
            break;
        }
    if(ok2==1&&ok==1){
            if(ok3==1)
                printf(" + ");
            ok3=1;
            switch(i){
            case 1:
            printf("D");
            break;
            case 3:
            printf("d");
            break;
            }
            for(k=i;k<i+2;k++)
                for(j=0;j<4;j++)
                TK2[j%4][k%4]=1;
    }
    }

    for(i=0;i<4;i++){//verificare cate 4 casute alaturate puse in forma de patrat, linie para
        for(k=0;k<4;k=k+2){//coloana para
            ok=0;
            ok2=1;
            for(l=i;l<i+2;l++){
                for(j=k;j<k+2;j++){
                    if(TK2[l%4][j%4]==2){
                    ok2=0;
                    break;}
                if(TK2[l%4][j%4]==0)
                ok=1;
                }
            if(ok2==0)
            break;
                }
                if(ok2==1&&ok==1){
            if(ok3==1)
                printf(" + ");
            ok3=1;
            casutepatrat4(i,k);
            for(l=i;l<i+2;l++)
                for(j=k;j<k+2;j++)
                TK2[l%4][j%4]=1;
            }
        }
        for(k=1;k<4;k=k+2){//coloana impara
            ok=0;
            ok2=1;
            for(l=i;l<i+2;l++){
                for(j=k;j<k+2;j++){
                    if(TK2[l%4][j%4]==2){
                    ok2=0;
                    break;}
                if(TK2[l%4][j%4]==0)
                ok=1;
                }
            if(ok2==0)
            break;
                }
                if(ok2==1&&ok==1){
            if(ok3==1)
                printf(" + ");
            ok3=1;
            casutepatrat4(i,k);
            for(l=i;l<i+2;l++)
                for(j=k;j<k+2;j++)
                TK2[l%4][j%4]=1;
            }
        }
    }
    for(i=1;i<4;i++){//verificare cate 4 casute alaturate puse in forma de patrat, linie impara
        for(k=0;k<4;k=k+2){//coloana para
            ok=0;
            ok2=1;
            for(l=i;l<i+2;l++){
                for(j=k;j<k+2;j++){
                    if(TK2[l%4][j%4]==2){
                    ok2=0;
                    break;}
                if(TK2[l%4][j%4]==0)
                ok=1;
                }
            if(ok2==0)
            break;
                }
                if(ok2==1&&ok==1){
            if(ok3==1)
                printf(" + ");
            ok3=1;
            casutepatrat4(i,k);
            for(l=i;l<i+2;l++)
                for(j=k;j<k+2;j++)
                TK2[l%4][j%4]=1;
            }
        }
        for(k=1;k<4;k=k+2){//coloana impara
            ok=0;
            ok2=1;
            for(l=i;l<i+2;l++){
                for(j=k;j<k+2;j++){
                    if(TK2[l%4][j%4]==2){
                    ok2=0;
                    break;}
                if(TK2[l%4][j%4]==0)
                ok=1;
                }
            if(ok2==0)
            break;
                }
                if(ok2==1&&ok==1){
            if(ok3==1)
                printf(" + ");
            ok3=1;
            casutepatrat4(i,k);
            for(l=i;l<i+2;l++)
                for(j=k;j<k+2;j++)
                TK2[l%4][j%4]=1;
            }
        }
    }

for(i=0;i<4;i++){//verificare cate 4 casute alaturate dispuse in linie dreapta, orizontal
    ok=0;
    ok2=1;
        for(j=0;j<4;j++){
            if(TK2[i%4][j%4]==2){
                ok2=0;
                break;}
            if(TK2[i%4][j%4]==0)
            ok=1;}
    if(ok2==1&&ok==1){
            if(ok3==1)
                printf(" + ");
            ok3=1;
            switch(i){
            case 0:
            printf("ab");
            break;
            case 1:
            printf("aB");
            break;
            case 2:
            printf("AB");
            break;
            case 3:
            printf("Ab");
            break;
            }
                for(j=0;j<4;j++)
                TK2[i%4][j%4]=1;
    }
    }

    for(i=0;i<4;i++){//verificare cate 4 casute alaturate dispuse in linie dreapta, vertical
    ok=0;
    ok2=1;
        for(j=0;j<4;j++){
            if(TK2[j%4][i%4]==2){
                ok2=0;
                break;}
            if(TK2[j%4][i%4]==0)
            ok=1;}
    if(ok2==1&&ok==1){
            if(ok3==1)
                printf(" + ");
            ok3=1;
            switch(i){
            case 0:
            printf("cd");
            break;
            case 1:
            printf("cD");
            break;
            case 2:
            printf("CD");
            break;
            case 3:
            printf("Cd");
            break;
            }
                for(j=0;j<4;j++)
                TK2[j%4][i%4]=1;
    }
    }



    for(i=0;i<4;i++){//verificare cate 2 casute alaturate dispuse orizontal
        for(k=0;k<4;k=k+2){//coloana para
            ok=0;
            ok2=1;
                for(j=k;j<k+2;j++){
                    if(TK2[i%4][j%4]==2){
                    ok2=0;
                    break;}
                if(TK2[i%4][j%4]==0)
                ok=1;
                }
                if(ok2==1&&ok==1){
            if(ok3==1)
                printf(" + ");
            ok3=1;
            casuteorizontal2(i,k);
                for(j=k;j<k+2;j++)
                TK2[i%4][j%4]=1;
            }

    }
            for(k=1;k<4;k=k+2){//coloana impara
            ok=0;
            ok2=1;
                for(j=k;j<k+2;j++){
                    if(TK2[i%4][j%4]==2){
                    ok2=0;
                    break;}
                if(TK2[i%4][j%4]==0)
                ok=1;
                }
                if(ok2==1&&ok==1){
            if(ok3==1)
                printf(" + ");
            ok3=1;
            casuteorizontal2(i,k);
                for(j=k;j<k+2;j++)
                TK2[i%4][j%4]=1;
            }

    }
    }

    for(i=0;i<4;i++){//verificare cate 2 casute alaturate dispuse vertical
        for(k=0;k<4;k=k+2){//linie para
            ok=0;
            ok2=1;
                for(j=k;j<k+2;j++){
                    if(TK2[j%4][i%4]==2){
                    ok2=0;
                    break;}
                if(TK2[j%4][i%4]==0)
                ok=1;
                }
                if(ok2==1&&ok==1){
            if(ok3==1)
                printf(" + ");
            ok3=1;
            casutevertical2(k,i);
                for(j=k;j<k+2;j++)
                TK2[j%4][i%4]=1;
            }

    }
            for(k=1;k<4;k=k+2){//linie impara
            ok=0;
            ok2=1;
                for(j=k;j<k+2;j++){
                    if(TK2[j%4][i%4]==2){
                    ok2=0;
                    break;}
                if(TK2[j%4][i%4]==0)
                ok=1;
                }
                if(ok2==1&&ok==1){
            if(ok3==1)
                printf(" + ");
            ok3=1;
            casutevertical2(k,i);
                for(j=k;j<k+2;j++)
                TK2[j%4][i%4]=1;
            }

    }
    }

    for(i=0;i<4;i++)//verificare cate o casuta
        for(j=0;j<4;j++){
        if(TK2[j%4][i%4]==0){
        if(ok3==1)
        printf(" + ");
        ok3=1;
        TK2[j%4][i%4]=1;
        ocasuta(i,j);
        }
        }



return 0;}
