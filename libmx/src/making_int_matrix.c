#include "libmx.h"

int **create_zero_matrix(int islands) {
     int INF = 999999999;
    int **res = (int**) malloc(sizeof(int*) * islands);
    for(int i = 0; i < islands; i++) {
        res[i] = (int*) malloc(sizeof(int) * islands);
        for(int j = 0; j < islands; j++) {
            res[i][j] =  INF;
        }
    }
    for(int i = 0; i < islands; i++)
        res[i][i] = 0;
    return res;
}

static int get_num_str(char *island_tmp) {
    int ind = mx_get_char_index(island_tmp, ',') + 1;
    return mx_atoi(&island_tmp[ind]);
}

int **create_matrix(char **islands, char **islands_tmp, int islands_int) {
    int i = 0;
    int j = 0;
    int **matrix = create_zero_matrix(islands_int);

    for (int line = 1; islands_tmp[line] != NULL; line++) {
        i = 0;
        j = 0;
        while (i < islands_int) {
            if (mx_memcmp(islands_tmp[line], islands[i], mx_strlen(islands[i])) == 0)
                break;
            i++;
        }
        char *word2 = mx_memchr(islands_tmp[line], '-', mx_strlen(islands_tmp[line]));
        while (j < islands_int) {
            if (mx_memcmp(word2 + 1, islands[j], mx_strlen(islands[j])) == 0)
                break;
            j++;
        }
        matrix[i][j] = get_num_str(islands_tmp[line]);
        matrix[j][i] = matrix[i][j];
    }
    return matrix;
}

int **crete_dist_matrix(int **matrix, int size) {
    int i;
    int j;  //Floyd Warshall Algorithm
    int k;
    int INF = 999999999; //infinity
    int **dist = create_zero_matrix(size);
    
    for (i = 0; i < size; i++) 
        for (j = 0; j < size; j++)
            dist[i][j] = matrix[i][j];
            
    for (k = 0; k < size; k++) { 
        for (i = 0; i < size; i++) { 
            for (j = 0; j < size; j++) {
                if (dist[i][k] < INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        } 
    }
    return dist;
}
