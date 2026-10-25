#include<stdio.h>
#define MAXN 50

unsigned int MyStrlen(char p[ ])	//此函数用于计算指针p所指向的字符串的长度(即实际字符个数)
{
	unsigned int len;
	len=0;
	for ( ; p[len]!=  0 ; )
	{
		len ++ ;		//累加各字符对应长度，存入len
	}
	return len ;	
}

int main()
{
	char a[MAXN];
	printf("Input a string :\n");
	int i=0 ;
	while(i<MAXN-1){	//注意字符串最后一个位置留给\0
		scanf("%c",&a[i]);
		if(a[i] == '.'){	
			a[i] = '\0';	//当读到'.'时，将最后一个位置变为\0，跳出循环
			break ;
		}
		i++;
	}

	printf("The length:%d\n", MyStrlen(a));		//调用函数，打印实际字符个数
	return 0;
}