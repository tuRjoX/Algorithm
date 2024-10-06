#include <iostream>
using namespace std;

// Structure for a Huffman tree node
struct HuffmanNode {
    char data;
    unsigned freq;
    HuffmanNode *left, *right;

    HuffmanNode(char data, unsigned freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Function to find the index of the minimum frequency node in the array
int findMinFreqNode(HuffmanNode* arr[], int n) {
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i]->freq < arr[minIndex]->freq)
            minIndex = i;
    }
    return minIndex;
}

// Function to traverse the Huffman tree and print Huffman codes
void printHuffmanCodes(HuffmanNode* root, string code) {
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << ": " << code << endl;
        return;
    }
    printHuffmanCodes(root->left, code + "0");
    printHuffmanCodes(root->right, code + "1");
}

// Function to build Huffman tree and generate codes
void buildHuffmanTree(char data[], unsigned freq[], int n) {
    // Create an array of leaf nodes
    HuffmanNode* arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new HuffmanNode(data[i], freq[i]);
    }

    int size = n;

    // Merge nodes until there is only one node left
    while (size > 1) {
        int min1 = findMinFreqNode(arr, size);
        HuffmanNode* left = arr[min1];
        for (int i = min1; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;

        int min2 = findMinFreqNode(arr, size);
        HuffmanNode* right = arr[min2];
        for (int i = min2; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;

        HuffmanNode* z = new HuffmanNode('$', left->freq + right->freq);
        z->left = left;
        z->right = right;
        arr[size++] = z;
    }

    // Root of Huffman tree
    HuffmanNode* root = arr[0];

    // Traverse the Huffman tree and print Huffman codes
    cout << "Huffman Codes are:\n";
    printHuffmanCodes(root, "");
}

int main() {
    char data[] = {'H', 'U', 'F', 'F', 'M', 'A', 'N'};
    unsigned freq[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(data) / sizeof(data[0]);

    buildHuffmanTree(data, freq, n);

    return 0;
}
