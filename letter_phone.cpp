#include<bits/stdc++.h>
using namespace std;



void print(vector<string> v){
     for(int i=0; i<v.size(); i++){
//         cout<<v[i]<<endl;
     }
 }
 


vector<string> res;
vector<string> helper(string A){

    if(A == "\0"){
//    	cout<<"base case"<<endl;
        vector<string> v(1,"");
        return v;
    }

    vector<string> ans = helper(A.substr(1));
    char ch = A[0];
    string temp;
    switch(ch){
        case '0': temp = " "; break;
        case '1': temp = "1"; break;
        case '2': temp = "abc"; break;
        case '3': temp = "def"; break;
        case '4': temp = "ghi"; break;
        case '5': temp = "jkl"; break;
        case '6': temp = "mno"; break;
        case '7': temp = "pqrs"; break;
        case '8': temp = "tuv"; break;
        case '9': temp = "wxyz"; break;
    }

    
	res.clear();
    for(int j=0; j<temp.length(); j++){
        for(int i=0; i<ans.size(); i++){
            res.push_back(temp[j] + ans[i]);
        }
    }
//	cout<<"res : ";
	print(res);
	cout<<endl;
//	cout<<"ans : ";
	print(ans);
	cout<<endl;
    return res;
    

}

vector<string> letterCombinations(string A) {
    vector<string> ans;
    helper(A);
}

int main(){
	string A = "234";
	vector<string> f = letterCombinations(A);
	cout<<endl;
	print(f);
	
}
