#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

#define MAX_ISLANDS 100
#define MAX_BRIDGES 1000
#define MAX_PATH 100

// Объявление структуры
typedef struct {
  char name[100];
  int num_bridges;
  int bridges[MAX_BRIDGES][2];
  int dist[MAX_ISLANDS]; 
  int prev[MAX_ISLANDS];
} Graph;

// Объявление переменных  
Graph g;
char *islands[MAX_ISLANDS];
int cont;
char *road[MAX_PATH];
bool incl[MAX_ISLANDS];
int way[MAX_PATH];
int lens[MAX_ISLANDS];

int main(int argc, char *argv[]) {

  char *filename;
  
  // Проверка кол-ва аргументов
  if (argc != 2) {
    mx_printerr("usage: ./pathfinder [filename]\n");
    return 1;
  }

  filename = argv[1];

  // Чтение и проверка файла
  char *str = mx_file_to_str(filename);
  if (str == NULL) {
    mx_printerr("error: file does not exist\n");
    return 1;
  }

  if (mx_strlen(str) == 0) {
    mx_printerr("error: file is empty\n");
    return 1;
  }

  // Остальная логика программы  

  return 0;
}

// Объявление функций
void read_graph(Graph* g, char* filename); 
void floyd_warshall(Graph* g);
// etc