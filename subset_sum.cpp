#include<bits/stdc++.h>
using namespace std;

void subsetsOfSums(int *input, int sum, int * out, int n, int m){
	if(sum == 0){
		for(int i=0; i<m; i++){
			cout<<out[i]<<" ";
		}
		cout<<endl;
		return;
	}
	if(sum < 0 || n == 0) return;
	subsetsOfSums(input+1, sum, out, n-1, m);
	out[m] = input[0];
	subsetsOfSums(input+1, sum-input[0], out , n-1, m+1);
	
}

int main(){
	int out[10000];
	int n;
	cin>>n;
	int input[n];
	for(int i=0; i<n; i++){
		cin>>input[i];
	}
	int sum;
	cin>>sum;
	subsetsOfSums(input,sum,out,n,0);
}
