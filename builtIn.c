#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exit_status = 0;

	if (info->argv[1]) {
		exit_status = _erratoi(info->argv[1]);
		if (exit_status == -1) {
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return 1;
		}
		info->err_num = exit_status;
	}
	else {
		info->err_num = -1;
	}
	return -2;
}

int _mycd(info_t *info)
{
	char *dir, buffer[PATH_MAX];
	int chdir_ret;

	if (!getcwd(buffer, PATH_MAX))
		_puts("TODO: >>getcwd failure emsg here<<\n");

	if (!info->argv[1]) {
		dir = _getenv(info, "HOME=");
	}
	else if (_strcmp(info->argv[1], "-") == 0) {
		dir = _getenv(info, "OLDPWD=");
		if (!dir) {
			_puts(buffer);
			_putchar('\n');
			return 1;
		}
		_puts(dir), _putchar('\n');
	}
	else {
		dir = info->argv[1];
	}

	chdir_ret = chdir(dir ? dir : "/");
	if (chdir_ret == -1) {
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else {
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, PATH_MAX));
	}

	return 0;
}

int _myhelp(info_t *info)
{
	(void)info; // To suppress unused parameter warning

	_puts("help call works. Function not yet implemented \n");
	return 0;
}

