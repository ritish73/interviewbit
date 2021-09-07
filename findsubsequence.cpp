#include<bits/stdc++.h>
using namespace std;

void helper(string s, string out, int n, int &cnt){
	if(s.length() == 0){
		cout<<out<<" ";
		cnt++;
		return;
	}
		
	helper(s.substr(1,n), out + s[0], n, cnt);
	helper(s.substr(1,n), out, n, cnt);
	return;
}
int main() {
	string s;
	cin>>s;
	string out;
	int cnt=0;
	helper(s, out, s.length(), cnt);
	cout<<endl<<cnt;
}
