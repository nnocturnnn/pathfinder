#include "libmx.h"

void mx_checked(char *str, char *argv) {
	if (str == NULL)
        print_error(NOT_EXIST, &argv, 0);
    if (mx_strlen(str) == 0)
        print_error(EMPTY, &argv, 0);
}
