#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> ans){
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[0].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

void generateMatrix(int n) {
        
        // if(n==1) return vector<vector<int>>(1,vector<int>(1,1));
        vector<vector<int>> ans(n,vector<int>(n,0));
        // fix i and do j++ for n times;
        
        // now fix j and do i++ for n-1 times
        
        // now fix i and do j-- for n-1 times
        
        // fix j do i-- for n-2 times
        
        // fix i do j++ for n-2 times
        
        // fix j do i++ for n-3 times
        
        // fix i do j-- for n-3 times
        int val = 1;
        int cut = 0;
        int i=0,j=0;
        while(val<=n*n){
            
            int count=0;
            for(count;count<n-cut;j++){
                ans[i][j] = val;
                val++;
                count++;
            } 
            cut++;
            
            if(val>=n*n) {print(ans);
            return;}
           
            j = j-1;
            i=i+1;
            
            count = 0;
            
            for(count;count<n-cut;i++){
              
                ans[i][j] = val;
                count++;
                val++;
            }
            
            if(val>n*n) {print(ans);
            return;}
             
            
            count = 0;
            j = j-1;
            i = i-1;
            for(count;count<n-cut;j--){
               
                ans[i][j] = val;
                count++;
                val++;
            }
            
            if(val>n*n) {print(ans);
            return;}
        
            
            cut++;
            count = 0;
            j = j+1;
            i = i-1;
            for(count;count<n-cut;i--){
                ans[i][j] = val;
                val++;
                count++;
            }
            i = i+1;
            j = j+1;
           
            
            if(val>n*n) {print(ans);
            return;}
      
            
        }
        
    }



    int main(){
        generateMatrix(10);
    }