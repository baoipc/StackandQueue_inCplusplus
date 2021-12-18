#include <iostream>

using namespace std;

class QueueNode
{
    private:
    public:
        int value; 
        QueueNode* next;
        QueueNode(int _value)
        {
            value = _value;
            next = NULL;
        }
    protected:
};

class Queue
{
    private:
    public:
        QueueNode* front;
        QueueNode* rear;
        Queue()
        {
            front = NULL;
            rear = NULL;
        }
        void push(int value)
        {
            QueueNode* temp = new QueueNode(value);
            if(rear == NULL)
            {
                front = temp;
                rear = temp;
                return;
            }
            rear->next = temp;
            rear = temp;
        }
        void pop()
        {
            if(front == NULL)
                return;
            QueueNode* temp = front;
            front = front->next;
            if(front == NULL)
                rear = NULL;
            delete (temp);
        }
        int size()
        {
            if(front == NULL)
                return 0;
            QueueNode* temp = front;
            int result = 1;
            for(result=0;temp != NULL; temp = temp->next)
                ++result;
            return result;
        }
        void Display()
        {
            if(front == NULL)
            {
                cout << "Queue is empty" << endl;
                return;
            }
            QueueNode* temp = front;
            for(;temp != NULL; temp = temp->next)
                cout << temp->value << " ";
        }
    protected:
};

int main()
{
    Queue qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.Display();
    qu.pop();
    cout << qu.size() << endl;
    return 0;
}