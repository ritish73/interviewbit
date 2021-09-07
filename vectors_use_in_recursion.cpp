#include<iostream>
#include<vector>
#include <queue>
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

void inorder(BinaryTreeNode<int>* root) {
	if (root == NULL) {
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
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


void helper(BinaryTreeNode<int>* root, vector<int>* v){
    if(root == NULL){
        return;
    }
    cout<<"data to be pushed back in vector"<<root->data<<endl;
    
    cout<<"size of vector : "<<v->size()<<endl; 
    for(int i=0;i<v->size();i++){
    	cout<<v->at(i)<<"\t";
	}
	cout<<"\n";
	helper(root->left, v);
	helper(root->right, v);
	v->push_back(root->data);
   
}

int solve(BinaryTreeNode<int>* root, int M){
    vector<int> *v = new vector<int>();	
    helper(root, v); 
    cout<<"\n\nhere ge got out of the recursive function\n\n";
	cout<<"size of vector : "<<v->size()<<endl; 
    for(int i=0;i<v->size();i++){
    	cout<<v->at(i)<<"\t";
	}
	cout<<"\n";
	for(int i=0;i<v->size();i++){
        if(v->at(i) == M){
            return v->at(i+1);
        }
    }
    return -1;
    
}

BinaryTreeNode<int>* findnode(BinaryTreeNode<int>* root, int M){
    if(root == NULL){
        return NULL;
    }
    if(root->data == M){
        return root;
    }
    BinaryTreeNode<int>* la = findnode(root->left,M);
    BinaryTreeNode<int>* ra = findnode(root->right,M);
    if(ra!=NULL) return ra;
    if(la!=NULL) return la;
    
}


BinaryTreeNode<int>* updateTree(BinaryTreeNode<int> *root){
	
    if(root == NULL){
        return NULL;
        cout<<"null returning";
    }
    cout<<"welcome\t"<<root->data<<endl;
    int a=0,b=0;
    

    if(root->left == NULL){
        a=0;
    }
    if(root->right == NULL){
        b=0;
    }
    if(root->left != NULL)
    	a = root->left->data;
    if(root->right != NULL)
    	b =  root->right->data;
    
    cout<<"this is a : "<<a<<" for "<<root->data<<" and this is b : "<<b<<" for "<<root->data<<endl;
    root->data = a+b;
    BinaryTreeNode<int> *leftTree = updateTree(root->left);
    BinaryTreeNode<int> *rightTree = updateTree(root->right);
    root->left = leftTree;
    root->right = rightTree;
    return root;
}

void helper1(BinaryTreeNode<int> *root, vector<int> &v){
    if(root==NULL) return;
    cout<<"data pushing back to vector v "<< root->data<<endl;
    v.push_back(root->data);
    helper1(root->left, v);
    helper1(root->right, v);
}

vector<int> sumTree(BinaryTreeNode<int> *root){
    
    BinaryTreeNode<int> *updatedroot = updateTree(root);
    vector<int> v;
    cout<<"v.size in sumTreefunc before "<<v.size()<<endl;
    helper1(updatedroot,v);
    cout<<"v.size in sumTreefunc after "<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
		cout<<v.at(i)<<"\t";
	}
    return v;    
}

void printpreorder(BinaryTreeNode<int>* root){
	if(root == NULL){
		return;
	}
    cout<<root->data<<"\t";
    printpreorder(root->left);
    printpreorder(root->right);
    return;
}


void swapSolve(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
 	int temp = root1->data;
    root1->data = root2->data;
    root2->data = temp;
    return;
}

void helperSolve(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2, int level){
	
	if(root1 == NULL || root2 == NULL){
        return;
    }
    cout<<endl<<endl;
    printTree(root1);
    printpreorder(root1);
    printpreorder(root2);
	cout<<"root values are : "<<root1->data<<"  and "<<root2->data<<" and level is : "<<level<<endl;
    
    if(level%2 == 0){
        swapSolve(root1,root2);
        cout<<"swap function called and returned for root : "<<root1->data<<"  and "<<root2->data<<endl;
    }
    helperSolve(root1->left, root2->right, level+1);
    helperSolve(root1->right, root2->left, level+1);
    return;
}

void solveAlternateSwap(BinaryTreeNode<int>* root){
    	/* Don't write main().
	* Don't read input, it is passed as function argument.
	* Print the preorder traversal of output tree
	*/
    helperSolve(root->left,root->right,0);
    printpreorder(root);

}



int main(){
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printTree(root);
//	cout<<solve(root,6);
//	BinaryTreeNode<int>* ans = findnode(root,23);
//	if(ans!=NULL){
//		cout<<ans->data<<endl;
//		cout<<ans;
//	}
//		
//	else cout<<"-1";

//	root = updateTree(root);
//	printTree(root);
	// 1 2 3 4 -1 5 6 -1 -1 -1 -1 -1 -1
	
//	vector<int> v = sumTree(root);
//	for(int i=0;i<v.size();i++){
//		cout<<v.at(i)<<"\t";
//	}
	
	solveAlternateSwap(root);
	// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
	// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
	printTree(root);
}

// 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

