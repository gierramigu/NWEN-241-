/**
 * editor2.h
 */

#include <stdio.h>
#include <string.h>

int editor_count_lines(const char *edit_buffer, int sizeOfBuffer);

int editor_search_multiple(const char *edit_buffer, int sizeOfBuffer, const char *search_string, int *int_array, int sizeOfIntArray);
