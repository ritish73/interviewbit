#include<bits/stdc++.h>
using namespace std;


bool canPlaceAtCol(int queen, int col, vector<string> v, int n){

       for(int row=0; row<queen; row++){
       if(v[row][col]=='Q'){
           return false; 
       }
   }


    // check upper diagonals and upwards vertical
    int i = queen;
    int j = col;

    while(i>=0 && j>=0){
        if(v[i][j] == 'Q'){
            return false;
        }
        i--;
        j--;
    }

    i = queen;
    j = col;

    while(i>=0 && j<n){
        if(v[i][j] == 'Q'){
            return false;
        }
        i--;
        j++;
    }


    return true;

}

bool nqueens(int queen, vector<string> v, int n, vector<vector<string>> &ans){
    // base case
    if(queen == n) {
    	
    
    	ans.push_back(v);
    	
        return false;
    }

    // check for each col whether we can place the queen
    for(int col=0; col<n; col++){
        bool canPlace = canPlaceAtCol(queen, col, v, n);
        if(canPlace){
            v[queen][col] = 'Q';
            bool queenRakhPaye = nqueens(queen+1, v, n ,ans);
            if(queenRakhPaye) {return true;}
            v[queen][col] = '.';
        }
    }
    return false;
}

void print(vector<vector<string>> v){
     for(int i=0; i<v.size(); i++){
         for(int j=0; j<v[0].size(); j++){
             cout<<v[i][j]<<" ";
         }
         cout<<endl;
     }
 }
 
 
vector<vector<string> > solveNQueens(int A, vector<vector<string>> &ans) {
    if(A==1) return vector<vector<string>>(1,vector<string>(1,"Q"));
    if(A<=3){
        vector<vector<string>> v1;
        return v1;
    }


	vector<string> v;
	
	for(int k=0; k<A; k++){
		string str;
		for(int i=0; i<A; i++){
		    str = str.append(".");
		}
		v.push_back(str);
	}
		

    bool a = nqueens(0, v, A, ans);
    return ans;
    
}

int main(){

	
	
	int A = 4;
	vector<vector<string>> ans;
	ans = solveNQueens(A, ans);
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++){
    	for(int j=0; j<ans[i].size(); j++){
	    	cout<<ans[i][j]<<endl;
		}
		cout<<endl<<endl;
	}
	
	
	
//	print(ans);
}
