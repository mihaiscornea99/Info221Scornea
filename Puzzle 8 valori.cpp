#include<iostream>
#include<iomanip>
#include<math.h>
#include<conio.h>

using namespace std;

//TRASH / EXPERIMENT ZONE
/*
int*** alocare(int pasi){
    int ***traseu;
    traseu=new int**[pasi];

    for(int i=0;i<3;i++){
        traseu[i]=new int*[3];
        for(int j=0;j<3;j++)
            traseu[i][j]=new int[3];
    }
    return traseu;
}



void integrare(int &nr, int prioritate[4][4],int mutare, int scorMutare, int x, int y){
    int poz=0;
    while(poz<nr&&prioritate[poz][1]>scorMutare)
        poz++;

        for(int i=nr;i>poz;i--){
            prioritate[i][0]=prioritate[i-1][0];
            prioritate[i][1]=prioritate[i-1][1];
            prioritate[i][2]=prioritate[i-1][2];
            prioritate[i][3]=prioritate[i-1][3];
        }

    prioritate[poz][0]=mutare;
    prioritate[poz][1]=scorMutare;
    prioritate[poz][2]=x;
    prioritate[poz][3]=y;
    nr++;
}

void verificareCasuteH1(int puzzle[3][3], int x, int y, int prioritate[4][4],int &nr,int puzzleRezolvat[3][3]){
    if(y-1>=0){
        puzzle[y][x]=puzzle[y-1][x];
        puzzle[y-1][x]=-1;
        integrare(nr,prioritate,0,calculareScorH1(puzzle,puzzleRezolvat),x,y-1);
        puzzle[y-1][x]=puzzle[y][x];
        puzzle[y][x]=-1;
    }
    else
        integrare(nr,prioritate,-1,0,0,0);

    if(x+1<3){
        puzzle[y][x]=puzzle[y][x+1];
        puzzle[y][x+1]=-1;
        integrare(nr,prioritate,1,calculareScorH1(puzzle,puzzleRezolvat),x+1,y);
        puzzle[y][x+1]=puzzle[y][x];
        puzzle[y][x]=-1;
    }
    else
        integrare(nr,prioritate,-1,0,0,0);

    if(y+1<3){
        puzzle[y][x]=puzzle[y+1][x];
        puzzle[y+1][x]=-1;
        integrare(nr,prioritate,2,calculareScorH1(puzzle,puzzleRezolvat),x,y+1);
        puzzle[y+1][x]=puzzle[y][x];
        puzzle[y][x]=-1;
    }
    else
        integrare(nr,prioritate,-1,0,0,0);

    if(x-1>=0){
        puzzle[y][x]=puzzle[y][x-1];
        puzzle[y][x-1]=-1;
        integrare(nr,prioritate,3,calculareScorH1(puzzle,puzzleRezolvat),x-1,y);
        puzzle[y][x-1]=puzzle[y][x];
        puzzle[y][x]=-1;
    }
    else
        integrare(nr,prioritate,-1,0,0,0);


}



int PuzzleGreedyH1(int puzzle[3][3], int ***traseu, int x, int y, int &gasit,int &contorTraseu,int contorTemp,int puzzleRezolvat[3][3],int mutarecurenta){

   for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<puzzle[i][j]<<" ";
        cout<<endl;
        }
        cout<<endl;

    //getch();



    int ver=1;
    for(int i=0;i<3&&ver==1;i++)
        for(int j=0;j<3&&ver==1;j++)
            if(puzzle[i][j]!=puzzleRezolvat[i][j])
            ver=0;
    if(ver==1){
        contorTraseu=contorTemp;
        //traseu=alocare(contorTraseu);
        gasit=1;
        return 0;
    }

    int prioritate[4][4],nr=0;
    verificareCasuteH1(puzzle,x,y,prioritate,nr,puzzleRezolvat);

    for(int i=0;i<nr&&gasit==0;i++){
            if(mutarecurenta!=(prioritate[i][0]+2)%4&&prioritate[i][0]>=0){
        cout<<endl<<prioritate[i][3]<<" "<<prioritate[i][2]<<endl;
        puzzle[y][x]=puzzle[prioritate[i][3]][prioritate[i][2]];
        puzzle[prioritate[i][3]][prioritate[i][2]]=-1;
        PuzzleGreedyH1(puzzle,traseu,prioritate[i][2],prioritate[i][3],gasit,contorTraseu,contorTemp+1,puzzleRezolvat,prioritate[i][0]);
        //if(gasit==1){
            //for(int j=0;j<3;j++)
              //  for(int k=0;k<3;k++)
                //    traseu[contorTemp][j][k]=puzzle[j][k];
        //}
        if(gasit!=1){
        puzzle[prioritate[i][3]][prioritate[i][2]]=puzzle[y][x];
        puzzle[y][x]=-1;}
    }}


return 0;}

void wrapperPuzzleGreedy(int puzzle[3][3]){
    int puzzleRezolvat[3][3]={{1,2,3},
                            {4,5,6},
                            {7,8,-1}};

    int gasit=0,contorTraseu=0,***traseu,x,y;

    gasireGol(puzzle,x,y);
    PuzzleGreedyH1(puzzle,traseu,x,y,gasit,contorTraseu,0,puzzleRezolvat,-1);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<puzzle[i][j]<<" ";
        cout<<endl;
        }

}

*/
//END OF TRASH / EXPERIMENT ZONE

