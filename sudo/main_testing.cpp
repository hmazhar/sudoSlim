#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include <string>
#include <stack>
#include <iomanip>
#include <stdio.h>

using namespace std;
inline  bool check(const char &row, const char &col,const unsigned char &num);
inline  void brute();
inline /* vector<unsigned char>*/ bool rsquares(/*const unsigned char &row,const unsigned char &col*/);
inline  bool nsquares();
struct position {unsigned char r,c;};
vector <position> emptypos;
char num=0, i=0, j=0,k=0, squarenum;
int numss;
unsigned char square[9][3][3]={0};
unsigned char sift[9]={1,2,3,4,5,6,7,8,9};
unsigned char m[9][9]={0};
char possib[9][9][9]={0};
vector<unsigned char> pvals;
stack<position> poss;
inline  void print() {
	for (i=0; i<9; ++i) {
		if (i==6||i==3||i==0) {cout<<"-------------"<<endl;}
		for (j=0; j<9; ++j) {
			if (j==0||j==3||j==6) {cout<<"|";}
			cout<<int(m[i][j]);
			if (j==8) {cout<<"|";}

		}
		cout<<endl;
		if (i==8) {cout<<"-------------"<<endl;}
	}
}
inline void gensq() {
	/*if(row<3){j=0;}
	else if(row<6){j=3;}
	else if(row<9){j=6;}
	int i=(col/3)*3;
	if(test==m[j+0][i+0]){return false;}	
	if(test==m[j+0][i+1]){return false;}	
	if(test==m[j+0][i+2]){return false;}	
	if(test==m[j+1][i+0]){return false;}	
	if(test==m[j+1][i+1]){return false;}	
	if(test==m[j+1][i+2]){return false;}	 
	if(test==m[j+2][i+0]){return false;}	
	if(test==m[j+2][i+1]){return false;}	
	if(test==m[j+2][i+2]){return false;}	
	return true;

	*/

	square[0][0][0]=m[0][0];	
	square[0][0][1]=m[0][1];	
	square[0][0][2]=m[0][2];	
	square[0][1][0]=m[1][0];	
	square[0][1][1]=m[1][1];	
	square[0][1][2]=m[1][2];	
	square[0][2][0]=m[2][0];	
	square[0][2][1]=m[2][1];	
	square[0][2][2]=m[2][2];	

	square[1][0][0]=m[0][3];	
	square[1][0][1]=m[0][4];	
	square[1][0][2]=m[0][5];	
	square[1][1][0]=m[1][3];	
	square[1][1][1]=m[1][4];	
	square[1][1][2]=m[1][5];	
	square[1][2][0]=m[2][3];	
	square[1][2][1]=m[2][4];	
	square[1][2][2]=m[2][5];

	square[2][0][0]=m[0][6];
	square[2][0][1]=m[0][7];
	square[2][0][2]=m[0][8];
	square[2][1][0]=m[1][6];
	square[2][1][1]=m[1][7];
	square[2][1][2]=m[1][8];
	square[2][2][0]=m[2][6];
	square[2][2][1]=m[2][7];
	square[2][2][2]=m[2][8];

	square[3][0][0]=m[3][0];	
	square[3][0][1]=m[3][1];	
	square[3][0][2]=m[3][2];	
	square[3][1][0]=m[4][0];	
	square[3][1][1]=m[4][1];
	square[3][1][2]=m[4][2];
	square[3][2][0]=m[5][0];
	square[3][2][1]=m[5][1];
	square[3][2][2]=m[5][2];

	square[4][0][0]=m[3][3];	
	square[4][0][1]=m[3][4];	
	square[4][0][2]=m[3][5];	
	square[4][1][0]=m[4][3];	
	square[4][1][1]=m[4][4];	
	square[4][1][2]=m[4][5];	
	square[4][2][0]=m[5][3];	
	square[4][2][1]=m[5][4];
	square[4][2][2]=m[5][5];

	square[5][0][0]=m[3][6];
	square[5][0][1]=m[3][7];
	square[5][0][2]=m[3][8];
	square[5][1][0]=m[4][6];
	square[5][1][1]=m[4][7];
	square[5][1][2]=m[4][8];
	square[5][2][0]=m[5][6];
	square[5][2][1]=m[5][7];
	square[5][2][2]=m[5][8];

	square[6][0][0]=m[6][0];	
	square[6][0][1]=m[6][1];	
	square[6][0][2]=m[6][2];	
	square[6][1][0]=m[7][0];	
	square[6][1][1]=m[7][1];	
	square[6][1][2]=m[7][2];	
	square[6][2][0]=m[8][0];	
	square[6][2][1]=m[8][1];	
	square[6][2][2]=m[8][2];

	square[7][0][0]=m[6][3];	
	square[7][0][1]=m[6][4];	
	square[7][0][2]=m[6][5];	
	square[7][1][0]=m[7][3];	
	square[7][1][1]=m[7][4];	
	square[7][1][2]=m[7][5];	
	square[7][2][0]=m[8][3];	
	square[7][2][1]=m[8][4];	
	square[7][2][2]=m[8][5];

	square[8][0][0]=m[6][6];
	square[8][0][1]=m[6][7];
	square[8][0][2]=m[6][8];
	square[8][1][0]=m[7][6];
	square[8][1][1]=m[7][7];
	square[8][1][2]=m[7][8];
	square[8][2][0]=m[8][6];
	square[8][2][1]=m[8][7];
	square[8][2][2]=m[8][8];


}
inline unsigned char squares(const unsigned char &row, const unsigned char &col) {
	if (row<3) {
		return int(col/3);
	} else if (row<6) {
		return int(col/3+3);
	} else if (row<9) {
		return int(col/3+6);
	}
}
int main() {
	unsigned char stop;
	ifstream ifile("sudokus.txt");
	string s1;
	position temp;
	for (int o=0; o<10000;++o) {
		s1.clear();
		getline(ifile,s1);
		k=0;
		for (i=0; i<9; ++i) {
			for (j=0; j<9; ++j) {
				m[i][j]=s1[k]-48;
				++k;
			}
		}
		emptypos.clear();

		gensq();

		bool change=true;
		//int changes=0;
		while (change==true){
			change=false;
			if(rsquares()==true)
			{
				change=true;
				//++changes;
			}
			if(nsquares()==true)
			{
				change=true;
				//++changes;
			}
//cout<<endl;

		}
		
		//cout<<changes<<endl;

		//print();
		for (int i=0; i<81; ++i) {
			if (m[i/9][i%9]==0) {
				temp.r=i/9;
				temp.c=i%9;
				emptypos.push_back(temp);
			}
		}
		//cout<<emptypos.size()<<endl;
		//cout << left;
		//cout.fill( '0' );
		
		//for (int i=0; i<9; ++i) {
		//if (i==6||i==3||i==0) {cout<<"-------------------------------------------------------------------------"<<endl;}
		//for (int j=0; j<9; ++j) {
		//if (j==0||j==3||j==6) {cout<<"|";}
		//if (m[i][j]==0) {
		//rsquares();cout<<"\t";
		//}else {cout<< setw( 1 )<<int(m[i][j]);cout<<"\t";}

		//if (j==8) {cout<<"|";}
		//}cout<<endl;
		//if (i==8) {cout<<"-------------------------------------------------------------------------"<<endl;}
		//}
		
		//cout<<o<<endl;
		//if(o%100==0){cout<<o<<endl;}
		brute();
		//print();
	}

	float cl=(float)clock();
	cout<<"Total time = "<< (cl/(float)CLOCKS_PER_SEC)<<endl;
	cout<<"Average time per sudoku = "<< cl/10000.0<<"msec"<<endl;
	ifile.close();

	/*for(int i=0; i<9; ++i){
		cout<<int(i/3)<<int(i%3)<<" ";}*/
	cin>>stop;
	return 0;
}
inline void brute() {
	bool rollback=false,isgood=false;
	k=num=numss=0;
	while (k<emptypos.size()&&emptypos.size()>0) {
		if (rollback==true) {
			--k;
			rollback=false;
			num=m[emptypos[k].r][emptypos[k].c];
		}
		//++numss;
		isgood=false;
		while (!isgood) {
			++num;
			if (num>9) {
				isgood=rollback=true;
				m[emptypos[k].r][emptypos[k].c]=num=0;
				gensq();
			} else {
				if(possib[emptypos[k].r][emptypos[k].c][num-1]==num){
				isgood=check(emptypos[k].r,emptypos[k].c,num);}
				if (isgood==true) {m[emptypos[k].r][emptypos[k].c]=num; 
				++k; 
				num=0; 
				gensq();
				}
			}
		}
	}
	//cout<<numss<<endl;
	return;
}

