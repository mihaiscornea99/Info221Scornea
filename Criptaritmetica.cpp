#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<string>
#include<string.h>

using namespace std;


void transformareMajuscule(char termen1[20],char termen2[20],char rezultat[20]){
    int contor=0;
    while(termen1[contor]!='\0'){
        if(termen1[contor]>='a')
            termen1[contor]=termen1[contor]-'a'+'A';
        contor++;
        }
    contor=0;
    while(termen2[contor]!='\0'){
        if(termen2[contor]>='a')
            termen2[contor]=termen2[contor]-'a'+'A';
        contor++;
        }
    contor=0;
    while(rezultat[contor]!='\0'){
        if(rezultat[contor]>='a')
            rezultat[contor]=rezultat[contor]-'a'+'A';
        contor++;
        }


}

int literePrezente(char termen1[20],char termen2[20],char rezultat[20], int alfabet[26][2]){
    int contor=0;
    while(termen1[contor]!='\0'){
        alfabet[termen1[contor]-'A'][0]=1;
        contor++;
        }
    contor=0;
    while(termen2[contor]!='\0'){
        alfabet[termen2[contor]-'A'][0]=1;
        contor++;
        }
    contor=0;
    while(rezultat[contor]!='\0'){
        alfabet[rezultat[contor]-'A'][0]=1;
        contor++;
        }
    int nrLitere=0;
    for(int i=0;i<26;i++)
        if(alfabet[i][0]==1)
            nrLitere++;

    return nrLitere;
}

int gasireLiteraFolosita(int pozStart, int alfabet[26][2]){
    int gasit=0;
    while(gasit==0&&pozStart<26){
        if(alfabet[pozStart][0]==1){
            gasit=1;
            pozStart--;}
            pozStart++;
            }
    return pozStart;
}

int criptaritmetica(int poz, int alfabet[26][2],char termen1[20],char termen2[20],char rezultat[20]){
    if(poz==26){
        /*cout<<poz<<endl;
        for(int i=0;i<26;i++)
            cout<<alfabet[i][1]<<" ";
        cout<<endl;*/
        int termen1Int=0,termen2Int=0,rezultatInt=0,contor=0;
        while(termen1[contor]!='\0'){
            termen1Int=termen1Int*10+alfabet[termen1[contor]-'A'][1];
            contor++;}
        contor=0;
        while(termen2[contor]!='\0'){
            termen2Int=termen2Int*10+alfabet[termen2[contor]-'A'][1];
            contor++;}
        contor=0;
        while(rezultat[contor]!='\0'){
            //cout<<rezultatInt<<" ";
            rezultatInt=rezultatInt*10+alfabet[rezultat[contor]-'A'][1];
            contor++;}
        //getch();
        //cout<<endl<<"test"<<endl;
        //cout<<termen1Int<<" "<<termen2Int<<" "<<rezultatInt<<endl;
        if(termen1Int+termen2Int==rezultatInt){
            cout<<endl<<termen1Int<<"+"<<endl<<termen2Int<<endl<<rezultatInt;
            return 1;
        }
        return 0;
    }
    //cout<<poz<<endl;
    int ok;
        for(int i=0;i<10;i++){
            ok=1;
            for(int j=0;j<26&&ok==1;j++)
                if(alfabet[j][1]==i)
                    ok=0;
            if(ok==1){
            alfabet[poz][1]=i;
            if(criptaritmetica(gasireLiteraFolosita(poz+1,alfabet),alfabet,termen1,termen2,rezultat))
                return 1;
            }
            alfabet[poz][1]=-1;
        }
    return 0;
    }

int main(){
    int alfabet[26][2];
    for(int i=0;i<26;i++){
        alfabet[i][0]=0;
        alfabet[i][1]=-1;
        }
    char termen1[20],termen2[20],rezultat[20];
    int nrLitere;

    cout<<"Introduceti cei 2 termeni si rezultatul lor"<<endl<<"Termen1=";
    gets(termen1);
    cout<<"Termen2=";
    gets(termen2);
    cout<<"Rezultat=";
    gets(rezultat);
    transformareMajuscule(termen1,termen2,rezultat);
    cout<<endl<<termen1<<"+"<<endl<<termen2<<endl<<rezultat<<endl;

    nrLitere=literePrezente(termen1, termen2, rezultat, alfabet);
    //cout<<endl<<nrLitere;
    if(nrLitere>10)
        cout<<endl<<"Nu se poate rezolva, prea multe litere diferite.";
    else{
        if(!criptaritmetica(gasireLiteraFolosita(0,alfabet),alfabet,termen1,termen2,rezultat))
            cout<<"Nu s-a putut gasi o solutie";

    }

getch();
return 0;}










