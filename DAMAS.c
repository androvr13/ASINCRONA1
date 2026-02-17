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
        for(j=0;j<SIZE;j++)
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
            printf("| %c ",*(tablero+acomodar));
        }
        printf("|\n");
}
}

int movimiento(char *t, char jugador){
    int fil, col; //posición actual
    int nuevaFil, nuevaCol; //posición destino
    int intentos= 0; //contador de intentos para evitar bucles infinitos (máximo 100)
    int d; //contador para recorrer direcciones de movimiento
    int direcciones[2]; //direcciones de movimiento para cada jugador

    direcciones[0]=1; //baja una fila
    direcciones[1]=-1; //sube una fila


    while(intentos<100){
        fil=rand()%SIZE; //genera fila aleatoria entre 0 y 7
        col=rand()%SIZE;

    if(*(t+fil*SIZE+col)==jugador){ //tablero[fil][col], verifica que la posición seleccionada tenga una ficha del jugador
        for(d=0; d<2; d++){ //intenta mover en ambas direcciones (hacia arriba y hacia abajo) *cumple requisito diagonal
            nuevaFil = fil + direcciones[d]; //calcula la nueva fila según la dirección

    if(nuevaFil>=0 && nuevaFil<SIZE){ //verifica que nunca se salga del tablero

        //LADO IZQUIERDO
        nuevaCol=col-1; //intenta mover a la izquierda
        if(nuevaCol>=0 && *(t+nuevaFil*SIZE+nuevaCol)=='.'){ //si está dentro del tablero y la casilla está vacía
            *(t+nuevaFil*SIZE+nuevaCol)=jugador; //coloca la ficha en la nueva posición
            *(t+fil*SIZE+col)='.'; //y deja un . en la posición original
            return 1; //si se logra hacer un movimiento válido
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
}
    intentos++;
}
return 0; //si no se logra hacer un movimiento válido después de 100 intentos
}

int main(){
    int turno;
    char enter; 
    char *ptr= &tablero[0][0];

    srand(time(NULL)); //numeros aleatorios diferentes cada vez que se ejecute el programa

    inicializar(ptr); 
    imprimir(ptr);

    for(turno=1; turno<=10; turno++){ //10 turnos para cada jugador
        printf("\nTurno %d - X(ENTER)\n", turno);
        while((enter=getchar()) != '\n'); //espera a que el usuario presione ENTER para continuar
        if(!movimiento(ptr, 'X'))
            printf("Sin movimientos, se pasa turno.\n");
        imprimir(ptr);

        printf("\nTurno %d - O(ENTER)\n", turno);
        while((enter=getchar()) != '\n');
        if(!movimiento(ptr, 'O'))
            printf("Sin movimientos, se pasa turno.\n");
        imprimir(ptr);
    }
    printf("\nJuego terminado\n");
    return 0;
}
