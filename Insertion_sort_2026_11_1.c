#include<stdio.h>

int main() 
{
    int arr[10] = {23, 5, 12, 7, 31, 19, 1, 8, 15, 4};
    int n = 10;
    int temp;
    int j;

    for(int k=1;k<n;k++){
        temp = arr[k];  //先将当前待比较的元素存放起来
        j = k-1;    
        while(j>=0 && arr[j]>arr[j+1]){ //从有序区的末端（即当前待比较的元素的前一个元素）开始比较
            arr[j+1] = arr[j];     //若前一个元素比当前待比较的元素大则将其后移（会覆盖当前待比较的元素）
            j--;
            arr[j+1] = temp ;       //此趟排序结束后，将存放的元素放入原有序区末端位置
        }
        printf("第%d趟:",k);
        for (int a = 0; a < n; a++) {
            printf("%d ", arr[a]);
        }
        printf("\n");
        //每一趟插入排序结束后，输出当前数组状态
    }

    printf("排序结果：");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    //输出最终数组状态
    return 0;
}