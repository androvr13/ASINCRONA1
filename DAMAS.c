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

void imprimir(const char *tablero){
    int i,j,acomodar;
    for (i = 0; i < SIZE; i++)
    {
        for (j= 0; j < SIZE; j++)
        {
            acomodar = i * SIZE + j; //acomoda las filas y las columnas 
            printf("| %c ",tablero[acomodar]);
        }
        printf("|\n");
}
}

int movimiento(char *t, char jugador){
    int fil, col;
    int nuevaFil, nuevaCol;
    int intentos= 0;

    while(intentos<100){
        fil=rand()%SIZE;
        col=rand()%SIZE;

    if(*(t+fil*SIZE+col)==jugador){
        nuevaFil=(jugador=='X') ? fil+1 : fil-1;

    if(nuevaFil>=0 && nuevaFil<SIZE){


        //LADO IZQUIERDO
        nuevaCol=col-1;
        if(nuevaCol>=0 && *(t+nuevaFil*SIZE+nuevaCol)=='.'){
            *(t+nuevaFil*SIZE+nuevaCol)=jugador;
            *(t+fil*SIZE+col)='.';
            return 1;
        }

        //LADO DERECHO
        nuevaCol=col+1;
        if(nuevaCol<SIZE && *(t+nuevaFil*SIZE+nuevaCol)=='.'){
            *(t+nuevaFil*SIZE+nuevaCol)=jugador;
            *(t+fil*SIZE+col)='.';
            return 1;
            }
        }
    }
    intentos++;
    }
    return 0;
}

int main(){
    int turno;
    char c;
    char *ptr= &tablero[0][0];

    srand(time(NULL));

    inicializar(ptr);
    imprimir(ptr);

    for(turno=1; turno<=10; turno++){
        printf("\nTurno %d - X(ENTER)\n", turno);
        while((c=getchar()) != '\n');
        movimiento(ptr, 'X');
        imprimir(ptr);

        printf("\nTurno %d - O(ENTER)\n", turno);
        while((c=getchar()) != '\n');
        movimiento(ptr, 'O');
        imprimir(ptr);
    }
    printf("\nJuego terminado\n");
    return 0;
}
