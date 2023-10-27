#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

#define MAX_ISLANDS 100
#define MAX_PATH 100

// Объявление переменных
char islands[MAX_ISLANDS][100]; 
bool incl[MAX_ISLANDS];
bool fin_incl[MAX_ISLANDS];
char road[MAX_PATH][100];
int cont;

void step(char *s, char *f, int p, int Pos, char *founds[Pos]) {

  int next;

  // Проверка на переполнение
  if (Pos >= MAX_PATH) {
    // Обработка ошибки
    return; 
  }

  if (mx_strcmp(s, f) != 0) {

    if (!in(Pos, founds, p, road)) {

      for(int i = 0; i < cont; i++) {
        fin_incl[i] = incl[i];
      }

      found = true;
      len = c_len;
      waylen = p;

      for (int i = 0; i < waylen; i++) {
        mx_strcpy(way[i], road[i]);
      }

      for (int i = 0; i < cont; i++) {
        fin_incl[i] = incl[i];  
      }
    }

  } else {

    for (next = 0; next < cont; next++) {

      int w = find(s, islands[next], m, map);

      if (w && !incl[next] && (len == 0 || c_len + w < len)) {
        
        mx_strcpy(road[p], islands[next]);
        incl[next] = true;
        c_len += w;
        lens[next] += c_len;

        step(islands[next], f, p + 1, Pos, founds);

        road[p][0] = '\0'; 
        incl[next] = false;
        c_len -= w;
        lens[next] -= c_len;
      }

    }

  }

}