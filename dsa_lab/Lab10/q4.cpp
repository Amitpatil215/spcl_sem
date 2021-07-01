#include <stdio.h>
#include <stdlib.h>

//POP OPERATION IS COSTLY

struct queue
{
    int *arr[50];
    int count, front, rear;
};

struct stack
{
    struct queue *q1;
    struct queue *q2;
};
void initialize(struct stack *s)
{
    s->q1 = malloc(50 * sizeof(struct queue));
    s->q1->count = 0;
    s->q1->front = -1;
    s->q1->rear = -1;
    s->q2 = malloc(50 * sizeof(struct queue));
    s->q2->count = 0;
    s->q2->front = -1;
    s->q2->rear = -1;
}

int isEmpty(struct queue *q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int n)
{
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
        q->arr[q->rear] = n;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = n;
    }
    q->count++;
}

int dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("empty stack\n");
        return 0;
    }
    else
    {
        int n = q->arr[q->front];
        //free(q->arr[q->front]);
        q->front++;
        q->count--;
        return n;
    }
}
void push(struct stack *s, int n)
{
    enqueue(s->q1, n);
    printf("PUSHED IN (q1) element= %d ,front=%d ,rear=%d ,count=%d", n, s->q1->front, s->q1->rear, s->q1->count);
}

void pop(struct stack *s)
{
    if (isEmpty(s->q1))
    {
        printf("UnderFlow");
    }
    else
    {
        int size = s->q1->count;
        for (int i = 0; i < size - 1; i++)
        {
            //insert elements if q1 into q2
            enqueue(s->q2, dequeue(s->q1));
        }
        int n = dequeue(s->q1);
        s->q1->front = -1;
        s->q1->rear = -1;
        for (int i = 0; i < size - 1; i++)
        {
            //insert the elements from q2 into q1
            enqueue(s->q1, dequeue(s->q2));
        }
        printf("Popped Element is %d\n", n);
    }
}

void display(struct queue *q)
{
    for (int i = 0; i < q->count; i++)
    {
        printf("%d <-- ", q->arr[i]);
    }
    printf("null");
}
void main()
{
    int choice, n, stop = 1;
    struct stack *s;
    initialize(s);
    printf("POP OPERATION IS COSTLY");
    while (stop == 1)
    {
        printf("\n----------MENU---------\n");
        printf("\t 1.PUSH \n\t 2.POP \n\t 3.DISPLAY \n\t 4.EXIT \n-----------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("ENTER ELEMENT TO PUSH\t");
            scanf("%d", &n);
            push(s, n);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            display(s->q1);
            break;
        case 4:
            stop = 0;
        }
    }
}