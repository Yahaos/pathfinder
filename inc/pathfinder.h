#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "../libmx/inc/libmx.h"

#define INT_MAX 2147483647

typedef struct {
    int number_of_islands;
    int number_of_words;
    int **result_arr;
    int **initial_arr;
    char *string;
    char **islands;
    char **unique_island;
}   find;

typedef struct {
    int distance;
    int *route;
}   output;

int main(int argc, char *argv[]);
void mx_error_handling(int argc, char *argv[], find *path);

void mx_handle_arg_count_error(int argc);
void mx_check_file_exist_error(char *argv[], find *path);
void mx_handle_empty_file_error(char *argv[], find *path);
void mx_print_line_error(int line);
void mx_handle_first_line_error(find *path);
void mx_input_line_validation(find *path);
void mx_count_unique_islands(find *path);
void mx_duplicate_bridges_error(find *path);
void mx_sum_of_bridges_lengths_error(find *path);
void mx_input_islands_validation(find *path);
void mx_create_matrix(find *path);
void mx_print_result(find *path);
void mx_floyd_warshall(find *path);
void mx_clean_memory(find *path);

#endif
