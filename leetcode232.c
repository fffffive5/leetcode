#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int stackin[101];
    int stackout[101];
    int top1;
    int top2;
} MyQueue;

MyQueue *myQueueCreate()
{
    MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
    queue->top1 = -1;
    queue->top2 = -1;
}

void myQueuePush(MyQueue *obj, int x)
{
    obj->top1++;
    obj->stackin[obj->top1] = x;
}

int myQueuePop(MyQueue *obj)
{
    if (obj->top2 == -1)
    {
        while (obj->top1 >= 0)
        {
            obj->top2++;
            obj->stackout[obj->top2] = obj->stackin[obj->top1];
            obj->top1--;
        }
    }
    if (obj->top2 < 0)
        return NULL;
    else
    {
        obj->top2--;
        return obj->stackout[obj->top2 + 1];
    }
}

int myQueuePeek(MyQueue *obj)
{
    if (obj->top2 == -1)
    {
        while (obj->top1 >= 0)
        {
            obj->top2++;
            obj->stackout[obj->top2] = obj->stackin[obj->top1];
            obj->top1--;
        }
    }
    if (obj->top2 < 0)
        return -1;
    else
    {
        return obj->stackout[obj->top2];
    }
}

bool myQueueEmpty(MyQueue *obj)
{
    if (obj->top1 == -1 && obj->top2 == -1)
        return true;
    else
        return false;
}

void myQueueFree(MyQueue *obj)
{
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
int main()
{
    MyQueue *obj = myQueueCreate();
    myQueuePush(obj, 1);
    int param_2 = myQueuePop(obj);
    int param_3 = myQueuePeek(obj);
    bool param_4 = myQueueEmpty(obj);
    myQueueFree(obj);
    //param_2 4 5
    printf("Popped element: %d\n", param_2);
    printf("Peeked element: %d\n", param_3);
    printf("Is queue empty: %s\n", param_4 ? "true" : "false");
    printf("Queue operations completed.\n");
}