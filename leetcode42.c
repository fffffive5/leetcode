#include<stdio.h>
#include<stdlib.h>

int trap(int* height, int heightSize) {
    int ans=0;
    int stack[heightSize];
    int top=0,index=0;
    int number=0;
    int left,min;
    while (index<heightSize && height[index]==0){
        index++;
    }
    stack[top]=index;
    index++;
    if (index>=heightSize)
        return 0;
    while (index<heightSize){
        if (height[stack[top]]>=height[index]){
            top++;
            stack[top]=index;
            index++;
        }else {
           left=top-1;
           while (left>=0 && height[stack[top]]<height[index]){
                number=index-stack[left]-1;
                if (height[stack[left]]>=height[index]){
                    min=height[index];
                }else{
                    min=height[stack[left]];
                }
                ans=ans+number*(min-height[stack[top]]);
                top--;
                left=top-1;
           }
            while (top>=0 && height[stack[top]]<height[index]){
                top--;
            }
            top++;
            stack[top]=index;
            index++;
        }
    
    }
    return ans;
}
int main(){
    int height[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = trap(height, 12);
    printf("Trapped rainwater: %d\n", result);
    return 0;
}