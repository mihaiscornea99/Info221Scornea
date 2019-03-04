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
	char proptemp[50],V[200];
	int propc,prop[52],nrprop,nrop,nrpar,nrtot,i,j,k,vartemp,pari,parf,nrtotal,pozop;
    nrprop=0;
    nrop=0;
    nrpar=0;
    nrtot=0;
    propc=0;

    	for(i=0;i<52;i++)
        prop[i]=-2;
	for(i=0;i<200;i++)
        V[i]='$';

    printf("Introduceti numarul de propozitii a caror consistenta doriti sa o verificati\nnr=");
    scanf("%d",&propc);
    printf("Introduceti fiecare propozitie logica folosind litere, paranteze si urmatoarele simboluri:\n   and=\"^\"\n    or=\"|\"\n   not=\"!\"\n  impl=\">\"\nechiv= \"=\"");
    k=0;
    for(i=0;i<propc;i++){
        for(j=0;j<50;j++)
        proptemp[j]='$';
        if(i==0)
            printf("\n");
        printf("P%d=",i+1);
        scanf("%s",proptemp);
        if(i>0)
            V[k++]='^';
            V[k++]='(';
            for(j=0;proptemp[j]=='^'||proptemp[j]=='|'||proptemp[j]=='!'||proptemp[j]=='='||proptemp[j]=='>'||(proptemp[j]>='a'&&proptemp[j]<='z')||(proptemp[j]>='A'&&proptemp[j]<='Z')||proptemp[j]=='('||proptemp[j]==')';j++)
                V[k++]=proptemp[j];
            V[k++]=')';
    }
        //debugging
        //printf("%s",V);


	for(i=0;V[i]!='$';i++){//numara cate propozitii, paranteze si operatori sunt
        //debugging
        //printf("\ntest");
        //debugging
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

            printf("Propozitia rezultata este ");
for(i=0;i<nrtot;i++)
    printf("%c",V[i]);

    for(i=0;i<nrtot;i++){//in vectorul in care stocam expresia, schimbam literele in cifre in functie de variabila temporara
        if(V[i]>='a'&&V[i]<='z'&&prop[V[i]-'a']>=0)
            V[i]=prop[V[i]-'a'];
        if(V[i]>='A'&&V[i]<='Z'&&prop[V[i]-'A'+26]==-1)
            V[i]=prop[V[i]-'A'+26];
        }
        //debugging
        //printf("\n%d %d %d",nrtot,nrpar,nrprop);
        //debugging

    int **tabel;
    if((tabel=(int**)malloc(sizeof(int*)*((int)pow(2,nrprop))))==NULL){
        exit(0);
        printf("\nMemorie insuficienta");
        }
    for(i=0;i<(int)pow(2,nrprop);i++)
        if((*(tabel+i)=(int*)malloc(sizeof(int)*(nrtot-nrpar+1)))==NULL){
        printf("\nMemorie insuficienta");
        exit(0);}
    //debugging
    //printf("\ntest");
    //debugging
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
    //debugging
    //printf("\ntest2");
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
//debugging
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

int satisfiabila;
satisfiabila=0;//verificare daca propozitia este satisfiabila(in cazul de fata, daca multimea este consistenta)
    for(i=0;i<(int)pow(2,nrprop);i++){
    if(*(*(tabel+i)+vartemp-1)==1){
        satisfiabila=1;
        break;
    }}
    if(satisfiabila==1)
        printf("\nMultimea de propozitii date este consistenta");
    else
        printf("\nMultimea de propozitii date este inconsistenta");

    for(i=0;i<(int)pow(2,nrprop);i++)
        free(*(tabel+i));
    free(tabel);
    getch();
	return 0;
	}

