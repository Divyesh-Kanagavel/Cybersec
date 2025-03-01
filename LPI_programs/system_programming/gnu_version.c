#include <gnu/libc-version.h>
#include <stdio.h>
int main()
{
	const char* version = gnu_get_libc_version();
	printf("%s\n", version);
	return 0;
}
