#include <stdio.h>
int main()
{
    int arr[5], i;
    printf("Enter 5 numbers:\n");
    for(i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    if(arr[0] == arr[4])
        printf("First and last numbers are same\n");
    else
        printf("First and last numbers are not same");
    return 0;
}
