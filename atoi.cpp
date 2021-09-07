#include<bits/stdc++.h>
using namespace std;

int atoi(const string A) {
    //  preprocessing
    string newstr;
    int i=0;
    bool neg=false;
    if(A[0]=='+'){
        i=1;
    } else if(A[0]=='-'){
        i=1;
        neg=true;
    }
    while(i<A.length()){

        if(A[i]>=48 && A[i]<=57){
            newstr+=A[i];
            cout<<"newstr : "<<newstr<<endl;
        } else {
            break;
        }
        i++;
    }


//    cout<<newstr<<endl;

  
    int ans = 0;
    int p=1;
    for(int i=newstr.length()-1; i>=0; i--){
    	int n = newstr[i]-'0';
    	
    	if(ans + n*p >= INT_MAX/10){
            if(neg) {
            	return INT_MIN;
			}
            else {
            	return INT_MAX;	
			}
            
        }
    	
    	
        
        ans = ans + n*p;
        cout<<"ans : "<<ans<<" ";
        p = p*10;
    }

    return neg?-ans:ans;
}

int main(){
	string s = "5121478262 8070067M75 X199R 547 8C0A11 93I630 4P4071 029W433619 M3 5 14703818 776366059B9O43393";
	cout<<endl;
	cout<<atoi(s);
}
