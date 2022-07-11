#include <stdio.h>
#include <string.h>
#include <windows.h>

int main()
{
    char arr1[] = { "welcome to my world!" };
    char arr2[] = { "...................." };
    int left = 0;
    int right = strlen(arr2) - 1;

    while (left <= right)
    {
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        system("cls");
        printf("%s", arr2);
        Sleep(500);
        left++;
        right--;
    }

    return 0;
}