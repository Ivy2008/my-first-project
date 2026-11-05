#include<stdio.h>
#include<string.h>

#define MAXN 50

int main()
{
    char strA[MAXN+1];
    char strB[MAXN+1];

    fgets(strA, sizeof(strA),stdin);   //读取用户输入的大数字符串A
    size_t lenA = strlen(strA);
    if(lenA>0 && strA[lenA-1] == '\n'){
        strA[lenA-1] = '\0';
    }       //手动去除换行符
    
    fgets(strB, sizeof(strB),stdin);   //读取用户输入的大数字符串B
    size_t lenB = strlen(strB);
    if(lenB>0 && strB[lenB-1] == '\n'){
        strB[lenB-1] = '\0';
    }      

    int arrA[lenA-1];       //注意有效数据个数是lenA-1(除去末尾\0)
    for(int i=0;i<lenA-1;i++){    
        arrA[i] = strA[lenA-2-i]-'0';  //将单个数字字符转为整型数值并存入相应数组中,注意存数方向和原来相反,且要跳过str末尾的\0
    }    

    int arrB[lenB-1];       
    for(int j=0;j<lenB-1;j++){
        arrB[j] = strB[lenB-2-j]-'0';  
    }

    int res[MAXN+1];
    int k=0;

    if(lenA==lenB){
        while(k<lenA-1){
            if((k+1)==(lenA-1) && (arrA[k]+arrB[k]>=10)){   //判断是否在计算至两数的最大位时需要进位
                res[k] = (arrA[k]+arrB[k])%10 ;
                res[k+1]=1;
                k = k+2;    //注意此过程对结果数组中两个位置赋值了
            }else{
                res[k] = (arrA[k]+arrB[k])%10 ; //遍历数组，该位两数之和除以10取余得到结果该位数字
                if(arrA[k]+arrB[k]>=10){
                    arrA[k+1]++;        //满10进位
                }
                k++;
            }
        }
    }   //当循环结束时，k即为结果数组中有效值个数

    if(lenA>lenB){
        for(k=0;k<lenB-1;k++){        //计算两数位数对齐部分
            res[k] = (arrA[k]+arrB[k])%10 ; //遍历数组，该位两数之和除以10取余得到结果该位数字
            if(arrA[k]+arrB[k]>=10){
                arrA[k+1]++;        //满10进位
            }
        }
        while(k<lenA-1){  //计算两数位数不对齐部分
            if(arrA[k]==10){    //判断当位是否需要进位
                if((k+1)==lenA-1){    //当计算至较长数的最大位时，进位并停止循环
                    res[k]=0;
                    res[k+1]=1;
                     k = k+2;    //注意此过程对结果数组中两个位置赋值了
                }else{
                    arrA[k+1]++;    //当未计算至较长数的最大位时，进位并继续计算
                    res[k]=0;
                    k++;
                }   
            }else{
                res[k] = arrA[k];
                k++;
            }
        }
    }   //当循环结束时，k即为结果数组中有效值个数
        
    if(lenA<lenB){  //同lenA>lenB的情况
        for(k=0;k<lenA-1;k++){        
            res[k] = (arrA[k]+arrB[k])%10 ; 
            if(arrA[k]+arrB[k]>=10){
                arrB[k+1]++;        
            }
        }
        while(k<lenB-1){  
            if(arrB[k]==10){    
                if((k+1)==lenB-1){    
                    res[k]=0;
                    res[k+1]=1;
                    k = k+2;
                }else{
                    arrB[k+1]++;    
                    res[k]=0;
                    k++;
                }   
            }else{
                res[k] = arrB[k];
                k++;
            }
        }
    }

    printf("最终结果是:");
    for(int x=k-1;x>=0;x--){
        printf("%d",res[x]);    //打印结果，注意计算从右往左而输出从左往右，故下标应从最大的开始
    }  
    printf("\n");   
    return 0 ;
}
