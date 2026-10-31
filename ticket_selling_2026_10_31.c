#include<stdio.h>
#define ROW 20
#define COL 5
#define MAXN 100

//此函数用于计算数组中前n个数据的总和
long long array_sum(const int a[],int n){   //对于数组只读不写
    long long  res = 0 ;    
    int i = 0 ;
    for( i = 0; i<n; i++){
        res += a[i];
    }
    return res ;    
}

int main()
{
    int used[ROW][COL]= {0};  //定义并初始化存放座位占用情况的二维数组，全部为0表示座位全空
    const char Charcol[COL] = {'A','B','C','D','F'};    //定义并初始化存放列对应字母的数组
    
    int n;
    scanf("%d",&n); //读取购票次数

    int num[n];  //定义并初始化存放每次购票张数的数组
    int i=0;
    int x;
    while(i<n && scanf("%d",&x) == 1 && x>0 && x<=5){    //只有当输入合法（每次购票张数不超过5）时才会逐个读取，存入数组
       num[i] = x; 
       i++;
    }
    //循环结束时，num[]中有效值的个数是i

    if(i!=n){
        return 0 ;  //如果读取的有效值个数不等于购票次数，直接结束进程
    }
    if(array_sum(num,i)>MAXN){
        return 0 ;
    }   //调用函数，计算购票张数总和，若超出100则直接结束进程
    
    int count =0 ;//此变量用于记录循环过程中该排的空位数
    int ocp = 0;  //此变量用于记录单次购票过程中已占的座位数
    int output = 0; //此变量用于记录在一轮循环中是否有输出

    for(int j=0;j<n;j++){
        output = 0;//在每一次购票循环的开始都先将输出指示初始化
        for(int a=0;a<ROW;a++){

            for(int b=0;b<COL;b++){
                if(used[a][b] == 0){       
                    count++;        
                }
            }
            //记算循环过程中该排的空位数

            if(count >= num[j]){        //如果该排的空位数大于等于当次应购买票数，则在当排占位，并输出结果
                for(int t=0;t<COL;t++){
                    if(used[a][t] == 0){    //逐列判断
                        used[a][t] = 1;     //如果是空位，则将该位置占用情况变为已用，即1
                        printf("%d%c",a+1,Charcol[t]);  //输出结果
                        ocp++;
                        if(ocp < num[j]){  //此部分通过比较已占的座位数与应购票数确认应该空格还是换行
                         printf(" ");
                        }else{
                            printf("\n");
                            break;
                        }
                    }  
                }
                count = 0 ; 
                ocp = 0 ;
                output = 1; //只要执行了此if语句，一定有输出
                break;
                //清零过程变量并跳出循环
            }else{
            count = 0 ; 
            ocp = 0 ;
             //清零过程变量
            }
        }
        if(output == 0){    //如果此次购票在上述循环中无输出，说明无法安排在同排相邻，则安排在编号最小的几个空座位中（不考虑是否相邻）
            for(int c=0;c<ROW;c++){
                for(int d=0;d<COL;d++){
                    if(ocp <num[j]){
                        if(used[c][d] == 0){
                            used[c][d] = 1;     //如果是空位，则将该位置占用情况变为已用，即1
                            printf("%d%c",c+1,Charcol[d]);  //输出结果
                            ocp++;
                            if(ocp <num[j]){    //判断是否购票已完成，确认应该空格还是换行
                                printf(" ");
                            }else{
                                printf("\n");
                                break;
                            }
                        }
                    }else {
                        break;  //若购票已完成则跳出里层循环
                    }
                }
                if(ocp == num[j]){
                    ocp = 0 ;   //清零过程变量
                    break;  //若购票已完成则跳出外层循环
                }
            }
        }
    }
    return 0 ;
}
    



  