//ZONA PUZZLE VERIFICAT CU FUNCTIA EURISTICA H1
void gasireGol(int puzzle[3][3], int &x, int &y){
    int ok=0;
    for(int i=0;i<3&&ok==0;i++)
        for(int j=0;j<3&&ok==0;j++)
            if(puzzle[i][j]==-1){
                ok=1;
                y=i;
                x=j;
            }
}


int calculareScorH1(int puzzle[3][3],int puzzleRezolvat[3][3]){
    int scor=0;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(puzzle[i][j]==puzzleRezolvat[i][j])
                scor++;

    return scor;
}

int comparareTabele(int puzzle[3][3], int puzzle2[3][3]){
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
    if(puzzle[i][j]!=puzzle2[i][j])
        return 0;
    return 1;
}

void integrareEuristic(int &nr,int puzzle[3][3],int scoruri[500],int asteptare[500][3][3],int scorMutare,int parinteTemp, int parinteAsteptare[500]){

int poz=0;
    while(poz<nr&&scoruri[poz]>scorMutare)
        poz++;

        for(int i=nr;i>poz;i--){
            for(int j=0;j<3;j++)
                for(int k=0;k<3;k++)
                   asteptare[i][j][k]=asteptare[i-1][j][k];
            scoruri[i]=scoruri[i-1];
            parinteAsteptare[i]=parinteAsteptare[i-1];
        }
    for(int j=0;j<3;j++)
        for(int k=0;k<3;k++)
            asteptare[poz][j][k]=puzzle[j][k];
    scoruri[poz]=scorMutare;
    parinteAsteptare[poz]=parinteTemp;
    if(nr<499)
    nr++;

}

void verificareCasuteEuristic(int puzzle[3][3], int asteptare[500][3][3],int &nr,int puzzleRezolvat[3][3],int scoruri[500],int vizitati[500][3][3], int nrViz,int parinteTemp,int parinteAsteptare[500]){
    int ok=0,x,y;
    gasireGol(puzzle,x,y);

    //cout<<x<<" "<<y<<endl;
    if(y-1>=0){

        //cout<<"test 1"<<endl;

        puzzle[y][x]=puzzle[y-1][x];
        puzzle[y-1][x]=-1;
        for(int i=0;i<nrViz;i++){
            if(ok==0)
            ok=comparareTabele(puzzle,vizitati[i]);}
        if(ok==0)
        integrareEuristic(nr,puzzle,scoruri,asteptare,calculareScorH1(puzzle,puzzleRezolvat),parinteTemp,parinteAsteptare);
        puzzle[y-1][x]=puzzle[y][x];
        puzzle[y][x]=-1;
    }
    ok=0;
    if(x+1<3){
        //cout<<"test 2"<<endl;
        puzzle[y][x]=puzzle[y][x+1];
        puzzle[y][x+1]=-1;
        for(int i=0;i<nrViz;i++){
            if(ok==0)
            ok=comparareTabele(puzzle,vizitati[i]);}
        if(ok==0)
        integrareEuristic(nr,puzzle,scoruri,asteptare,calculareScorH1(puzzle,puzzleRezolvat),parinteTemp,parinteAsteptare);
        puzzle[y][x+1]=puzzle[y][x];
        puzzle[y][x]=-1;
    }
    ok=0;
    if(y+1<3){
        //cout<<"test 3"<<endl;
        puzzle[y][x]=puzzle[y+1][x];
        puzzle[y+1][x]=-1;
        for(int i=0;i<nrViz;i++){
            if(ok==0)
            ok=comparareTabele(puzzle,vizitati[i]);}
        if(ok==0)
        integrareEuristic(nr,puzzle,scoruri,asteptare,calculareScorH1(puzzle,puzzleRezolvat),parinteTemp,parinteAsteptare);
        puzzle[y+1][x]=puzzle[y][x];
        puzzle[y][x]=-1;
    }
    ok=0;
    if(x-1>=0){
        //cout<<"test 4"<<endl;
        puzzle[y][x]=puzzle[y][x-1];
        puzzle[y][x-1]=-1;
        for(int i=0;i<nrViz;i++){
            if(ok==0)
            ok=comparareTabele(puzzle,vizitati[i]);}
        if(ok==0)
        integrareEuristic(nr,puzzle,scoruri,asteptare,calculareScorH1(puzzle,puzzleRezolvat),parinteTemp,parinteAsteptare);
        puzzle[y][x-1]=puzzle[y][x];
        puzzle[y][x]=-1;
    }

}


