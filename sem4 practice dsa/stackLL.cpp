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
class stackLL{
	node* head;
	int size;
	public:
		stackLL(){
			head = NULL;
			size = 0;
		}
		
		int getSize(){
			return size;
		}
		
		bool isEmpty(){
			return size==0;
		}
		
		void push(int data){
			node *newnode = new node(data);
			newnode->next = head;
			head = newnode;
			size++;
		}
		
		int pop(){
			if(head == NULL){
				cout<<"stack is empty"<<endl;
				return 0;
			}
			node *t = head;
			int d = t->data;
			head = head->next;
			delete t;
			size--;
			return d;
		}
		
		int top(){
			int d = head->data;
			return d;
		}
};

int main(){
	stackLL s;
	s.push(12);
	s.push(10);
	s.push(17);
	s.push(19);
	cout<<s.top()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
}
