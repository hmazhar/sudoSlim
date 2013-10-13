#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include <string>
#include <sstream>
#include <omp.h>
using namespace std;
inline  bool check(const char &row, const char &col,const unsigned char &num);
inline  void brute();

struct position {unsigned char r,c;};
vector <position> emptypos;
 //vector<unsigned char> pvals1;
 unsigned char num=0;
 char i=0, j=0,k=0, squarenum;
//unsigned int numss=0;
// unsigned char square[3][3];
 unsigned char m[9][9];
// unsigned char sift[9]={1,2,3,4,5,6,7,8,9};

inline  void print() {
	for (i=8; i>=0; --i) {
		if (i==8) {cout<<"-------------"<<endl;}
		for (j=8; j>=0; --j) {
			if (j==8) {cout<<"|";}
			cout<<int(m[i][j]);
			if (j==6||j==3||j==0) {cout<<"|";}
		}
		cout<<endl;
		if (i==6||i==3||i==0) {cout<<"-------------"<<endl;}
	}
}
inline bool gensq(const unsigned char  &test, const  char &row, const char &col) {
/*if(num>=0&&num<=2){
square[0][0]=m[0][num*3+0];	
square[0][1]=m[0][num*3+1];	
square[0][2]=m[0][num*3+2];	
square[1][0]=m[1][num*3+0];	
square[1][1]=m[1][num*3+1];	
square[1][2]=m[1][num*3+2];	
square[2][0]=m[2][num*3+0];	
square[2][1]=m[2][num*3+1];	
square[2][2]=m[2][num*3+2];	
return;
}*/
/*else if(num==1){
square[0][0]=m[0][3];	
square[0][1]=m[0][4];	
square[0][2]=m[0][5];	
square[1][0]=m[1][3];	
square[1][1]=m[1][4];	
square[1][2]=m[1][5];	
square[2][0]=m[2][3];	
square[2][1]=m[2][4];	
square[2][2]=m[2][5];}	
else if(num==2){
square[0][0]=m[0][6];
square[0][1]=m[0][7];
square[0][2]=m[0][8];
square[1][0]=m[1][6];
square[1][1]=m[1][7];
square[1][2]=m[1][8];
square[2][0]=m[2][6];
square[2][1]=m[2][7];
square[2][2]=m[2][8];}*/
/*else if(num>=3&&num<=5){
	square[0][0]=m[3][(num-3)*3+0];	
	square[0][1]=m[3][(num-3)*3+1];	
	square[0][2]=m[3][(num-3)*3+2];	
	square[1][0]=m[4][(num-3)*3+0];	
	square[1][1]=m[4][(num-3)*3+1];
	square[1][2]=m[4][(num-3)*3+2];
	square[2][0]=m[5][(num-3)*3+0];
	square[2][1]=m[5][(num-3)*3+1];
	square[2][2]=m[5][(num-3)*3+2];
return;
}*/
/*else if(num==4){
	square[0][0]=m[3][3];	
	square[0][1]=m[3][4];	
	square[0][2]=m[3][5];	
	square[1][0]=m[4][3];	
	square[1][1]=m[4][4];	
	square[1][2]=m[4][5];	
	square[2][0]=m[5][3];	
	square[2][1]=m[5][4];	
	square[2][2]=m[5][5];}	
else if(num==5){
	square[0][0]=m[3][6];
	square[0][1]=m[3][7];
	square[0][2]=m[3][8];
	square[1][0]=m[4][6];
	square[1][1]=m[4][7];
	square[1][2]=m[4][8];
	square[2][0]=m[5][6];
	square[2][1]=m[5][7];
	square[2][2]=m[5][8];}*/
/*else if(num>=6&&num<=8){
	square[0][0]=m[6][(num-6)*3+0];	
	square[0][1]=m[6][(num-6)*3+1];	
	square[0][2]=m[6][(num-6)*3+2];	
	square[1][0]=m[7][(num-6)*3+0];	
	square[1][1]=m[7][(num-6)*3+1];	
	square[1][2]=m[7][(num-6)*3+2];	
	square[2][0]=m[8][(num-6)*3+0];	
	square[2][1]=m[8][(num-6)*3+1];	
	square[2][2]=m[8][(num-6)*3+2];
return;
}	*/
/*else if(num==7){
	square[0][0]=m[6][3];	
	square[0][1]=m[6][4];	
	square[0][2]=m[6][5];	
	square[1][0]=m[7][3];	
	square[1][1]=m[7][4];	
	square[1][2]=m[7][5];	
	square[2][0]=m[8][3];	
	square[2][1]=m[8][4];	
	square[2][2]=m[8][5];}	
else if(num==8){
	square[0][0]=m[6][6];
	square[0][1]=m[6][7];
	square[0][2]=m[6][8];
	square[1][0]=m[7][6];
	square[1][1]=m[7][7];
	square[1][2]=m[7][8];
	square[2][0]=m[8][6];
	square[2][1]=m[8][7];
	square[2][2]=m[8][8];
}*/


	if(row<3){j=0;}
	else if(row<6){j=3;}
	else if(row<9){j=6;}
	i=(col/3)*3;
	 if(test==m[j+0][i+0]){return false;}	
else if(test==m[j+0][i+1]){return false;}	
else if(test==m[j+0][i+2]){return false;}	
else if(test==m[j+1][i+0]){return false;}	
else if(test==m[j+1][i+1]){return false;}	
else if(test==m[j+1][i+2]){return false;}	
else if(test==m[j+2][i+0]){return false;}	
else if(test==m[j+2][i+1]){return false;}	
else if(test==m[j+2][i+2]){return false;}	
return true;

}
/*inline unsigned char squares(const unsigned char &row, const unsigned char &col) {
	if (row<3) {
		//if (col>=0&&col<3) {return 0;}
		///if (col>=3&&col<6) {return 1;}
		///if (col>=6&&col<9) {return 2;}
		return int(col/3);
	} else if (row<6) {
		//if (col>=0&&col<3) {return 3;}
		//if (col>=3&&col<6) {return 4;}
		//if (col>=6&&col<9) {return 5;}
		return int(col/3+3);
	} else if (row<9) {
		//if (col>=0&&col<3) {return 6;}
		//if (col>=3&&col<6) {return 7;}
		//if (col>=6&&col<9) {return 8;}
		return int(col/3+6);
	}
}*/
/*inline void pvals(const unsigned char &row,const unsigned char &col) {
	pvals1.clear();
	squarenum=squares(row,col);
	for (i=3;i>=0; --i) {
		for (j=3; j>=0; --j) {
			if (square[squarenum][i][j]==sift[i]) {sift[i]=0;}
		}
	}
	for (i=8; i>=0; --i) {
		if (m[i][col]==sift[i]||m[row][i]==sift[i]) {sift[i]=0;}
	}
	for (j=0; j>=9; ++j) {
		if (sift[j]!=0) {
			pvals1.push_back(sift[j]);
			sift[j]=j+1;
		}
	}
}*/
int main() {
unsigned char stop;
	ifstream ifile("sudokus.txt");
	 string s1;

	position temp;
	for (int o=0; o<10000;++o) {
		s1.clear();
		getline(ifile,s1);
		k=0;
		for (i=8; i>=0; --i) {
			for (j=8; j>=0; --j) {
				m[i][j]=s1[k]-48;
				++k;
			}
		}
		emptypos.clear();
			for (i=0; i<81; ++i) {
				if (m[i/9][i%9]==0) {
					temp.r=i/9;
					temp.c=i%9;
					emptypos.push_back(temp);
				}
			}

		brute();
		//if(o%100==0){cout<<o<<endl;}
		//print();
	}
	float cl=(float)clock();
	cout<<"Total time = "<< (cl/(float)CLOCKS_PER_SEC)<<endl;
	cout<<"Average time per sudoku = "<< cl/10000.0<<"msec"<<endl;
	ifile.close();

/*for(int i=0; i<9; ++i){
cout<<int(i%3+i/9)<<endl;

}*/
	cin>>stop;
	return 0;
}

