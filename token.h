#pragma once

#include "kind.h"

struct Token {
	const enum Kind kind;
	const char *start;
	const unsigned short length;
	const unsigned short line;
};
