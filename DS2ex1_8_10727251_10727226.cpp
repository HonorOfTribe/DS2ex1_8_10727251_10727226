//10727226 ��l�s
//10727251 �d�Y�E 
#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<time.h>
#include<cstring>
#include<string.h>
#include<fstream>
#include<math.h>
using namespace std ;
typedef char Str20[40] ;

struct info{
	int num = 0 ;
	int degree = 0 ;	
	int height = 1 ;
};

class sort{
	public :
		void minheap(vector<info> &sort, int j){ //�̤p��n 
			j++ ;
			int i = 0 ;
			i = j / 2 ;
			info temp ;
			while(i != 0){ //�@�����ڤ�� 
				if(sort[j - 1].degree < sort[i - 1].degree){ //��l�`�I�Ȥ���`�I�p�N�洫 
					temp.num = sort[j - 1].num ;
					temp.degree = sort[j - 1].degree ;
					sort[j - 1].num = sort[i - 1].num ;
					sort[j - 1].degree = sort[i - 1].degree ;
					sort[i - 1].num = temp.num ;
					sort[i - 1].degree = temp.degree ;	
				}
				j = i ;
				i = i / 2 ;//�W�@�Ӥ��`�I 
			}
		}
		int cacu(vector<info> sort, int j){//�p�⦹�h���Ӽ� 
			int num = 1 ;
			while(j != 0 && sort[j].height == sort[j - 1].height){
				num++ ;
				j-- ;
			}
			return num ;
		}
		void minmaxheap(vector<info> &sort, int j){//�̤p�̤j��n 
			j++ ;
			int i = 0 ;
			i = j / 2 ;
			info temp ;
			while(i != 0){ //�@�����ڤ�� 
				if(sort[j - 1].height % 2 == 1 && sort[i - 1].height % 2 == 0){ //����`�I�b���Ƽh��(���Ƽh���̤j��n�h) 
					if(sort[j - 1].degree > sort[i - 1].degree){ //��l�`�I����`�I�j�N�洫 
						temp.num = sort[j - 1].num ;
						temp.degree = sort[j - 1].degree ;
						sort[j - 1].num = sort[i - 1].num ;
						sort[j - 1].degree = sort[i - 1].degree ;
						sort[i - 1].num = temp.num ;
						sort[i - 1].degree = temp.degree ;	
						j = i ;
					}
				}
				else if(sort[j - 1].height % 2 == 0 && sort[i - 1].height % 2 == 1){ //����`�I�b�_�Ƽh��(�_�Ƽh���̤p��n�h) 
					if(sort[j - 1].degree < sort[i - 1].degree){ //��l�`�I����`�I�p�N�洫 
						temp.num = sort[j - 1].num ;
						temp.degree = sort[j - 1].degree ;
						sort[j - 1].num = sort[i - 1].num ;
						sort[j - 1].degree = sort[i - 1].degree ;
						sort[i - 1].num = temp.num ;
						sort[i - 1].degree = temp.degree ;
						j = i ;	
					}
				}
				else if(sort[j - 1].height % 2 == 0 && sort[i - 1].height % 2 == 0){  //�̤j��n�h�P�̤j��n�h����� 
					if(sort[j - 1].degree > sort[i - 1].degree){ //��l�`�I����`�I�j�N�洫  
						temp.num = sort[j - 1].num ;
						temp.degree = sort[j - 1].degree ;
						sort[j - 1].num = sort[i - 1].num ;
						sort[j - 1].degree = sort[i - 1].degree ;
						sort[i - 1].num = temp.num ;
						sort[i - 1].degree = temp.degree ;
						j = i ;
						i = i / 2 ;	//�Ĥ@���H�᪺������O�P�W�W�h�����`�I��� �ҥH�n�h���H2�@�� 
					}
				}
				else if(sort[j - 1].height % 2 == 1 && sort[i - 1].height % 2 == 1){ //�̤p��n�h�P�̤p��n�h����� 
					if(sort[j - 1].degree < sort[i - 1].degree){ //��l�`�I����`�I�p�N�洫  
						temp.num = sort[j - 1].num ;
						temp.degree = sort[j - 1].degree ;
						sort[j - 1].num = sort[i - 1].num ;
						sort[j - 1].degree = sort[i - 1].degree ;
						sort[i - 1].num = temp.num ;
						sort[i - 1].degree = temp.degree ;
						j = i ;
						i = i / 2 ;	//�Ĥ@���H�᪺������O�P�W�W�h�����`�I��� �ҥH�n�h���H2�@�� 
					}
				}
				i = i / 2 ;
			}
		}
		void mission1(string fileName){
		vector<info> sort;
		int i = 0, k = 0, j = 0 ;
		char c ;
		Str20 useless = "" ;
		info work ;
		FILE *infile = NULL;
		FILE *outfile = NULL; 	
	    infile = fopen(("input"+fileName+".txt").c_str(),"r");
	    if ( infile == NULL)
			cout << fileName << "does not exist!"<< endl;
		else {  
			while(j < 3 ){        //�e3�� 
	        	fscanf(infile, "%c", &c) ;
	        	if ( c == '\n')
	        	    j++;
	        	 	        	
			}			
	    	while(fscanf(infile, "%c", &c) != -1){
	    		if(k == 7 && c == '\t'){ //�u�ݭn���~�H�� ��L�������n(�]�L7��\t��U�@�ӴN�O���~�H��) 
	    			fscanf(infile, "%s", useless) ;
	    			sort.push_back(work) ;
	    			sort[i].degree = atoi(useless) ;
	    			sort[i].num = i + 1 ;
	    			if(i != 0){
	    				sort[i].height = sort[i - 1].height ;
	    				if(cacu(sort, i) > pow(2, sort[i].height - 1)){ //�p�G��e�o�h�\���F�N�n���U�@�h�\ 
	    					sort[i].height++ ;
						}
					}
	    			minheap(sort, i) ;
	    			i++ ;
				}
				if(c == '\n'){
					k = 0 ;
				}
				if(c == '\t'){
					k++ ;
				}
			}
			i-- ;
			while(i != 0 && sort[i].height == sort[i - 1].height){
				i-- ;
			}
			cout << sort[0].num << "\t" << sort[0].degree << "\n" ; 
			cout << sort[sort.size() - 1].num << "\t" << sort[sort.size() - 1].degree << "\n" ;
			cout << sort[i].num << "\t" << sort[i].degree << "\n" ;
			for(i = 0 ; i < sort.size() ; i++){
				cout << sort[i].num << "\t" << sort[i].degree << "\t" << sort[i].height << "\n" ;
			}
		}
	}
	void mission2(string fileName){
		vector<info> sort;
		int i = 0, k = 0, j = 0 ;
		char c ;
		Str20 useless = "" ;
		info work ;
		FILE *infile = NULL;
		FILE *outfile = NULL; 	
	    infile = fopen(("input"+fileName+".txt").c_str(),"r");
	    if ( infile == NULL)
			cout << fileName << "does not exist!"<< endl;
		else {
			while(j < 3 ){        //�e3�� 
	        	fscanf(infile, "%c", &c) ;
	        	if ( c == '\n')
	        	    j++;
	        	 	        	
			}			
	    	while(fscanf(infile, "%c", &c) != -1){
	    		if(k == 7 && c == '\t'){
	    			fscanf(infile, "%s", useless) ;
	    			sort.push_back(work) ;
	    			sort[i].degree = atoi(useless) ;
	    			sort[i].num = i + 1 ;
	    			if(i != 0){
	    				sort[i].height = sort[i - 1].height ;
	    				if(cacu(sort, i) > pow(2, sort[i].height - 1)){
	    					sort[i].height++ ;
						}
					}
	    			minmaxheap(sort, i) ;
	    			i++ ;
				}
				if(c == '\n'){
					k = 0 ;
				}
				if(c == '\t'){
					k++ ;
				}
			}
			i-- ;
			while(i != 0 && sort[i].height == sort[i - 1].height){
				i-- ;
			}
			cout << sort[0].num << "\t" << sort[0].degree << "\n" ; 
			cout << sort[sort.size() - 1].num << "\t" << sort[sort.size() - 1].degree << "\n" ;
			cout << sort[i].num << "\t" << sort[i].degree << "\n" ;
		}
	}
};
int main(){
	sort a ;
	int m ;
	Str20 fileName = "" ;
	cout << "enter 0, 1, 2:" ;
	cin >> m ;
	while(m != 0){
		cin >> m ;
		if(m == 1){
			cout << "enter a file:" ;
			cin >> fileName ;
			a.mission1(fileName) ;
		}
		else if(m == 2){
			cout << "enter a file:" ;
			cin >> fileName ;
			a.mission2(fileName) ;
		}
		cout << "enter 0, 1, 2:" ;
	}
}
