#include <iostream>
#include <queue>
#include <vector>

using namespace std;
template <typename T>
class BinaryTreeNode {
public :
 T data;
 BinaryTreeNode<T> *left;
 BinaryTreeNode<T> *right;

 BinaryTreeNode(T data) {
	 this -> data = data;
	 left = NULL;
	 right = NULL;
 }
};

class Pair {
    public:
    	vector<int> v;
    	int sum;
    	Pair(){
    		this->sum = 0;
		}
    	Pair(vector<int> v, int sum){
        	for(int i=0; i<v.size(); i++){
                this->v.push_back(v[i]);
            }
            this->sum = sum;
    	}
	};

BinaryTreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

	queue<BinaryTreeNode<int>*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}

void printTree(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << ":";
	if (root->left != NULL) {
		cout << "L" << root->left->data;
	}

	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << endl;
	printTree(root->left);
	printTree(root->right);
}

BinaryTreeNode<int>* takeInput() {
	int rootData;
	cout << "Enter data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	BinaryTreeNode<int>* leftChild = takeInput();
	BinaryTreeNode<int>* rightChild = takeInput();
	root->left = leftChild;
	root->right = rightChild;
	return root;
}

int numNodes(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + numNodes(root->left) + numNodes(root->right);
}

void inorder(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS, int inE, int preS, int preE) {
	if (inS > inE) {
		return NULL;
	}

	int rootData = pre[preS];
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == rootData) {
			rootIndex = i;
			break;
		}
	}

	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPreS = preS + 1;
	int lPreE = lInE - lInS + lPreS;
	int rPreS = lPreE + 1;
	int rPreE = preE;
	int rInS = rootIndex + 1;
	int rInE = inE;
	BinaryTreeNode<int>*  root = new BinaryTreeNode<int>(rootData);
	root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
	root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
}

BinaryTreeNode<int>* buildTree(int* in, int* pre, int size) {
	return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}


// print boundry functions

void printLeftBoundry(BinaryTreeNode<int>* root){
    if(root==NULL)
        return;

    if(root->left){
        cout<<root->data<<" ";
        printLeftBoundry(root->left);
    } else if(root->right){
        cout<<root->data<<" ";
        printLeftBoundry(root->right);
    }
    
}

void printLeaves(BinaryTreeNode<int>* root){
    if(root == NULL)
        return;
    
    if(root->left == NULL && root->right == NULL){
        cout<<root->data<<" ";
    }
    
    printLeaves(root->left);
    printLeaves(root->right);
}

void printRightBoundry(BinaryTreeNode<int>* root){
    if(root==NULL)
        return;
    if(root->right){
        printRightBoundry(root->right);
        cout<<root->data<<" ";
    } else if(root->left){
        printRightBoundry(root->left);
        cout<<root->data<<" ";
    }
}



void solve(BinaryTreeNode<int>* root){
    
    cout<<root->data<<" "<<endl;
    if(root->left!=NULL){
        cout<<"start left boundry "<<endl;
    	printLeftBoundry(root->left);
    	cout<<"end left boundry "<<endl;
    	cout<<"start left leaves "<<endl;
        printLeaves(root->left);
        cout<<"end left leaves "<<endl;
    }
    
    if(root->right!=NULL){
        cout<<"start right leaves "<<endl;
    	printLeaves(root->right);
    	cout<<"end right leaves "<<endl;
    	cout<<"start right boundry "<<endl;
    	printRightBoundry(root->right);
    	cout<<"end right boundry "<<endl;
    }
    
}


int findDepth(BinaryTreeNode<int>* root, int data, int level){
	if(root == NULL ){
		return -1;
	}
	if(root->data == data){
		return level;
	}
	int la = findDepth(root->left,data,level+1);
	int ra = findDepth(root->right,data,level+1);
	return max(la,ra);
}

void helperDeepestLeft(BinaryTreeNode<int>* root, int &depth, int &value, BinaryTreeNode<int>* savedroot,int level){
	if(root == NULL){
		return;
	}
	helperDeepestLeft(root->left, depth, value, savedroot,level+1);
	if(root->left){
		if(root->left->left == NULL && root->left->right == NULL){
			int cur_depth = level+1; // instead of using this level parameter and passing 
			//level+1 in recursive call,  i could've used a function findDepth defined above but it would increase complexity
			if(cur_depth > depth){
				value = root->left->data;
				depth = cur_depth;
			} else if(cur_depth == depth){
				if(root->left->data > value){
					value = root->left->data;
					depth = cur_depth;
				}
			}
		}
	}
	helperDeepestLeft(root->right, depth, value, savedroot,level+1);
}

int deepestLeft(BinaryTreeNode<int>* root){
	int depth = INT_MIN;
	BinaryTreeNode<int>* answer;
	int value = 0;
	cout<<"before :: depth : "<<depth<<endl;
	cout<<"before :: value : "<<value<<endl;
	helperDeepestLeft(root, depth, value, root, 0);
	cout<<"after :: depth : "<<depth<<endl;
	cout<<"after :: value : "<<value<<endl;
	return value;
}


