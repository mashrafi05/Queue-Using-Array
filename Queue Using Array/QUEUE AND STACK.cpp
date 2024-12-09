#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }

};

struct Queue{
    Node *Front=NULL,*Rear=NULL;
    int cnt =0;
    void push(int d);
    int pop();
    int Size();
    bool Empty();
    int Frontt();
};

void Queue :: push(int d){
    Node *n= new Node(d);
    if(Front==NULL){
        Front=n;
        Rear=n;
    }
    else{
        Rear->next=n;
        Rear=n;
    }
    cnt++;
}

int Queue :: pop(){
    if(Size()==0){
        cout<<"Under flow";

    }
    else if(Front==Rear){
        Front=NULL;
        Rear=NULL;

    }
    else {
        Node *del = Front;


        Front=Front->next;
        delete del;

    }
    cnt--;
}

int Queue::Frontt(){
    if(Size()==0){
        return -1;
    }
    return Front->data;
}

bool Queue::Empty(){
    if(Size()==0){
        return 0;
    }
    else{
        return 1;
    }
}
int Queue:: Size(){
    return cnt;
}
int main(){
    Queue sl;
    sl.push(110);
    sl.push(10);
    sl.push(10);
    sl.push(120);

    sl.pop();
    cout<<sl.Frontt();

}
