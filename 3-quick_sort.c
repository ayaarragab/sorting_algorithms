#include "sort.h"
/**
 * partition_so - Partitions the array using Lomuto scheme.
 * @array: Array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Size of the array.
 * Return: Index of the pivot element.
 */
int partition_so(int *array, int low, int high, size_t size)
{
	int pivotValue = array[high];

	int i = low - 1, j;

	if (!array || low >= high || low < 0 || high < 0)
		return (-1);

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivotValue)
		{
			i++;
			if (i != j)
			{
				int temp = array[i];

				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		int temp = array[i + 1];

		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
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

	if (low < high)
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
