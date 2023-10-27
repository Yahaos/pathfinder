#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"
int find(char *s, char *f, int m, struct item map[m]){
    for(int i = 0;i < m; i++){
    	if((mx_compr(map[i].st,s)!=0 && mx_compr(map[i].en,f)!=0) || (mx_compr(map[i].st,f)!=0 && mx_compr(map[i].en,s)!=0)){
    	     return map[i].v;
    	}
    }
    return 0;
}