int verificareRezolvabilitate(int puzzle[3][3]){
    int numere[9],inversiuni=0,k=0;;
    for(int i=0;i<9;i++)
        if(puzzle[i/3][i%3]!=-1)
        numere[k++]=puzzle[i/3][i%3];
    for(int i=0;i<8;i++)
        for(int j=i+1;j<8;j++)
            if(numere[i]>numere[j])
                inversiuni++;

    if(inversiuni%2==0)
        return 1;
    else
        return 0;
}

void PuzzleEuristicH1(int puzzle[3][3]){

    if(verificareRezolvabilitate(puzzle)){
    int puzzleRezolvat[3][3]={{1,2,3},
                            {4,5,6},
                            {7,8,-1}};

    int asteptare[500][3][3],nr=1,nrViz=0,vizitati[500][3][3],gasit=0,scoruri[500],traseu[500];
    int parinte[500],parinteAsteptare[500],parinteTemp=0;
    parinteAsteptare[0]=0;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            asteptare[0][i][j]=puzzle[i][j];
    scoruri[0]=calculareScorH1(puzzle,puzzleRezolvat);

    int nod[3][3];
    while(gasit==0&&nr>0){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                nod[i][j]=asteptare[0][i][j];
                vizitati[nrViz][i][j]=asteptare[0][i][j];
            }
        parinte[nrViz]=parinteAsteptare[0];
        nr--;

        for(int i=0;i<nr;i++){
            for(int j=0;j<3;j++)
                for(int k=0;k<3;k++)
                    asteptare[i][j][k]=asteptare[i+1][j][k];
            parinteAsteptare[i]=parinteAsteptare[i+1];
            scoruri[i]=scoruri[i+1];
            }


        parinteTemp=nrViz;

        verificareCasuteEuristic(nod, asteptare, nr, puzzleRezolvat,scoruri,vizitati,nrViz,parinteTemp,parinteAsteptare);
        nrViz++;


        //getch();
        /*/debugging
        for(int i=0;i<nr;i++){
            cout<<parinteAsteptare[i]<<" ";
        }
        cout<<endl;
        //debugging*/

        /*/debugging
        for(int i=0;i<nr;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++)
                    cout<<asteptare[i][j][k]<<" ";
                cout<<endl;
                    }
                cout<<endl;
            }
            cout<<endl;
        //debugging*/

        /*/debugging
        for(int i=0;i<1;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++)
                    cout<<vizitati[i][j][k]<<" ";
                cout<<endl;
                    }
                cout<<endl;
            }
            cout<<endl<<endl;
        //debugging*/

        if(comparareTabele(nod,puzzleRezolvat))
            gasit=1;
    }

        int pozGasit=0;

        for(int i=0;i<nrViz;i++){
            if(comparareTabele(nod,vizitati[i]))
            pozGasit=i;
            }
            int contorTraseu=0;
            while(pozGasit!=0){
                traseu[contorTraseu++]=pozGasit;
                pozGasit=parinte[pozGasit];
            }


    //cout<<endl<<pozGasit<<endl;

    /*
    for(int i=0;i<400;i++)
        cout<<parinte[i]<<" ";
    cout<<endl;
    */

    /*
    for(int i=0;i<contorTraseu;i++)
        cout<<traseu[i]<<" ";
    cout<<endl;
    */
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(puzzle[i][j]==-1)
            cout<<"  ";
            else
            cout<<puzzle[i][j]<<" ";
            }
        cout<<endl;
        }
        cout<<endl;


    for(int i=contorTraseu-1;i>=0;i--){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(vizitati[traseu[i]][j][k]==-1)
            cout<<"  ";
            else
                cout<<vizitati[traseu[i]][j][k]<<" ";
                }
            cout<<endl;
            }
            cout<<endl;
    }
    cout<<endl<<contorTraseu<<" mutari folosind H1"<<endl<<endl;
