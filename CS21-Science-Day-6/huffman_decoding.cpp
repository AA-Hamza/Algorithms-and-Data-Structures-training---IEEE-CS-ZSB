/*
    Problem Link https://www.hackerrank.com/challenges/tree-huffman-decoding/problem
    Time Complexity O(log n)
*/


/* 
The structure of the node is

typedef struct node {

	int freq;
    char data;
    node * left;
    node * right;
    
} node;
*/


void decode_huff(node * root, string s) {
    node *curr = root;
    for (auto ch: s) {
        if (ch == '1') {
            curr = curr->right;
        }
        else {
            curr = curr->left;
        }
        if (curr->data != 0) {
            cout << curr->data;
            curr = root;
        }
    }
}
