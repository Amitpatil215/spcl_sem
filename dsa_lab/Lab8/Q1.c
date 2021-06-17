#include <stdio.h>
void push(char element, char stack[], int *top, int stackSize)
{
    if (*top == -1)
    {
        stack[stackSize - 1] = element;
        *top = stackSize - 1;
    }
    else if (*top == 0)
    {
        printf("The stack is full. \n");
    }
    else
    {
        stack[(*top) - 1] = element;
        (*top)--;
    }
}

void pop(char stack[], int *top, int stackSize)
{
    if (*top == -1)
    {
        printf("The stack is empty. \n");
    }
    else
    {
        printf("Element popped: %c \n", stack[(*top)]);
        // if last elemet is popped flag top as empty
        if ((*top) == stackSize - 1)
        {
            (*top) = -1;
        }
        else
        {
            (*top)++;
        }
    }
}

int main()
{
    int size = 10;
    char stack[size];

    int top = -1;
    push('m', stack, &top, size);
    push('n', stack, &top, size);
    pop(stack, &top, size);
    return 0;
}