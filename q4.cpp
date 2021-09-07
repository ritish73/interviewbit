#include<bits/stdc++.h>
using namespace std;

void helper(string s, int n, string &out){
	if(n==0) return;
	helper(s,n-1,out);
	if(s[n-1]=='x'){
		out = out + 'x';
	} else {
		
		int l = out.length();
		
		int index = 0;
		for(int i = 0; i<l; i++){
			if(out[i] == 'x'){
				index = i;
				out[index] = s[n-1];
				out = out + 'x';
				return ;
			} 
		}	
		out = out + s[n-1];
		
	}
	return;
}
int main() {
	string s;
	cin>>s;
	
	string out;
	helper(s,s.length(),out);
	cout<<out;
}
