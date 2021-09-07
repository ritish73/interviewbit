#include<iostream>
using namespace std;
string helper(string s,int n){
	cout<<"at recursive call with n : "<<n<<" and string is : "<<s<<endl;
	if(n==1) return s;
	string smalls = helper(s.substr(1,n), n-1);
	cout<<smalls<<endl;
	if(s[0] == s[1]){
		
		for(int i = n+1; i >= 1; i--){
			
			s[i+1] = s[i];
			cout<<s[0]<<s[1]<<s[2]<<s[3]<<s[4]<<endl;
		}
		s[1] = '*';
		
	} else {
		s = s[0] + smalls;
	}
	return s;
}

int main() {
	char s[100000];
	cin.getline(s,100000);
	

	string ans = helper(s,5);
	cout<<s;
//	cout<<s.substr(2,len);

}
