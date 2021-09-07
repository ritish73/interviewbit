#include<iostream>
using namespace std;
class node{
	public:
		node* next;
		int data;
		node(int data){
			this->data = data;
			next = NULL;
		}
};
class queueLL{
	node *head, *tail;
	int size;
	public:
		queueLL(){
			head = NULL;
			tail = NULL;
			size = 0;
		}
		int getSize(){
			return size;
		}
		bool isEmpty(){
			return size==0;
		}
		void enqueue(int data){
			node *newnode = new node(data);
			if(isEmpty()){
				head = newnode;
				tail = newnode;
			}
			else{
				tail->next = newnode;
				tail = newnode;
			}
			size++;
		}
		int dequeue(){
			if(isEmpty()){
				cout<<"queue is empty"<<endl;
				return 0;
			}
			int d = head->data;
			node *t = head;
			head = head->next;
			delete t;
			size--;
			return d;
		}
};
int main(){
	queueLL q;
	
	q.enqueue(12);
	q.enqueue(17);
	q.enqueue(13);
	cout<<q.dequeue()<<endl;
	cout<<q.getSize()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	
}
