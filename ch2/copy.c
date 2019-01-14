#include <stdio.h>

#define BUFSIZE 1024

int main(int argc, char **argv){
	char buf[BUFSIZE];
	size_t n;

	char *source = argv[1];
	char *dest = argv[2];
	
	FILE *sptr = fopen(source, "rb");
	FILE *dptr = fopen(dest, "wb");
	
	while((n = fread(buf, sizeof(*buf), BUFSIZE, sptr)) > 0){
		fwrite(buf, sizeof(*buf), n, dptr);
	}

	fclose(sptr);
	fclose(dptr);
}
