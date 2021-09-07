#include<bits/stdc++.h>
using namespace std;

vector<int> dNums(vector<int> &A, int B) {
    
    vector<int> ans;
//    if(B==1){
//        for(int i: A) ans.push_back(1);
//        return ans;
//    }
    unordered_map<int , int> m; 
    int cnt=0;
    for(int k=0; k<B; k++){
        if(m.find(A[k]) != m.end()){
            m[A[k]]++;
        } else {
            m.insert({A[k],1});
            cnt++;
        }   
    }
    ans.push_back(cnt);
//    cout<<cnt<<endl;
    for(int i=1; i<=A.size() - B; i++){
        // cnt = 0;
        m[A[i-1]]--;
        if( m[A[i-1]]==0){
//            cnt--;
        }
        
        if(m.find(A[i+B-1]) != m.end()){  
            m[A[i+B-1]]++;
        } else{
            m.insert({A[i+B-1], 1});
//            cnt++;
        }
        
        
//        cout<<cnt<<endl;
        int cont=0;
        for(auto i: m){
//        	cout<<i.first<<" "<<i.second<<endl;
        	if(i.second!=0)cont++;
		}
//		cout<<"cont  : " << cont<<endl;
//        cout<<endl;
        ans.push_back(cont);
    }
    
    return ans;

}

int main(){
	vector<int> A;
	int B;
	cin>>B;
	for(int i=0; i<B; i++){
		int el;
		cin>>el;
		A.push_back(el);
	}
	int b;cin>>b;
	vector<int> a = dNums(A, b);
	for(int i: a){
		cout<<i<<" ";
	}
}
//6
//1 2 1 3 4 3
//3

//10
//80 18 80 80 80 80 80 80 94 18 
//8

