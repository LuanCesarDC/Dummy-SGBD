#ifndef _SGBD_H_
#define _SGBD_H_

typedef enum {
	META_COMMAND_SUCCESS,
	META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum {
	PREPARE_SUCCESS,
	PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef enum {
	STATEMENT_INSERT,
	STATEMENT_SELECT
} StatementType;

typedef struct {
	char * buffer;
	size_t buffer_length;
	ssize_t input_length;
} InputBuffer;

typedef struct {
	StatementType type;
} Statement;

InputBuffer * new_input_buffer();
void read_input(InputBuffer * input_buffer);
void print_prompt();
void close_input_buffer(InputBuffer * input_buffer);
MetaCommandResult do_meta_command(InputBuffer * input_buffer);
PrepareResult prepare_statement(InputBuffer * input_buffer, Statement * statement);
void execute_statement(Statement * statement);


#endif //_SGBD_H_
