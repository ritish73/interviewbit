#include<iostream>
using namespace std;
int main(){
	
	int a[6] = {5,6,9,3,2,8};
	for(int i=0;i<6;i++){
		int min = i;
		for(int j=i+1;j<6;j++){
			if(a[min]>a[j]){
				min = j;
			}
		}
			if(min!=i){
			int temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
		
	}
	for(int i=0;i<6;i++){
		cout<<a[i]<<" ";
	}
}
