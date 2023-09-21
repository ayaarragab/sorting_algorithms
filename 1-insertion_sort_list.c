#include "sort.h"
/**
 * insertion_sort_list - insertion sort for a dbl list
 * @list: ptr to ptr of the list
 * Return: nothing
*/
void insertion_sort_list(listint_t **list)
{
    int value;
    listint_t *current, *NodeA, *NodeB;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current)
    {
        value = current->n;

        while (current->prev && current->prev->n > value)
        {
            NodeA = current;
            NodeB = current->prev;

            NodeA->prev = NodeB->prev;

            if (NodeB->prev)
                NodeB->prev->next = NodeA;
            else
                *list = NodeA;

            NodeB->next = NodeA->next;
            NodeA->next = NodeB;

            if (NodeB->next)
                NodeB->next->prev = NodeB;
        }

        current = current->next;
    }
}
