#include<bits/stdc++.h>
using namespace std;
pair<int,int> helper(vector<int> A , int s, int e){
	if(s==e) return pair<int,int>({A[s] , A[s]});
//    if(s>e) return pair<int,int>({INT_MIN , INT_MAX});
    int m = l + (e-s)/2;
    pair<int,int> sa1 = helper(A , s, m);
    pair<int,int> sa2 = helper(A , m+1, e);
    pair<int,int> fa;
    fa.first = max(sa1.first , sa2.first);
    fa.second = min(sa1.second , sa2.second);
    cout<<s<<" , "<<e<<" , "<<fa.first<<" "<<fa.second<<endl;
    return fa;
}

int solve(vector<int> &A) {
//    pair<int,int> ans({INT_MIN , INT_MAX});
    int s=0 , e=A.size()-1;
    pair<int,int> a = helper(A , s, e);
    cout<<a.first<<" "<<a.second;
    return (a.first + a.second);
}

int main(){
	vector<int> A;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int ele; cin>>ele;
		A.push_back(ele);
	}
	cout<< solve(A);
}
//-2 1 -4 5 3
