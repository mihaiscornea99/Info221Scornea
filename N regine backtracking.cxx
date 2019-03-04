#include<stdio.h>
#include<conio.h>

#define N 6

int neatacata(int tabla[N][N],int rnd,int col){
	int i,j;
	for(i=col;i>=0;i--)
		if(tabla[rnd][i]==1)
		return 0;
	
	for(i=rnd;i>=0;i--)
		if(tabla[i][col]==1)
		return 0;
		
	for(i=rnd,j=col;i>=0&&j>=0;i--,j--)
		if(tabla[i][j]==1)
		return 0;
		
	for(i=rnd,j=col;i<N&&j>=0;i++,j--)
		if(tabla[i][j]==1)
		return 0;
	return 1;
	
}

int cautasolutii(int tabla[N][N],int col){
	if(col>=N)
	return 1;
	
	for(int i=0;i<N;i++)
	if(neatacata(tabla,i,col)==1){
		tabla[i][col]=1;
		if(cautasolutii(tabla,col+1)==1)
		return 1;
		tabla[i][col]=0;
		}
	return 0;
	}
	
int main(){
	int tabla[N][N];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		tabla[i][j]=0;
		
		if(cautasolutii(tabla,0)==1){
			for(int i=0;i<N;i++){
				for(int j=0;j<N;j++)
				printf("%d ",tabla[i][j]);
			printf("\n");
			}
			}
			else
			printf("Nu s-au gasit solutii");
		
	
	return 0;}