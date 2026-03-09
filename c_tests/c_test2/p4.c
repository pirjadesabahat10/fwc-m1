#include <stdio.h>
int main()
{
    char str[100];
    int n, i = 0;
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Enter number of characters to remove: ");
    scanf("%d", &n);
    while(str[n] != '\0')
    {
        str[i] = str[n];
        i++;
        n++;
    }
    str[i] = '\0';
    printf("Characters are removed and result is: %s\n", str);
    return 0;
}
