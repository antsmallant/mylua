#include <stdlib.h>
#include <stdio.h>

int main(void)
{    
    extern char a;    // extern variable must be declared before use
    printf("%c ", a);
    msg();
    return 0;
}