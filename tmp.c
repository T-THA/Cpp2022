#include<stdio.h>
int main(){
    int x = 1, y = 2, z = 3;
    if( x < y < z) printf("x<y<z\n");
    if( x < z < y) printf("x<z<y\n");
    if( z < x < y) printf("z<x<y\n");
    if( z < y < x) printf("z<y<x\n");
    if( y < x < z) printf("y<x<z\n");
    if( y < z < x) printf("y<z<x\n");
    printf("%d %d",x < y, y < x);
}