#include<iostream>
using namespace std;

int fib(int n, int* memo){
    if(memo[n]!=-1) return memo[n];
    int ans = 0;
    if(n<=2) ans =  1;
    else ans =  fib(n-1, memo)+fib(n-2, memo);       
    memo[n] = ans;
    return ans; 
}

int main(){
    int n = 40;
    int *memo = new int[n+1];
    for(int i=0;i<=n;i++){
        memo[i] = -1;
    }
    cout<<fib(n, memo);
}