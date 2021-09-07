#include<iostream>
using namespace std;
void ratbahar(char input[10][10],int output[][10],int m,int n,int i,int j){
if(i==m-1 && j==n-1){
	output[i][j] = 1;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<output[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
	return;
}
if(i>m-1 || j>n-1){
	return;
}
if(input[i][j]=='x'){
	return;
}
output[i][j]= 1;
ratbahar(input,output,m,n,i,j+1);
ratbahar(input,output,m,n,i+1,j);
output[i][j]= 0;
return;
}
int main() {
	char input[10][10] = {
		"0000",
		"00x0",
		"000x",
		"0x00"
	
	};
	int output[10][10]={0};
	ratbahar(input,output,4,4,0,0);
	return 0;
}
