#include "libmx.h"

int **path_int(int **matrix, int **min_dist, int begin_index, int end, int size) {
    int count = mx_count_short_way(matrix,min_dist, begin_index, end, size);
    int **ver = malloc(sizeof(int *) * count);
    int flag = 0;

    for (int i = 0; i < size; i++)
        ver[i] = malloc(sizeof(int) * size + 1);


    for (int y = 0; y < count; y++) {
        ver[y][0] = end + 1;
        int k = 1;

        int weight = min_dist[end][begin_index];
            while (end != begin_index) { // пока не дошли до начальной вершины 
                flag = 0;
                for (int i = 0; i < size; i++) {// просматриваем все вершины
                    if (matrix[end][i] != 0 && matrix[end][i] != 999999999) {  // если связь есть 
                        int temp = weight - matrix[end][i]; // определяем вес пути из предыдущей вершины
                        if (y > 0) { // если второй кратчайшый путь
                            for (int a = i + 1; a < size && flag != 1; a++) {
                                if (matrix[end][a] != 0 && matrix[end][a] != 999999999) {
                                    int temp2 = weight - matrix[end][a];
                                    if (temp2 == min_dist[a][begin_index] && flag == 0) {
                                        temp = temp2;
                                        i = a;
                                        flag = 1;
                                    }
                                }
                            }
                        }

                        if (temp == min_dist[i][begin_index]) // если вес совпал с рассчитанным
                        {                 // значит из этой вершины и был переход
                            weight = temp; // сохраняем новый вес
                            end = i;       
                            ver[y][k] = i + 1; 
                            k++;
                        }
                    }
                 }
            }
           // ver[y][k] = -1;
    }
    return ver;
}

