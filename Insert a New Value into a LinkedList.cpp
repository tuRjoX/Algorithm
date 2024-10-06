#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    Node* current;

    int initialDataSize;
    cout << "Enter the number of elements for the initial data: ";
    cin >> initialDataSize;

    cout << "Enter " << initialDataSize << " elements for the initial data: ";
    for (int i = 0; i < initialDataSize; ++i) {
        current = new Node;
        cin >> current->data;
        current->next = head;
        head = current;
    }

    current = head;
    cout << "Original Linked List: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    int newData;
    cout << "Enter the data to be inserted: ";
    cin >> newData;

    int insertAfter;
    cout << "Enter the data after which to insert the new data: ";
    cin >> insertAfter;

    current = head;
    while (current != NULL) {
        if (current->data == insertAfter) {
            Node* newNode = new Node;
            newNode->data = newData;
            newNode->next = current->next;
            current->next = newNode;
            break;
        }
        current=current->next;
    }

    current = head;
    cout << "Linked List After Insertion: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}
