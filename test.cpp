#include<iostream>
using namespace std;
bool issort(int a[],int n){
	
	if(n==0) return true;
	bool ans = issort(a+1, n-1);
	if(ans == false) return false
	else{
		if(a[0] > a[1]) return false;
	}	
	return true;
}

int main() {
	int n;
	cin>> n;
	
	int a[100000];
	for(int i =0;i<n;i++){
		cin>>a[i];
	}

	if(issort(a,n) == 1) cout<<"true";
	else cout<<"false";

}
