#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../libmx/inc/libmx.h"

#define MAX_ISLANDS 100
#define MAX_BRIDGES 1000
#define MAX_PATH 100

// Структура для хранения графа
struct Island {
  char name[100];
  int num_bridges;
  int bridges[MAX_BRIDGES][2];
  int dist[MAX_ISLANDS];
  int prev[MAX_ISLANDS];  
};

// Переменные для поиска пути
static int g_cont; 
static int g_num_bridges;
static char* g_islands[MAX_ISLANDS];
static bool g_visited[MAX_ISLANDS];
static int g_path_len;
static char* g_path[MAX_PATH];

// Функция поиска ребра между вершинами
int find_bridge(char* island1, char* island2, struct Island graph[]);

// Функция шага алгоритма поиска кратчайшего пути
void step(char* start, char* end, int depth, char* path[]); 

// Функция печати найденного пути  
void print_path(char* start, char* end, char* path[]);

// Функция чтения графа из файла
void read_graph(struct Island* graph, char* filename);

// Функция алгоритма Флойда-Уоршелла
void floyd_warshall(struct Island* graph);

// Вспомогательные функции
int count_islands(char* names[], char* name);
bool visited(int num_islands, bool visited[], char* path[]);