inline void brute() {
	bool rollback=false,isgood=false;
	k=num=0;
	while (k<emptypos.size()&&emptypos.size()>0) {
		if (rollback==true) {--k;rollback=false;num=m[emptypos[k].r][emptypos[k].c];}
		isgood=false;
		while (!isgood) {
			++num;
			if (num>9) {
				isgood=rollback=true;
				m[emptypos[k].r][emptypos[k].c]=num=0;
				/*gensq();*/
			} else {
				isgood=check(emptypos[k].r,emptypos[k].c,num);
				if (isgood==true) {m[emptypos[k].r][emptypos[k].c]=num; /*gensq();*/ ++k; num=0; }
			}
		}
	}
	return;
}

inline  bool check(const  char &row, const  char &col,const unsigned  char &num) {
/*	gensq(squares(row,col));
	for (i=2;i>=0; --i) {
		for (j=2;j>=0; --j) {
			if (num==square[i][j]) {return false;}
		}
	}*/
	for (i=8; i>=0; --i) {
		if (num==m[row][i]||num==m[i][col]) {return false;}
	}
	if(!gensq(num,row,col)){return false;}
	/*	if(row<3){j=0;}
	else if(row<6){j=3;}
	else if(row<9){j=6;}
	i=(col/3)*3;
	 if(num==m[j+0][i+0]){return false;}	
else if(num==m[j+0][i+1]){return false;}	
else if(num==m[j+0][i+2]){return false;}	
else if(num==m[j+1][i+0]){return false;}	
else if(num==m[j+1][i+1]){return false;}	
else if(num==m[j+1][i+2]){return false;}	
else if(num==m[j+2][i+0]){return false;}	
else if(num==m[j+2][i+1]){return false;}	
else if(num==m[j+2][i+2]){return false;}	
return true;*/
	
	return true;
}