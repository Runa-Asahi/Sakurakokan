# <center> C语言输入输出函数
1. #### gets()
   - 功能：
    从标准输入读入<u>字符</u>,并保存到s指定的内存空间，直到出现换行符或文件结尾为止
    - 参数
    s：字符串首地址
    - 返回值
    成功：读入的字符串
    失败：NULL  
```c
#include <stdio.h>
char *gets(char *s);
```
   
   ##### gets(str)与scanf("%s",str)的区别：
   - gets(str)允许输入的字符串有空格
   - scanf("%s",str)不允许含有空格
   - scanf()和gets()无法知道字符串s大小，因此容易导致字符数组越界
  <br>
  2. #### fgets()
```c
#include <stdio.h>
char *fgets(char *s,int size,FILE *stream);    
```
- 功能：   
  从stream指定的文件内读入字符，保存到s指定的内存空间，直到出现换行字符、文件结尾或是已读size-1个字符为止，最后会<u>自动加上字符'\0'</u>作为字符串结束。
- 参数
  s：字符串首地址
  size：指定最大读取字符串的长度（size-1）
  stream：文件指针，如果都键盘输入的字符串，固定写为stdin
- 返回值
  成功：成功读取的字符串
  读到文件结尾或出错：NULL
- fgets()在读取用户通过键盘输入的字符串的时候，同时把用户输入的回车也作为字符串的一部分。==通过scanf和gets输入一个字符串的时候，不包含结尾的'\n'，但通过fgets结尾多了'\n'。==fgets()函数是安全的，不存在缓冲区溢出的问题
  <br>
3. puts()
   ```c
   #include <stdio.h>
   int puts(const char *s);
   ```
   - 功能：<br>标准设备输出s字符串，在输出完成后自动输出一个'\n'
   - 参数：<br>s:字符串首地址
   - 返回值：
   成功：非负数
   失败：-1