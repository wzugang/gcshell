#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>


#define SUCCESS 0
#define FAILURE -1
#define TRUE 1
#define FALSE 0
#define MAX_STRING 250
#define fatal()                                          \
        do { fprintf (stderr, "Error: %s: %d: %s: %s\n", \
         __FILE__, __LINE__,                             \
        __PRETTY_FUNCTION__, strerror (errno));          \
        exit (EXIT_FAILURE);} while (0)

#define STDOUT_DESC 1
#define STDIN_DESC 0


struct JOB {
    struct JOB *next_job;
    char **arg_strings;
    int num_args;
    char IS_FOREGROUND_FLAG;
    char IS_RUNNING_FLAG;
};

int string_to_job(char *, struct JOB **);
int is_running(struct JOB *);
int is_foreground(struct JOB *);
int add_job(struct JOB **, struct JOB *);
void delete_jobs(struct JOB **);
void print_jobs(struct JOB *);
void process_job(struct JOB *);
void execute(char **, int);
int check_builtin(struct JOB *);
void help(void);





#endif
