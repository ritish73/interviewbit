#include<bits/stdc++.h>
using namespace std;

void printPermutations(char* s, int index, set<string> &firstset){
	// base case
	if(s[index] == '\0'){
//		cout<<s<<" ";
		string newstring(s); // created a string object and made its value =  s
		firstset.insert(newstring); // insert the string into the set
		return;
	}
	
	for(int j = index; s[j] != '\0'; j++){
		swap(s[index],s[j]);
		printPermutations(s, index + 1, firstset);
		
		// backtracking step
		swap(s[index], s[j]);
		
	}
}

int main(){
	char s[10];
	cin>>s;
	set<string> firstset;
	printPermutations(s,0, firstset);
	
	set<string>::iterator it = firstset.begin();
	while (it != firstset.end()){	
    // Print the element
	    cout << (*it) << " , ";
	    //Increment the iterator
	    it++;
	}

}
