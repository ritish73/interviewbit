#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
		node(int data){
			this->data = data;
			next = NULL;
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
			newnode->next = newnode;
			tail = newnode;
		}
		else{
			tail->next = newnode; 
			tail = newnode;
			tail->next = head;
		}
	}
	return head;
}

void print(node* head){
	node *t=head;
	while(t->next!=head){
		cout<<t->data<<"	";	
		t = t->next;
	}
	cout<<t->data;
	cout<<endl;
	return;
}

node *insertBeg(node *head){
	node *t = head;
	while(t->next!=head){
		t=t->next;
	}
	cout<<"what valude do you want to insert at beg"<<endl;
	int data;
	cin>>data;
	node *newnode = new node(data);
	newnode->next = head;
	head = newnode;
	t->next = newnode;
	return head;
}

node* insertPos(node* head,int pos){
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
	t->next = newnode;
	newnode->next = h;
	return head;
}

void insertEnd(node* head){
	node *t = head;
	while(t->next!=head){
		t=t->next;
	}
	cout<<"what valude do you want to insert at the end"<<endl;
	int data;
	cin>>data;
	node *newnode = new node(data);
	t->next = newnode;
	newnode->next = head;
}

node* delBeg(node *head){
	node *t = head;
	while(t->next!=head){
		t=t->next;
	}
	t->next = head->next;
	node* d=head;
	head = head->next;
	delete d;
	return head;
}

void delPos(node* head,int pos){
	int k=1; node* t = head;
	while(k<pos-1){
		t = t->next;
		k++;
	}
	node* d = t->next;
	t->next = d->next;
	delete d;
	return;
}

void delEnd(node* head){
	node *t = head;
	while(t->next->next!=head){
		t=t->next;
	}
	node *d = t->next;
	t->next = head;
	delete d;
	return;
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
	insertEnd(head);
	print(head);
	head = delBeg(head);
	print(head);
	delPos(head,pos); 
	print(head);
	delEnd(head);
	print(head);
}

