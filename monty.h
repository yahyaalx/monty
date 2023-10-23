#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
int     n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void free_nodes(void);
void open_file(char *file_name);
void read_file(FILE *fd);
void call_fun(op_func func, char *op, char *val, int ln, int format);
void find_func(char *opcode, char *value, int ln, int format);
int parse_line(char *buffer, int line_number, int format);
void pop_top(stack_t **stack, unsigned int line_number);
void print_top(stack_t **stack, unsigned int line_number);
void print_stack(stack_t **stack, unsigned int line_number);
void add_to_stack(stack_t **new_node,  unsigned int ln);
void add_to_queue(stack_t **new_node,  unsigned int ln);
stack_t *create_node(int n);
void nop(stack_t **stack, unsigned int line_number);
void swap_nodes(stack_t **stack, unsigned int line_number);
void handle_error2(int code, ...);
void handle_error(int code, ...);
void add_nodes(stack_t **stack, unsigned int line_number);
#endif
