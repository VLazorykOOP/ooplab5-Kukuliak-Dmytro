#include <iostream>
#include <string>
using namespace std;

struct Node {
public:
    int key;
    string key_string;
    Node* left;
    Node* right;

    Node(int a, string b) {
        key = a;
        key_string = b;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    void insert(int a, string b) {
        root = insertRecursive(root, a,b);
    }

    Node* insertRecursive(Node* root, int a, string b) {
        if (root == nullptr) {
            return new Node(a,b);
        }

        if (a < root->key) {
            root->left = insertRecursive(root->left, a, b);
        }
        else if (a > root->key) {
            root->right = insertRecursive(root->right, a,b);
        }

        return root;
    }

    void output(Node* root) {
        if (root != nullptr) {
            output(root->left);
            cout << root->key << "-" << root->key_string << endl;
            output(root->right);
        }
    }

    Node* search(Node* root, int a) {
        if (root == nullptr) {
            cout << "Value not found";
            return nullptr;
        }
        if (root->key == a) {
            cout << a << " - " << root->key_string;
            return nullptr;
        }
       
        
        if (a < root->key) {
            return search(root->left, a);
        }
        else {
            return search(root->right, a);
        }
    }
    void search(Node* root, string a) {
        if (root != nullptr) {
            search(root->left, a);
            if (a == root->key_string) {
                cout << root->key << "-" << root->key_string << endl;
            }
            search(root->right, a);
        }
    }
   

};

int main() {
    BinaryTree tree;
    tree.insert(8,"Eight");
    tree.insert(3,"Three");
    tree.insert(10,"Ten");
    tree.insert(1,"One");
    tree.insert(6,"Six");
    tree.insert(14,"Fourteen");
    tree.insert(4,"Four");
    tree.insert(7,"Seven");
    tree.insert(13,"Thirteen");

    cout << "Output of binary tree: "<< endl;
    tree.output(tree.root);
    cout << endl;

    cout << "Searching for 6:" << endl;
    tree.search(tree.root,"Six");
    cout << endl;


    cout << "Searching for 6:" << endl;
    tree.search(tree.root, 6);
    cout << endl;


    return 0;
}
