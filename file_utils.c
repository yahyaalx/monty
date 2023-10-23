#include "monty.h"
#include <stdio.h>

/**
 * open_file - open the given file file
 * @file_name: file name
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		handle_error(2, file_name);

	read_file(fd);
	fclose(fd);
}

/**
 * read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_file(FILE *fd)
{
	int line_number = 1;
	int format = 0;
	char *buffer = NULL;
	size_t len = 0;

	while (1)
	{
		char temp[256];

		if (fgets(temp, sizeof(temp), fd) == NULL)
		{
			break;
		}

		len = strlen(temp);
		buffer = (char *)realloc(buffer, len + 1);
		if (buffer == NULL)
		{
			exit(1);
		}

		strcpy(buffer, temp);

		format = parse_line(buffer, line_number, format);
		line_number++;
	}

	free(buffer);
}
/**
 * parse_line - tokenize the line
 * @buffer: line
 * @line_number: line number
 * @format:  0 nodes are in stack 1 nodes ar in quee
 * Return: 0 stack otherwise 1 if queue
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		handle_error(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, line_number, format);
	return (format);
}

/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int i = 0;
	int flag = 1;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	while (func_list[i].opcode != NULL)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_fun(func_list[i].f, opcode, value, ln, format);
			flag = 0;
			break;
		}
		i++;
	}

	if (flag == 1)
		handle_error(3, ln, opcode);
}
/**
 * call_fun - call the wnated function
 * @func: pointer to the function
 * @op: opcode
 * @val: number value
 * @ln: line number of instruction
 * @format: on 0 node enterde as stack 1 node as queue
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			handle_error(5, ln);
		i = 0;
		while (val[i] != '\0')
		{
			if (!isdigit(val[i]))
			{
				handle_error(5, ln);
				break;
			}
			i++;
		}

		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
