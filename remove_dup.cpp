// take 2 pointers to remove duplicates

#include<bits/stdc++.h>
using namespace std;

removeDuplicates(char a[]){
    int j=0,i=1;
    while(a[i] != '\0'){
        if(a[j] != a[i]) a[++j] = a[i];
        i++; 
    }
    a[++j] = '\0';
}

int main(){
    char a[] = "ccoooding";
    removeDuplicates(a);
    // string s[3] = {"aaaaaaa","ubhibhi","ssssssss"};
    // cout<<s[0]<<s[1]<<s[2];
}