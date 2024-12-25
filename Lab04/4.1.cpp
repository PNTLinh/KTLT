#include <bits/stdc++.h> 
using namespace std;
struct Node { 
    int data; 
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};
Node* prepend(Node* head, int data) {//NguyenThuyLinh_20225031
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return head;
}
void print(Node* head) {
    Node* curr = head;
    while (curr != nullptr){
        cout<< curr->data <<" ";
        curr = curr->next;
    }
    cout<< endl;
}
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* after = nullptr;
    while (curr != nullptr){
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    return prev;
}
int main() {
    int n, u;
    cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        cin >> u;
        head = prepend(head, u);
    } 
    cout << "Original list: ";
    print(head);
    head = reverse(head);
    cout << "Reversed list: ";
    print(head);
    return 0; 
}
//NguyenThuyLinh_20225031
