#include<stdio.h>
#include<string.h>
long long calculate(char* s) {
    int sign[300000];
    int number_sign=1;
    int top=1;
    sign[top]=1;
    int i=0;
    long long number=0,sum=0;
    while (i<strlen(s)){
        if (s[i]>='0' && s[i]<='9'){
            number=0;;
            while (i<strlen(s) && s[i]>='0' && s[i]<='9'){
                number=number*10+s[i]-'0';
                i=i+1;
            }
            sum=sum+number*sign[top]*number_sign;
        }
        else if (s[i]=='+'){
            number_sign=1;
            i++;
       } else if (s[i]=='-'){
            number_sign=-1;
            i++;
       }else if (s[i]=='('){
        top=top+1;
        sign[top]=sign[top-1]*number_sign;
        number_sign=1;
        i++;
       }else if (s[i]==')'){
        top=top-1;
        i++;
       }else {
        i=i+1;
       }
    }
    return sum;
}
int main(){
    char* s = "2147483648";
    printf("%lld\n", calculate(s));
    return 0;
}