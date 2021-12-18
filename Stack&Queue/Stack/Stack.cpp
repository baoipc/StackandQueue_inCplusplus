#include <iostream>
#define cin std::cin 
#define cout std::cout

class Stack{
    private:
    public:
        int value;
        Stack* next;
    protected:
};

Stack* top = NULL;

inline void down(){
    cout << '\n';
}

void push(int value)
{
    Stack* node = new Stack();
    if(node == NULL){
        cout << "Memory Heap is Full!!!";
        return;
    }
    node->value = value;
    node->next = top;
    top = node;
}

bool isEmpty(){
    return (top == NULL); 
}

void GetTop(){
    if(!isEmpty())
        cout << "Top at Stack: " << top->value;
    else
        return;
}

void pop(){
    if(isEmpty())
    {
        cout << "Stack is empty!!!";
        return;
    }
    Stack* node = top;
    top=top->next;
    node->next=NULL;
    free(node);    
}

void Display(){
    if(isEmpty())
    {
        cout << "Stack is empty!!!";
        return;
    }
    Stack* node = top;
    while(node->next != NULL)
    {
        cout << node->value << "->";
        node=node->next;
    }
    cout << node->value;
}

int GetLength(){
    if(isEmpty())
    {
        cout << "Stack is empty!!!";
        return 0;
    }
    Stack* node = top;
    int result = 0;
    for(;node!=NULL;node=node->next) ++result;
    return result;
}

int main()
{   
    return 0;
}