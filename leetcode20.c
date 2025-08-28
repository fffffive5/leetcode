#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include <string.h>
bool isValid(char* s) {
    char *s2=(char*)malloc(10000*sizeof(char));
    if (s==NULL)
        return true;
    int top=0;
    s2[top]=s[0];
    int test=s[0];
    printf("%d   %d ",strlen(s2),test);

    for (int i=1;i<strlen(s);i++){
        if (s[i]=='(' || s[i]=='[' || s[i]=='{'){
            top=top+1;
            s2[top]=s[i];    
        } else{
            if (s[i]==')'){
                if (top>=0 && s2[top]=='('){
                    top=top-1;
                }else {
                    return false;
                }
            }else  if (s[i]==']'){
                if (top>=0 && s2[top]=='['){
                    top=top-1;
                }else {
                    return false;
                }
            }else  if (s[i]=='}'){
                if (top>=0 && s2[top]=='{'){
                    top=top-1;
                }else {
                    return false;
                }
            }
        }
    }
    if (top==-1)
        return true;
    return false;
}
int main(){
    char* s = "(){}}{";
    if (isValid(s)) {
        printf("Valid\n");
    } else {
        printf("Invalid\n");
    }
    return 0;
}