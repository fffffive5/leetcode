#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    int capacity;
    int *nums;
    int rear;
    int front;
} MyCircularQueue;

MyCircularQueue *myCircularQueueCreate(int k)
{
    MyCircularQueue *obj = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    obj->capacity = k + 1;
    obj->nums = (int *)malloc(obj->capacity * sizeof(int));
    obj->rear = 0;
    obj->front = 0;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue *obj, int value)
{
    if ((obj->rear + 1) % obj->capacity == obj->front)
        return false;
    obj->nums[obj->rear] = value;
    obj->rear = (obj->rear + 1) % obj->capacity;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue *obj)
{
    if ((obj->front ) % obj->capacity == obj->rear)
        return false;
    obj->front = (obj->front + 1) % obj->capacity;
    return true;
}

int myCircularQueueFront(MyCircularQueue *obj)
{
    if (obj->rear == obj->front)
        return -1;
    else
        return obj->nums[obj->front];
}

int myCircularQueueRear(MyCircularQueue *obj)
{
    if (obj->rear == obj->front)
        return -1;
    else
        return obj->nums[(obj->rear - 1+obj->capacity) % (obj->capacity)];
}

bool myCircularQueueIsEmpty(MyCircularQueue *obj)
{
    if ((obj->front ) % obj->capacity == obj->rear)
        return true;
    else
        return false;
}

bool myCircularQueueIsFull(MyCircularQueue *obj)
{
    if ((obj->rear + 1) % obj->capacity == obj->front)
        return true;
    else
        return false;
}

void myCircularQueueFree(MyCircularQueue *obj)
{
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/

int main()
{
    MyCircularQueue *obj = myCircularQueueCreate(6);
    printf("%s\n", myCircularQueueEnQueue(obj, 6) ? "true" : "false");
    printf("%d\n", myCircularQueueRear(obj));
    printf("%d\n", myCircularQueueRear(obj));
    printf("%s\n", myCircularQueueDeQueue(obj) ? "true" : "false");
    printf("%s\n", myCircularQueueEnQueue(obj, 5) ? "true" : "false");
    printf("%d\n", myCircularQueueRear(obj));
    printf("%s\n", myCircularQueueDeQueue(obj) ? "true" : "false");
    printf("%d\n", myCircularQueueFront(obj));
    printf("%s\n", myCircularQueueDeQueue(obj) ? "true" : "false");
    printf("%s\n", myCircularQueueDeQueue(obj) ? "true" : "false");
    printf("%s\n", myCircularQueueDeQueue(obj) ? "true" : "false");
    myCircularQueueFree(obj);
    return 0;
}
