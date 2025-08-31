
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int capacity;
    int *nums;
    int front;
    int rear;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *obj=(MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->capacity=k+1;
    obj->nums=(int*)malloc(obj->capacity*sizeof(int));
    obj->front=0;
    obj->rear=0;
    return obj;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->front==(obj->rear+1)%obj->capacity)
        return false;
    obj->front=(obj->front-1+obj->capacity)%obj->capacity;
    obj->nums[obj->front]=value;
    return true;
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->front==(obj->rear+1)%obj->capacity)
        return false;
    obj->nums[obj->rear]=value;
    obj->rear=(obj->rear+1)%obj->capacity;
    
    return true;
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->rear == obj->front)
        return false;
    obj->front=(obj->front+1)%obj->capacity;
    return true;
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->rear == obj->front)
        return false;
    obj->rear=(obj->rear-1+obj->capacity)%obj->capacity;
    return true;
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->rear==obj->front)
        return -1;
    else 
        return obj->nums[obj->front];
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->rear==obj->front)
        return -1;
    else 
        return obj->nums[(obj->rear-1+obj->capacity)%obj->capacity];
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    if (obj->front==obj->rear)
        return true;
    else 
        return false;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    if ((obj->rear+1)%obj->capacity==obj->front)
        return true;
    else 
        return false;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/
int main() {
    MyCircularDeque *obj = myCircularDequeCreate(3);
    printf("%s\n", myCircularDequeInsertLast(obj, 1) ? "true" : "false");
    printf("%s\n", myCircularDequeInsertLast(obj, 2) ? "true" : "false");
    printf("%s\n", myCircularDequeInsertFront(obj, 3) ? "true" : "false");
    printf("%s\n", myCircularDequeInsertFront(obj, 4) ? "true" : "false");
    printf("%d\n", myCircularDequeGetRear(obj));
    printf("%s\n", myCircularDequeIsFull(obj) ? "true" : "false");
    printf("%s\n", myCircularDequeDeleteLast(obj) ? "true" : "false");
    printf("%s\n", myCircularDequeInsertFront(obj, 4) ? "true" : "false");
    printf("%d\n", myCircularDequeGetFront(obj));
    myCircularDequeFree(obj);
    return 0;
}