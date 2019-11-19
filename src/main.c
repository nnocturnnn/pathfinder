#include "libmx.h"

//static void final_print(char **islands, int **min_dist, int **matrix);

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
    int **path = path_int(matrix, min_dist, 0, 4, size);
    //final_print(islands, min_dist, matrix);
    printf("%s\n", "s");
    for(int n = 0; n < 2; n++) {  
        for(int m = 0; m < size; m++) {
            printf("%d", path[n][m]);
        }
        printf("%s\n", "\n");
    }
    return 0;
}

// static void final_print(char **islands, int **min_dist, int **matrix) {
//     int islands_count = mx_arr_size(islands);
//     for(int count = 0; count < islands_count; count++){
//         for(int i = count + 1; i < islands_count; i++) {
//             int count_path = mx_count_short_way(matrix,min_dist,count,i,islands_count);
//             for(int q = 0; q < count_path; q++) {
//                 mx_printstr("========================================\n");
//                 mx_printstr("Path: ");
//                 mx_printstr(islands[count]);
//                 mx_printstr(" -> ");
//                 mx_printstr(islands[i]);
//                 mx_printstr("\n");
//                 mx_printstr("Route: ");
//                 mx_print_strarr(mx_char_route(matrix, min_dist, islands, count, i), " -> ");
//                 mx_printstr("Distance: ");
//                 if(mx_arr_size(mx_char_route(matrix, min_dist, islands, count, i)) == 2) {
//                     mx_printint(min_dist[count][i]);
//                 }
//                 else {
//                 mx_char_dist(matrix, min_dist, islands, count, i);
//                 mx_printstr(" = ");
//                 mx_printint(min_dist[count][i]);
//                 }
//                 mx_printstr("\n");
//                 mx_printstr("========================================\n");
//             }
//         }
//     }
// }


int mx_count_short_way(int **matrix, int **min_dist,int begin_index, int end, int islands_count) {
    int weight = min_dist[end][begin_index];
    int c =  0;

    for (int i = 0; i < islands_count; i++) {// просматриваем все вершины
        if (matrix[end][i] != 0 && matrix[end][i] != 999999999) {  // если связь есть 
            int temp = weight - matrix[end][i]; 
            if (temp == min_dist[i][begin_index]) {   
                c++;
            }
        }
    }
    end--;
    if (begin_index < end)
        c = c + (mx_count_short_way(matrix, min_dist, begin_index, end, islands_count) - 1);
    return c;
}
