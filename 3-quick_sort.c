#include "sort.h"
/**
 *int_swap - Swaps the values of 2 integers
 *@xp: The pointer of the first integer
 *@yp: The pointer of the second integer
 */
void int_swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 *partition_arr - Partitions an array around a pivot
 *@arr: The array to partition
 *@start: The start of the array
 *@end: The end of the array
 *
 *Return: the index of the pivot
 */
int partition_arr(int *arr, int start, int end, size_t size)
{
	int i, j, pivot;

	pivot = arr[end];
	i = start - 1;

	for (j = start; j <= end; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			int_swap(&arr[i], &arr[j]);
			if (arr[i] != arr[j])
				print_array(arr, size);
		}
	}
	int_swap(&arr[i + 1], &arr[end]);
	print_array(arr, size);
	return (i + 1);
}

/**
 *quick_sort_arr - sorts an array of integers in ascending order using
 *the Quick sort algorithm
 *@arr: The array to sort
 *@start: The start of the array
 *@end: The end of the array
 */
void quick_sort_arr(int *arr, int start, int end, size_t size)
{
	int pi;

	if (start < end)
	{
		pi = partition_arr(arr, start, end, size);
		quick_sort_arr(arr, start, pi - 1, size);
		quick_sort_arr(arr, pi + 1, end, size);
	}
}

/**
 *quick_sort - sorts an array of integers in ascending order using
 *the Quick sort algorithm
 *@array: The array to sort
 *@size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_arr(array, 0, size - 1, size);
}
