#include<bits/stdc++.h>
using namespace std;
vector<int> stepnum(int A, int B) {
	
    queue<int> q;
    vector<int> v;
    for(int i=0; i<10; i++){
        q.push(i);
    }
    
    while(!q.empty()){
//    	cout<<"ghello"<<endl;
        int ele = q.front();
        q.pop();
        
        if(ele >= A && ele <= B) {
//        	cout<<"ff"<<endl;
        	v.push_back(ele);
		}
        if(ele == 0 || ele > B) continue;
        int newl=-1, newr=-1;
        if(ele%10 == 0){
            newr = (ele*10 + ((ele%10) + 1));
        }
        else if(ele%10 == 9){
            newl = (ele*10 + ((ele%10) - 1));
        } 
        else{

            newl = (ele*10 + ((ele%10) - 1));
            newr = (ele*10 + ((ele%10) + 1));

        }

        if(newl != -1  && newl < B) {
//			cout<<newl<<endl;
        	q.push(newl);
		}
        if(newr != -1  && newr < B){
//        	cout<<newr<<endl;
        	q.push(newr);
		} 
    }


    return v;
}

int main(){
	vector<int> ans = stepnum(0,231141);
	for(auto i: ans){
		cout<<i<<" ";
	}
}
