#include "../inc/pathfinder.h"
#include "../libmx/inc/libmx.h"
int count_str(char *arr[],int size,char *s){
    int t=0;
    for(int i=0;i<size;i++){
    	if(mx_compr(arr[i],s)){
    	    t++;
    	}
    }
    return t;
}
