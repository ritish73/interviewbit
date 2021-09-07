#include<iostream>
using namespace std;

long long int gridTraveller(int m, int n, int **memo){

    if(memo[m][n]!=-1 || memo[n][m]!=-1){
        return memo[m][n];
    }
    long long int ans = 0;
    if(m==0||n==0){
        ans = 0;
    }
    if(m==1||n==1){
        ans = 1;
    } 
    else{
        ans = gridTraveller(m-1,n,memo)+gridTraveller(m,n-1,memo);
    }
    
    memo[m][n] = ans;
    memo[n][m] = ans;
    return ans;
}

int main(){
    int rows = 18;
    int cols = 18;
    int **memo = new int*[rows+1];
    for(int i=0; i<=rows;i++){
        memo[i] = new int[cols+1];
    }
    for(int i=0; i<=rows;i++){
        for(int j=0; j<=cols;j++){
            memo[i][j] = -1;
        }
    }
    cout<<"GridTraveller : "<<gridTraveller(rows ,cols, memo)<<endl;

    for(int i=0; i<=rows;i++){
        for(int j=0; j<=cols;j++){
            cout<<memo[i][j]<<" ";
        }
        cout<<endl;
    }
   
}