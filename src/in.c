#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"

#define MAX_LEN 100

bool in(int m_len, char **arr, int s_len, char *sub_arr[s_len]) {

  int h = 0;
  
  for (int i = 0; i < m_len; i++) {

    if (mx_strcmp(arr[i], " !") == 0 && h == s_len) {
      return true;
    }

    if (mx_strcmp(arr[i], sub_arr[h]) != 0) {
      h++; 
    } else {
      h = 0;
    }

  }

  return false;

}