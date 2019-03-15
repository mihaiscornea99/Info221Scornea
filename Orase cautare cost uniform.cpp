#include<iostream>
#include<conio.h>
#include<iomanip>

using namespace std;

//char *nume[20]={"Arad", "Zerind", "Sibiu", "Timisoara", "Oradea", "Fagaras", "Rimnicu Valcea", "Lugoj", "Bucuresti", "Pitesti", "Mehadia", "Drobeta", "Craiova", "Giurgiu", "Urziceni", "Hirsova", "Eforie", "Vaslui", "Iasi", "Neamt"};
			//    0         1        2          3          4          5              6            7          8           9         10          11        12         13         14          15         16        17       18      19
/*
int A[20][20] =         { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
						  { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, };


//{"Arad", "Zerind", "Sibiu", "Timisoara", "Oradea", "Fagaras", "Rimnicu Valcea", "Lugoj", "Bucuresti", "Pitesti", "Mehadia", "Drobeta", "Craiova", "Giurgiu", "Urziceni", "Hirsova", "Eforie", "Vaslui", "Iasi", "Neamt"};
//    0         1        2          3          4          5              6            7          8           9         10          11        12         13         14          15         16        17       18      19
A[0][1] = 75;
A[1][0] = 75;
A[0][2] = 140;
A[2][0] = 140;
A[0][3] = 118;
A[3][0] = 118;
A[1][4] = 71;
A[4][1] = 71;
A[4][2] = 151;
A[2][4] = 151;
A[3][7] = 111;
A[7][3] = 111;
A[7][10] = 70;
A[10][7] = 70;
A[10][11] = 75;
A[11][10] = 75;
A[11][12] = 120;
A[12][11] = 120;
A[2][5] = 99;
A[5][2] = 99;
A[2][6] = 80;
A[6][2] = 80;
A[6][12] = 146;
A[12][6] = 146;
A[6][9] = 97;
A[9][6] = 97;
A[12][9] = 138;
A[9][12] = 138;
A[5][8] = 211;
A[8][5] = 211;
A[9][8] = 101;
A[8][9] = 101;
A[8][13] = 90;
A[13][8] = 90;
A[8][14] = 85;
A[14][8] = 85;
A[14][15] = 98;
A[15][14] = 98;
A[15][16] = 86;
A[16][15] = 86;
A[14][17] = 142;
A[17][14] = 142;
A[17][18] = 92;
A[18][17] = 92;
A[18][19] = 87;
A[19][18] = 87;*/

int CreareMatrice(int A[20][20]) {

	A[0][1] = 75;
	A[1][0] = 75;

	A[0][2] = 140;
	A[2][0] = 140;

	A[0][3] = 118;
	A[3][0] = 118;

	A[1][4] = 71;
	A[4][1] = 71;

	A[4][2] = 151;
	A[2][4] = 151;

	A[3][7] = 111;
	A[7][3] = 111;

	A[7][10] = 70;
	A[10][7] = 70;

	A[10][11] = 75;
	A[11][10] = 75;

	A[11][12] = 120;
	A[12][11] = 120;

	A[2][5] = 99;
	A[5][2] = 99;

	A[2][6] = 80;
	A[6][2] = 80;

	A[6][12] = 146;
	A[12][6] = 146;

	A[6][9] = 97;
	A[9][6] = 97;

	A[12][9] = 138;
	A[9][12] = 138;

	A[5][8] = 211;
	A[8][5] = 211;

	A[9][8] = 101;
	A[8][9] = 101;

	A[8][13] = 90;
	A[13][8] = 90;

	A[8][14] = 85;
	A[14][8] = 85;

	A[14][15] = 98;
	A[15][14] = 98;

	A[15][16] = 86;
	A[16][15] = 86;

	A[14][17] = 142;
	A[17][14] = 142;

	A[17][18] = 92;
	A[18][17] = 92;

	A[18][19] = 87;
	A[19][18] = 87;


	return 0;
}

int gasireVecini(int n,int A[20][20], /*char *nume[20],*/int noduri[20],int &nrnoduri) {
	//cout << "Orasul " << nume[n] << " are ca vecini:" << endl;
	for(int i=0;i<20;i++)
		if (A[n][i] != 0) {
			noduri[nrnoduri++] = i;
			//cout << "-" << nume[i] << " aflat la " << A[n][i] << " km distanta" << endl;
		}

	return 0;
}

