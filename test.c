#include <stdio.h>
#include <string.h>
int main(void)
{
    char str[25]; // variable for input (duh)
    puts("enter sentence");
    fgets(str, sizeof(str), stdin);
    printf("%s", str);
}