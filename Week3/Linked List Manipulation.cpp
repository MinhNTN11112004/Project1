/*Description
Viết chương trình thực hiện công việc sau:
Xây dựng danh sách liên kết với các khóa được cung cấp ban đầu là dãy a1, a2, …, an, 
sau đó thực hiện các thao tác trên danh sách bao gồm: thêm 1 phần tử vào đầu, vào cuối danh sách, hoặc vào trước, 
vào sau 1 phần tử nào đó trong danh sách, hoặc loại bỏ 1 phần tử nào đó trong danh sách
Input
Dòng 1: ghi số nguyên dương n (1 <= n <= 1000)
Dòng 2: ghi các số nguyên dương a1, a2, …, an.
Các dòng tiếp theo lần lượt là các lệnh để thao tác (kết thúc bởi ký hiệu #) với các loại sau:
addlast  k: thêm phần tử có key bằng k vào cuối danh sách (nếu k chưa tồn tại)
addfirst  k: thêm phần tử có key bằng k vào đầu danh sách (nếu k chưa tồn tại)
addafter  u  v: thêm phần tử có key bằng u vào sau phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u chưa tồn tại)
addbefore  u  v: thêm phần tử có key bằng  u vào trước phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u của tồn tại)
remove  k: loại bỏ phần tử có key bằng k khỏi danh sách
reverse: đảo ngược thứ tự các phần tử của danh sách (không được cấp phát mới các phần tử, chỉ được thay đổi mối nối liên kết)
Output
Ghi ra dãy khóa của danh sách thu được sau 1 chuỗi các lệnh thao tác đã cho
Example
Input
5
5 4 3 2 1
addlast 3
addlast 10
addfirst 1
addafter 10 4
remove 1
#
Output
5 4 3 2 10*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

void addLast(Node*& head, int k) {
    Node* current = head;
    while (current) {
        if (current->value == k) return; 
        current = current->next;
    }
    Node* newNode = new Node(k);
    if (!head) {
        head = newNode;
    } else {
        current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}
void addFirst(Node*& head, int k) {
    Node* current = head;
    while (current) {
        if (current->value == k) return; 
        current = current->next;
    }

    Node* newNode = new Node(k);
    newNode->next = head;
    head = newNode;
}
void addAfter(Node*& head, int u, int v) {
    Node* current = head;
    while (current) {
        if (current->value == v) {
            Node* check = head;
            while (check) {
                if (check->value == u) return; 
                check = check->next;
            }
            Node* newNode = new Node(u);
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}
void addBefore(Node*& head, int u, int v) {
    if (head && head->value == v) {
        addFirst(head, u);
        return;
    }
    Node* current = head;
    while (current && current->next) {
        if (current->next->value == v) {
            Node* check = head;
            while (check) {
                if (check->value == u) return; 
                check = check->next;
            }
            Node* newNode = new Node(u);
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
}
void remove(Node*& head, int k) {
    if (!head) return;

    if (head->value == k) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }
    Node* current = head;
    while (current->next) {
        if (current->next->value == k) {
            Node* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
            return;
        }
        current = current->next;
    }
}
void reverse(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;       
    }
    head = prev; 
}
void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }
}
int main() {
    int n;
    cin >> n;
    Node* head = nullptr;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        addLast(head, value);
    }
    cin.ignore();
    string command;
    while (getline(cin, command)) {
        if (command == "#") break;
        stringstream ss(command);
        string operation;
        int u, v;
        ss >> operation;
        if (operation == "addlast") {
            ss >> u;
            addLast(head, u);
        } else if (operation == "addfirst") {
            ss >> u;
            addFirst(head, u);
        } else if (operation == "addafter") {
            ss >> u >> v;
            addAfter(head, u, v);
        } else if (operation == "addbefore") {
            ss >> u >> v;
            addBefore(head, u, v);
        } else if (operation == "remove") {
            ss >> u;
            remove(head, u);
        } else if (operation == "reverse") {
            reverse(head);
        }
    }
    printList(head);
    cout << endl;
    while (head) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    return 0;
}
