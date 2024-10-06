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

	cout<<endl;

    cout<<"Enter The Value You Wanted To Search : ";
	int searchValue;
	cin>>searchValue;

	current=head;
	bool found= false;
	while(current!=NULL){
        if(current->data == searchValue){
            found=true;
            break;
        }
        current=current->next;
	}
	if(found){
        cout<<"Value Existed.";
	}else{
	    cout<<"Value Not Existed.";
	}
	return 0;
}
