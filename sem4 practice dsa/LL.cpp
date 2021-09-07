#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		node(int data){
			this->data = data;
			next = NULL;
		}
};
node* takeInput(){
	int n;
	cout<<"how many values you want "<<endl;
	cin>>n;
	node *head = NULL;
	for(int i=1;i<=n;i++){
		int data;
		cout<<"enter data of the node"<<endl;
		cin>>data;
		node* newnode = new node(data);
		
		if(head == NULL){
			head = newnode;
		}
		else{
			node* temp = head;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = newnode;
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
	head = newnode;
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
node* delBeg(node* head){
	node* d = head;
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
int main(){
	node* head = takeInput();
	print(head);
	head = insertBeg(head);
	print(head);
	cout<<"at what pos to insert";
	int pos;
	cin>>pos;
	head = insertPos(head,pos);
	print(head);
	head = delBeg(head);
	print(head);
	delPos(head,pos);
	print(head);
}
