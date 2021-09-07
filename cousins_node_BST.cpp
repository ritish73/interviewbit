#include <iostream>
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


BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
		queue<BinaryTreeNode<int>*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty()) {
			BinaryTreeNode<int> *first = q.front();
			q.pop();
			if(first == NULL) {
				if(q.empty()) {
					break;
				}
				cout << endl;
				q.push(NULL);
				continue;
			}
			cout << first -> data << " ";
			if(first -> left != NULL) {
				q.push(first -> left);
			}
			if(first -> right != NULL) {
				q.push(first -> right);
			}
		}
}

int depth(BinaryTreeNode<int>* root, int x){
	if(root == NULL){
		return -1;
	}
    if(root->data == x){
        return 0;
    }
    int l = depth(root->left, x);
    if(l!=-1){
    	return l+1;
	}
	int r = depth(root->right, x);
	if(r!=-1){
		return r+1;
	}
	return -1;
}

bool isSibling(BinaryTreeNode<int>* root, int p, int q){
	bool l,r;
	if(root == NULL){
		return 0;
	}
	if(root->left != NULL && root->right != NULL){
		
		if((root->left->data == p && root->right->data == q)|| (root->left->data == q && root->right->data == p)){
			return 1;
		} else{
			l = isSibling(root->left, p, q);
			r = isSibling(root->right, p, q);
			return l||r;
		}
	}
	else if(root->left!=NULL){
		return isSibling(root->left, p, q);
	}
	else{
		return  isSibling(root->right, p, q);
	}
	return 0;
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
	if(root == NULL)
        return 0;
        cout<<depth(root,p)<<" "<<depth(root,q)<<endl;
        cout<<isSibling(root,p,q);
    return (depth(root,p) == depth(root,q)) && (!isSibling(root,p,q));
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    int n1, n2;
    cin >> n1 >> n2;
    cout<<isCousin(root, n1, n2);
    if(isCousin(root, n1, n2)) {
	    cout << "true" << endl;
    }
    else {
	    cout << "false" << endl;
    }
}

