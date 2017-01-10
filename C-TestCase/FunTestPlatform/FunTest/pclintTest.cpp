#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(void)
{
	char  *name = NULL;
	name = (char*)malloc(20);
	
	if (name != NULL)
	{
		memcpy(name, "Tongji", 20);
		printf("%s", name);
	}
		
	free(name);
	*name = NULL;
	return 0;
}
