#include<stdio.h>
#include<stdbool.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *ans=(int*)malloc(sizeof(int)*temperaturesSize);
    int top=0,index=1;
    int stack[temperaturesSize];
    stack[0]=0;
    while (index<temperaturesSize){
        if (temperatures[stack[top]]>=temperatures[index]){
            top=top+1;
            stack[top]=index;
            index++;
        }else{
            while (top>=0 && temperatures[stack[top]]<temperatures[index]){
                ans[stack[top]]=index-stack[top];
                top--;
            }
            top=top+1;
            stack[top]=index;
            index++;
        }
    }
    while(top>=0){
        ans[stack[top]]=0;
        top--;
    }
    *returnSize = temperaturesSize;
    return ans;
}
int main(){
    int temperatures[] = {30,40,50,60};
    int returnSize;
    int* result = dailyTemperatures(temperatures, 4, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}