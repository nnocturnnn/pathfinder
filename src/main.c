#include "libmx.h"

static int **mx_int_route(tool *data, int num, int from, int to);
static tool *inicialize(int s, int **m, int **d, char **t);
static void one_print(tool *d, int *path, int i, int j);
static void final_print(tool *d);

int main(int n, char **argv) {
    char *file_str;
    char **islands_arr;
    int size;
    char **islands; 
    int **matrix;
    int **min_dist;

     if (n != 2) 
        print_error(INVALID_NUMBER, NULL, 0);
    
    file_str = mx_file_to_str(argv[1]);
    mx_checked(file_str, argv[1]);
    islands_arr = mx_strsplit(file_str, '\n');
    mx_firstline_check(islands_arr[0]);
    size = mx_atoi(islands_arr[0]);
    islands = read_arguments(islands_arr, size);
    matrix = create_matrix(islands, islands_arr, size);
    min_dist = crete_dist_matrix(matrix, size);
    tool *d = inicialize(size, matrix, min_dist, islands);

    final_print(d);
    free(d);
    return 0;
}

static void final_print(tool *d) {
    int num;
    int **path;
    
    for (int i = 0; i < d->size; i++){
        for (int j = i + 1; j < d->size; j++) {
            num = mx_count_short_ways(d, i, j);
            path = mx_int_route(d, num, i, j);
            for (int c = 0; c < num; c++) {
                d->file = mx_file_to_print(d, path, c);
                one_print(d, path[c], i, j);
                mx_del_strarr(&d->file);
            }
        }
    }       
}


static void one_print(tool *d, int *path, int i, int j) {
    mx_printstr("========================");
    mx_printstr("================\nPath: ");
    mx_printstr(d->top[i]);
    mx_printstr(" -> ");
    mx_printstr(d->top[j]);
    mx_printstr("\nRoute: ");
    mx_print_strarr(d->file, " -> ");
    mx_printstr("Distance: ");
    if(mx_arr_size(d->file) == 2)
        mx_printint(d->dist[i][j]);
    else 
        mx_print_distance(d, path, i, j);
    mx_printstr("\n====================");
    mx_printstr("====================\n");
}

static tool *inicialize(int s, int **m, int **d, char **t) {
    tool *data= malloc(sizeof(tool));
    data->size = s;
    data->matrix = m;
    data->dist = d;
    data->top = t;
    return data;
}

static int **mx_int_route(tool *d, int num, int from, int to) {
    int **paths = malloc(num * sizeof(int *));
    int k = 1;

    for (int a = 0; a < num; a++) {
        paths[a] = malloc((d->size + 1) * sizeof(int));
        for (int k = 0; k < d->size + 1; k++)
            paths[a][k] = -1;
    }
    for (int a = 0; a < num; a++) {
        int end = to;
        paths[a][k - 1] = to;
        while(end != from) {
            paths[a][k] = mx_previos_top(d, from, end);
            if (a > 0 && paths[a][k] == paths[a - 1][k]) {
                int tmp = mx_next_top(d, from, end, paths[a][k] + 1);
                if (tmp != -2)
                    paths[a][k] = tmp;
            }
            end = paths[a][k];
            k++;
        } 
        k = 1;
    }
    return paths;
}
