// find how many numbers from 1 to n are divisible by prime numbers less than 20

// this is just like inclusion exclusion concept

#include<bits/stdc++.h>
using namespace std;
int main(){
//	
//	int tc;
//	cin>>tc;
//	
//	while(tc--){
		
		
		int n;
    cin>>n;
    int prime_nums[] = {2,3,5,7,11,13,17,19};
    int ans = 0;
    // we can have 2^n - 1 subsets
    int subsets = (1<<n)-1;
    for(int i=1; i<=subsets; i++){
        // do two things  
        
        // count number of set bits in i
        // check at what position the bit is set and for that particular position multiply current element from prime number list to curdenominator
        
//        int temp = i;
        int cur_denominator=1;
//        int cnt = 0;
        int cnt = __builtin_popcount(i);
        for(int j=0; j<=7; j++){
            // if(temp&1) 
            if(i&(1<<j)){
//                cnt++;
                cur_denominator = cur_denominator*prime_nums[j];
            }
            // temp = temp << 1;
        }

        if(cnt&1) ans += n/cur_denominator;
        else ans -= n/cur_denominator;

    }
    cout<< ans;
		
		
//		
//	}
	
    
}
