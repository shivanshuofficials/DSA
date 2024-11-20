// linearsearch by user input value
#include <stdio.h>  

int main()
{
    int n, i, item, flag = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the item to search: ");
    scanf("%d", &item);
    for (i = 0; i < n; i++)
    {
        if (arr[i] == item)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        printf("Item found at index %d", i);
    }
    else
    {
        printf("Item not found");
    }
    return 0;
}