#include "libmx.h"

static void final_print(int islands_count, char **islands, int **min_dist,int **matrix);
static char **mx_char_route(int **matrix, int **min_dist,int begin_index, char **islands, int end);
static void mx_char_dist(int **matrix, int **min_dist,int begin_index, char **islands, int end);

int main(int n, char **argv) {
    if (n != 2) 
        print_error(INVALID_NUMBER, NULL, 0);
    char *file_str = mx_file_to_str(argv[1]);
    if (file_str == NULL)
        print_error(NOT_EXIST, argv, 0);
    if (mx_strlen(file_str) == 0)
        print_error(EMPTY, argv, 0);

    char **islands_arr = mx_strsplit(file_str, '\n');
    mx_firstline_check(islands_arr[0]);
    int size = mx_atoi(islands_arr[0]);
    char **islands = read_arguments(islands_arr, size);
    int **matrix = create_matrix(islands, islands_arr, size);
    int **min_dist = crete_dist_matrix(matrix, size);
    int islands_count = mx_arr_size(islands);
     for(int a = 0; a < size; a++) {
        for(int j = 0; j < size; j++) 
            printf("%d\t\t\t", min_dist[a][j]);
        printf("\n");
    }
    printf("----------------------------\n");
    final_print(islands_count, islands, min_dist, matrix);
    mx_strdel(islands_arr);
    mx_strdel(islands);
    return 0;
}

static void final_print(int islands_count, char **islands, int **min_dist, int **matrix) {
    for(int count = 0; count < islands_count; count++){
        for(int i = count + 1; i < islands_count; i++) {
            mx_printstr("========================================\n");
            mx_printstr("Path: ");
            mx_printstr(islands[count]);
            mx_printstr(" -> ");
            mx_printstr(islands[i]);
            mx_printstr("\n");
            mx_printstr("Route: ");
            mx_print_strarr(mx_char_route(matrix, min_dist, count, islands, i), " -> ");
            mx_printstr("Distance: ");
            if(mx_arr_size(mx_char_route(matrix, min_dist, count, islands, i)) == 2) {
                mx_printint(min_dist[count][i]);
            }
            else {
            mx_char_dist(matrix, min_dist, count, islands, i);
            mx_printstr(" = ");
            mx_printint(min_dist[count][i]);
            }
            mx_printstr("\n");
            mx_printstr("========================================\n");
        }
    }
}


static void mx_char_dist(int **matrix, int **min_dist,int begin_index, char **islands, int end) {
    int islands_count = mx_arr_size(islands);
    int ver[islands_count];
    ver[0] = end + 1;
    int k = 1;
    int weight = min_dist[end][begin_index];
    int c =  0;
        while (end != begin_index) { // пока не дошли до начальной вершины 
            for (int i = 0; i<islands_count; i++) {// просматриваем все вершины
                if (matrix[end][i] != 0 && matrix[end][i] != 999999999) {  // если связь есть 
                    int temp = weight - matrix[end][i]; // определяем вес пути из предыдущей вершины
                    if (temp == min_dist[i][begin_index]) // если вес совпал с рассчитанным
                    {                 // значит из этой вершины и был переход
                        weight = temp; // сохраняем новый вес
                        end = i;       // сохраняем предыдущую вершину
                        ver[k] = i + 1; // и записываем ее в массив
                        k++;
                    }
                }
             }
        }
    int nedlee[k];
    for (int i = k - 1; i >= 0; i--) {
        nedlee[c] = matrix[begin_index][ver[i] - 1];
        c++;
        begin_index = ver[i] -1;
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
    //free(nedlee);
}


static char **mx_char_route(int **matrix, int **min_dist,int begin_index, char **islands, int end) {
    int islands_count = mx_arr_size(islands);
    int ver[islands_count];
    ver[0] = end + 1;
    int k = 1;
    int weight = min_dist[end][begin_index];
    int c =  0;
        while (end != begin_index) { // пока не дошли до начальной вершины 
            for (int i = 0; i<islands_count; i++) {// просматриваем все вершины
                if (matrix[end][i] != 0 && matrix[end][i] != 999999999) {  // если связь есть 
                    int temp = weight - matrix[end][i]; // определяем вес пути из предыдущей вершины
                    if (temp == min_dist[i][begin_index]) // если вес совпал с рассчитанным
                    {                 // значит из этой вершины и был переход
                        weight = temp; // сохраняем новый вес
                        end = i;       
                        ver[k] = i + 1; 
                        k++;
                    }
                }
             }
        }
    char **nedlee = malloc(sizeof(char *) * (islands_count + 1));
    for (int i = k - 1; i >= 0; i--) {
        nedlee[c] = mx_strdup(islands[ver[i] - 1]);
        c++;
    }
    return nedlee;
}
