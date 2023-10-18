#ifndef main_h
#define main_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <limits.h>

#define CD 5863276
#define EXIT 6385204799
#define ECHO 6385181892
#define SET 193505681
#define SETENV 6954013771834
#define UNSETENV 7573017818690365
#define ENV 193490734
#define TOKEN_BUFSIZE 64

extern char **envp;
int non_inter_mode(int argc, char **argv, char **envp);
unsigned long hash(const char *str);
void free_vector(char **argv);
void myprintf(const char *datas);
void process_setenv(char **envp);
int executecmd(char **argv, char **envp, char *line);
char **tokenize(char *str);
char *_getenv(char *name, char **envp);
int _atoi(char *s);
void exitshell(char **tokk, char *line);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_getpath(char *strings, char ** envp);
int process(char **command, char **envp);
int change_dir(char **command, char **envp);
int main(int argc, char **argv, char **envp);
/*ssize_t _getline(char **lineptr, FILE *stream);*/
char *_strdup(const char *str);
char *_strchr(char *s, char c);
void print_env(char **argv, char **envp);
void set_env_var(char **args);
void un_set_env_var(char **args);
int cd_dir(char **args, char **envp);
int interract(int argc, char **argv, char **envp);
int _getppid(char **argv, char *line);
ssize_t _getline(char **lineptr, size_t *n, int fd);

#endif
