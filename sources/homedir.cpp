#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "homedir.h"

char *home_dir;
char fallback[] = "./";

void get_home()
{
	char *home = getenv("HOME");
	if(home != NULL)
	{
		home_dir = (char *)malloc(strlen(home) + strlen("/.stransball2") + 1);
		if(home_dir != NULL)
		{
			sprintf(home_dir, "%s/.stransball2", home);
			mkdir(home_dir, 0755); // Create the directory if it doesn't exist.
		}
	}

	if (home == NULL)
	{
		home_dir = fallback;
	}
}
