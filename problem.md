1. gets 
   - 返回值：成功：读入字符串 失败：NULL
   - 参数 char*s
   - 停止条件：遇到换行或结束
2. scanf（%s）
   - 停止条件 遇到空格
3. puts
   - 返回值：成功：非负 失败：-1
   - 参数 char*s
   - 输出：字符串，在输出完成后自动输出一个'\n'
4. printf(%s)
   - 没啥说的
5. fgets
  - 返回值：char*
  - 参数：char*s size FILE*stream
  - 特性：在结尾添上'\0' 并且会读取用户输入的\n
6. fputs
   - 并不会输出一个'\n'
7. strlen
    - 功能：求字符串的长度（不包括'\0'）
    - 返回值：size_t
    - 参数：const char*s
8. strcmp
   - 字典序比较两个字符串
   - 返回值 0 <0 >0
   - 参数 const char*s1, const char*s2
9.  strstr
    - 返回值 成功char * 即首地址 失败NULL
    - 参数 const char *s1,const char *s2
10. strcpy
    - 返回值char*
    - 参数：1.目标字符串2.源字符串
    - 特性：覆盖，结尾添加'\0'
11. strncpy
    - 前n个的复制
12. strcat
    - 结尾追加
    - 返回值：成功char*s,失败NULL
13. strncat
    - 前n个的拼接（n均对源字符串进行操作）
14. strncmp
    - 前n个的字典序比较
15. strchr
    - 返回值 字符指针
    - 参数const char*s,int target(编译器自动转换为ASCII)
16. atoi stdlib.h
    - 参数 const char* s
    - 返回值 int
    - 类似函数atof stol