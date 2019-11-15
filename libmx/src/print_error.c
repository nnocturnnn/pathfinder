#include "libmx.h"

void mx_printerr(const char *s) {
    if (!s) return;
    write(2, s, mx_strlen(s));
}

void print_error(enum m_eror errors, char **a, int i) {
    if (errors == INVALID_NUMBER) {
        mx_printerr("usage: ./pathfinder [filename]");
        mx_printerr("\n");
        exit(1);
    } else if (errors == NOT_EXIST) {
        mx_printerr("error: file ");
        mx_printerr(a[1]);
        mx_printerr(" doesn't exist");
        mx_printerr("\n");
        exit(1);
    } else if (errors == EMPTY) {
        mx_printerr("error: file ");
        mx_printerr(a[1]);
        mx_printerr(" is empty");
         mx_printerr("\n");
        exit(1);
    } else if (errors == LINE1_INVALID) {
            mx_printerr("error: line 1 isn't valid");
             mx_printerr("\n");
            exit(1);
    } else if (errors == LINE_INVALID) {
        mx_printerr("error: line ");
        mx_printerr(mx_itoa(i + 1));
        mx_printerr(" isn't valid");
         mx_printerr("\n");
        exit(1);
    } else if (errors == ISLANDS_INVALID)
        mx_printerr("error: invalid number of islands");
         mx_printerr("\n");
    exit(1);
}

bool mx_line_check(char *str, int line) {
    while (*str != '-')
        if (mx_isalpha(*str))
            str++;
        else
            print_error(LINE_INVALID, NULL, line);
    str++;
    while (*str != ',')
        if (mx_isalpha(*str))
            str++;
        else
            print_error(LINE_INVALID, NULL, line);
    str++;
    while (*str != '\0')
        if (mx_isdigit(*str))
            str++;
        else 
            print_error(LINE_INVALID, NULL, line);
    return true;
}

void mx_firstline_check(char *str) {
    while (*str != '\0')
        if (mx_isdigit(*str))
            str++;
        else 
            print_error(LINE1_INVALID, NULL, 1);
}
