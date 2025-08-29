#include<stdio.h>


typedef struct {
    int val[30000];
    int min[30000];
    int top;
} MinStack;


MinStack* minStackCreate() {
    MinStack* minstack=( MinStack*)malloc(sizeof( MinStack));
    minstack->top=0;
    return minstack;
}

void minStackPush(MinStack* obj, int val) {
    obj->top=obj->top+1;
    obj->val[obj->top]=val;
    obj->min[obj->top]=val;

    if (obj->top>1 && obj->min[obj->top-1]<val){
    obj->min[obj->top]=obj->min[obj->top-1];
    }
}

void minStackPop(MinStack* obj) {
    obj->top=obj->top-1;
}

int minStackTop(MinStack* obj) {
    return obj->val[obj->top];
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->top];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

int main(){
    MinStack* obj = minStackCreate();
    minStackPush(obj, 5);
    minStackPush(obj, 2);
    minStackPush(obj, 8);
    printf("Top element: %d\n", minStackTop(obj));
    printf("Minimum element: %d\n", minStackGetMin(obj));
    minStackPop(obj);
    printf("Top element after pop: %d\n", minStackTop(obj));
    printf("Minimum element after pop: %d\n", minStackGetMin(obj));
    minStackFree(obj);
    return 0;
}
/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/