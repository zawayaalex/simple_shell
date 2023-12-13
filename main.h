#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;
/*prototype takeinputs.c*/
char *take_inputs(void);

/*prototype word_split.c*/
char **word_split(char *inputs);

/*prtotypes string.c*/
char *_strdup(const char *str_input);
int _strcmp(char *str1, char *str2);
int _strlen(char *c);
char *_strcat(char *direct, char *inbound);
char *_strcpy(char *direct, char *inbound);

/*prototype aidkit.c*/
void freecharstar(char **array);

/*exec proto*/
int _execute(char **commands, char **argv, int ind);

/*get env proto*/
char *_getenv(char *var);

/*path_done.c proto*/
char *_getpath(char *commands);

/*error print proto*/
void output_error(char *thing, char *cmd, int ind);

/*int to as proto*/
char *_intoas(int n);

/*reverse string proto*/
void rev_str(char *str, int len);

/*inside_deal.c proto*/
int is_inside(char *commands);
void inside_deal(char **commands, char **argv, int *out_log, int inds);
void exit_shell(char **commands, char **argv, int *out_log, int inds);
void print_env(char **commands, int *out_log);

/*is positive & as to int*/
int is_positive(char *str);
int _astoin(char *str);


#endif
