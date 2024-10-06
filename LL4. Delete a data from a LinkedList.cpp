#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int main() {
    Node* head = NULL;
    Node* current;

    const int size = 5 ;
    int dataArray[size] = {120,50,20,2,80};

    for (int i = 0; i < size; ++i) {
        current = new Node;
        current->data = dataArray[i];
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

    int deleteData;
    cout << "Enter the data to be deleted: ";
    cin >> deleteData;

    Node* prev = NULL;
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

    return 0;
}
