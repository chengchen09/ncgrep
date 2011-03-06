/********************************
 * author: chen
 * filename: get_ncheader.c
 * date: 2011/03/04
 *******************************/
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "my_ncdump.h"
#include "get_ncheader.h"

int get_ncheader(const char *file, int write_pipe){
	
	int		original_stdout;

	original_stdout = dup(STDOUT_FILENO);

	dup2(write_pipe, STDOUT_FILENO);
	close(write_pipe);

	ncdump_header(file);
	fflush(stdout);

	dup2(original_stdout, STDOUT_FILENO);

	return 0;
}


