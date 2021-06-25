

#include <bits/stdc++.h>
using namespace std;

void reverseQueueFirstKElements(
    int k, queue<int> &Queue)
{
    if (Queue.empty() == true || k > Queue.size())
        return;
    if (k <= 0)
        return;

    stack<int> Stack;

    for (int i = 0; i < k; i++)
    {
        Stack.push(Queue.front());
        Queue.pop();
    }

    while (!Stack.empty())
    {
        Queue.push(Stack.top());
        Stack.pop();
    }

    for (int i = 0; i < Queue.size() - k; i++)
    {
        Queue.push(Queue.front());
        Queue.pop();
    }
}

void Print(queue<int> &Queue)
{
    while (!Queue.empty())
    {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

int main()
{
    queue<int> Queue;
    Queue.push(1);
    Queue.push(2);
    Queue.push(3);
    Queue.push(4);
    Queue.push(5);
    Queue.push(6);
    Queue.push(7);
    Queue.push(8);
    Queue.push(9);
    Queue.push(10);

    int k = 5;
    reverseQueueFirstKElements(k, Queue);
    Print(Queue);
}
