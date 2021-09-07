#include<iostream>
using namespace std;
void helper(string s, int index , int n){
	cout<<"at recursive call with n : "<<n<<" and string is : "<<s<<endl;
	if(index==n-1) return;
	helper(s, index+1, n);
	
	if(s[index] == s[index+1]){
		
		for(int i = n; i >= index+1; i--){
			
			s[i+1] = s[i];
			cout<<s[0]<<s[1]<<s[2]<<s[3]<<s[4]<<endl;
		}
		s[index+1] = '*';
		
	} 
	
}

int main() {
	string s;
	cin>>s;
	int n = s.length();
	helper(s,0,n);
	cout<<s;
//	cout<<s.substr(2,len);

}
