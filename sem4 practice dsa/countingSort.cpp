#include<iostream>
using namespace std;
int main(){
	int a[9] = {5,8,4,5,2,4,8,7,7};
	int b[9] = {0,0,0,0,0,0,0,0,0};
	int count[10] = {0,0,0,0,0,0,0,0,0,0};
	for(int i=0;i<9;i++){
		++count[a[i]];
	}
	for(int i=1;i<9;i++){
		count[i] = count[i] + count[i-1];
	}
	for(int i=8;i>=0;i--){
		--count[a[i]];
		b[count[a[i]]] = a[i];
	}
	for(int i=0;i<9;i++){
		cout<<b[i]<<" ";
	}
}
