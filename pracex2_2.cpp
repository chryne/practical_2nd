#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

void sort(float x[], int N){
	for(int i = 1; i < N; i++){
		for(int j = i; j > 0; j--){
			if(x[j] < x[j-1]){
				float temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}else{
				break;
			} 
		}
	}
}

int main(){
	
	//Write your code here
	ifstream score;
	score.open("score1.txt");
	string text;
	int N=20,i=0;
	float x[20]={};
	while(getline(score,text)){
		x[i]=atof(text.c_str());
		i++;
	}
	sort(x,N);
	ofstream result("result.txt");
	int j=N-1,k=1;
	for (int g=1;j>=0;j--,g++){
		if(x[j]==x[j+1]) k=k;
		else k=g;
		result<<k<<":"<<x[j]<<endl;
	}
	
	return 0;
}

