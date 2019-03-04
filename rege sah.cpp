#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int afisareTabel(int tabla[8][8]);
int gasireRege(int tabla[8][8],int *pozVertical, int* pozOrizontal);
int backtrackingRege(int tabla[8][8],int pozVertical, int pozOrizontal, int contor);
int verificareRege(int tabla[8][8],int pozVertical, int pozOrizontal, int *pozNouV, int*pozNouO);

int gasireRege(int tabla[8][8],int *pozVertical, int* pozOrizontal){
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(tabla[i][j]==1){
                *pozVertical=i;
                *pozOrizontal=j;
                return 1;
            }

return 0;}


int verificareRege(int tabla[8][8],int pozVertical, int pozOrizontal, int *pozNouV, int*pozNouO){
    for(int i=pozVertical-1;i<pozVertical+2;i++)
        for(int j=pozOrizontal-1;j<pozOrizontal+2;j++)
        if((i!=pozVertical||j!=pozOrizontal)&&i>=0&&i<9&&j>=0&&j<9){
            if(tabla[i][j]==0)
            *pozNouV=i;
            *pozNouO=j;
            return 1;}
return 0;
}

int wrapperBacktrackingRege(int tabla[8][8], int pozVertical, int pozOrizontal){
    backtrackingRege(tabla,pozVertical,pozOrizontal,64);
}

int backtrackingRege(int tabla[8][8],int pozVertical, int pozOrizontal, int contor){
    if(contor==0)
        return 1;
    //int poz2V, poz2O;

    tabla[pozVertical][pozOrizontal]=65-contor;
    printf("\n");
    afisareTabel(tabla);
    for(int i=pozVertical-1;i<pozVertical+2;i++)
    for(int j=pozOrizontal-1;j<pozOrizontal+2;j++){
        //printf("\n%d,%d",i,j);
    if((i!=pozVertical||j!=pozOrizontal)&&i>=0&&i<8&&j>=0&&j<8)
        if(tabla[i][j]==0)
            if(!backtrackingRege(tabla, i, j, contor-1))
                tabla[i][j]=0;
            else
            return 1;
            }


    return 0;}

int afisareTabel(int tabla[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)
            printf("%6d ",tabla[i][j]);
        printf("\n");
        }

    return 0;
}

int main(){
    int tabla2[8][8],tabla[8][8]={{0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {1,0,0,0,0,0,0,0}};

    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            tabla2[i][j]=0;

    int pozVertical,pozOrizontal;

    if(gasireRege(tabla,&pozVertical,&pozOrizontal)==0)
        printf("Nu exista regele pe tabla de sah");
    else{
        wrapperBacktrackingRege(tabla2,pozVertical,pozOrizontal);
        printf("\n");
        afisareTabel(tabla2);
    }




return 0;}
