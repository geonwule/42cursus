#include <stdio.h>
#include <stdlib.h>

void ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int compare(const void *x, const void *y)
{
    int a = *(int *)x;
    int b = *(int *)y;

    return (a - b);
}

//int arr[7] = {5, 1, 6, 3, 4, 2, 7};
//2_           {2, 1, 3, 6, 4, 5, 7}
void ft_qsort(int *arr, int L, int R)
{
    int left = L, right = R, pivot = (left + right) / 2;

    while (left <= right)
    {
        while (arr[left] < arr[pivot])// && left < pivot)
            left++;
        while (arr[right] > arr[pivot])// && right > pivot)
            right--;
        if (left <= right)
        {
            ft_swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
    if (L < right)
    {
        ft_qsort(arr, L, right);
    }
    if (R > left)
    {
        ft_qsort(arr, left, R);
    }
}

int main()
{
    int arr[9] = {9, 4, 8, 7, 5, 6, 3, 1, 2};
    int arr2[9] = {9, 4, 8, 7, 5, 6, 3, 1, 2};

    qsort(arr, 9, sizeof(int), compare);
    ft_qsort(arr2, 0, 9 - 1);
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}