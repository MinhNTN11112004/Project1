/*Description
Mỗi nút trên cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau)
Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
· MakeRoot u: Tạo ra nút gốc u của cây
· Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không chèn thêm mới)
· PreOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự trước
· InOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự giữa
· PostOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự sau
Dữ liệu: bao gồm các dòng, mỗi dòng là 1 trong số các hành động được mô tả ở trên, dòng cuối dùng là * (đánh dấu sự kết thúc của dữ liệu).
Kết quả: ghi ra trên mỗi dòng, thứ tự các nút được thăm trong phép duyệt theo thứ tự trước, giữa, sau của các hành động PreOrder, InOrder, PostOrder tương ứng đọc được từ dữ liệu đầu vào
Ví dụ
Dữ liệu
MakeRoot 10
Insert 11 10
Insert 1 10
Insert 3 10
InOrder
Insert 5 11
Insert 4 11
Insert 8 3
PreOrder
Insert 2 3
Insert 7 3
Insert 6 4
Insert 9 4
InOrder
PostOrder
*
Kết quả
11 10 1 3
10 11 5 4 1 3 8
5 11 6 4 9 10 1 8 3 2 7
5 6 9 4 11 1 8 2 7 3 10*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;
struct Node {
    int id;
    vector<Node*> children;
    Node(int id) : id(id) {}
};
Node* root = nullptr; 
unordered_map<int, Node*> nodesMap; 
void makeRoot(int id) {
    if (nodesMap.find(id) == nodesMap.end()) {
        root = new Node(id);
        nodesMap[id] = root;
    }
}
void insert(int u, int v) {
    if (nodesMap.find(v) == nodesMap.end() || nodesMap.find(u) != nodesMap.end()) {
        return; 
    }
    Node* parent = nodesMap[v];
    Node* child = new Node(u);
    parent->children.push_back(child);
    nodesMap[u] = child;
}
void preOrder(Node* node, vector<int>& result) {
    if (!node) return;
    result.push_back(node->id);
    for (Node* child : node->children) {
        preOrder(child, result);
    }
}
void inOrder(Node* node, vector<int>& result) {
    if (!node) return;
    int childCount = node->children.size();
    for (int i = 0; i < childCount; ++i) {
        if (i == childCount / 2) result.push_back(node->id); 
        inOrder(node->children[i], result);
    }
    if (childCount == 0) result.push_back(node->id); 
}
void postOrder(Node* node, vector<int>& result) {
    if (!node) return;
    for (Node* child : node->children) {
        postOrder(child, result);
    }
    result.push_back(node->id);
}
void printTraversal(const vector<int>& result) {
    for (int id : result) {
        cout << id << " ";
    }
    cout << endl;
}
int main() {
    string line;
    while (getline(cin, line) && line != "*") {
        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "MakeRoot") {
            int id;
            ss >> id;
            makeRoot(id);
        } else if (command == "Insert") {
            int u, v;
            ss >> u >> v;
            insert(u, v);
        } else if (command == "PreOrder") {
            vector<int> result;
            preOrder(root, result);
            printTraversal(result);
        } else if (command == "InOrder") {
            vector<int> result;
            inOrder(root, result);
            printTraversal(result);
        } else if (command == "PostOrder") {
            vector<int> result;
            postOrder(root, result);
            printTraversal(result);
        }
    }

    return 0;
}
