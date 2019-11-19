#include "libmx.h"

 void mx_char_dist(int **matrix,int **min_dist, char **islands, int begin_index, int end) {
    int islands_count = mx_arr_size(islands);
    int i = 1;
    int c = 0;
    int nedlee[islands_count];
    int *ver = path_int(matrix, min_dist, begin_index, end, islands_count);
    for (int k = i - 1; k >= 0; k--) {
        nedlee[c] = matrix[begin_index][ver[k] - 1];
        c++;
        begin_index = ver[k] -1;
    }
    for (int ci = 1; ci < c; ci++) {
        if(ci == 1) {
             mx_printint(nedlee[ci]);
        }
        else {
        mx_printstr(" + ");
        mx_printint(nedlee[ci]);
        }
    }
}
