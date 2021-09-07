#include<bits/stdc++.h>
using namespace std;
int* howSum(int sum, int* arr, int n, int& k){  
	cout<<"\nfor sum = "<<sum<<endl;
    if(sum < 0) {
        int* arr = new int[1];
        arr[0]=sum;
        cout<<"\n returnning array for negative sum"<<arr[0];
        return arr;
    }
    if(sum == 0){
        int* arr = new int[7];
        return arr;
    }
    for(int i=0; i<n; i++){
        int remainder = sum-arr[i];
        int *ra = howSum(remainder,arr,n,k);
        
        if( ra[0] < 0){
        	cout<<"\nreturned array"<<ra[0];
            continue;
        } else {
        	cout<<"\n value of k is : "<<k<<"\nvalue of ra[0] : "<<ra[0];
            ra[k++] = arr[i];
            return ra;
        }
    }
    int array[1];
    array[0] = -1;
    cout<<"\nall were negative , so returning result for sum "<<sum<<" as -1";
    return array;
}
int main(){
    int size = 4;
    int arr[] = {5, 3, 4, 7};
    int sum = 7;
    int k=0;
    int* ans = howSum(sum, arr, size, k);
    cout<<endl;
    for (int i = 0; i < 7; i++){
        cout<<ans[i]<<" ";
    }   
}

