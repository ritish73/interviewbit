#include<bits/stdc++.h>
using namespace std;
void findalloccurences(int* arr, int i, int n, int m, vector<int> &v){
	if(i == n) return;
	findalloccurences(arr, i+1, n, m, v);
	if(arr[i] == m){
		v.push_back(i);
	}
	
}

int main() {
	int n,m;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin>>m;
	vector<int> v;
	findalloccurences(arr,0,n,m,v);
	for(int i=0; i<v.size();i++){
		cout<<v[i]<<" ";
	}
}
