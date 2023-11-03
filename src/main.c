#include "pathfinder.h"

int main(int argc, char *argv[]) {
    find *path = (find*) malloc(sizeof(find));

    mx_error_handling(argc, argv, path);
    mx_create_matrix(path);
    mx_floyd_warshall(path);
    mx_print_result(path);
    return 0;
}
