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

3. #### puts()
   ```c
   #include <stdio.h>
   int puts(const char *s);
   ```
   - 功能：<br>标准设备输出s字符串，在输出完成后自动输出一个'\n'
   - 参数：<br>s:字符串首地址
   - 返回值：
   成功：非负数
   失败：-1
  
4. #### fputs
    ```c
    #include <stdio.h>
    int fputs(const char *str,FILE *stream);
    ```
    - 功能：将str指定的字符串写入到stream指定的文件中，字符串结束符'\0'不写入文件
    - 参数：<br>str：字符串<br>stream：文件指针，如果把字符出输出到屏幕，固定为stdout
    - 返回值<br>成功：0<br>失败：-1
  ==fputs()是puts()的文件操作版本，但fputs()不会在自动输出一个'\n'==
  5. #### strlen()
   ```c
   #include <string.h>
   size_t strlen(const char*s);
   ```
   - 功能<br>计算指定字符串s的长度，不包含字符串结束符'\0'
   - 参数<br>s：字符串首地址
   - 返回值<br>字符串s的长度，size_t为unsigned int类型
  6. #### strcpy()
   ```c
#include <string.h>
char *strcpy(char *dest,const char *src);
   ```
   - 功能<br>把src所指向的字符串复制到dest所指的空间中，'\0'也会被拷贝过去
   - 参数<br>dest：目的字符串首地址<br>src：源字符首地址
   - 返回值<br>成功：返回dest字符串的首地址<br>失败：NULL
   - 注意：如果参数dest所指的内存空间不够大，可能会造成缓冲溢出的错误情况
```c
#include <string.h>
char *strncpy(char *dest,const char *src, size_t n);
```
7. #### strcnpy()
   - 功能<br>把src指向字符串的前n个字符复制到dest所指向的空间中，是否拷贝结束符看指定的长度是否包含'\0'
   - 参数<br>dest：目的字符串首地址<br>src：源字符首地址<br>n：指定需要拷贝字符个数
   - 返回值<br>成功：返回dest字符的首地址<br>失败：NULL
8. #### strcat
   - 功能<br>将src字符串连接到dest的尾部，'\0'也会追加过去
   - 参数<br>dest：目的字符串首地址<br>src：源字符首地址
   - 返回值<br>成功：返回dest字符串的首地址<br>失败：NULL
9. #### strncat()
  ```c
  #include <string.h>
  char *strncat(char *dest,const char *src,size_t n);
  ```
  - 功能
  将src字符串前n个字符连接到dest的尾部，'\0'也会追加过去
  - 参数
  dest：目的字符串首地址
  src：源字符首地址
  n：指定需要追加字符个数
  - 返回值
  成功：返回dest字符串首地址
  失败：NULL
  10. #### strcmp()
  ```c
#include <string.h>
int strcmp(const char*s1,const char*s2);
  ```
  - 功能
  比较s1和s2的大小，比较的是字符ASCII码的大小
  - 参数
  s1：字符串1首地址
  s2：字符串2首地址
  - 返回值
  相等：0
  大于：>0
  小于：<0

11. #### strncmp()
```c
#include <string.h>
int strncmp(const char *s1, const char *s2, size_t n);
```
- 功能
比较s1和s2前n个字符的大小，比较的是字符ASCII码的大小
- 参数
  s1：字符串1首地址
  s2：字符串2首地址
  n：指定比较字符串的数量
- 返回值
  相等：0
  大于：>0
  小于：<0
12.  #### strchr()
```c
#include <string.h>
char *strchr(const char *s, int c);
```
- 功能
在字符串s中查找字符s出现的位置
- 参数
s：字符串首地址
c：匹配字符
- 返回值
成功：返回第一次出现的c地址
失败：NULL
13. #### strstr()
  ```c
  #include <string.h>
  char *strstr(const char*haystack,const char *needle);
  ```
  - 功能
  在字符串 haystack 中查找字符串 needle 出现的位置
  - 参数
haystack：源字符串首地址
needle：匹配字符串首地址
  - 返回值
成功：返回第一次出现的 needle 地址
失败：NULL
14. atoi()
  ```c
  #include <stdlib.h>
  int atoi(const char *nptr);
  ```
  - 功能
atoi()会扫描 nptr 字符串，跳过前面的空格字符，直到遇到数字或正负号才开始做转 换，而遇到非数字或字符串结束符('\0')才结束转换，并将结果返回返回值。
  - 参数
nptr：待转换的字符串
  - 返回值
成功转换后整数

  类似的函数有：
- atof()：把一个小数形式的字符串转化为一个浮点数。
- atol()：将一个字符串转化为 long 类型
