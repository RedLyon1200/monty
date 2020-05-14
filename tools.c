#include "monty.h"

/**
 * add_node_end - Add node to end of linked list
 * @st: head of the list
 * @num: string for node
 *
 * Return: address to new node
 */
void *add_node_end(stack_t **st, int num)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *temp;

	if (st == NULL || new == NULL)
		return (NULL);
	new->n = num;
	if (*st == NULL)
	{
		*st = new;
		new->prev = NULL;
		new->next = NULL;
		return (new);
	}
	temp = *st;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->prev = temp;
	new->next = NULL;
	return (0);

}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if OK or 0 if error
 */

int _strcmp(char *s1, char *s2)
{
	for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

/**
 * push - push
 * @st: stock
 * @line_number: test
 */
void push(stack_t **st, unsigned int line_number)
{
	add_node_end(st, _atoi(args[1]));
	(void)line_number;
}

/**
 * _atoi - validate if argument is a number
 * @s: char to compares with numbers
 *
 * Return: result of atoi or Err_msg
 */
int _atoi(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			continue;
		}

		if (s[i] < 48 || s[i] > 57)
		{
			fprintf(stderr, "L1: usage: push integer\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (atoi(s));
}

/**
 * pall - pall
 * @st: stock
 * @line_number: test
 */
void pall(stack_t **st, unsigned int line_number)
{
	stack_t *tmp = *st;

	while (tmp->next != NULL)
		tmp = tmp->next;

	while (tmp->prev != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
	(void)line_number;
}
