#include <stdio.h>

void Swap(int *x, int *y)   //此函数用于交换两个变量的值
{
int temp;
temp = *x;
*x = *y;
*y = temp;
}  

int main()
{
    int arr[10] = {29, 10, 14, 37, 13, 5, 40, 8, 33, 2};
    int n = 10;
    int min_index ;

    for(int k=0;k<n;k++){
        min_index = k ;     //先假设该位置就是最小值位置
        for(int j=k+1;j<n;j++){ 
            if(arr[j]<arr[k]){
                min_index = j ;     //和其他元素逐一比较，当有更小元素时更新最小值位置
                Swap(&arr[j],&arr[k]);  //调用函数，将原最小值与新最小值交换位置
            }
        }
        printf("第%d趟:最小值为%d,位置%d",k+1,arr[min_index],min_index);    //输出每一趟找到的最小值位置
        printf("\n");
    }

    printf("排序结果：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    //输出最终数组状态

    return 0;
}
