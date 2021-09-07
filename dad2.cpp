#include<iostream>
using namespace std;

func(int p, float r, int t, int in){
	float temp = p;
	float val=0;
	
	for(int i=1;i<=in;i++){
		float intrest = (temp*r)/100;
		float newval = temp+intrest;
		cout<<fixed<<"value at the end of"<<i<<" th year is"<<newval<<endl;
		val = newval;
		newval = newval + p; 
		cout<<"value at the start of"<<i+1<<"year is  : "<<newval<<endl;
		temp = newval; 
	}
	
	cout<<"amount after "<<in<<" years is : "<<val<<endl;
		// 100000 15 4.9 2
	int remt = t - in;
	float temp2 = val;
	for(int i=in+1; i<=t;i++){
		float intrest = (temp2*r)/100;
		float newval = temp2 + intrest;
		cout<<fixed<<"amount at the end of "<<i<<" year is : "<<newval<<endl;
		temp2 = newval;
	}
	
}

int main(){
	int p,t,in;
	float r;
	cout<<"enter principat amount"<<endl;
	cin>>p;
	cout<<"enter number of years"<<endl;
	t=12;
	cout<<"rate of i"<<endl;
	cin>>r;
	cout<<"enter initial investment time"<<endl;
	in=6;
	func(p,r,t,in);
}


