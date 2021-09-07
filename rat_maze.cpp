#include<iostream>
using namespace std;

bool printAllMazePaths(char maze[10][10], int soln[10][10], int i, int j, int m, int n ){
	// base case if reaches last cell
	if(i == m && j == n){
		
		// print the path;
		for(int i=0; i<=m; i++){
			for(int j=0; j<=n; j++){
				cout<<soln[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		// put value of last cell = 1
		soln[m][n] = 1;
		return true;
	}
	
	// check for no path cells
	if(i>m || j>n){
		return false;
	}
	if(maze[i][j] == 'X'){
		return false;	
	}
	
	
	// Assume solution exists
	soln[i][j] = 1;
	
	bool rightpath = printAllMazePaths(maze, soln, i, j+1, m, n);
	bool downpath = printAllMazePaths(maze, soln, i+1, j, m, n);
	
	
	// backtracking
	soln[i][j] = 0;
	
	
	if(rightpath || downpath){
		return true;
	}
	return false;
	
}

int main(){
	char maze[10][10] = {
						"0000",
						"00X0",
						"000X",
						"0X00"
	};
	int m = 4,n = 4;
	int soln[10][10] =  {0};
	bool ans = printAllMazePaths(maze, soln, 0, 0, m-1, n-1);
	if(ans == false){
		cout<<"no paths found";
	}
}
