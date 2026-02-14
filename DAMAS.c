#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 8

char tablero[SIZE][SIZE];

void inicializar(char *t){
    int i,j;

    for(i=0;i<SIZE;i++)
        for(j=0;j<SIZE;j++)
            *(t+i*SIZE+j)='.';

    for(i=0;i<3;i++)
        for(j=0,j<SIZE;j++)
            if((i+j)%2==1) //hace el patrón del tablero
                *(t+i*SIZE+j)='X';
    
    for(i=5;i<8;i++)
        for(j=0;j<SIZE;j++)
            if((i+j)%2==1) 
                *(t+i*SIZE+j)='O';
}

