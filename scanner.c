#include "scanner.h"
#include <stdlib.h>

struct Scanner * scannerInit(const char *path, const char *source) {
	struct Scanner *scanner = malloc(sizeof(struct Scanner *));
	scanner->path = path;
	scanner->start = source;
	scanner->current = source;
	scanner->line = 1;
	scanner->columm = 1;
	return scanner;
}

struct Token scannerGetToken(Scanner *scanner) {
	
}
