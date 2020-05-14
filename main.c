#include "monty.h"
char *args[1024];
int main(int ac, char **av)
{
	char file_content[1024];
	FILE *file;
	int line = 0;
	stack_t *st = NULL;

	st = malloc(sizeof(stack_t));
	if (!st)
	{
		return (-1);
	}

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_ERROR);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		printf("ERROR: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	/* Indicate the end of the file give 0 if didn't find the end of the file */
	while (!feof(file))
	{
		/* the 1024 is the number the file is goint to read */
		if (fgets(file_content, 1024, file) != NULL)
			opt_cmp(&st, line, file_content);
	}
	fclose(file);
	return (0);
}

/**
 *opt_cmp - asd
 *@st: asd
 *@line: asd
 *@opcode: asd
 *Return: 0
 */
void opt_cmp(stack_t **st, unsigned int line, char *opcode)
{
	int opi = 0, i = 0;
	char *tok = NULL;

	tok = strtok(opcode, " \n");

	instruction_t opt[] = {{"push", push}, {"pall", pall}, {"NULL", NULL}};

	while (tok)
	{
		args[i] = tok;
		tok = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;

	opi = 0;
	while (opt[opi].opcode)
	{
		if (_strcmp(args[0], opt[opi].opcode) == 1 && opt[opi].opcode && args[0])
		{
			opt[opi].f(st, line);
			return;
		}
		opi++;
	}
	printf("L%u: Unknown instruction %s\n", line, opcode);
	exit(EXIT_FAILURE);
}
