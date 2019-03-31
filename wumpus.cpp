#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<time.h>

using namespace std;

void afisareTabel(int harta[12][12], int dimV, int dimO){
    for(int i=0;i<dimV;i++){
        for(int j=0;j<dimO;j++)
            switch(harta[i][j]){
                case 0:
                    cout<<"  ";
                    break;
                case 1:
                    cout<<"# ";
                    break;
                case 2:
                    cout<<"$ ";
                    break;
                case 3:
                    cout<<"W ";
                    break;
                case 4:
                    cout<<"^ ";
                    break;
                case 5:
                    cout<<"> ";
                    break;
                case 6:
                    cout<<"V ";
                    break;
                case 7:
                    cout<<"< ";
                    break;
            }
        cout<<endl;
        }


}

void gasireExplorator(int &y, int &x, int harta[12][12], int dimV, int dimO){
    int gasit=0;
    for(int i=0;i<dimV&&gasit==0;i++)
        for(int j=0;j<dimO&&gasit==0;j++)
        if(harta[i][j]>3){
            y=i;
            x=j;
            gasit=1;
            }
}

int numarareComori(int harta[12][12],int dimV, int dimO){
    int nrComori=0;
    for(int i=0;i<dimV;i++)
        for(int j=0;j<dimO;j++)
        if(harta[i][j]==2){
            nrComori++;
            }
    return nrComori;
}

void gasireInFata(int harta[12][12], int x, int y, int &xFata, int &yFata, int &inFata, int dimV, int dimO){
    switch(harta[y][x]){
        case 4:
            yFata=y-1;
            xFata=x;
            if(yFata<0)
                inFata=1;
            else
                inFata=harta[yFata][xFata];
            break;
        case 5:
            yFata=y;
            xFata=x+1;
            if(xFata>=dimO)
                inFata=1;
            else
                inFata=harta[yFata][xFata];
            break;
        case 6:
            yFata=y+1;
            xFata=x;
            if(yFata>=dimO)
                inFata=1;
            else
                inFata=harta[yFata][xFata];
            break;
        case 7:
            yFata=y;
            xFata=x-1;
            if(xFata<0)
                inFata=1;
            else
                inFata=harta[yFata][xFata];
            break;
    }
}


int jocWumpus(int harta[12][12], int dimV, int dimO){

    int y,x,nrComori=numarareComori(harta,dimV,dimO),scor=0,inFata,xFata,yFata,decizie,temp;
    srand(time(0));
    gasireExplorator(y,x,harta,dimV,dimO);
    int oprire=0;

    afisareTabel(harta,dimV,dimO);
    cout<<"Scor="<<scor<<endl<<endl;
    getch();

    while(nrComori>0&&oprire==0){
        gasireInFata(harta,x,y,xFata,yFata,inFata,dimV,dimO);
            switch(inFata){
                case 0:
                    decizie=rand()%101;
                    if(decizie<80){
                        harta[yFata][xFata]=harta[y][x];
                        harta[y][x]=0;
                        x=xFata;
                        y=yFata;
                        }
                        else
                            if(decizie>=80&&decizie<90){
                                temp=(harta[y][x]-4-1)+4;
                                if(temp<4)
                                    temp=temp+4;
                                if(temp>7)
                                    temp=temp-4;
                                harta[y][x]=temp;}
                            else
                                if(decizie>=90&&decizie<100){
                                    temp=(harta[y][x]-4+1)+4;
                                    if(temp<4)
                                        temp=temp+4;
                                    if(temp>7)
                                    temp=temp-4;
                                    harta[y][x]=temp;}
                               // else
                                    //if(decizie==100)
                                      //  oprire=1;
                    scor--;
                    break;
                case 1:
                    decizie=rand()%100;
                    if(decizie<50){
                        temp=(harta[y][x]-4-1)+4;
                        if(temp<4)
                            temp=temp+4;
                        if(temp>7)
                            temp=temp-4;
                        harta[y][x]=temp;}
                        else
                            if(decizie>=50&&decizie<100){
                                    temp=(harta[y][x]-4+1)+4;
                                    if(temp<4)
                                        temp=temp+4;
                                    if(temp>7)
                                    temp=temp-4;
                                    harta[y][x]=temp;}
                            //else
                              //  if(decizie==100)
                                //    oprire=1;
                    scor--;
                    break;
                case 2:
                    harta[yFata][xFata]=harta[y][x];
                    harta[y][x]=0;
                    x=xFata;
                    y=yFata;
                    scor--;
                    scor=scor+100;
                    nrComori--;
                    break;
                case 3:
                    harta[yFata][xFata]=0;
                    scor=scor-25;
                    scor=scor+50;
                    break;
            }
    afisareTabel(harta,dimV,dimO);
    cout<<"Scor="<<scor<<endl<<endl;
    getch();
    }





}


int main(){

    int dimV=12,dimO=12;

    int harta[12][12]={{0,0,0,0,0,0,0,0,0,0,0,0},
                       {0,1,0,0,1,0,0,3,0,0,2,0},
                       {0,1,2,0,1,0,0,0,0,1,0,0},
                       {0,1,0,0,1,0,1,1,0,1,0,0},
                       {0,1,1,1,1,0,0,0,0,1,0,0},
                       {0,1,0,0,0,0,0,0,0,1,0,3},
                       {0,1,0,0,0,0,0,0,0,1,0,0},
                       {0,1,0,0,0,0,0,0,0,0,0,0},
                       {0,1,0,0,0,0,0,1,1,1,1,0},
                       {0,1,0,0,0,0,0,0,0,0,0,0},
                       {0,0,0,1,1,1,1,0,2,0,0,0},
                       {4,0,0,0,0,3,0,0,0,0,0,0},};

    jocWumpus(harta,dimV,dimO);


    getch();


return 0;}
