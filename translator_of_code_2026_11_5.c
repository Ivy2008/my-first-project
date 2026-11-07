#include<stdio.h>
#include<string.h>
#define MAXN 80

int main()
{
    char str[MAXN];
    char res[MAXN];
    fgets(str,sizeof(str),stdin);   //读取用户输入的字符串
    size_t len = strlen(str);
    if(len>0 && str[len-1]=='\n'){
        str[len-1] = '\0';
        len--;      //手动清除末尾换行符
    }

    for(int i=0;i<len;i++){         //利用ASCLL码判断当位置属于字母还是非字母字符，进行对应加密操作
        if(str[i]<'A'  || (str[i]>'Z' && str[i]<'a') || str[i]>'z'){
            res[i] = str[i];
        }else{
            if((str[i]>='A'   && str[i]<='Y')||(str[i]>='a' && str[i]<='y')){
                res[i] = str[i]+1;  //a-y，A-Y的字母用其后继字母替代
            }else{
                res[i] = str[i]-('Z'-'A'); //把z和Z用a和A替代
            }
        }
    }

    for(int j=0;j<len;j++){
        printf("%c",res[j]);
    }
    printf("\n");
    return 0 ;
}