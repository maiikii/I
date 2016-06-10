#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

class node{
public:
    int item;
    node *next;
    node(){
    	item = 0;
    	next = NULL;
    }
    node(int x){
    	item = x;
    	next = NULL;
    }
};

class List{
protected:
    node *head, *tail;
    int size;
public:
	List();
	~List();
	void display();
	void append(int);
	void insertFront(int);
	bool insert(int,int);
	bool deleteItem(int);
	int getItem(int);
};

List::List(){
    head = tail = NULL;
    size = 0;
}
List::~List(){
	while(size!=0)
		deleteItem(1);
}
void List::display(){
    node *tmp = head;
    while(tmp!=NULL){
        printf("%d ", tmp->item);
        tmp = tmp->next;
    }
    printf("\n");
}

void List::append(int x){
    node *n = new node(x);

    if(size==0)
        head = tail = n;
    else{
        tail->next = n;
        tail = n;
    }
    size++;
}

bool List::deleteItem(int p){
    node *tmp, *del;
    int ctr=1;
    if(p<1 || p>size)
        return false;
    tmp = head;
    if(p==1){
        del = tmp;
        head = tmp->next;
    }
    else{
        while(ctr < p - 1){
            tmp = tmp->next;
            ctr++;
        }
        del = tmp->next;
        tmp->next = del->next;
        del->next = NULL;

        if(del == tail)
            tail = tmp;
    }
    delete(del);
    size--;
    return true;
}

int List::getItem(int p){
	if(p < 1)
		throw 1;
	else
	if(p > size)
		throw 2;
	else{
		node *tmp = head;
		int c = 1;
		while(c < p){
		    tmp = tmp->next;
		    c++;
		}
		return tmp->item;
	}
}

class Stack : private List{
public:
	void push(int n) { append(n);}
	bool pop() {return deleteItem(size);}
	void printItems(){display();}
	int peek() {return getItem(size);}
};

template <class T>

class newNode{
public:
	T item;
	newNode<T> *next, *prev;
	newNode(){item = 0; next = prev = NULL;}
	newNode(T x){item = x; next = prev = NULL;}
};

int main(){
	Stack s;
	for(int i=5; i<8; i++)
		s.push(i);
	s.printItems();
	s.pop();
	s.pop();
	s.printItems();
	cout<<s.getItem(1)<<endl;
	s.printItems();
	/*newNode<char*> n("hello");
	cout<<n.item<<endl;	
	char st[100];
	int x;
	cin>>x;
	cin.ignore();
	cin.getline(st,100,'#');
	cout<<st<<endl;
	
	
    /*List l;
    for(int i=2; i<5; i++)
    	l.append(i);
    try{
	    printf("%d\n",l.getItem(-24));
	}
	catch(int e){
		if(e==1)
			printf("position Less than 1!\n");
		else
		if(e==2)
			printf("position greater than size!\n");
	}
    l.display();    */
}

