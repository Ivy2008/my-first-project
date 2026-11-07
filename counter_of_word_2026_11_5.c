#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//此函数用于读取长度不定的字符串
char* read_dynamic_line(){
    int capacity = 16 ;     //初始容量
    int length = 0 ;     //初始长度
    char *str = (char*)malloc(capacity*sizeof(char));       //用malloc向系统请求内存
    if(str == NULL){        //安全检查，看内存是否分配成功
        printf("内存分配失败!\n");
        return NULL;
    }
    int ch;
    while((ch = getchar()) != '\n' && ch!=EOF){       //当读取的字符不为换行符或结束符时才继续
        if(length >= capacity-1){       //判断现在所需长度是否超出容量（注意-1是因为句末）\0
            capacity = capacity*2;      //容量加倍
            char *temp = (char*)realloc(str,capacity*sizeof(char));     //用realloc扩容，注意其返回值先赋给临时指针
            if(temp == NULL){       //安全检查，看是否扩容成功
                printf("内存扩容失败!\n");
                free(str);
                return NULL;
            }
            str = temp ;    //成功则更新指针
        }
        str[length] = (char)ch;   //存放字符
        length++;
    }
    str[length] = '\0'; //末尾手动添\0
    return str ;
}

int main()
{
    char *sentence = read_dynamic_line();
    if(sentence == NULL){
        printf("读取失败！\n");
        return 0 ;
    }

    int capacity = 5;
    int word_count = 0 ;
    char **words = (char**)malloc(capacity*sizeof(char*));  //用malloc向系统请求内存
    if(words == NULL){      //安全检查，看内存是否分配成功
        printf("内存分配失败!\n");  
        return 0;
    }
    char temp_word[100];
    int temp_len = 0;
    for(int i = 0; sentence[i] != '\0';i++){
        char ch ;
        ch = sentence[i];   //用一个临时变量存放当前字符，方便操作
        if(ch >= 'A' && ch <= 'Z'){     //判断是否为字母
            ch = ch + ('a'-'A') ;   //大写转小写
            temp_word[temp_len] = ch ;  //存放字符
            temp_len++;
        }else{
            if(ch >= 'a' && ch<= 'z'){
                temp_word[temp_len] = ch ;
                temp_len++;
            }else{
                if(temp_len>0){ //增加判断，确保此位置是有效单词
                    temp_word[temp_len] = '\0' ;   //如果此位置不是字符说明此单词结束
                    if(word_count >= capacity){     //判断现在所需长度是否超出容量
                        capacity = capacity*2;       //容量加倍
                        char **new_words = (char**)realloc(words,capacity*sizeof(char*));   //用realloc扩容，注意其返回值先赋给临时指针
                        if(new_words == NULL){
                            printf("内存扩容失败!\n");       //安全检查，看是否扩容成功
                            free(words);
                            free(sentence); //扩容失败则释放内存
                            return 0 ;
                        }
                    words = new_words ;     //成功则更新指针
                    }
                    words[word_count] = (char*)malloc((temp_len+1)*sizeof(char));   //给words分配对应大小的内存，注意\0
                    strcpy(words[word_count],temp_word);    //将字符串复制给words
                    word_count++;
                    temp_len = 0 ;//清零这一轮temp_len的值
                }
            }
        }
        
    }

    int count = 0 ;
    for(int k=0 ;k<word_count;k++){
        int is_new = 1;  //假设为新单词
        for(int t=0 ;t<k;t++){
            if(strcmp(words[t],words[k]) == 0){     //遍历数组，比较当前单词与前面的单词
                is_new = 0 ;  //如果和前面的比，有相同的，说明不是新单词
                break;
            }
        }
        if(is_new == 1){
            count++;
        }
    }

    printf("%d\n",count);   //输出不同单词的数量

    for(int j=0 ;j<word_count;j++){
        free(words[j]);
    }
    free(words);
    free(sentence); //逐层释放内存
    return 0 ;
}