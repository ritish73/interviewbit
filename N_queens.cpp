#include<iostream>
using namespace std;

bool isSafe(int board[10][10], int i, int j, int n){
	// vertical
	for(int r=0; r<i; r++){
		if(board[r][j] == 1) return false;
	}
	//top left diagonal
	int x = i;
	int y = j;
	while(x>=0 && y>=0){
		if(board[x][y] == 1) return false;
		x--;
		y--;
	}
	//top right diagonal
	x = i;
	y = j; 
	while(x>=0 && y<n){
		if(board[x][y] == 1) return false;
		x--;
		y++;
	}
	return true;
}

bool placeQueens(int board[10][10], int i, int n){
	// base case
	if(i == n){
		// print
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(board[i][j] == 1){
					cout<<"Q ";
				} else {
					cout<<"_ ";
				}
			}
			cout<<endl;
		}
		cout<<endl;
		//return false if u wanna print all configrations else return true if you wanna print only the first configration
		return false;
	}
	
	
	// do your work . For loop to check if queen can be placed in any of the column for given i
	for(int j=0; j<n; j++){
		if(isSafe(board, i, j, n)){
			// place the queen
			board[i][j] = 1;
			// check if next queen can be placed
			bool nextQueenCanBePlaced = placeQueens(board, i+1, n);
			if(nextQueenCanBePlaced){
				return true;
			}
			
			// if not possible then use another column for placing current queen as if we reach here for loop continues
			board[i][j] = 0;
			
		}
	}	
	return false;
}

int main(){
	
	int board[10][10] = {0};
	int n;
	cout<< "enter number of queens : ";
	cin>>n;
	bool ans = placeQueens(board, 0, n);
	return 0;

}
