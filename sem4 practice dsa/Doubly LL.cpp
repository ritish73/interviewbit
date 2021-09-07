#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next,*prev;
		node(int data){
			this->data = data;
			next = NULL;
			prev = NULL;
		}
};
node* takeInput(){
	node *head = NULL, *tail = NULL;
	cout<<"how many nodes u want to create";
	int n; cin>>n;
	for(int i=0;i<n;i++){
		int data;
		cout<<"enter data of the node"<<endl;
		cin>>data;
		node* newnode = new node(data);
		if(head == NULL){
			head = newnode;
			tail = newnode;
		}
		else{
			node *p = tail;
			tail->next = newnode; 
			tail = newnode;
			tail->prev = p;
		}
	}
	return head;
}

void print(node *head){
	node *t = head;
	while(t!=NULL){
		cout<<t->data<<"	";
		t = t->next;
	}
	cout<<endl;
}

node* insertBeg(node *head){
	cout<<"what valude do you want to insert at beg"<<endl;
	int data;
	cin>>data;
	node *newnode = new node(data);
	newnode->next = head;
	head->prev = newnode;
	head = newnode;
	return head;
}

void insertPos(node* head,int pos){
	cout<<"what valude do you want to insert"<<endl;
	int data;
	cin>>data;
	node *newnode = new node(data);
	int k=1;
	node *t = head;
	while(k<pos-1){
		t = t->next;
		k++;
	}
	node *h = t->next;
	newnode->prev = t;
	t->next = newnode;
	newnode->next = h;
	h->prev = newnode;
	return;
}


node* delBeg(node* head){
	node* t = head;
	head = t->next;
	head->prev = NULL;
	delete t;
	return head;
}

void delPos(node* head,int pos){
	int k=1; node* t = head;
	while(k<pos){
		t = t->next;
		k++;
	}
	t->prev->next = t->next;
	t->next->prev = t->prev;
	delete t;
	
}
int main(){
	node* head = takeInput();
	print(head);
	head = insertBeg(head);
	print(head);
	cout<<"at what pos u wanna insert a node"<<endl;
	int pos;
	cin>>pos;
	insertPos(head,pos);
	print(head);
	head = delBeg(head);
	print(head);
	delPos(head,pos);
	print(head);
}

