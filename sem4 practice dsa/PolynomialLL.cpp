#include<iostream>
using namespace std;

class node {
	public:
		int data,pow;
		node* next;
		node(int data,int pow) {
			this->data = data;
			this->pow = pow;
			next = NULL;
		}
};

node* inputPolynomial() {
	cout<<"deg of polynomial"<<endl;
	int n;
	cin>>n;
	node *head = NULL, *tail = NULL;
	for(int i=n; i>=0; i--) {
		
		int data;
		cout<<"enter coeff of x^"<<i<<endl;
		cin>>data;
		node* newnode = new node(data,i);
		if(head == NULL) {
			head = newnode;
			tail = newnode;
		} else {
			tail->next = newnode;
			tail = newnode;
		}
	}
	return head;
}

void print(node* head) {
	node *t = head;
	while(t!=NULL) {
		if(t->next == NULL){
			cout<<t->data<<"x^"<<t->pow;
		}
		else
		cout<<t->data<<"x^"<<t->pow<<" + ";
		t=t->next;
	}
	cout<<endl;
}

node* add(node *head1, node *head2){
	node* head = NULL, *tail = NULL;
	node *larger = (head1->pow > head2->pow)?head1:head2;
	node*smaller = head2;
	if(larger == head2)
		smaller = head1;
	int d = larger->pow - smaller->pow;
	node *tl = larger;
	for(int i=0;i<d;i++){
		node *newnode = new node(tl->data,tl->pow);
		tl = tl->next;
		if(head==NULL){
			head = newnode;
			tail = newnode;
		}
		else{
			tail->next = newnode;
			tail = newnode;
		}
	}
	node* ts = smaller;
	for(int i=smaller->pow;i>=0;i--){
		node *newnode = new node(tl->data+ts->data,tl->pow);
		tl = tl->next;
		ts = ts->next;
		if(head==NULL){
			head = newnode;
			tail = newnode;
		}
		else{
			tail->next = newnode;
			tail = newnode;
		}
	}
	return head;
}


int main() {
	cout<<"enter polynomial 1"<<endl; //5 10 6 3 8 2 1
	node *head1 = inputPolynomial();
	cout<<"enter polynomial 2"<<endl;  //3 9 6 3 2
	node *head2 = inputPolynomial();
	print(head1);
	print(head2);
	node *head = add(head1,head2);
	
	print(head);

}
