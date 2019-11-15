#include "libmx.h"

void first_word(char *str, char **result, int *num) {
    int end = mx_get_char_index(str, '-');
    char *res = mx_strndup(str, end);
    int index = 0;

    while (index < *num && result[index] != NULL) {
        if (mx_strcmp(result[index], res) == 0) {
            free(res);
            res = NULL;
            break;
        }
        index++;
    }    
    if (res != NULL) {
        result[*num] = res;
        (*num)++;
    }
}

void second_word(char *str, char **result, int *num) {
    int start = mx_get_char_index(str, '-');
    int end = mx_get_char_index(str, ',');
    char *res = mx_strndup(&str[start + 1], end - start - 1);
    int index = 0;

    while (index < *num && result[index] != NULL) {
        if (mx_strcmp(result[index], res) == 0) {
            free(res);
            res = NULL;
            break;
        }
        index++;
    }

    if (res != NULL) {
        result[*num] = res;
        (*num)++;
    }
}

char **read_arguments(char **str, int islands) {            // Read islands from string_arr.
    if (islands < 2)
        print_error(ISLANDS_INVALID, NULL, 0);
    char **result = malloc((islands + 1)*sizeof(char*));
    result[islands] = NULL;
    int line = 0;
    int num = 0;

    for (; line < islands; line++)
        result[line] = "";
        
    for (line = 1; str[line] != NULL; line++) {
        if (mx_line_check(str[line], line)) {
            if (num > islands)
                print_error(ISLANDS_INVALID, NULL, 0);
            first_word(str[line], result, &num);
            if (num > islands)
                print_error(ISLANDS_INVALID, NULL, 0);
            second_word(str[line], result, &num);

        }
    }
    if (num != islands)
        print_error(ISLANDS_INVALID, NULL, 0);
    return result;
}
