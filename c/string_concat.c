/**
 * Copyright 2020 Outfrost
 * This work is free software. It comes without any warranty, to the extent
 * permitted by applicable law. You can redistribute it and/or modify it under
 * the terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the LICENSE.WTFPL file for more details.
 */

#include <stdlib.h>
#include <string.h>

char* cat(const char* s1, const char* s2) {
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);
	size_t bufferLength = len1 + len2 + sizeof(char);
	
	char* result = malloc(bufferLength);
	
	char* bufferPtr = result;
	strncpy(bufferPtr, s1, len1);
	bufferPtr += len1;
	strncpy(bufferPtr, s2, len2);
	bufferPtr += len2;
	*bufferPtr = '\0';
	
	return result;
}
