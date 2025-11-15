#include <stdio.h>
#define N 105
char arr[N];

int main(){ 
    int tmp;//注意这里要用int类型来接收getchar()的返回值，以便正确判断EOF
    int i=0;
    while((tmp=getchar())!=EOF&&i<N-1){//注意这里要留一个位置给字符串结束符'\0'
        arr[i]=(char)tmp;//注意这里要强制转换为char类型，否则在某些编译器下会报错
        i++;
    }
    printf("%d\n",i);
    return 0;
}