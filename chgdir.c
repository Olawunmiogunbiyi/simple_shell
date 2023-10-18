#include "main.h"
/**
 * cd_dir -A function to change directory
 * @argv:  directory argument
 * @envp: Environment variable
 *
 * Return: retunr 0
 */
int cd_dir(char **args, char **envp){
    char *new_dir;

    char cwd[PATH_MAX];

    if (args[1] == NULL || strcmp(args[1], "~") == 0) {
        /No directory provided or "cd ~" means change to home directory/
        new_dir = _getenv("HOME", envp);
    } else if (strcmp(args[1], "-") == 0) {
        /* Handle "cd -" to change to the previous directory*/
        new_dir = _getenv("OLDPWD", envp);
    } else {
        /Change to the specified directory/
        new_dir = args[1];
    }

    /* Get the current working directory*/
    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        perror("getcwd");
        return 1;
    }

    /Store the current working directory in OLDPWD/
    if (setenv("OLDPWD", cwd, 1) != 0) {
        perror("setenv");
        return 1;
    }

    /Change to the new directory/
    if (chdir(new_dir) != 0) {
        perror("chdir");
        return 1;
    }

    /* Update the PWD environment variable*/
    if (setenv("PWD", new_dir, 1) != 0) {
        perror("setenv");
        return 1;
    }
	free_vector(args);
    return (0);
}
