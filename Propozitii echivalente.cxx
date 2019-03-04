#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>

int negatie(int v){
if(v==0)
return 1;
else
return 0;
}

int si(int a,int b){
if(a==1&&b==1)
    return 1;
else
    return 0;
}

int sau(int a,int b){
if(a==1||b==1)
    return 1;
else
    return 0;
}

int impl(int a,int b){
if(a==1&&b==0)
    return 0;
else
    return 1;
}

int echiv(int a,int b){
if((a==1&&b==1)||(a==0&&b==0))
    return 1;
else
    return 0;
}




int main(){
	char V[50];
	int prop[52],nrprop,nrop,nrpar,nrtot,i,j,k,vartemp,pari,parf,nrtotal,pozop;
    nrprop=0;
    nrop=0;
    nrpar=0;
    nrtot=0;


	for(i=0;i<52;i++)
        prop[i]=-2;
	for(i=0;i<50;i++)
        V[i]='$';
	printf("Introduceti doua propozitii logice folosind litere, paranteze si urmatoarele simboluri:\n   and=\"^\"\n    or=\"|\"\n   not=\"!\"\n  impl=\">\"\nechiv= \"=\"\npropozitia1=");
	scanf("%s",V);


	for(i=0;V[i]!='$';i++){//numara cate propozitii, paranteze si operatori sunt
    if(V[i]>='a'&&V[i]<='z')
        prop[V[i]-'a']=-1;
    if(V[i]>='A'&&V[i]<='Z')
        prop[V[i]-'A'+26]=-1;
    if(V[i]=='('||V[i]==')')
        nrpar++;
    if(V[i]=='^'||V[i]=='|'||V[i]=='!'||V[i]=='='||V[i]=='>')
        nrop++;
        nrtot++;
        }
        nrtot--;
    for(i=0;i<52;i++)
        if(prop[i]==-1)
        nrprop++;

    nrtotal=nrtot;
    vartemp=0;//in vectorul in care am numarat care litere apar, le atribuim care un numar celor prezente
    for(i=0;i<nrtot;i++){
        if(V[i]>='a'&&V[i]<='z'&&prop[V[i]-'a']==-1)
            prop[V[i]-'a']=vartemp++;
        if(V[i]>='A'&&V[i]<='Z'&&prop[V[i]-'A'+26]==-1)
            prop[V[i]-'A'+26]=vartemp++;
        }

    for(i=0;i<nrtot;i++){//in vectorul in care stocam expresia, schimbam literele in cifre in functie de variabila temporara
        if(V[i]>='a'&&V[i]<='z'&&prop[V[i]-'a']>=0)
            V[i]=prop[V[i]-'a'];
        if(V[i]>='A'&&V[i]<='Z'&&prop[V[i]-'A'+26]==-1)
            V[i]=prop[V[i]-'A'+26];
        }


    int **tabel;

    if((tabel=(int**)malloc(sizeof(int*)*((int)pow(2,nrprop))))==NULL){
    printf("\nMemorie insuficienta");
    exit(0);}
    for(i=0;i<(int)pow(2,nrprop);i++)
        if((*(tabel+i)=(int*)malloc(sizeof(int)*(nrtot-nrpar+1)))==NULL){
    printf("\nMemorie insuficienta");
    exit(0);
        }

    int l,ok;
for(j=0;j<nrprop;j++){
    l=0;
    ok=1;
    for(i=0;i<(int)pow(2,nrprop);i++){
    switch(ok){
    case 0:
        *(*(tabel+i)+nrprop-1-j)=0;
    break;
    case 1:
        *(*(tabel+i)+nrprop-1-j)=1;
    break;
    }
    l++;
    if(l==pow(2,j)){
        if(ok==1)
            ok=0;
        else
            ok=1;
    l=0;
    }
    }
}
//debugging
//printf("\n%d\n",vartemp);
//debugging


while(nrtot>1){

    ok=0;
    for(i=0;i<nrtot;i++){
    if(V[i]=='('){
        pari=i;
        ok=1;}
    if(V[i]==')'){
        parf=i;
        ok=1;
        break;}
    }
    if(ok==0){
        pari=-1;
        parf=nrtot;
    }
    if(parf-pari>2){
    while((parf-pari)>2){//rezolva toate negatiile din paranteza
            ok=0;
        for(j=pari+1;j<parf;j++)
        if(V[j]=='!'){
            pozop=j;
            ok=1;
        }
        //debugging
        //printf("\n%d\n",ok);
        //debugging
        if(ok==0)
        break;
        else{
            for(k=0;k<(int)pow(2,nrprop);k++){
            *(*(tabel+k)+vartemp)=negatie(*(*(tabel+k)+V[pozop+1]));
            }
            V[pozop+1]=vartemp;
            vartemp++;
            for(k=pozop;k<nrtot;k++)
                V[k]=V[k+1];
            parf--;
            nrtot--;
        //debugging
        //printf("\n%d\n",nrtot);
        //debugging
        }
        }
        while((parf-pari)>2){//rezolva toate conjunctiile din paranteza
            ok=0;
        for(j=pari+1;j<parf;j++)
        if(V[j]=='^'){
            pozop=j;
            ok=1;
        }
        if(ok==0)
        break;
        else{
            for(k=0;k<(int)pow(2,nrprop);k++){
            *(*(tabel+k)+vartemp)=si(*(*(tabel+k)+V[pozop-1]),*(*(tabel+k)+V[pozop+1]));
            }
            V[pozop+1]=vartemp;
            vartemp++;
            for(k=pozop-1;k<nrtot;k++)
                V[k]=V[k+1];
            for(k=pozop-1;k<nrtot;k++)
                V[k]=V[k+1];
            parf=parf-2;
            nrtot=nrtot-2;
        //debugging
        //printf("\n%d\n",nrtot);
        //debugging
        }
        }
                while((parf-pari)>2){//rezolva toate disjunctiile din paranteza
            ok=0;
        for(j=pari+1;j<parf;j++)
        if(V[j]=='|'){
            pozop=j;
            ok=1;
        }
        //printf("\n%d\n",ok);
        if(ok==0)
        break;
        else{
            for(k=0;k<(int)pow(2,nrprop);k++){
            *(*(tabel+k)+vartemp)=sau(*(*(tabel+k)+V[pozop-1]),*(*(tabel+k)+V[pozop+1]));
            }
            V[pozop+1]=vartemp;
            vartemp++;
            for(k=pozop-1;k<nrtot;k++)
                V[k]=V[k+1];
            for(k=pozop-1;k<nrtot;k++)
                V[k]=V[k+1];
            parf=parf-2;
            nrtot=nrtot-2;
        //debugging
        //printf("\n%d\n",nrtot);
        //debugging
        }
        }
                        while((parf-pari)>2){//rezolva toate implicatiile din paranteza
            ok=0;
        for(j=pari+1;j<parf;j++)
        if(V[j]=='>'){
            pozop=j;
            ok=1;
        }
        //printf("\n%d\n",ok);
        if(ok==0)
        break;
        else{
            for(k=0;k<(int)pow(2,nrprop);k++){
            *(*(tabel+k)+vartemp)=impl(*(*(tabel+k)+V[pozop-1]),*(*(tabel+k)+V[pozop+1]));
            }
            V[pozop+1]=vartemp;
            vartemp++;
            for(k=pozop-1;k<nrtot;k++)
                V[k]=V[k+1];
            for(k=pozop-1;k<nrtot;k++)
                V[k]=V[k+1];
            parf=parf-2;
            nrtot=nrtot-2;
        //debugging
        //printf("\n%d\n",nrtot);
        //debugging
        }
        }
                        while((parf-pari)>2){//rezolva toate ecvivalentele din paranteza
            ok=0;
        for(j=pari+1;j<parf;j++)
        if(V[j]=='='){
            pozop=j;
            ok=1;
        }
        //printf("\n%d\n",ok);
        if(ok==0)
        break;
        else{
            for(k=0;k<(int)pow(2,nrprop);k++){
            *(*(tabel+k)+vartemp)=echiv(*(*(tabel+k)+V[pozop-1]),*(*(tabel+k)+V[pozop+1]));
            }
            V[pozop+1]=vartemp;
            vartemp++;
            for(k=pozop-1;k<nrtot;k++)
                V[k]=V[k+1];
            for(k=pozop-1;k<nrtot;k++)
                V[k]=V[k+1];
            parf=parf-2;
            nrtot=nrtot-2;
        //debugging
        //printf("\n%d\n",nrtot);
        //debugging
        }
        }
    }
    else{
        V[pari]=V[pari+1];
        for(k=pari+1;k<nrtot;k++)
            V[k]=V[k+1];
        for(k=pari+1;k<nrtot;k++)
            V[k]=V[k+1];
        nrtot=nrtot-2;
    }

}



/*/debugging
printf("\n");
for(i=0;i<(int)pow(2,nrprop);i++){
    for(j=0;j<vartemp;j++)
        printf("%d ",*(*(tabel+i)+j));
    printf("\n");
    }
/*
//printf("\n%d %d %d %d\n\n",nrprop,nrop,nrpar,nrtot);
for(i=0;i<nrtotal-nrpar+1;i++)
    printf("%d",V[i]);
printf("\n");
//printf("%d %d",nrtotal-nrpar+1,vartemp);
//debugging*/

//Aici incepe pentru propozitia 2

	char V2[50];
	int prop2[52],nrprop2,nrop2,nrpar2,nrtot2,vartemp2,nrtotal2,pozop2;
    nrprop2=0;
    nrop2=0;
    nrpar2=0;
    nrtot2=0;


	for(i=0;i<52;i++)
        prop2[i]=-2;
	for(i=0;i<50;i++)
        V2[i]='$';
	printf("propozitia2=");
	scanf("%s",V2);


	for(i=0;V2[i]!='$';i++){//numara cate propozitii, paranteze si operatori sunt
    if(V2[i]>='a'&&V2[i]<='z')
        prop2[V2[i]-'a']=-1;
    if(V2[i]>='A'&&V2[i]<='Z')
        prop2[V2[i]-'A'+26]=-1;
    if(V2[i]=='('||V2[i]==')')
        nrpar2++;
    if(V2[i]=='^'||V2[i]=='|'||V2[i]=='!'||V2[i]=='='||V2[i]=='>')
        nrop2++;
        nrtot2++;
        }
        nrtot2--;
    for(i=0;i<52;i++)
        if(prop2[i]==-1)
        nrprop2++;

    nrtotal2=nrtot2;
    vartemp2=0;//in vectorul in care am numarat care litere apar, le atribuim care un numar celor prezente
    for(i=0;i<nrtot2;i++){
        if(V2[i]>='a'&&V2[i]<='z'&&prop2[V2[i]-'a']==-1)
            prop2[V2[i]-'a']=vartemp2++;
        if(V2[i]>='A'&&V2[i]<='Z'&&prop2[V2[i]-'A'+26]==-1)
            prop2[V2[i]-'A'+26]=vartemp2++;
        }

    for(i=0;i<nrtot2;i++){//in vectorul in care stocam expresia, schimbam literele in cifre in functie de variabila temporara
        if(V2[i]>='a'&&V2[i]<='z'&&prop2[V2[i]-'a']>=0)
            V2[i]=prop2[V2[i]-'a'];
        if(V2[i]>='A'&&V2[i]<='Z'&&prop2[V2[i]-'A'+26]==-1)
            V2[i]=prop2[V2[i]-'A'+26];
        }


    int **tabel2;

    if((tabel2=(int**)malloc(sizeof(int*)*((int)pow(2,nrprop2))))==NULL){
    printf("\nMemorie insuficienta");
    exit(0);}
    for(i=0;i<(int)pow(2,nrprop2);i++)
        if((*(tabel2+i)=(int*)malloc(sizeof(int)*(nrtot2-nrpar2+1)))==NULL){
    printf("\nMemorie insuficienta");
    exit(0);
        }

for(j=0;j<nrprop2;j++){
    l=0;
    ok=1;
    for(i=0;i<(int)pow(2,nrprop2);i++){
    switch(ok){
    case 0:
        *(*(tabel2+i)+nrprop2-1-j)=0;
    break;
    case 1:
        *(*(tabel2+i)+nrprop2-1-j)=1;
    break;
    }
    l++;
    if(l==pow(2,j)){
        if(ok==1)
            ok=0;
        else
            ok=1;
    l=0;
    }
    }
}
//debugging
//printf("\n%d\n",vartemp2);
//debugging


while(nrtot2>1){

    ok=0;
    for(i=0;i<nrtot2;i++){
    if(V2[i]=='('){
        pari=i;
        ok=1;}
    if(V2[i]==')'){
        parf=i;
        ok=1;
        break;}
    }
    if(ok==0){
        pari=-1;
        parf=nrtot2;
    }
    if(parf-pari>2){
    while((parf-pari)>2){//rezolva toate negatiile din paranteza
            ok=0;
        for(j=pari+1;j<parf;j++)
        if(V2[j]=='!'){
            pozop2=j;
            ok=1;
        }
        //debugging
        //printf("\n%d\n",ok);
        //debugging
        if(ok==0)
        break;
        else{
            for(k=0;k<(int)pow(2,nrprop2);k++){
            *(*(tabel2+k)+vartemp2)=negatie(*(*(tabel2+k)+V2[pozop2+1]));
            }
            V2[pozop2+1]=vartemp2;
            vartemp2++;
            for(k=pozop2;k<nrtot2;k++)
                V2[k]=V2[k+1];
            parf--;
            nrtot2--;
        //debugging
        //printf("\n%d\n",nrtot2);
        //debugging
        }
        }
        while((parf-pari)>2){//rezolva toate conjunctiile din paranteza
            ok=0;
        for(j=pari+1;j<parf;j++)
        if(V2[j]=='^'){
            pozop2=j;
            ok=1;
        }
        if(ok==0)
        break;
        else{
            for(k=0;k<(int)pow(2,nrprop2);k++){
            *(*(tabel2+k)+vartemp2)=si(*(*(tabel2+k)+V2[pozop2-1]),*(*(tabel2+k)+V2[pozop2+1]));
            }
            V2[pozop2+1]=vartemp2;
            vartemp2++;
            for(k=pozop2-1;k<nrtot2;k++)
                V2[k]=V2[k+1];
            for(k=pozop2-1;k<nrtot2;k++)
                V2[k]=V2[k+1];
            parf=parf-2;
            nrtot2=nrtot2-2;
        //debugging
        //printf("\n%d\n",nrtot2);
        //debugging
        }
        }
                while((parf-pari)>2){//rezolva toate disjunctiile din paranteza
            ok=0;
        for(j=pari+1;j<parf;j++)
        if(V2[j]=='|'){
            pozop2=j;
            ok=1;
        }
        //printf("\n%d\n",ok);
        if(ok==0)
        break;
        else{
            for(k=0;k<(int)pow(2,nrprop2);k++){
            *(*(tabel2+k)+vartemp2)=sau(*(*(tabel2+k)+V2[pozop2-1]),*(*(tabel2+k)+V2[pozop2+1]));
            }
            V2[pozop2+1]=vartemp2;
            vartemp2++;
            for(k=pozop2-1;k<nrtot2;k++)
                V2[k]=V2[k+1];
            for(k=pozop2-1;k<nrtot2;k++)
                V2[k]=V2[k+1];
            parf=parf-2;
            nrtot2=nrtot2-2;
        //debugging
        //printf("\n%d\n",nrtot2);
        //debugging
        }
        }
                        while((parf-pari)>2){//rezolva toate implicatiile din paranteza
            ok=0;
        for(j=pari+1;j<parf;j++)
        if(V2[j]=='>'){
            pozop2=j;
            ok=1;
        }
        //printf("\n%d\n",ok);
        if(ok==0)
        break;
        else{
            for(k=0;k<(int)pow(2,nrprop2);k++){
            *(*(tabel2+k)+vartemp2)=impl(*(*(tabel2+k)+V2[pozop2-1]),*(*(tabel2+k)+V2[pozop2+1]));
            }
            V2[pozop2+1]=vartemp2;
            vartemp2++;
            for(k=pozop2-1;k<nrtot2;k++)
                V2[k]=V2[k+1];
            for(k=pozop2-1;k<nrtot2;k++)
                V2[k]=V2[k+1];
            parf=parf-2;
            nrtot2=nrtot2-2;
        //debugging
        //printf("\n%d\n",nrtot2);
        //debugging
        }
        }
                        while((parf-pari)>2){//rezolva toate ecvivalentele din paranteza
            ok=0;
        for(j=pari+1;j<parf;j++)
        if(V2[j]=='='){
            pozop2=j;
            ok=1;
        }
        //printf("\n%d\n",ok);
        if(ok==0)
        break;
        else{
            for(k=0;k<(int)pow(2,nrprop2);k++){
            *(*(tabel2+k)+vartemp2)=echiv(*(*(tabel2+k)+V2[pozop2-1]),*(*(tabel2+k)+V2[pozop2+1]));
            }
            V2[pozop2+1]=vartemp2;
            vartemp2++;
            for(k=pozop2-1;k<nrtot2;k++)
                V2[k]=V2[k+1];
            for(k=pozop2-1;k<nrtot2;k++)
                V2[k]=V2[k+1];
            parf=parf-2;
            nrtot2=nrtot2-2;
        //debugging
        //printf("\n%d\n",nrtot2);
        //debugging
        }
        }
    }
    else{
        V2[pari]=V2[pari+1];
        for(k=pari+1;k<nrtot2;k++)
            V2[k]=V2[k+1];
        for(k=pari+1;k<nrtot2;k++)
            V2[k]=V2[k+1];
        nrtot2=nrtot2-2;
    }

}


//debugging
printf("\nTabelul de adevar pentru prima propozitie este:");
printf("\n");
for(i=0;i<(int)pow(2,nrprop);i++){
    for(j=0;j<vartemp;j++)
        printf("%d ",*(*(tabel+i)+j));
    printf("\n");
    }
//*/


//debugging
printf("\nTabelul de adevar pentru a doua propozitie este:");
printf("\n");
for(i=0;i<(int)pow(2,nrprop2);i++){
    for(j=0;j<vartemp2;j++)
        printf("%d ",*(*(tabel2+i)+j));
    printf("\n");
    }

/*
//printf("\n%d %d %d %d\n\n",nrprop2,nrop2,nrpar2,nrtot2);
for(i=0;i<nrtotal2-nrpar2+1;i++)
    printf("%d",V2[i]);
printf("\n");
//printf("%d %d",nrtotal2-nrpar2+1,vartemp2);
//debugging*/

if((int)pow(2,nrprop)==(int)pow(2,nrprop2)){
    int echivalente=1;
    for(i=0;i<(int)pow(2,nrprop);i++)
        if(*(*(tabel+i)+vartemp-1)!=*(*(tabel2+i)+vartemp2-1)){
        echivalente=0;
        break;
    }
    if(echivalente==1)
        printf("\n\nCele doua propozitii sunt logic echivalente");
    else
        printf("\n\nCele doua propozitii nu sunt logic echivalente");
}
else
    printf("\n\nCele doua propozitii nu sunt logic echivalente");



getch();
return 0;
}
