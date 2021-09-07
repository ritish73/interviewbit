#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a, int b){
    string o1 = to_string(a) + to_string(b);
    string o2 = to_string(b) + to_string(a);
    int x = stoi(o1);
    int y = stoi(o2);
    return x > y? a<b: a>b;

}

string largestNumber(const vector<int> &A) {
    sort(A.begin(), A.end(), cmp);
    string ans = "";
    for(int i=0; i<A.size(); i++){
        ans = ans + to_string(A[i]);
    }

    return ans;
}
int main(){
	vector<int> A{3, 30, 34, 5, 9};
	cout<<largestNumber(A);
}
 
 
