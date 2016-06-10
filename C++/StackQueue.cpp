#include <iostream>

using namespace std;

template <class T>

class node{
public:
    T item;
    node<T> *next, *prev;
};

template <class T>
class List{
protected:
    node<T> *head, *tail;
    int size;
public:
    int getSize(){return size;}
    T getItem(int);
    void append(T);
    void insertFront(T);
    bool deleteItem(int);
    List(){ head = tail = NULL;size =0;};
    List(const List&);
    ~List();
};
template <class T>
class Stack:private List<T>{
public:
    Stack() {};
    ~Stack();
    void push(T);
    bool pop();
    void display();
};

int main(){
    Stack<int> s;

    for(int i=1; i<15; i+=3){
        s.push(i);
        s.display();
    }
    s.pop();
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
}

template <class T>
List<T>::List(const List<T> &l){
    head = tail = NULL;
    size = 0;
    node<T> *tmp = l.head;
    while(tmp!=NULL){
        append(tmp->item);
        tmp = tmp->next;
    }
}

template <class T>
T List<T>::getItem(int p){
    if(p<1 || p > size)
        throw "invalid position";
    else{
        node<T> *tmp = head;
        int i=1;
        while(i<p){
            i++;
            tmp = tmp->next;
        }
        return tmp->item;
    }
}

template <class T>
void List<T>::append(T x){
    node<T> *n = new node<T>;
    n->item = x;
    n->next = NULL;
    n->prev = NULL;
    if(size==0)
        head = tail = n;
    else{
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    size++;
}

template <class T>
void List<T>::insertFront(T x){
    node<T> *n = new node<T>;
    n->item = x;
    n->next = NULL;
    n->prev = NULL;
    if(size==0)
        head = tail = n;
    else{
        n->next = head;
        head->prev = n;
        head = n;
    }
    size++;
}
template <class T>
bool List<T>::deleteItem(int p){
    if(p<1 || p>size)
        return false;
    else{
        node<T> *tmp = head, *del;
        if(p==1){
            del = head;
            head = head->next;
        }
        else{
            int i=1;
            while(i<p-1){
                tmp = tmp->next;
                i++;
            }
            del = tmp->next;
            tmp->next = del->next;

            if(del == tail)
                tail = tmp;
            else
                del->next->prev = tmp;
        }
        del->next = NULL;
        del->prev = NULL;
        size--;
        delete del;
        return true;
    }
}
template <class T>
List<T>::~List(){
    while(size!=0)
        deleteItem(1);
}
template <class T>
void Stack<T>::push(T x){
    List<T>::append(x);
}
template <class T>
bool Stack<T>::pop(){
    return List<T>::deleteItem(List<T>::size);
}
template <class T>
void Stack<T>::display(){
    node<T> *tmp = List<T>::tail;
    while(tmp!=NULL){
        cout<<tmp->item<<" ";
        tmp = tmp->prev;
    }
    cout<<endl;
}
template <class T>
Stack<T>::~Stack(){
    while(List<T>::size!=0){
        pop();
    }
}
