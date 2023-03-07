#include<stdio.h>
#include<stdint.h>
int arr[3] = {1,1,1};

int main(int argc, char const *argv[])
{
    uint8_t y = 0;
    for(int i = 0; i < 3; i++){
        uint8_t a = (arr[i] > 0) ? 1 : 0;
        y = y*2 + a;
    }
    printf("y = %d\n",y);
    
    return 0;
}
