/* Double Ended Queue implementation */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


// Double Ended Queue
class DEQueue{
    private:
        int front, rear, size;
        int *arr;
    public:
        DEQueue(int s){
            front = -1;
            rear = 0;
            size = s;
            arr = new int[s];
        }
        void insertfront(int key);
        void insertrear(int key);
        void deletefront();
        void deleterear();
        bool isFull();
        bool isEmpty();
        int getFront();
        int getRear();
};

// Check if queue is full
bool DEQueue::isFull(){
    return ((front == 0 && rear == size-1) || front == rear+1);
}

// Check if queue is empty
bool DEQueue::isEmpty(){
    return (front == -1);
}

// Insert at front
void DEQueue::insertfront(int key){
    if(isFull()){
        cout << "Overflow";
        return;
    }
    if(front == -1){
        front = 0;
        rear = 0;
    } else if(front == 0){
        front = size - 1;
    } else {
        front = front - 1;
    }
    arr[front] = key;
}

// Insert at rear
void DEQueue::insertrear(int key){
    if(isFull()){
        cout << "Overflow";
        return;
    }
    if(front == -1){
        front = 0;
        rear = 0;
    } else if(rear == size - 1){
        rear = 0;
    } else {
        rear = rear + 1;
    }
    arr[rear] = key;
}


// Delete from front
void DEQueue::deletefront(){
    if(isEmpty()){
        cout << "Underflow";
        return;
    }
    if(front == rear){
        front = -1;
        rear = -1;
    } else {
        if(front == size - 1){
            front = 0;
        } else {
            front = front + 1;
        }
    }
}


// Delete from rear
void DEQueue::deleterear(){
    if(isEmpty()){
        cout << "Underflow";
        return;
    }
    if(front == rear){
        front = -1;
        rear = -1;
    } else if(rear == 0){
        rear = size - 1;
    } else {
        rear = rear - 1;
    }
}

// Get front element
int DEQueue::getFront(){
    if(isEmpty()){
        cout << "Underflow";
        return -1;
    }
    return arr[front];
}

// Get rear element
int DEQueue::getRear(){
    if(isEmpty() || rear < 0){
        cout << "Underflow";
        return -1;
    }
    return arr[rear];
}


// Driver program to test above functions
int main(){
    DEQueue dq(5);
    cout << "Insert element at rear end  : 5" << endl;
    dq.insertrear(5);
    cout << "insert element at rear end : 10" << endl;
    dq.insertrear(10);
    cout << "get rear element " << " " << dq.getRear() << endl;
    dq.deleterear();
    cout << "After delete rear element new rear become " << " " << dq.getRear() << endl;
    cout << "inserting element at front end" << endl;
    dq.insertfront(15);
    cout << "get front element " << " " << dq.getFront() << endl;
    dq.deletefront();
    cout << "After delete front element new front become " << " " << dq.getFront() << endl;
    return 0;
}
