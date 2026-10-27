#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name, phone; Node *left, *right;
    Node(string n, string p): name(n), phone(p), left(nullptr), right(nullptr) {}
};
Node* insert(Node* root, string name, string phone) {
    if (!root) return new Node(name, phone);
    if (name < root->name) root->left = insert(root->left, name, phone);
    else if (name > root->name) root->right = insert(root->right, name, phone);
    else root->phone = phone;
    return root;
}
Node* search(Node* root, const string& name) {
    if (!root || root->name == name) return root;
    return name < root->name ? search(root->left, name) : search(root->right, name);
}
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left); cout << root->name << " : " << root->phone << '\n';
    inorder(root->right);
}
void destroy(Node* root) {
    if (!root) return; destroy(root->left); destroy(root->right); delete root;
}
int main() {
    Node* root = nullptr; int ch;
    do {
        cout << "\n1.Add/update 2.Search 3.List directory 0.Exit\nChoice: "; cin >> ch;
        if (ch == 1) {
            string n, p; cout << "Name (one word): "; cin >> n;
            cout << "Phone: "; cin >> p; root = insert(root, n, p);
        } else if (ch == 2) {
            string n; cout << "Name to search: "; cin >> n;
            Node* found = search(root, n);
            if (found) cout << found->name << " : " << found->phone << '\n';
            else cout << "Entry not found.\n";
        } else if (ch == 3) inorder(root);
    } while (ch != 0);
    destroy(root);
}