/*
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<nod[i][j]<<" ";
        cout<<endl;
        }
*/
    }
    else
        cout<<"Puzzle-ul nu poate fi rezolvat"<<endl;

}
//INCHEIERE ZONA PUZZLE VERIFICAT CU FUNCTIA EURISTICA H1

//ZONA PUZZLE VERIFICAT CU FUNCTIA EURISTICA H2

void integrareEuristicH2(int &nr,int puzzle[3][3],int scoruri[500],int asteptare[500][3][3],int scorMutare,int parinteTemp, int parinteAsteptare[500]){

int poz=0;
    while(poz<nr&&scoruri[poz]<scorMutare)
        poz++;

        for(int i=nr;i>poz;i--){
            for(int j=0;j<3;j++)
                for(int k=0;k<3;k++)
                   asteptare[i][j][k]=asteptare[i-1][j][k];
            scoruri[i]=scoruri[i-1];
            parinteAsteptare[i]=parinteAsteptare[i-1];
        }
    for(int j=0;j<3;j++)
        for(int k=0;k<3;k++)
            asteptare[poz][j][k]=puzzle[j][k];
    scoruri[poz]=scorMutare;
    parinteAsteptare[poz]=parinteTemp;
    if(nr<499)
    nr++;

}

int calculareScorH2(int puzzle[3][3],int puzzleRezolvat[3][3]){
    int scor=0;
    int pozX,pozY;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                for(int l=0;l<3;l++)
                    if(puzzle[i][j]==puzzleRezolvat[k][l])
                        scor=scor+abs(i-k)+abs(j-l);

    return scor;
}

void verificareCasuteEuristicH2(int puzzle[3][3], int asteptare[500][3][3],int &nr,int puzzleRezolvat[3][3],int scoruri[500],int vizitati[500][3][3], int nrViz,int parinteTemp,int parinteAsteptare[500]){
    int ok=0,x,y;
    gasireGol(puzzle,x,y);

    //cout<<x<<" "<<y<<endl;
    if(y-1>=0){

        //cout<<"test 1"<<endl;

        puzzle[y][x]=puzzle[y-1][x];
        puzzle[y-1][x]=-1;
        for(int i=0;i<nrViz;i++){
            if(ok==0)
            ok=comparareTabele(puzzle,vizitati[i]);}
        if(ok==0)
        integrareEuristicH2(nr,puzzle,scoruri,asteptare,calculareScorH2(puzzle,puzzleRezolvat),parinteTemp,parinteAsteptare);
        puzzle[y-1][x]=puzzle[y][x];
        puzzle[y][x]=-1;
    }
    ok=0;
    if(x+1<3){
        //cout<<"test 2"<<endl;
        puzzle[y][x]=puzzle[y][x+1];
        puzzle[y][x+1]=-1;
        for(int i=0;i<nrViz;i++){
            if(ok==0)
            ok=comparareTabele(puzzle,vizitati[i]);}
        if(ok==0)
        integrareEuristicH2(nr,puzzle,scoruri,asteptare,calculareScorH2(puzzle,puzzleRezolvat),parinteTemp,parinteAsteptare);
        puzzle[y][x+1]=puzzle[y][x];
        puzzle[y][x]=-1;
    }
    ok=0;
    if(y+1<3){
        //cout<<"test 3"<<endl;
        puzzle[y][x]=puzzle[y+1][x];
        puzzle[y+1][x]=-1;
        for(int i=0;i<nrViz;i++){
            if(ok==0)
            ok=comparareTabele(puzzle,vizitati[i]);}
        if(ok==0)
        integrareEuristicH2(nr,puzzle,scoruri,asteptare,calculareScorH2(puzzle,puzzleRezolvat),parinteTemp,parinteAsteptare);
        puzzle[y+1][x]=puzzle[y][x];
        puzzle[y][x]=-1;
    }
    ok=0;
    if(x-1>=0){
        //cout<<"test 4"<<endl;
        puzzle[y][x]=puzzle[y][x-1];
        puzzle[y][x-1]=-1;
        for(int i=0;i<nrViz;i++){
            if(ok==0)
            ok=comparareTabele(puzzle,vizitati[i]);}
        if(ok==0)
        integrareEuristicH2(nr,puzzle,scoruri,asteptare,calculareScorH2(puzzle,puzzleRezolvat),parinteTemp,parinteAsteptare);
        puzzle[y][x-1]=puzzle[y][x];
        puzzle[y][x]=-1;
    }

}


