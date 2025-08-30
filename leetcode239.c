#include<stdio.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int queue[numsSize+1];
    int head=0,tail=0;
    queue[0]=0;
    int index=1;
    *returnSize=numsSize-k+1;
    int *ans=(int*)malloc((numsSize-k+1)*sizeof(int));
    int  indexans=0;
    if (k==1)
        return nums;
    while (index < numsSize){

        while ((head<=tail)&&(nums[queue[tail]]<=nums[index])){
            tail--;
        }
        tail++;
        queue[tail]=index;
        while((head<tail)&&( (queue[tail]-queue[head]+1)>k)){
            head++;
        }
        if (index+1>=k){
            ans[indexans]=nums[queue[head]];
            indexans++;
        }
        index++;
    }
    return ans;
}
int main(){
    int nums[] = {1,3,1,2,0,5};
    int k = 3;
    int returnSize;
    int* result = maxSlidingWindow(nums, 6, k, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}