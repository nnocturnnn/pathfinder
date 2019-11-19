#include "libmx.h"

char **mx_char_route(int **matrix,int **min_dist, char **islands, int begin_index, int end) {
	int islands_count = mx_arr_size(islands);
	int i = 0;
    int c = 0;
	int *ver = path_int(matrix, min_dist, begin_index, end, islands_count);
    char **nedlee = malloc(sizeof(char *) * (islands_count + 1));
    for(; ver[i] != 0; i++)
    for (int k = i - 1; k >= 0; k--) {
        nedlee[c] = mx_strdup(islands[ver[k] - 1]);
        c++;
    }
    return nedlee;
}
