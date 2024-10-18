/*Description
Given a BST initialized by NULL. Perform a sequence of operations on a BST including:
insert k: insert a key k into the BST (do not insert if the key k exists)
Input
•Each line contains command under the form: “insert k”
•The input is terminated by a line containing #
Output
•Write the sequence of keys of nodes visited by the pre-order traversal (separated by a SPACE character)
Example
Input
insert 20
insert 10
insert 26
insert 7
insert 15
insert 23
insert 30
insert 3
insert 8
#
Output
20 10 7 3 8 15 26 23 30*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value): val(value), left(nullptr), right(nullptr) {}
};
TreeNode* insert(TreeNode* node, int k){
    if(node==nullptr){
        return new TreeNode(k);
    }
    if(k<node->val){
        node->left=insert(node->left,k);
    }else if(k>node->val){
        node->right=insert(node->right,k);
    }
    return node;
}
void PreOrder(TreeNode* node){
    if(node!=nullptr){
        cout<<node->val<<" ";
        PreOrder(node->left);
        PreOrder(node->right);
    }
}
int main() {
    TreeNode* root=nullptr;
    string command;
    while(getline(cin, command)){
        if(command=="#"){
            break;
        }
        stringstream ss(command);
        string operation;
        int value;
        ss >> operation >> value;
        if(operation=="insert"){
            root=insert(root, value);
        }
    }
    PreOrder(root);
    cout<<endl;
    return 0;
}
