#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
#include <string>

struct ListNode{
public:
    ListNode(int n);
    ~ListNode();
    int value;
    ListNode* next;
};

class List{
public:
    List(int n);
    ~List();
    void insertFront(int n);
    //position is the index (starts from 0)
    void insert(int n, int pos);
    void remove(int pos);
private:
    ListNode* front;
    int numElements;
};
ListNode::ListNode(int n)
{
    value = n;
}

ListNode::~ListNode()
{}

List::List(int n)
{
    front = new ListNode(n);
    front->next = nullptr;
    numElements = 1;
}

List::~List()
{
   while(front != nullptr){
       ListNode* tmp = front->next;
       delete front;
       front = tmp;
   }  
}

void List::insertFront(int n)
{
    ListNode *oldFront = front->next;
    front = new ListNode(n);
    front->next = oldFront;
    numElements++;
}

void List::insert(int n, int pos)
{
    ListNode *tmp = front;
    int index = 0;
    while(tmp != nullptr && index < pos){
        tmp = tmp->next;
        index++;
    }

    ListNode* holder = tmp->next;
    tmp = new ListNode(n);
    tmp->next = holder;

    numElements++;
}

void List::remove(int pos)
{
    if(pos >= numElements){
        std::string error = "Position given does not exist.  There are " + std::to_string(numElements) + " items in the list";
        throw error;
    }
    else{
        int index = 0;
        ListNode* tmp = front;
        while(index < pos){
            tmp = tmp->next;
        }
        ListNode* trash = tmp;
        tmp = tmp->next;
        delete trash;
        numElements--;
    }
}

#endif