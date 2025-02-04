#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
void insertlast(Node* &head,int val) {
    
    Node* x = new Node(val);
    if(head == NULL){
        head = x;
        return;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = x;
}
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
        cout<<endl;
}
int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    display(head);
    insertlast(head, 30);
    insertlast(head, 40);
    insertlast(head, 50);
    display(head);

    return 0;
}