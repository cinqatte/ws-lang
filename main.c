#include "scanner.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * readFile(const char *path);

int main(int argc, char * argv[]) {
	if (argc == 2) {
		fprintf(stderr, "usage: ws <script>\n");
		return 1;
	}
	
	char * source = readFile(argv[1]);
	
	if (source == NULL) {
		return 1;
	}
	
	struct Scanner * scanner = scannerInit(argv[1], source);
	
	free(source);
	free(scanner);
	return 0;
}

char * readFile(const char *path) {
	FILE *file = fopen(path, "rb");
	
	if (file == NULL) {
		fprintf(stderr, "ws error reading '%s'\n%s\n", path, strerror(errno));
		return NULL;
	}
	
	if (fseek(file, 0L, SEEK_END) != 0) {
		fprintf(stderr, "ws error reading '%s'\n%s\n", path, strerror(errno));
		fclose(file);
		return NULL;
	}
	
	long file_size = ftell(file);
	
	if (file_size == -1) {
			fprintf(stderr, "ws error reading '%s'\n%s\n", path, strerror(errno));
			fclose(file);
			return NULL;
		}
	
	if (fseek(file, 0L, SEEK_SET) != 0) {
		fprintf(stderr, "ws error reading '%s'\n%s\n", path, strerror(errno));
		fclose(file);
		return NULL;
	}
	
	char *buffer = malloc(file_size + 1);
	
	if (buffer == NULL) {
		fprintf(stderr, "ws error reading '%s'\nMemory Allocation Failed\n", path);
		fclose(file);
		return NULL;
	}
	
	if ((size_t) file_size != fread(buffer, file_size, 1L, file)) {
		fprintf(stderr, "ws error reading '%s'\n%s\n", path, strerror(errno));
		fclose(file);
		free(buffer);
		buffer = NULL;
		return NULL;
	}
	
	buffer[file_size] = '\0';
	fclose(file);
	return buffer;
}
