#include<iostream>
using namespace std;

void function(int index, int n, string out, int &count){
	if(index == n){
//		cout<<out<<endl;
		count++;
		return;
	}
	
	function(index+1, n, out+'a', count);
//	cout<<*(out.end()-1)<<"//////"<<endl;
	if(*(out.end()-1) != 'b') {
		function(index+1, n, out+'b', count);
	}
	
}

int main(){
	int testcases;
	cin>>testcases;
	int n=0;
	for(int i=0; i<testcases; i++){
		cin>>n;
		string out;
		int count=0;
		function(0, n, out, count);
		cout<<"#"<<i+1<<" : "<<count<<endl;
	}
}
