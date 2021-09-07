#include<bits/stdc++.h>
#include<queue>
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

int findMaxWidth(binaryTreeNode<int>* root){
	int height = heightOfTree(root);
	cout<<height;
	return height;
}

// 3 2 4 1 6 5 9 -1 -1 -1 -1 -1 -1 -1 -1
// 4 3 -1 2 -1 1 -1 -1 -1
// 4 3 1 2 8 -1 6 -1 -1 9 -1 -1 3 11 15 4 -1 13 14 -1 -1 19 1 -1 -1 -1 -1 -1 -1 -1 -1
// 1 2 -1 6 -1 3 8 -1 -1 -1 9 12 3 -1 -1 -1 -1
// 1 2 3 4 5 2 -1 -1 -1 -1 -1 -1 4 -1 5 -1 6 -1 -1
int main(){
	binaryTreeNode<int>* root = takeInputLevelWise();
	print(root);
//	cout<<longestIncreasingPath(root);

//	int maxsum = INT_MIN;
//	int ans=maximumSumLeafPath(root, maxsum);
//	cout<<maxsum;
	cout<<findMaxWidth(root);
	
}


