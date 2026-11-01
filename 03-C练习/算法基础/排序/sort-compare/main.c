#include <stdio.h>

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void copy_array(int source[], int target[], int n)
{
    for (int i = 0; i < n; i++)
    {
        target[i] = source[i];
    }
}

void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap_int(&a[j], &a[j + 1]);
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
    }
}

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }

        if (min_index != i)
        {
            swap_int(&a[i], &a[min_index]);
        }
    }
}

void insertion_sort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }
}

int main(void)
{
    int original[] = {5, 2, 4, 1, 3};
    int n = sizeof(original) / sizeof(original[0]);
    int bubble[n];
    int selection[n];
    int insertion[n];

    copy_array(original, bubble, n);
    copy_array(original, selection, n);
    copy_array(original, insertion, n);

    printf("原始数组：");
    print_array(original, n);

    bubble_sort(bubble, n);
    printf("冒泡排序：");
    print_array(bubble, n);

    selection_sort(selection, n);
    printf("选择排序：");
    print_array(selection, n);

    insertion_sort(insertion, n);
    printf("插入排序：");
    print_array(insertion, n);

    return 0;
}
