#pragma once

#include "token.h"

struct Scanner {
	const char *path;
	const char *start;
	const char *current;
	unsigned short line;
	unsigned short column;
};

struct Scanner * scannerInit(const char *path, const char *source);
struct Token scannerGetToken(Scanner *scanner);
