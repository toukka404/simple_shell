#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>

/*prototypes*/

char **path_direc(char **env);
void exe_command(char **commands, char *names, char **env, int cycle);
void error_messages(char *names, int cycle, char **commands);
void prints_environ(char **env);
int strings_compare(char *string1, char *string2);
unsigned int strings_length(char *string);
char *strings_copy(char *desti, char *sources);
char *string_conc(char *desti, char *sources);
int string_int(char *string);
int main(int num_args, char **arry_args, char **env);
void signal_handler(int prompt_handle);
void prompt(void);
void exits_shell(char **commands);
void handles_EOF(char *buff_strings);
void free_memry_exit(char **cmds);
void memry_freed(char **cmds);
int changes_directories(const char *paths);
void child_process(char **cmds, char *names, char **env, int cycle);
char **tokenizing(char *buffers, const char *strings);

#endif