int latime(int start, int stop, int A[20][20], char *nume[20]) {



	int nrNoduri = 0, contorViz = 0;

	int noduri[20];//orasele in asteptare
	int viz[20];//orase deja vizitate
	int parinte[20];//parinte[i]=j =>j este parintele lui i
	int gasit = 0;
	for (int i = 0;i < 20;i++)
		viz[i] = 0;
	viz[start] = 1;
	noduri[0] = start;
	nrNoduri++;
	int contorpas = 0;

	cout << "Pasul " << contorpas++ << ": ";
	for (int i = 0;i < nrNoduri;i++)
		cout << nume[noduri[i]] << " ";
	cout << endl;


	while (gasit == 0 && nrNoduri > 0) {
		int nod = noduri[0];
		//cout << nume[nod] << " ";
		for (int i = 0;i < nrNoduri - 1;i++)
			noduri[i] = noduri[i + 1];
		nrNoduri--;
		if (nod == stop)
			gasit = 1;
		else
			for (int i = 0;i<20;i++)
				if ((A[nod][i] != 0) && (viz[i] == 0)) {
					noduri[nrNoduri++] = i;
					viz[i] = 1;//cout << "-" << nume[i] << " aflat la " << A[n][i] << " km distanta" << endl;
					parinte[i] = nod;
				}
		cout << "Pasul " << contorpas++ << ": ";
		for (int i = 0;i < nrNoduri;i++)
			cout << nume[noduri[i]] << " ";
		cout << endl;
		//cout << nume[nod] << " ";

	}
	cout << endl;
	int temp = stop;
	int contorTraseu = 0;
	int traseu[20];
	while (parinte[temp] != start) {
		traseu[contorTraseu++] = temp;
		temp = parinte[temp];
	}
	traseu[contorTraseu++] = temp;
	traseu[contorTraseu++] = parinte[temp];
	for (int i = contorTraseu - 1;i >= 0;i--) {
		cout << nume[traseu[i]] << ", ";
	}

	return 0;
}

int adancime(int start, int stop, int A[20][20], char *nume[20]) {



	int nrNoduri = 0, contorViz = 0;

	int noduri[20];//orasele in asteptare
	int viz[20];//orase deja vizitate
	int parinte[20];//parinte[i]=j =>j este parintele lui i
	int gasit = 0;
	for (int i = 0;i < 20;i++)
		viz[i] = 0;
	viz[start] = 1;
	noduri[0] = start;
	nrNoduri++;
	int contorpas = 0;

	cout << "Pasul " << contorpas++ << ": ";
	for (int i = 0;i < nrNoduri;i++)
		cout << nume[noduri[i]] << " ";
	cout << endl;


	while (gasit == 0 && nrNoduri > 0) {
		int nod = noduri[0];
		//cout << nume[nod] << " ";
		for (int i = 0;i < nrNoduri - 1;i++)
			noduri[i] = noduri[i + 1];
		nrNoduri--;
		if (nod == stop)
			gasit = 1;
		else
			for (int i = 0;i<20;i++)
				if ((A[nod][i] != 0) && (viz[i] == 0)) {
					for (int j = nrNoduri-1;j >= 0;j--)
						noduri[j+1] = noduri[j];
					nrNoduri++;
					noduri[0] = i;
					viz[i] = 1;//cout << "-" << nume[i] << " aflat la " << A[n][i] << " km distanta" << endl;
					parinte[i] = nod;
				}
		cout << "Pasul " << contorpas++ << ": ";
		for (int i = 0;i < nrNoduri;i++)
			cout << nume[noduri[i]] << " ";
		cout << endl;
		//cout << nume[nod] << " ";

	}
	cout << endl;
	int temp = stop;
	int contorTraseu = 0;
	int traseu[20];
	while (parinte[temp] != start) {
		traseu[contorTraseu++] = temp;
		temp = parinte[temp];
	}
	traseu[contorTraseu++] = temp;
	traseu[contorTraseu++] = parinte[temp];
	for (int i = contorTraseu - 1;i >= 0;i--) {
		cout << nume[traseu[i]] << ", ";
	}

	return 0;
}

