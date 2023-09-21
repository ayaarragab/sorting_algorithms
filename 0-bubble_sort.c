#include "sort.h"
/** 
 * swap - swap function
 * @a: pointer to address of a
 * @b: pointer to address of b
 * Return: nothing
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * bubble_sort - bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: nothing
*/
void bubble_sort(int *array, size_t size)
{
	size_t swapped, i, j;

	if (array == NULL || size == 0)
		return
	for (i = 0; i < size; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
	
}
