#include<bits/stdc++.h>
using namespace std;
int main() {
	int m,n;
	cin>>m>>n;
	int a[m][n];
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>a[i][j];
		}
	}

	int tr=0,lc=0,br=m-1,rc=n-1;

	while(tr<br && lc<rc){

		for(int i=tr; i<=br; i++){
			cout<<a[i][lc]<<", ";
		} lc++;

		for(int i=lc; i<=rc; i++){
			cout<<a[br][i]<<", ";
		} br--;

		for(int i=br; i>=tr; i--){
			cout<<a[i][rc]<<", ";
		} rc--;

		for(int i=rc; i>=lc; i--){
			cout<<a[tr][i]<<", ";
		} tr++;

	}

	cout<<"END";

	

	return 0;
}
