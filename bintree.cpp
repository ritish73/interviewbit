#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
template <typename T>
class binaryTreeNode{
	public:
		T data;
		binaryTreeNode<T>* left;
		binaryTreeNode<T>* right;
		
		binaryTreeNode(T data){
			this->data = data;
			left = NULL;
			right = NULL;
		}
};


binaryTreeNode<int>* takeInputLevelWise(){
	queue<binaryTreeNode<int>*> q;
	cout<<"enter the root node"<<endl;
	int data;
	cin>>data;
	if(data == -1){
		return NULL;
	}
	binaryTreeNode<int>* root = new binaryTreeNode<int>(data);
	q.push(root);
	while(!q.empty()){
		binaryTreeNode<int>* rootnode = q.front();
		q.pop();
		cout<<"enter left child of : "<<rootnode->data<<endl;
		int leftchild; 
		cin >> leftchild;
		if(leftchild != -1){
			binaryTreeNode<int>* leftnode = new binaryTreeNode<int>(leftchild);
			q.push(leftnode);
			rootnode->left = leftnode;
		}
		int rightchild;
		cout<<"enter right child of : "<<rootnode->data<<endl;
		cin >> rightchild;
		if(rightchild != -1){
			binaryTreeNode<int>* rightnode = new binaryTreeNode<int>(rightchild);
			q.push(rightnode);
			rootnode->right = rightnode;
		}
	}
	return root;
}

void print(binaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
	queue<binaryTreeNode<int>*> q;
	q.push(root);
	while(!q.empty()){
		binaryTreeNode<int>* rootnode = q.front();
		q.pop();
		cout<<rootnode->data<<" : ";
		if(rootnode->left != NULL){
		
			cout<<"L: "<<rootnode->left->data<<" ,";
			q.push(rootnode->left);
		}
		if(rootnode->left == NULL){
			cout<<"L: -1,";
		}
		if(rootnode->right != NULL){
			cout<<"R: "<<rootnode->right->data<<endl;
			q.push(rootnode->right);
		}
		if(rootnode->right == NULL){
			cout<<"R: -1"<<endl;
		}
		
	}
}



int helperLongestIncreasingPath(binaryTreeNode<int> *root, int &maxval){
	
    if(root == NULL)
        return 0;
    int ans=0;
    int la = helperLongestIncreasingPath(root->left, maxval);
    int ra = helperLongestIncreasingPath(root->right, maxval);
    
    if(la == ra){
        if(root->left && root->right){
            if( root->data < root->left->data || root->data < root->right->data ){
                ans =  la+1;
            } else {
                ans =  1;
            }
        }
        if(root->left){
            if( root->data < root->left->data){
                ans =  la+1;
            } else {
                ans =  1;
            }
        } else if(root->right){
            if( root->data < root->right->data){
                ans =  ra+1;
            } else {
                ans =  1;
            }
        } else {
            ans =  1;
        }
    }
    
    int maximum = la>ra?la:ra;
    if(maximum == la && root->left != NULL){
        if( root->data < root->left->data){
            ans =  maximum+1;
        } else {
            ans =  1;
        }
    } else if(maximum == ra && root->right != NULL){
        if( root->data < root->right->data){
            ans =  maximum+1;
        } else {
            ans =  1;
        }
    } 
    if(ans > maxval){
    	cout<<"ans : "<<ans<<" , maxval  : "<<maxval<<endl;
    	maxval = ans;
	}
    return ans;
}

int longestIncreasingPath(binaryTreeNode<int> *root) {
	int maxval = INT_MIN;
	cout<<"maxval before : "<< maxval<<endl;
    int ans = helperLongestIncreasingPath(root,maxval); 
    cout<<"maxval after : "<< maxval<<endl;
    return maxval;
}


int maximumSumLeafPath(binaryTreeNode<int>* root, int &maxsum){
	if(root == NULL) return 0;

	if(root->left == NULL && root->right == NULL){
		return root->data;
	}
	int la = maximumSumLeafPath(root->left, maxsum);
	int ra = maximumSumLeafPath(root->right, maxsum);
	if(root->left && root->right){
		int ans = la+ra+root->data;
		if(ans > maxsum){
			maxsum = ans;
		}
		return max(la,ra)+root->data;
	} else {
		return (root->left)?la+root->data:ra+root->data;
	}
}

int heightOfTree(binaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int la = heightOfTree(root->left);
    int ra = heightOfTree(root->right);
    if(la > ra){
        return la+1;
    } else{
        return ra+1;
    }
}

void findWidth(binaryTreeNode<int>* root,int level, int &width){
	
	if(level == 1){
		width += 1;
		
		return;
	}
	if(root->left)
		findWidth(root->left, level-1, width);
	if(root->right)
		findWidth(root->right, level-1, width);
	return;
}

int findMaxWidth(binaryTreeNode<int>* root){
	int height = heightOfTree(root);
//	cout<<"height of tree  :  "<<height<<endl;
	int width = 0;
	int maxwidth= INT_MIN;
	for(int i=1;i<=height;i++){
		findWidth(root, i, width);
//		cout<<"width at level : "<<i<<" is : "<<width<<endl;
		if(width > maxwidth){
			maxwidth = width;
		}
		width=0;
	}
	return maxwidth;
}

int findMaxWidthQueue(binaryTreeNode<int>* root){
	int result = 0;
	if(root == NULL){
		return 0;
	}
	queue<binaryTreeNode<int>*> q;
	q.push(root);
	while(!q.empty()){
		int count = q.size();
		result = max(count,result);
		while(count--){
			binaryTreeNode<int>* fr = q.front();
			q.pop();
			if(fr->left){
				q.push(fr->left);
			}
			if(fr->right){
				q.push(fr->right);
			}
//			count--;
		}
	}
	return result;
}


