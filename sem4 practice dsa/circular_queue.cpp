#include<iostream>
using namespace std;
class queue{
	int fi;
	int ni;
	int size,capacity;
	int* arr;
	public:
	queue(int size){
		arr = new int[size];
		fi = -1;
		ni = 0;
		this->size = 0;
		capacity = size;
	}
	int getSize(){
		return size;
	}
	bool isEmpty(){
		return size==0;
	}
	void enqueue(int element){
		if(isEmpty()){
			fi = 0;
		}
		if(size==capacity){
			cout<<"queue is full";
			return;
		}
		arr[ni] = element;
		ni = (ni+1)%capacity;
		size++;
	}
	int dequeue(){
		if(isEmpty()){
			cout<<"queue is empty";
			return 0;
		}
		int d = arr[fi];
		fi = (fi+1)%capacity;
		size--;
		if(getSize() == 0){
			fi = -1;
			ni = 0;
		}
		return d;
	}
	int front(){
		int d = arr[fi];
		return d;
	}
};

int main(){
	queue q(6);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	cout<<q.getSize()<<endl; //4
	q.enqueue(6);
	cout<<q.dequeue()<<endl;//2
	cout<<q.getSize()<<endl; //4
	cout<<q.dequeue()<<endl;//3
	cout<<q.front()<<endl;//4
	cout<<q.dequeue()<<endl;//4
	cout<<q.dequeue()<<endl;//5
	cout<<q.dequeue()<<endl;//6
	cout<<q.dequeue()<<endl;//full
	q.enqueue(98);
	q.enqueue(8);
	q.enqueue(41);
	cout<<q.dequeue()<<endl;//98
	q.enqueue(48);
	q.enqueue(49);
	q.enqueue(32);
	q.enqueue(499);
	cout<<q.front()<<endl;//499
	q.enqueue(499);//full
	cout<<q.getSize()<<endl;//6
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	
}
