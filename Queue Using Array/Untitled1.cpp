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
struct Stack{
    Node *top=NULL;
    int cnt =0;

    void push(int d);
    int pop();
    bool Empty();
    int Size();
    int Top();
};

void Stack::push(int d){
    Node *n= new Node(d);
    if(top==NULL){
        top=n;
    }
    else{
        n->next= top;
        top=n;
    }
    cnt++;

}

int Stack::pop(){
    if(top==NULL){
        cout<<"UNderflow";

    }
    else{
        Node *h=top;
        top=top->next;
        int d=h->data;
        delete h;
        cnt--;
        return d;
    }

}

int Stack::Top(){
    if(top==NULL){
        return -1;
    }

    else {
        return top->data;
    }
}

bool Stack::Empty(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }

}
int Stack:: Size(){
    return cnt;
}

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);

    // Display the top element
    cout << "Top element: " << st.Top() << endl;

    // Pop and display elements
    cout << "Popped element: " << st.pop() << endl;
    cout << "New top element: " << st.Top() << endl;




}
