#include <iostream>
using namespace std;

struct node
{
    int data;
    node * next;
};

int main()
{
    node * head = NULL;
    node * current ;

    /*Take Input Into A lInked List*/
    int n;
    cout<<"How Many Elements You Wanted to Store ? Ans . ";
    cin>>n;

    cout<<"Enter The "<<n<< " Elements : ";
    for(int i=0;i<n;i++){
        current = new node;
        cin>>current->data; /*For Generate Random Value Write : current->data = rand()%100 */
        current->next=head;
        head=current;
    }

    current=head;
    cout<<"Linked List is : ";
    while(current!=NULL){
        cout<<current->data<<"  ";
        current=current->next;
    }

    /*----------------------------------------------------------------------*/
    cout<<endl;
    /* Insert A Value in a specific position into A Linked List */


    int newValue;
    cout<<"Enter The New Value : ";
    cin>>newValue;

    int insertAfter;
    cout<<"After Which Value you wanted to insert the new value ? Ans. ";
    cin>>insertAfter;

    current=head;
    while(current!=NULL){
        if(current->data==insertAfter){
            node *newNode = new node;
            newNode->data = newValue;
            newNode->next = current->next;
            current->next = newNode;
            break;
        }
        current = current->next;
    }

    current = head;
    cout<<"New Linked List is : ";
    while(current!=NULL){
        cout<<current->data<<"  ";
        current=current->next;
    }

    /*----------------------------------------------------------------------*/
    cout<<endl;
    /*Delete A Specific Value From A Linked List*/

    int deleteData;
    cout << "Enter the data to be deleted: ";
    cin >> deleteData;

    node* prev = NULL;
    current = head;
    while (current != NULL) {
        if (current->data == deleteData) {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            break;
        }
        prev = current;
        current = current->next;
    }

    current = head;
    cout << "Linked List After Deletion: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }

    /*----------------------------------------------------------------------*/
    cout << endl;
    /*Search for A Specific Value In Link List*/

    int searchValue;
    cout << "Enter the value to search: ";
    cin >> searchValue;

    current = head;
    bool found = false;
    while (current != NULL){
        if (current->data == searchValue){
            found = true;
            break;
        }
        current = current->next;
    }

    if (found){
        cout << "Value found in the linked list." << endl;
    }
    else{
        cout << "Value not found in the linked list." << endl;
    }

    return 0;
}