void getArray(binaryTreeNode<int>* root,vector<int> &v){
	if(root == NULL){
		return;
	}
	getArray(root->left, v);
	v.push_back(root->data);
	getArray(root->right, v);
	return;
}

// quick sort function
void swap(int* a,int* b){
    int t=*a;
    *a=*b;
    *b=t; 
}
int partition(int input[] , int s, int e){
    int temp=input[s];
    int i=s+1,c=0;
    while(i<=e)
    {
        if(input[i] <= temp ) {
            c++;
        }
        i++;  
    }
    int x=s+c;
    swap(&input[s],&input[x]);
      i=s; int j=e;
    while(i<x && j>x)
    {       
    if(input[i]<=input[x] )
        i++; 
    else if(input[j]>input[x] )
        j--;
        else{   
			swap(&input[i],&input[j]);
        	i++; j--;  
        }
	}     
    return x;
}
void QuickSort(int input[] , int s , int e){
    if(s>=e)
        return;
     int pivotindex = partition(input,s,e);
     QuickSort( input, s , pivotindex-1);
     QuickSort( input, pivotindex+1 , e);  
}

void quickSort(int input[], int size) {
     QuickSort(input , 0 , size-1);   
}




bool isTripletSumHelper(int *arr,int n, int sum){
	bool ans = false;
	// first sort the array
	quickSort(arr, n);
//	for(int i=0;i<n;i++){
//		cout<<arr[i];
//	}
	for(int i=0; i<n; i++){
		int fix = arr[i];
		int fr = i+1;
		int end = n-1;
		
		//now traverse the array by fixing a position and saerch for sum-arr[pos] using 2 pointers ,
		while(fr < end){
			if(arr[fr] + arr[end] == sum-fix){
				ans = true;
				break;
			} else if(arr[fr] + arr[end] < sum-fix){ //incrementing first one if sum is greater and decrementing second one if sum is decreasing
				fr++;
			} else if(arr[fr] + arr[end] > sum-fix){
				end--;
			}
		}
	}
	return ans;
}

string isTripletSum(binaryTreeNode<int>* root, int sum){
	vector<int> v;
	getArray(root, v);
//	for(int i=0;i<v.size();i++){
//		cout<<v[i]<<" ";
//	}
//	cout<<endl;
	int l = v.size();
	int *arr = new int[l];
	for(int i=0;i<l;i++){
		arr[i] = v[i];
	}
	bool ans = isTripletSumHelper(arr, l, sum);
	if(ans == 1){
		return "Yes";
	} else {
		return "No";
	}
}

binaryTreeNode<int>* removeNodesHelper(binaryTreeNode<int>* root){
	if(root == NULL){
		return NULL;
	}
	binaryTreeNode<int>* l = removeNodesHelper(root->left);
	binaryTreeNode<int>* r = removeNodesHelper(root->right);
	if(l == NULL && r != NULL){
		return r;
	}
	if(r == NULL && l != NULL){
		return l;
	} 
	else{
		root->left = l;
		root->right = r;
		return root;
	}
}

void inorder(binaryTreeNode<int>* root){
	if(root == NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void removeNodes(binaryTreeNode<int>* root){
	binaryTreeNode<int>* newroot = removeNodesHelper(root);
	inorder(newroot);
}

bool checkXOR(binaryTreeNode<int>*root) { 
	if(root == NULL){
		return 1;
	}
	bool l = checkXOR(root->left);
	bool r = checkXOR(root->right);
	bool c = 1;
	if(root->left && root->right){
		c = root->data == root->left->data ^ root->right->data;
	}
	
	return l & r & c;
}

void reverseLevelOrder(binaryTreeNode<int>*root) {
	stack<int> s;
	queue<binaryTreeNode<int>*> q;
	q.push(root);
	while(!q.empty()){
		binaryTreeNode<int>* fr = q.front();
		q.pop();
		s.push(fr->data);
		if(fr->left){
			q.push(fr->left);
		} 
		if(fr->right){
			q.push(fr->right);
		}
	}
	
	while(!s.empty()){
		int top = s.top();
		cout<<top<<" ";
		s.pop();
	}
	
}

bool tripletSumHashmap(binaryTreeNode<int>* root, int sum){
	
	vector<int> v;
	getArray(root, v);
	unordered_map<int,int> mymap;
	for(int i=0;i<v.size();i++){
		mymap[v[i]] = i;
	}
	cout<<mymap.bucket_count();
	return true;
}


// 3 2 4 1 6 5 9 -1 -1 -1 -1 -1 -1 -1 -1
// 4 3 -1 2 -1 1 -1 -1 -1
// 4 3 1 2 8 -1 6 -1 -1 9 -1 -1 3 11 15 4 -1 13 14 -1 -1 19 1 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 -1 6 -1 3 8 -1 -1 -1 9 12 3 -1 -1 -1 -1
// 1 2 3 4 5 2 -1 -1 -1 -1 -1 -1 4 -1 5 -1 6 -1 -1
// 5 6 2 2 3 -1 -1 9 7 -1 -1 -1 -1 -1 -1

int main(){
	binaryTreeNode<int>* root = takeInputLevelWise();
	print(root);
//	cout<<longestIncreasingPath(root);
//	int maxsum = INT_MIN;
//	int ans=maximumSumLeafPath(root, maxsum);
//	cout<<maxsum;

//	cout<<findMaxWidth(root);
//	cout<<findMaxWidthQueue(root);
//	cout<<isTripletSum(root, 6);

//this function will remove half nodes then we will print inorder traversal of updated tree
//	removeNodes(root);
//	cout<<checkXOR(root);
//	reverseLevelOrder(root);
	cout<<tripletSumHashmap(root, 6);
	
}