void helperAncestors(BinaryTreeNode<int> *root, int k, vector<int> v, vector<int>* ans){
    if(root == NULL)
        return;
    
    if(root->data == k){
    	
        for(int i = 0 ; i < v.size() ; i++){
        	ans->push_back(v[i]);
		}
		return;
    }
//    cout<<" here root is "<<root->data<<endl;
    v.push_back(root->data);
	helperAncestors(root->left, k, v, ans);
    helperAncestors(root->right, k, v, ans);
}

vector<int> ancestors(BinaryTreeNode<int> *root, int k) {
    
    vector<int> v;
    vector<int>* ans = new vector<int>();
//    cout<<ans->size()<<"*********"<<endl;
    helperAncestors(root, k, v, ans);
//    cout<<ans->size()<<"*********"<<endl;
    for(int i=0; i<ans->size();i++){
		v.push_back(ans->at(i));
	}
 	return v;
    
}



bool helperCheckLeaves(BinaryTreeNode<int>* root, int &samelevel, int level){
    if(root == NULL)
        return 1;
    if(root->left == NULL && root->right == NULL){
        if (samelevel == INT_MIN){
            samelevel = level;
            return 1;
        } else if(level == samelevel){
            return 1;
        } else {
            return 0;
        }
    }
    return helperCheckLeaves(root->left, samelevel, level+1) && helperCheckLeaves(root->right, samelevel, level+1);
    
}

void checkLeaves(BinaryTreeNode<int>* root){
	int lvl = INT_MIN;
    int ans = helperCheckLeaves(root,lvl, 0);
    if(ans == 0){
        cout<<"NO";
    } else {
        cout<<"YES";
    }  
}




vector<int> helperMaxSumPath(BinaryTreeNode<int>* root, int &maxsum, int cur_sum, vector<int> v){
    if(root == NULL){
        vector<int> v;
        return v;
    }
    
    v.push_back(root->data);
    
    if(root->left == NULL && root->right == NULL){
        if(cur_sum  > maxsum){
            maxsum = cur_sum;
            cout<<endl<<"the leaf is : "<<root->data<<" and max sum is : "<<maxsum<<" and the path  is :";
            for(int i=0;i<v.size();i++){
		        cout<<v[i]<<" ";
		    }
            return v;
        } else {
            return v;
        }
    }
        
    vector<int> vl,vr;
    if(root->left){
    	vl = helperMaxSumPath(root->left, maxsum, cur_sum + root->left->data , v);
	} 
	
	if(root->right){
    	vr = helperMaxSumPath(root->right, maxsum, cur_sum + root->right->data , v);
	} 
	if(root->right == NULL)
		return vl;
		
	if(root->left == NULL)
		return vr;
		
    int lsum=0;
    for(int i=0;i<vl.size();i++){
        lsum += vl[i];
    }
    if(maxsum == lsum){
        return vl;
    } else {
        return vr;
    }
    
    
}



Pair helperMaxSumPathApproach2(BinaryTreeNode<int>* root, int &maxsum, Pair p){
	
	if(root == NULL){
        Pair p;
        return p;
    }
    
    p.v.push_back(root->data);
    
    if(root->left == NULL && root->right == NULL){
        if(p.sum  > maxsum){
            maxsum = p.sum;
            cout<<endl<<"the leaf is : "<<root->data<<" and max sum is : "<<maxsum<<" and the path  is :";
            for(int i=0;i<p.v.size();i++){
		        cout<<p.v[i]<<" ";
		    }
            return p;
        } else {
            return p;
        }
    }
        
    Pair vl,vr;
    if(root->left){
    	p.sum += root->left->data;
    	vl = helperMaxSumPathApproach2(root->left, maxsum, p);
	} 
	
	if(root->right){
		p.sum += root->right->data;
    	vr = helperMaxSumPathApproach2(root->right, maxsum, p);
	} 
	if(root->right == NULL)
		return vl;
		
	if(root->left == NULL)
		return vr;
		
    if(vl.sum == maxsum) return vl;
    else return vr;
	
}


void maxSumPathApproach2(BinaryTreeNode<int>* root){
    
    int maxsum = INT_MIN;
    
    Pair p;
    p.sum = root->data;
 
    Pair ans = helperMaxSumPathApproach2(root, maxsum, p);
    for(int i=0;i<ans.v.size();i++){
        cout<<ans.v[i]<<" ";
    }
}


void maxSumPath(BinaryTreeNode<int>* root){
    
    int maxsum = INT_MIN;
    vector<int> v;
    vector<int> ans = helperMaxSumPath(root, maxsum, root->data, v);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}





