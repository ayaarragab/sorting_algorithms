#include "sort.h"
/**
 * selection_sort - selection sort algorithm
 * @array: array
 * @size: size
 * Return: NULL
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, index, temp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		index = i;
		for (j = i + 1; j < size ; j++)
		{
			if (array[index] > array[j])
				index = j;
		}
		if (i != index)
		{
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
		print_array(array, size);
		}
	}
}
