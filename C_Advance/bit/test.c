#include<stdio.h>

int main(int argc, char const *argv[])
{
    int a = 255;
    int b = 6;
    unsigned char c = (char)a << 4;
    printf("%d\n",c);
    return 0;
}
