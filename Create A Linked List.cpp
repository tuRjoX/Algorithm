#include<iostream>
using namespace std;

struct node{
	int data;
	node * next;
};

int main() {

	node * head =NULL;
	node * current;

	cout<<"Enter 5 Value : ";
	for(int i=0;i<5;i++){
		current = new node;
		cin>>current->data;
		current->next = head;
		head = current;
	}

	current = head;

	cout<<"LinkedList is : ";
	while(current!=NULL){
		cout<<current->data<<"  ";
		current=current->next;
	}
	return 0;
}
