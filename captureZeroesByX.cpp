#include<bits/stdc++.h>
using namespace std;


int m = 0 , n = 0;
vector<vector<bool>> visited;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void markNeighbouringZeroes(vector<vector<char> > &A, int i, int j){
	cout<<"g";
    visited[i][j] = 1;

    for(int k=0; k<4; k++){
        int newx = i + dx[k];
        int newy = j + dy[k];

        if(i >=0 && j>=0 && i<m && j<n && A[newx][newy] == 'O' && visited[newx][newy] == 0){
            A[newx][newy] = '1';
            markNeighbouringZeroes(A, newx, newy);
        }

    }
    return;


}

void solve(vector<vector<char> > &A) {
    // mark all such zeroes by a special character say 1 who are not surrounded by 4 X's
    m = A.size();
    n = A[0].size();

    visited.resize(m);
    for(int i=0; i<m; i++){
        visited[i].resize(n);
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = 0;        
        }  
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            // check from corner
            if(i == 0 || j == 0 || i == m-1 || j == n-1){
                if(A[i][j] == 'O'){ 
                    A[i][j] = '1';   
                    markNeighbouringZeroes(A, i, j);
                    cout<<"h";
                }
            }
            
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(A[i][j] == 'O') {
                A[i][j] = 'X';
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(A[i][j] == '1') {
                A[i][j] = 'O';
            }
        }
    }
    
}


int main(){
	int m = 1;
	int n = 1;
	
	vector<vector<char>> v(m, vector<char> (n));
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cin>>v[i][j];
		}
	}
	
	solve(v);
	
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
