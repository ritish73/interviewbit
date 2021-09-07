#include<iostream>
using namespace std;
int main(){

    int *arr = new int();
    *(arr) = 7;
    *(arr+1)=9; 
    cout<<*(&arr+1) - arr<<endl;

}