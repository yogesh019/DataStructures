#include<iostream>
#include<queue>
#include<limits>
using namespace std;


int minFallingSum(int  arr[][100],int N,int M){
	queue<pair<pair<int,int>,int>>Q;
	int Min=numeric_limits<int>::max();
	for(int i=0;i<M;i++){
		Q.push(make_pair(make_pair(0,i),arr[0][i]));
	}
	while(!Q.empty()){
		pair<pair<int,int>,int>P=Q.front();
		Q.pop();
		if(P.first.first==N-1){
			Min=min(Min,P.second);
			continue;
		}
		Q.push(make_pair(make_pair(P.first.first+1,P.first.second),P.second+arr[P.first.first+1][P.first.second]));
		if(P.first.second!=0)
			Q.push(make_pair(make_pair(P.first.first+1,P.first.second-1),P.second+arr[P.first.first+1][P.first.second-1]));
		if(P.first.second==M-1)
			continue;
		Q.push(make_pair(make_pair(P.first.first+1,P.first.second+1),P.second+arr[P.first.first+1][P.first.second+1]));
	}
	return Min;
}

int minFallingSum2(int arr[][100],int x,int y,int N,int M){
	if(y>=M||y<0)
		return numeric_limits<int>::max();
	if(x==N-1)return arr[x][y];
	return arr[x][y]+min(minFallingSum2(arr,x+1,y,N,M),min(minFallingSum2(arr,x+1,y+1,N,M),minFallingSum2(arr,x+1,y-1,N,M)));

}

	
int main(){
	int arr[100][100];
	int N=3,M=3;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cin>>arr[i][j];
		}
	}
	cout<<"answer is: "<<minFallingSum(arr,3,3)<<endl;
	int Min=numeric_limits<int>::max();
	for(int i=0;i<3;i++){
		Min=min(Min,minFallingSum2(arr,0,i,3,3));
	}
	cout<<"anser is: "<<Min<<endl;

	
	return 0;
}

