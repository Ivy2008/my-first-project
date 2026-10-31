#include<stdio.h>

//此函数用于将原数组分成奇偶两个数组，并返回偶数个数
int array_classify_number_of_even(int x,int or[x],int od[x],int ev[x]){
    int k=0 ;
    int m=0 ;
    for(int i=0; i<x; i++){
            if(or[i]%2 == 0){       
                ev[k]=or[i];
                k++;
            }else{
                od[m]=or[i];
                m++;
            }
    }
    return k ;
}

//此函数用于合并出新数组
void array_compose(int ne,int no, int ev[],int od[],int to[]){
    int k=0 ;
    int i = 0;
    if(ne>=no){
        for(i=0;i<2*no-1;i=i+2){
            to[i]=ev[k];        //先取偶后取奇
            to[i+1]=od[k];
            k++;
        }
        for(int j=2*no;j<ne+no;j++){
            to[j]=ev[k];        //若一方耗尽，追加另一方全部剩余元素至新数组
            k++;
        }
    }else{
        for(i=0;i<2*ne-1;i=i+2){
            to[i]=ev[k];
            to[i+1]=od[k];
            k++;
        }
        for(int j=2*ne;j<ne+no;j++){
            to[j]=od[k];
            k++;
        }
    }
}

//此函数用于使合并后的数组去除相邻重复项
int  array_repeat_delete(int x,int to[],int re[]){
    int k=0;
    for(int i=0;i<x-1;i++){
        if(to[i] != to[i+1]){
            re[k]=to[i];    //当数组该位元素与下一位元素不同时，对结果数组进行赋值，并使结果数组下标加一
            k++;
        }else{
            re[k]=to[i];   //当数组该位元素与下一位元素相同时，对结果数组进行赋值，但结果数组下标不变（使得下一次赋值仍在原位进行，相当于去除相邻重复项）
        }
    }
    if(to[x-2]!=to[x-1]){       //单独判断末位元素是否是相邻重复元素，若否则补充赋值
            re[k] = to[x-1];    
            return k+1; //当末位元素不是相邻重复元素时，上面的最后一次循环已使k+1，补充赋值后结果数组中最后一个元素下标刚好为k
        }else{
            return k+1; //当末位元素是相邻重复元素时，上面的最后一次循环不会使k+1，结果数组中最后一个元素也下标刚好为k
        }
        //返回结果数组有效值个数
}

int main()
{
    int n ;
    scanf("%d",&n);     //读取一非负整数作为数组长度
    if(n<0 || n>1000){  //先判断输入是否合法
        return 0;
    }else if(n==0){ 
        printf("\n");
        return 0 ;
    }
    int ori[n];   //原数组
    int odd[n];     //奇数组
    int even[n];    //偶数组
    int tog[n]; //合并后数组
    int res[n]; //结果数组

    for(int k=0; k<n; k++){
        scanf("%d",&ori[k]);         //逐个读取原数组元素
    }

    int nuE = array_classify_number_of_even(n,ori,odd,even);
    int nuO = n-nuE;
    //调用函数，将原数组分成奇偶两个数组，并分别记录奇偶数个数

    array_compose(nuE,nuO,even,odd,tog);
    //调用函数，合并出新数组

    int t = array_repeat_delete(n,tog,res);
    //调用函数，使合并后的数组去除相邻重复项，并记录结果数组有效值个数

    printf("偶数组:");
    for(int i=0; i<nuE; i++){
        printf("%d ",even[i]);
    }
    printf("\n");

    printf("奇数组:");
    for(int v=0; v<nuO; v++){
        printf("%d ",odd[v]);
    }
    printf("\n");

    printf("合并后的新数组:\n");
    for(int j=0;j<n;j++){
        printf("%d ",tog[j]);
    }
    printf("\n");

    printf("结果数组:\n");
    for(int i=0;i<t;i++){
        printf("%d ",res[i]);
    }
    printf("\n");


    return 0;
}