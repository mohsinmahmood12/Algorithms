/* Singly linked list */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList{
    private:
        Node *head, *tail;
    public:
        LinkedList(){
            head = NULL;
            tail = NULL;
        }
        void createNode(int value){
            Node *temp = new Node;
            temp->data = value;
            temp->next = NULL;
            if(head == NULL){
                head = temp;
                tail = temp;
                temp = NULL;
            } else {
                tail->next = temp;
                tail = temp;
            }
        }
        void display(){
            Node *temp = new Node;
            temp = head;
            while(temp != NULL){
                cout << temp->data << "\t";
                temp = temp->next;
            }
        }
        void insert_start(int value){
            Node *temp = new Node;
            temp->data = value;
            temp->next = head;
            head = temp;
        }
        void insert_position(int pos, int value){
            Node *pre = new Node;
            Node *cur = new Node;
            Node *temp = new Node;
            cur = head;
            for(int i = 1; i < pos; i++){
                pre = cur;
                cur = cur->next;
            }
            temp->data = value;
            pre->next = temp;
            temp->next = cur;
        }
        void delete_first(){
            Node *temp = new Node;
            temp = head;
            head = head->next;
            delete temp;
        }
        void delete_last(){
            Node *current = new Node;
            Node *previous = new Node;
            current = head;
            while(current->next != NULL){
                previous = current;
                current = current->next;
            }
            tail = previous;
            previous->next = NULL;
            delete current;
        }
        void delete_position(int pos){
            Node *current = new Node;
            Node *previous = new Node;
            current = head;
            for(int i = 1; i < pos; i++){
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
        }
};

int main(){
    LinkedList list;
   
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        list.createNode(rand() % 100);
    }
    list.display();
    cout << endl;
    list.insert_start(100);
    list.display();
    cout << endl;
    list.insert_position(3, 200);
    list.display();
    cout << endl;
    list.delete_first();
    list.display();
}