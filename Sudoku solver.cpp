#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int verificareLinieColoanaCasuta(int tabla[9][9],int pozVertical, int pozOrizontal, int numar);
int gasireCasutaGoala(int tabla[9][9],int*pozVertical,int*pozOrizontal);
int sudokuBacktracking(int tabla[9][9]);
int afisaretabel(int tabla[9][9]);

int verificareLinieColoanaCasuta(int tabla[9][9],int pozVertical, int pozOrizontal, int numar){//functia verifica daca acelasi numar este prezent in
                                                                                    //aceeasi linie/coloana/casuta de 3x3 cu el insusi
        int ok=1;
    for(int i=0;i<9&&ok==1;i++)
        if(i!=pozOrizontal&&tabla[pozVertical][i]==numar)//verificare linie
            ok=0;
    for(int i=0;i<9&&ok==1;i++)
        if(i!=pozVertical&&tabla[i][pozOrizontal]==numar)//verificare coloana
            ok=0;
    for(int i=(pozVertical/3)*3;i<(pozVertical/3+1)*3&&ok==1;i++)//verificarea casutei in care se afla numarul
        for(int j=(pozOrizontal/3)*3;j<(pozOrizontal/3+1)*3&&ok==1;j++)
            if(i!=pozVertical&&j!=pozOrizontal&&tabla[i][j]==numar)
            ok=0;
    return ok;
}

int gasireCasutaGoala(int tabla[9][9],int*pozVertical,int*pozOrizontal){//scaneaza toata matricea pana
    for(int i=0;i<9;i++)                                                //gaseste o casuta care sa fie 0, apoi
        for(int j=0;j<9;j++)                                            //returneaza prin pointeri locatia acesteia.
            if(tabla[i][j]==0){                     //De asemenea, o folosesc ca si conditie
                *pozVertical=i;                     //de oprire, functia returnand 0 in cazul in care sunt
                *pozOrizontal=j;                    //toate casutele ocupate
                return 1;
        }
    return 0;
}

int sudokuBacktracking(int tabla[9][9]){//backtracking asemanator cu cel de la harta cu culori
    int pozVertical,pozOrizontal;
    if(!gasireCasutaGoala(tabla,&pozVertical,&pozOrizontal))
        return 1;//conditia de oprire
    for(int i=1;i<=9;i++){//parcurge numerele de la 1 la 9, punandu-le in prima casuta libera

        if(verificareLinieColoanaCasuta(tabla,pozVertical,pozOrizontal,i)){
            tabla[pozVertical][pozOrizontal]=i;
            if(sudokuBacktracking(tabla))//reapelarea functiei
                return 1;
            tabla[pozVertical][pozOrizontal]=0;//anularea modificarii casutei in cazul in care nu se gaseste solutia
            }
            }
    return 0;//intoarcerea la pasul anterior in cazul in care nu se gaseste solutia
}

int afisaretabel(int tabla[9][9]){

        for(int i=0;i<9;i++){
        if(i==0){
            printf("-------------------------\n");
        }
        for(int j=0;j<9;j++){
            if(j==6||j==3||j==0)
                printf("| ");
            printf("%d ",tabla[i][j]);
            if(j==8)
                printf("|");
            }
        if(i==2||i==5||i==8){
        printf("\n-------------------------");
    }
    printf("\n");
    }

return 0;}

int main(){
    int tabla[9][9]={{9,8,0,7,0,0,0,0,0},
                     {6,0,0,0,0,0,9,7,0},
                     {0,0,7,0,0,0,0,0,5},
                     {0,4,0,0,3,0,0,0,0},
                     {0,0,6,5,0,0,0,9,0},
                     {0,0,0,0,0,2,0,0,1},
                     {0,0,8,6,0,0,0,5,0},
                     {0,0,0,0,1,0,3,0,0},
                     {5,0,0,0,0,4,0,0,2}};


    printf("Tabelul sudoku este:\n");//afisare tabel initial
    afisaretabel(tabla);

    sudokuBacktracking(tabla);//rezolvare tabel

    printf("Solutia este:\n");//afisare solutie
    afisaretabel(tabla);

    getch();
    return 0;

    }





/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TEST AREA~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{{0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0,0}};

{{9,8,0,7,0,0,0,0,0},
                     {6,0,0,0,0,0,9,7,0},
                     {0,0,7,0,0,0,0,0,5},
                     {0,4,0,0,3,0,0,0,0},
                     {0,0,6,5,0,0,0,9,0},
                     {0,0,0,0,0,2,0,0,1},
                     {0,0,8,6,0,0,0,5,0},
                     {0,0,0,0,1,0,3,0,0},
                     {5,0,0,0,0,4,0,0,2}};
un tabel sudoku luat de pe internet (pentru teste), solutia este:
982 753 416
653 421 978
417 968 235

849 136 527
126 547 893
375 892 641

238 679 154
764 215 389
591 384 762

            //debugging
            printf("\n");
    for(int j=0;j<9;j++){
        for(int k=0;k<9;k++)
        printf("%d ",tabla[j][k]);
    printf("\n");
    }
    printf("\n");
    //debugging




/
    //printf("%d",verificareLinieColoanaCasuta(tabla,1,6));
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~TEST AREA END~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
