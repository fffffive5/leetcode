#include<stdio.h>
#include<stdbool.h>
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    int pushedindex=1,poppedindex=0,top=1;
    int stack[1001];
    stack[top]=pushed[0];
    while (pushedindex<pushedSize && poppedindex <poppedSize){
        if (popped[poppedindex]==stack[top]){
            top=top-1;
            poppedindex++;
        }else{
            top++;
            if (pushedindex>=pushedSize)
                return false;
            else 
                stack[top]=pushed[pushedindex];
            pushedindex++;
        }
    }
while (poppedindex<poppedSize){
    if (popped[poppedindex]==stack[top]){
        top=top-1;
        poppedindex++;
    }else{
        return false;
    }
}
return true;

}
int main(){
    int pushed[] = {2,1,0};
    int popped[] = {2,0,1};
    bool result = validateStackSequences(pushed, 3, popped, 3);
    printf("Is valid stack sequence: %s\n", result ? "true" : "false");
    return 0;
}