void PuzzleEuristicH2(int puzzle[3][3]){

    if(verificareRezolvabilitate(puzzle)){
    int puzzleRezolvat[3][3]={{1,2,3},
                            {4,5,6},
                            {7,8,-1}};

    int asteptare[500][3][3],nr=1,nrViz=0,vizitati[500][3][3],gasit=0,scoruri[500],traseu[500];
    int parinte[500],parinteAsteptare[500],parinteTemp=0;
    parinteAsteptare[0]=0;

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            asteptare[0][i][j]=puzzle[i][j];
    scoruri[0]=calculareScorH2(puzzle,puzzleRezolvat);

    int nod[3][3];
    while(gasit==0&&nr>0){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                nod[i][j]=asteptare[0][i][j];
                vizitati[nrViz][i][j]=asteptare[0][i][j];
            }
        parinte[nrViz]=parinteAsteptare[0];
        nr--;

        for(int i=0;i<nr;i++){
            for(int j=0;j<3;j++)
                for(int k=0;k<3;k++)
                    asteptare[i][j][k]=asteptare[i+1][j][k];
            parinteAsteptare[i]=parinteAsteptare[i+1];
            scoruri[i]=scoruri[i+1];
            }


        parinteTemp=nrViz;

        verificareCasuteEuristicH2(nod, asteptare, nr, puzzleRezolvat,scoruri,vizitati,nrViz,parinteTemp,parinteAsteptare);
        nrViz++;


        //getch();
        /*/debugging
        for(int i=0;i<nr;i++){
            cout<<parinteAsteptare[i]<<" ";
        }
        cout<<endl;
        //debugging*/

        /*/debugging
        for(int i=0;i<nr;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++)
                    cout<<asteptare[i][j][k]<<" ";
                cout<<endl;
                    }
                cout<<endl;
            }
            cout<<endl;
        //debugging*/

        /*/debugging
        for(int i=0;i<1;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++)
                    cout<<vizitati[i][j][k]<<" ";
                cout<<endl;
                    }
                cout<<endl;
            }
            cout<<endl<<endl;
        //debugging*/

        if(comparareTabele(nod,puzzleRezolvat))
            gasit=1;
    }

        int pozGasit=0;

        for(int i=0;i<nrViz;i++){
            if(comparareTabele(nod,vizitati[i]))
            pozGasit=i;
            }
            int contorTraseu=0;
            while(pozGasit!=0){
                traseu[contorTraseu++]=pozGasit;
                pozGasit=parinte[pozGasit];
            }


    //cout<<endl<<pozGasit<<endl;

    /*
    for(int i=0;i<400;i++)
        cout<<parinte[i]<<" ";
    cout<<endl;
    */

    /*
    for(int i=0;i<contorTraseu;i++)
        cout<<traseu[i]<<" ";
    cout<<endl;
    */
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(puzzle[i][j]==-1)
            cout<<"  ";
            else
            cout<<puzzle[i][j]<<" ";
            }
        cout<<endl;
        }
        cout<<endl;


    for(int i=contorTraseu-1;i>=0;i--){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if(vizitati[traseu[i]][j][k]==-1)
            cout<<"  ";
            else
                cout<<vizitati[traseu[i]][j][k]<<" ";
                }
            cout<<endl;
            }
            cout<<endl;
    }
    cout<<endl<<contorTraseu<<" mutari folosind H2"<<endl<<endl;
/*
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            cout<<nod[i][j]<<" ";
        cout<<endl;
        }
*/
    }
    else
        cout<<"Puzzle-ul nu poate fi rezolvat"<<endl;

}

//INCHEIERE ZONA PUZZLE VERIFICAT CU FUNCTIA EURISTICA H2

int main(){
    int puzzle[3][3]={{-1,2,3},
                      {1,4,6},
                      {8,7,5}};


    PuzzleEuristicH1(puzzle);
    getch();
    PuzzleEuristicH2(puzzle);
    //wrapperPuzzleGreedy(puzzle);



return 0;
}
/*

{{8,6,7},
                      {2,5,4},
                      {3,-1,1}};

{{8,-1,6},
                      {5,4,7},
                      {2,3,1}};


{{-1,2,3},
                      {1,4,6},
                      {8,7,5}};

{{1,2,3},
                      {4,5,6},
                      {7,-1,8}}


{{-1,2,3},
                      {1,4,6},
                      {8,7,5}};*/
