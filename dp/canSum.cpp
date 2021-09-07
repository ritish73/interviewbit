#include<iostream>
using namespace std;

int canSum(int s, int* arr, int n, int* memo){
    if(memo[s]!=-1) return memo[s];
    // cout<<"s : "<<s<<endl;
    bool ans = 0;
    if(s == 0) return 1;
    if(s < 0) return 0;
    
    for(int i=0;i<n;i++){
        int remainder = s-arr[i];
        if(canSum(remainder, arr, n, memo) == true) {
            memo[s] = true;
            return true;
        }
    }
    memo[s] = false;
    return false;
}

int main(){
    int size = 2;
    int arr[] = {2,5};
    int sum = 7;
    int *memo = new int[sum+1];
    for(int i=0;i<=sum;i++){
        memo[i] = -1;
    }
    cout<<canSum(sum, arr, size, memo)<<endl;

    for(int i=0;i<=sum;i++){
        cout<<i<<" : "<<memo[i]<<endl;
    }

}