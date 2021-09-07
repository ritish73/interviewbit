s#include<iostream>
using namespace std;
int main(){
	int a[6] = {5,6,9,2,2,8};

	for(int i=1;i<6;i++){
		int t = a[i];
		int j=i-1;
		while(j>=0 && a[j]>t){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = t;
	}
	
	for(int i=0;i<6;i++){
		cout<<a[i]<<" ";
	}
}
