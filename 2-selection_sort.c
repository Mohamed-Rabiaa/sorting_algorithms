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
 *selection_sort - sorts an array of integers in ascending order
 *using the Selection sort algorithm
 *@array: The array to sort
 *@size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, current_min_idx;


	for (i = 0; i < size - 1; i++)
	{
		current_min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[current_min_idx])
				current_min_idx = j;
		}
		if (current_min_idx != i)
		{
			int_swap(&array[i], &array[current_min_idx]);
			print_array(array, size);
		}
	}
}
