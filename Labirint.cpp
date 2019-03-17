#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;

int afisareLabirint(char labirint[6][6], int dimV, int dimO){
    for(int i=0;i<dimV;i++){
        for(int j=0;j<dimO;j++)
        cout<<labirint[i][j]<<" ";
    cout<<endl;
    }
    return 0;
}

int verificareCasuta(char labirint[6][6],int pozV,int pozO,int dimV, int dimO){//verifica daca o casuta se afla in labirint si daca aceasta nu este zid
    if(pozV>=0&&pozV<dimV&&pozO>=0&&pozO<dimO&&(labirint[pozV][pozO]=='0'||labirint[pozV][pozO]=='2'||labirint[pozV][pozO]=='3'))
        return 1;
    return 0;
}

int verificareVecinatate(int i,int j,int dimO){//Verifica daca 2 casute sunt vecine
    if((i/dimO==(j/dimO-1)&&(i%dimO==j%dimO))||(i/dimO==(j/dimO+1)&&(i%dimO==j%dimO))||(i/dimO==j/dimO&&(i%dimO==(j%dimO-1)))||(i/dimO==j/dimO&&(i%dimO==(j%dimO+1))))
       return 1;
    return 0;
}


int formareMatriceAdiacenta(int adiacenta[36][36],char labirint[6][6],int dimV, int dimO){

    for(int i=0;i<dimV*dimO;i++)
        for(int j=0;j<dimV*dimO;j++)
        adiacenta[i][j]=0;

    for(int i=0;i<dimV*dimO;i++)
        for(int j=0;j<dimV*dimO;j++){
            if(verificareCasuta(labirint,i/dimO,i%dimO,dimV,dimO)&&verificareCasuta(labirint,j/dimO,j%dimO,dimV,dimO))
                if(verificareVecinatate(i,j,dimO))
                    adiacenta[i][j]=1;
        }



    return 0;
}

int gasireStart(char labirint[6][6], int dimV, int dimO){
    for(int i=0;i<dimV;i++)
        for(int j=0;j<dimO;j++)
            if(labirint[i][j]=='2')
                return (i*dimO+j);
    cout<<"Nu s-a gasit punctul de start.";
    getch();
    exit(0);
    return 0;
}

int gasireStop(char labirint[6][6], int dimV, int dimO){
    for(int i=0;i<dimV;i++)
        for(int j=0;j<dimO;j++)
            if(labirint[i][j]=='3')
                return (i*dimO+j);
    cout<<"Nu s-a gasit punctul de stop.";
    getch();
    exit(0);
    return 0;
}

int cautareLatime(int adiacenta[36][36], char labirint[6][6], int dimV, int dimO){
    int start=gasireStart(labirint,dimV,dimO),stop=gasireStop(labirint,dimV,dimO),parinte[36];
    int noduri[36],viz[36],nrNoduri=0;
    for(int i=0;i<dimV*dimO;i++)
        viz[i]=0;

    viz[start]=1;
    noduri[0]=start;
    nrNoduri++;

    int contorpas=0;
    //debugging
    cout << "Pasul " << contorpas++ << ": ";
	for (int i = 0;i < nrNoduri;i++)
		cout << noduri[i]/*noduri[i]/dimO << " "<<noduri[i]%dimO*/<<", ";
	cout << endl;
	//debugging*/

	int gasit=0;
	while(gasit==0&&nrNoduri>0){
        int nod=noduri[0];
        for(int i=0;i<nrNoduri;i++){
            noduri[i]=noduri[i+1];
        }
        nrNoduri--;
        if(nod==stop)
            gasit=1;
        else
            for(int i=0;i<dimV*dimO;i++){
                if((adiacenta[nod][i]!=0)&&(viz[i]==0)){
                    noduri[nrNoduri++]=i;
                    parinte[i]=nod;
                    viz[i]=1;
                }
            }

        //debugging
        cout << "Pasul " << contorpas++ << ": ";
        for (int i = 0;i < nrNoduri;i++)
            cout << noduri[i]/*noduri[i]/dimO << " "<<noduri[i]%dimO*/<<", ";
        cout << endl;
        //debugging*/

	}

	    int temp = stop;
	int contorTraseu = 0;
	int traseu[20];
	while (temp != start) {
		traseu[contorTraseu++] = temp;
		temp = parinte[temp];
	}
	traseu[contorTraseu++] = temp;

    /*/debugging
    for(int i=contorTraseu-1;i>=0;i--)
        cout<<traseu[i]<<" ";
    //debugging*/

    char litera='a';
    for(int i=contorTraseu-1;i>=0;i--){
        labirint[traseu[i]/dimO][traseu[i]%dimO]=litera++;
        }



    return 0;
    }

int main(){
    int dimV=6,dimO=6;
    char labirint[6][6]={{'0','0','0','0','0','0'},//0 inseamna casuta libera
                         {'0','0','0','3','0','0'},//1 inseamna perete
                         {'1','1','1','1','1','0'},//2 inseamna start
                         {'0','0','0','0','1','0'},//3 inseamna stop
                         {'1','1','0','0','0','0'},
                         {'0','0','2','0','1','0'}};

    int adiacenta[36][36];

    formareMatriceAdiacenta(adiacenta,labirint,dimV,dimO);

    /*/debugging
    cout<<"   ";
    for(int i=0;i<36;i++)
        cout<<setfill(' ')<<setw(2)<<i<<" ";
    cout<<endl;
    for(int i=0;i<36;i++){
        cout<<setfill(' ')<<setw(2)<<i<<" ";
        for(int j=0;j<36;j++)
            cout<<setfill(' ')<<setw(2)<<adiacenta[i][j]<<" ";
        cout<<endl;
    }
    //debugging*/

    cout<<endl<<endl<<"Labirintul este urmatorul, 1 sunt pereti, 2 e start, 3 e stop"<<endl;//afisez labirintul initial
    afisareLabirint(labirint,dimV,dimO);


    //Aceasta sectiune este cu scop ajutator pentru a verifica algoritmul
    cout<<endl<<endl<<"Pentru a putea urmari mai usor pasii, includ reprezentarea prin numere a casutelor"<<endl<<"-1 vor fi peretii, -2 va fi start, -3 va fi stop"<<endl<<endl;
    for(int i=0;i<dimV;i++){
        for(int j=0;j<dimO;j++)
            if(labirint[i][j]=='1')
            cout<<setfill(' ')<<setw(2)<<-1<<" ";
            else
                if(labirint[i][j]=='2')
                    cout<<setfill(' ')<<setw(2)<<-2<<" ";
                else
                    if(labirint[i][j]=='3')
                        cout<<setfill(' ')<<setw(2)<<-3<<" ";
                    else
                        cout<<setfill(' ')<<setw(2)<<i*dimO+j<<" ";
        cout<<endl;
        }
    //incheiere sectiune verificare

    cout<<endl<<endl;

    cautareLatime(adiacenta,labirint,dimV,dimO);
    cout<<endl<<endl<<"Solutia este:"<<endl;
    afisareLabirint(labirint,dimV,dimO);//afisez solutia

    getch();
    return 0;
}
