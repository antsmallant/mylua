#include <stdlib.h>
#include <stdio.h>



int main(void)
{    
    extern char a;    // extern variable must be declared before use
    printf("%c ", a);

    //阻止针对 msg() 函数没有在 test_extern 的头文件声明的 warning 报错
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"
    
    msg();

#pragma GCC diagnostic pop

    return 0;
}