void helperMinDepth(BinaryTreeNode<int>* root, int level, int &minDepth){
    if(root == NULL){
        return;
    }
    
    if(root->left == NULL && root->right == NULL){
        int cur_depth = level;
        if(cur_depth<minDepth){
            minDepth = cur_depth;
            return;
        }
    }
    
    helperMinDepth(root->left,level+1,minDepth);
    helperMinDepth(root->right,level+1,minDepth);
    
}

int minDepth(BinaryTreeNode<int> *root) {
    int mind = INT_MAX;
    helperMinDepth(root,1,mind);
    return mind;

}


void printDiagonal(BinaryTreeNode<int>* root){
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	int nextCount=1,c=0;
	while(!q.empty()){
		vector<int> v;
		c=0;
		cout<<" nextcount is : "<<nextCount<<endl;
		for(int i=0;i<nextCount;i++){
			BinaryTreeNode<int>* cur_root = q.front();
			cout<<" current parent  : "<<cur_root->data<<endl;
			q.pop();
			while(cur_root != NULL){
				if(cur_root->left){
					q.push(cur_root->left);
					cout<<"children pushed : "<<cur_root->left->data<<" "<<endl;
					c++;
				}
				v.push_back(cur_root->data);
				cur_root = cur_root->right;
			}		
		}
		nextCount = c;
		for(int i=0;i<v.size();i++){
	     	cout<<v[i]<<" ";
		}
		cout<<endl;
	}   
}






int helperLongestIncreasingPath(BinaryTreeNode<int> *root){
    if(root == NULL)
        return 0;
    
    int la = helperLongestIncreasingPath(root->left);
    int ra = helperLongestIncreasingPath(root->right);
    cout<<"current root is : "<<root->data<<endl;
    cout<<"la : "<<la<<endl<<"ra : "<<ra<<endl;
    if(la == ra){
        
        
        if(root->left && root->right){
            
            if( root->data < root->left->data || root->data < root->right->data ){
                return la+1;
            } else {
                return la;
            }
        }
        if(root->left){
            if( root->data < root->left->data){
                return la+1;
            } else {
                return la;
            }
        } else if(root->right){
            if( root->data < root->right->data){
                return ra+1;
            } else {
                return ra;
            }
        } else {
            return 0;
        }
            
        
    }
    
    int maximum = la>ra?la:ra;
    if(maximum == la && root->left != NULL){
        if( root->data < root->left->data){
            return maximum+1;
        } else {
            return la;
        }
    } else if(maximum == ra && root->right != NULL){
        if( root->data < root->right->data){
            return maximum+1;
        } else {
            return ra;
        }
    } 
    
    
}

int longestIncreasingPath(BinaryTreeNode<int> *root) {
    return helperLongestIncreasingPath(root);
    
}



int maxWidth(binaryTreeNode<int>* root){
	queue<binaryTreeNode<int>*> q;
	binaryTreeNode<int>* l = root->left; 
	binaryTreeNode<int>* r = root->right;
	int level = 1;
	width = 2;
	q.push(root->left);
	q.push(root->right);
	int count = 0;
	while(l != NULL || r != NULL){
		binaryTreeNode<int>* fr = q.front();
		q.pop();
		if(fr != NULL){
			q.push(fr->left);
			q.push(fr->right);
			count++;
		}
	}
}





// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main() {
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printTree(root);
	
//	 BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
//	 BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
//	 BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);
//	 root->left = node1;
//	 root->right = node2;
	
//	int in[] = {4,2,5,1,8,6,9,3,7};
//	int pre[] = {1,2,4,5,3,6,8,9,7};
//	BinaryTreeNode<int>* root = buildTree(in, pre, 9);
//	printTree(root);
//	cout << "Num: " << numNodes(root) << endl;
//	inorder(root);
	
	// 1 2 3 4 5 7 -1 -1 -1 6 -1 -1 8 -1 -1 -1 -1
	// 1 2 3 4 5 7 2 -1 -1 6 -1 1 8 -1 -1 -1 8 -1 -1 -1 -1 -1 -1
	// 5 4 3 0 -1 2 -1 7 9 6 1 -1 -1 -1 -1 -1 -1 -1 11 8 -1 -1 -1
	// 5 -1 4 -1 3 -1 2 -1 -1 // right tree
	// 5 4 -1 3 -1 2 -1 -1 -1 //left tree
	// 1 2 3 4 5 -1 7 -1 -1 6 -1 8 -1 -1 -1 -1 -1
//	solve(root);
//	cout<<"depth of node is : "<<findDepth(root,4,0);
//	cout<< "the deepest left node is : "<<deepestLeft(root);
//	cout<<"enter value of k : "<<endl;
//	int k=0;
//	cin>>k;
//	vector<int> v = ancestors(root, k);
//	for(int i=0; i<v.size();i++){
//		cout<<v[i]<<" ";
//	}
//	checkLeaves(root);
//	maxSumPath(root);
//	maxSumPathApproach2(root);
//	cout<<"minimum depth of this tree is : "<<minDepth(root);
//	printDiagonal(root);
	cout<<longestIncreasingPath(root);
	delete root;
}