int cautareCostUniform(int start, int stop, int A[20][20], char *nume[20]) {



	int nrNoduri = 0, contorViz = 0;

	int cost[20];
	int noduri[20];//orasele in asteptare
	int viz[20];//orase deja vizitate
	int parinte[20];//parinte[i]=j =>j este parintele lui i
	int gasit = 0;
	for (int i = 0;i < 20;i++){
		viz[i] = 0;
		cost[i]=0;}

	viz[start] = 1;

	noduri[0] = start;
	nrNoduri++;
	int contorpas = 0;

	cout << "Pasul " << contorpas++ << ": ";
	for (int i = 0;i < nrNoduri;i++)
		cout << nume[noduri[i]] << " "<<cost[noduri[i]]<<", ";
	cout << endl;


	while (gasit == 0 && nrNoduri > 0) {
        int pozInsert;
        int pozAcelasi=0;
		int nod = noduri[0];
		//cout << nume[nod] << " ";
		for (int i = 0;i < nrNoduri - 1;i++)
			noduri[i] = noduri[i + 1];
		nrNoduri--;
		if (nod == stop)
			gasit = 1;
		else{

			for (int i = 0;i<20;i++)
				if ((A[nod][i] != 0) && ((viz[i] == 0)||(cost[i]>(A[nod][i]+cost[nod])))) {//Aici verifica daca un nod a mai fost vizitat, iar daca da, verifica daca drumul actual costa mai putin

                    int ok=0;
                    pozInsert=nrNoduri;
                    viz[i] = 1;//cout << "-" << nume[i] << " aflat la " << A[n][i] << " km distanta" << endl;
					parinte[i] = nod;

                    cost[i]=cost[nod]+A[nod][i];
                    //cout<<"test";

                    for(int j=0;j<nrNoduri;j++)//aici verifica daca in stiva curenta se haseste acelasi nod pentru a fi eliminat din lista
                        if(cost[noduri[j]]>=cost[i]&&noduri[j]==i){
                        ok=1;
                        pozAcelasi=j;
                        nrNoduri--;
                        break;
                        }

                    if(ok==1)
                        for(int j=pozAcelasi;j<nrNoduri;j++)
                            noduri[j]=noduri[j+1];

					for(int j=0;j<nrNoduri;j++)
                        if(cost[noduri[j]]>=cost[i]){
                        pozInsert=j;
                        break;}
                    for(int j=nrNoduri-1;j>=pozInsert;j--)
                        noduri[j+1]=noduri[j];
                        nrNoduri++;

                    //cout<<pozInsert<<endl;
                    noduri[pozInsert]=i;


					/*/test
                    cout << "Pasul " << contorpas++ << ": ";
		for (int i = 0;i < nrNoduri;i++)
			cout << nume[noduri[i]] << " "<<cost[noduri[i]]<<", ";
		cout << endl;
		//cout << nume[nod] << " ";*/

            }}
        //test
		cout << "Pasul " << contorpas++ << ": ";
		for (int i = 0;i < nrNoduri;i++)
			cout << nume[noduri[i]] << " "<<cost[noduri[i]]<<", ";
		cout << endl;
		//cout << nume[nod] << " ";*/

	}
	cout << endl;
	int temp = stop;
	int contorTraseu = 0;
	int traseu[20];
	while (parinte[temp] != start) {
		traseu[contorTraseu++] = temp;
		temp = parinte[temp];
	}
	traseu[contorTraseu++] = temp;
	traseu[contorTraseu++] = parinte[temp];
	for (int i = contorTraseu - 1;i >= 0;i--) {
		cout << nume[traseu[i]] << ", ";
	}

	cout<<endl<<"Cost traseu: "<<cost[stop];

	return 0;
}


int main() {


	char *nume[20] = { "Arad", "Zerind", "Sibiu", "Timisoara", "Oradea", "Fagaras", "Ramnicu Valcea", "Lugoj", "Bucuresti", "Pitesti", "Mehadia", "Drobeta", "Craiova", "Giurgiu", "Urziceni", "Hirsova", "Eforie", "Vaslui", "Iasi", "Neamt" };
	               //    0         1        2          3          4          5              6            7          8           9         10          11        12         13         14          15         16        17       18      19

	int A[20][20] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, };

	CreareMatrice(A);

    /*/test
	for (int i = 0;i < 20;i++) {
		for (int j = 0;j < 20;j++)
			cout << setfill(' ') << setw(3) << A[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	//test*/

    //Aici introduceti cifrele corespunzatoare oraselor
	int start = 0, stop = 8;


	cout << endl<<"Cautare in latime:" << endl;
	latime(start, stop, A, nume);
	cout << endl << endl<< "Cautare in adancime:" << endl;
	adancime(start, stop, A, nume);
	cout << endl<< endl<< "Cautare cu cost uniform:" << endl;
	cautareCostUniform(start, stop, A, nume);
	//gasireVecini(9, A, nume);

	_getch();
	return 0;
}

