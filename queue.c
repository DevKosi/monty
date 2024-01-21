#include "monty.h"

/**
 * f_queue - Sets the queue mode for stack operations.
 * @head: Stack head (unused)
 * @counter: Line number (unused)
 * Return: No return
 */
void f_queue(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    bus.lifi = 1;
}

/**
 * addqueue - Adds a node to the tail of the stack (queue).
 * @head: Pointer to the head of the stack
 * @n: New value to be added
 * Return: No return
 */
void addqueue(stack_t **head, int n)
{
    stack_t *new_node, *current;

    current = *head;
    new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->next = NULL;

    if (current)
    {
        while (current->next)
            current = current->next;
    }

    if (!current)
    {
        *head = new_node;
        new_node->prev = NULL;
    }
    else
    {
        current->next = new_node;
        new_node->prev = current;
    }
}

