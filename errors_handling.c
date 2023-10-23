#include "monty.h"

/**
 * handle_error - print suitable error messages deppending on their error code
 * @code: the error code
 */
void handle_error(int code, ...)
{
	va_list arg;
	char *line;
	int line_nu;

	va_start(arg, code);
	switch (code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			line_nu = va_arg(arg, int);
			line = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_nu, line);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * handle_error2 - print suitable error messages deppending on their error code
 * @code: error code
 */
void handle_error2(int code, ...)
{
	va_list arg;
	char *line;
	int line_nu;

	va_start(arg, code);
	switch (code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't open an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			line_nu = va_arg(arg, unsigned int);
			line = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_nu, line);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
