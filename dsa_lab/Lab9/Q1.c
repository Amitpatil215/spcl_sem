#include <stdio.h>

#include <stdlib.h>

#define Size 10

int Top = -1, inp_array[Size];
void Push();
int Pop();
void show();
void reverseStackElements();
void insertAtBottom();
int main()
{
    Push(1);
    Push(2);
    Push(3);
    show();
    reverseStackElements();
    show();
}

void Push(int i)
{

    if (Top == Size - 1)
    {
        printf("\nOverflow!!");
    }
    else
    {

        Top = Top + 1;
        inp_array[Top] = i;
    }
}

int Pop()
{
    if (Top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        int popedElement = inp_array[Top];
        printf("\nPopped element:  %d", popedElement);
        Top = Top - 1;
        return popedElement;
    }
}

void show()
{

    if (Top == -1)
    {
        printf("\nUnderflow!!");
    }
    else
    {
        printf("\nElements present in the stack: \n");
        for (int i = Top; i >= 0; --i)
            printf("%d\n", inp_array[i]);
    }
}
void reverseStackElements()
{
    // base case
    if (Top == -1)
    {
        return;
    }

    //recursive case
    int popedElemet = Pop();
    reverseStackElements();
    insertAtBottom(popedElemet);
}

void insertAtBottom(int popedElemet)
{
    if (Top == -1)
    {
        Push(popedElemet);
    }
    else
    {

        int temp = Pop();
        insertAtBottom(popedElemet);
        Push(temp);
    }
}