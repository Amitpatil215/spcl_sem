#include <stdio.h>

#include <stdlib.h>

#define Size 10

int Top = -1, inp_array[Size];
void Push();
int Pop();
void show();

int main()
{
    Push(1);
    Push(2);
    Push(3);
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

void sortStack(){

}