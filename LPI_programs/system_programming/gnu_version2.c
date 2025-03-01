#include <stdio.h>
#include <unistd.h>

int main()
{
	char version[100];
	size_t len = sizeof(version);
	if (confstr(_CS_GNU_LIBC_VERSION, version, len)!=0)
	{
		printf("version is %s\n", version);

	}
	else
	{
		printf("Error!\n");
	}
	return 0;
}
