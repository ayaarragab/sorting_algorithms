#include "sort.h"

/**
 * swap - swap function
 * @a: pointer to a variable
 * @b: pointer to b variable
 * Return: NULL
*/
void swap(int *a, int *b)
{
	int temp = *a;

	if (!a || !b)
		return;
	*a = *b;
	*b = temp;
}
/**
 * partition_so - the partition function
 * @array: array
 * @low: low value
 * @high: high value
 * @size: size
 * Return: index of the pivot
*/
int partition_so(int *array, int low, int high, size_t size)
{

	int pivotValue, i, j;

	if (!array || low >= high || low < 0 || high < 0)
		return (-1);
	pivotValue = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivotValue)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i);
}

/**
 * recursion - quick sort recursion
 * @array: array
 * @low: low
 * @high: high
 * @size: size
 * Return: NULL
*/
void recursion(int *array, int low, int high, size_t size)
{
	if (!array)
		return;

	if ((high - low) > 0)
	{
		int pivot_idx = partition_so(array, low, high, size);

		recursion(array, low, pivot_idx - 1, size);
		recursion(array, pivot_idx + 1, high, size);
	}
}
/**
 * quick_sort - quick sort algorithm
 * @array: array
 * @size: size
 * Return: Null
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	recursion(array, 0, size - 1, size);
}
