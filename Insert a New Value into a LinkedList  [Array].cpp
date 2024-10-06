#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

int main() {
    const int size = 7;
    int dataArray[size] = {125, 75, 90, 58, 39, 22, 170};

    node* head = NULL;
    node* current;

    for (int i = 0; i < size; i++) {
        current = new node;
        current->data = dataArray[i];
        current->next = head;
        head = current;
    }

    cout << "LinkedList is: ";
    current = head;
    while (current != NULL) {
        cout << current->data << "  ";
        current = current->next;
    }

    cout << endl;

    cout << "Enter After Which Value You Want To Insert: ";
    int insertAfter;
    cin >> insertAfter;

    cout << "Enter The Value You Want To Add: ";
    int newValue;
    cin >> newValue;

    current = head;
    while (current != NULL) {
        if (current->data == insertAfter) {
            node* newNode = new node;
            newNode->data = newValue;
            newNode->next = current->next;
            current->next = newNode;
            break;
        }
        current = current->next;
    }

    cout << "New LinkedList is: ";
    current = head;
    while (current != NULL) {
        cout << current->data << "  ";
        current = current->next;
    }

    return 0;
}
