#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int source[101] ;
typedef struct ways{
    int city1 ;
    int city2 ;
    int cost ;
}Edge;

Edge s1[10000] ;
int index2 = 0 ;

int cmp(const void* a , const void* b )
{
    return ((Edge*)a)->cost -((Edge*)b)->cost ;
}

int find_source(int pos){
    if(source[pos]== 0 )
        return pos ;
    else
        return source[pos] = find_source( source[pos]) ;
}

int main() {
    int N ;
    scanf("%d" , &N) ;
    int num = N *(N-1) /2 ;
   // printf("num : %d" , num) ;
    int count = 0 ;
    int pos1 , pos2 , value ,status ;
    int total = 0 ;
    memset(source , 0 , 101*source[0]);
    for(int i = 0 ; i< num ; i++)
    {
        //printf("i:%d\n" , i);
        scanf("%d %d %d %d" , &pos1 , &pos2 , &value , &status) ;
        if(status == 1 )
        {
            int source1 = find_source(pos1) ;
            int source2 = find_source(pos2) ;
            if(source1 != source2){
                count++ ;
                source[source2] = source1 ;
            }
        }
        else
        {
            Edge temp ;
            temp.city1 = pos1 ;
            temp.city2 = pos2 ;
            temp.cost = value ;
            s1[index2 ++] = temp ;
        }
    }
    //printf("finish");
    qsort(s1 , index2 , sizeof(s1[0]) , cmp ) ;
    int test =0 ;
    while(count < N-1){
        int source1 = find_source(s1[test].city1) ;
        int source2 = find_source(s1[test++].city2) ;
        if(source1 !=source2){
            count ++ ;
            total += s1[test-1].cost ;
            source[source2] = source1 ; 
        }
    }
    printf("%d" , total );

 }