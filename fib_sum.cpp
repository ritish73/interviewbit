#include<bits/stdc++.h>
using namespace std;

int ans;
void helper_fibsum(int A){
	if(A<=0) return;
    ans+=1;
//    cout<<"ans : "<<ans<<" A: "<<A<<endl;
    int prev = 1;
    int num = 1;

    while(num<=A){
        int t = num + prev;
        prev = num;
        num = t;
        if(num>A) {
            num = prev;
            break;
        }
    }
    // num is just smaller fib number than current number
    helper_fibsum(A-num);
    return;

}


int fibsum(int A) {
    ans = 0;
    helper_fibsum(A);
    return ans;
}

int main(){
	int n;
	cin>>n;
	cout<< fibsum(n);
}

