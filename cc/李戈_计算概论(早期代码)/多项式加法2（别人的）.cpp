#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
/*
1 注意flag的存放，不能放在for循环里面，否则每次for循环都置flag=0，导致内层else始终无法执行；
2 判断条件中，arr[i]与i不要弄混了，这是逻辑错误
3 总体思路，先按系数分三类1，每类1里面，按首项和其他项分类2，每类2里面再按指数不同分三种处理情况，对应输出不同格式
*/
int main()
{
    int coef,expo;
    int cnt=0;
    int arr[SIZE];
    int i;
    for (i=0;i<SIZE;i++){
        arr[i]=0;
    }
    while(scanf("%d %d",&expo,&coef)){
        arr[expo] += coef; // 这一步忘了要可以实现重复加，所以要多个+号
        if (expo == 0) cnt++;
        if (cnt == 2) break;
    }
  
	int flag = 0;
    //不能放在for循环里面，否则每次for循环都置flag=0，导致内层else始终无法执行；
    for (i=SIZE-1;i>=0;i--){
        if (arr[i]>1 || arr[i] <-1){ //判断条件中，arr[i]与i不要弄混了，这是逻辑错误
            if (!flag){
                flag = 1;
                if (i>1){
                    printf("%dx%d",arr[i],i);
                }
                else if (i == 1){
                    printf("%dx",arr[i]);
                }
                else{
                     printf("%d",arr[i]);
                }
            }
            else {
                    if (i>1){
                        printf("%+dx%d",arr[i],i);
                    }
                    else if (i == 1){
                        printf("+%dx",arr[i]);
                    }
                    else{
                         printf("+%d",arr[i]);
                    }
            }

        }
        else if (arr[i] == 1){
            flag = 1;
            if (!flag){
                flag = 1;
                if (i>1){
                    printf("x%d",i);
                }
                else if (i == 1){
                    printf("x");
                }
                else{
                     printf("1");
                }
            }
            else {
                    if (i>1){
                        printf("+x%d",i);
                    }
                    else if (i == 1){
                        printf("+x");
                    }
                    else{
                         printf("+1");
                    }
            }

        }
        else if (arr[i] == -1){
            if(!flag){
                flag =1;
                if (i>1){
                    printf("-x%d",i);
                }
                else if (i == 1){
                    printf("-x");
                }
                else {
                    printf("-1");
                }
            }
        }
    }
    if (flag == 0)
        printf("0");

    return 0;
}
