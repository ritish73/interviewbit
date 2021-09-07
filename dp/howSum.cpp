#include<bits/stdc++.h>
using namespace std;
vector<int> howSum(int sum, int* arr, int n){
	cout<<"\nfor sum = "<<sum<<endl;
	if(sum < 0) {
	    vector<int> v;
	    v.push_back(sum);
	    cout<<"\n returnning array for negative sum"<<v[0];
	    return v;
	}  
    
    if(sum == 0){
        vector<int> v;
        return v;
    }
    for(int i=0; i<n; i++){
        int remainder = sum-arr[i];
//        cout<<"about to call how sum with sum : "<<remainder<<endl;
        vector<int> rv = howSum(remainder,arr,n);
//        cout<<"the rv returned for sum "<<remainder<<" is "<<rv[0]<<endl;
        if(rv.size()>=1 && rv[0] < 0){
        	cout<<"\nreturned array"<<rv[0];
            continue;
        } else {
        	cout<<"\nvalue of ra[0] : "<<rv.size();
//        	cout<<"pushing : "<<arr[i]<<endl;
            rv.push_back(arr[i]);
//            memo[sum].push_back(rv);
            return rv;
        }
    }
    vector<int> v;
    v.push_back(-1);
//    memo[sum].push_back(v);
cout<<"\nall were negative , so returning result for sum "<<sum<<" as -1";
    return v;
}
int main(){
    int size = 4;
    int arr[] = {5,3, 4, 7};
    int sum = 7;
//    vector< vector<int> > memo;
//    cout<<memo.size()<<endl;
//    for(int i=0; i<=7; i++){
//    	vector<int> v;
//		memo.push_back();
//	}
//	cout<<memo.size()<<endl;
	
    vector<int> ans = howSum(sum, arr, size);
    for (int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }  

}