inline  bool check(const  char &row, const  char &col,const unsigned  char &num) {
	squarenum=squares(row,col);
	for (int i=0; i<9; ++i) {
		if (num==m[row][i]||num==m[i][col]) {return false;}
	}
	for (int i=0;i<9; ++i) {
		//for (int j=2;j>=0; --j) {
			if (num==square[squarenum][i/3][i%3]) {return false;}
		//}
	}
	return true;
}

inline bool rsquares() {
	char c=0,i=0, j=0, k=0, row, col;
	bool changes=false;
	for (k=0; k<81; ++k) {
		if (m[k/9][k%9]==0) {
			row=k/9;
			col=k%9;
			pvals.clear();
			squarenum=squares(row,col);

			for (i=0;i<9;++i) {
				//for (j=0;j<3;++j) {
					for (c=0; c<9; ++c) {
						if (square[squarenum][i/3][i%3]==sift[c]) {sift[c]=0;}
					}
				//}
			}
			for (i=0; i<81; ++i) {
				//for (j=0; j<9; ++j) {
					if (m[i/9][col]==sift[i%9]||m[row][i/9]==sift[i%9]) {sift[i%9]=0;}
				//}
			}

			for ( j=0; j<9; ++j) {
				if (sift[j]!=0) {

					pvals.push_back(sift[j]);
				}
				possib[row][col][j]=sift[j];

				sift[j]=j+1;
			}

			if(pvals.size()==1){
			m[row][col]=pvals[0];
			gensq();
			changes=true;
			}
			
			//for(int i=0; i<pvals.size(); ++i){cout<<int(pvals[i]);}
			//cout<<endl;
		}
	}

	return changes;
}
char search(const char &num,const bool &rows, char &row, char &col){
	char retnum=0;
	for( i=0; i<9; ++i){
		if(rows)
		{if(possib[row][i][num]==num+1&&m[row][i]==0){++retnum;col=i;}}
		if(!rows)
		{if(possib[i][col][num]==num+1&&m[i][col]==0){++retnum;row=i;}}





		//else return 0;
	}
	return retnum;
}

inline bool nsquares() {
	char row=0, col=0;
	//bool changes=false;
	for(char a=0; a<9; ++a){
		for(char b=0; b<9; ++b){				
			if(search(b,true, a,col)==1){if(check(a,col,b+1)){m[a][col]=b+1;possib[a][col][b]=0;return true;}}
			if(search(b,false, row,a)==1){if(check(row,a,b+1)){m[row][a]=b+1;possib[row][a][b]=0;return true;}}
		}
	}
	return false;
}


/*
in a row or column
if two candidates have the same two possibilites
if three candidates have the same three possibilites
if four candidates have the same four possibilites
remove these possibilities from the rest








--


for(int 






*/