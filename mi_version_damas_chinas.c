//mi version
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void iniciar_tablero(char *tablero); //crea el tablero inicial para jugar con sus fichas y casillas respectivas
void print_tablero(const char *tablero);
void esperar_enter();
void seleccionar_ficha(const char *t, char jugador);
void mover_ficha(char *t, int pos, char jugador);
void jugar_turno(char *t, char jugador);

int main()
{
    char tablero[64];
    int X,O;
    /*ejemplo para mover tablero
    tmp = *(mat+1);
    *(mat+1) = *(mat+2);
    *(mat+2) = tmp;
    */
    return 0;
}

void iniciar_tablero(char *tablero)
{
    int i,fila,columna;
    for (i = 0; i <64; i++)
    {
        fila = i / 8;
        columna = i % 8;
        if ((fila+columna) % 2 ==0) //verificar si la casilla debe ser o oscura o clara 
                                 //si no es oscura pues la casilla no se usa para jugar y se deja un espacio en blanco 
                                 //y si es oscura se alinea donde va cada X y O en tablero inicial
                                 // en caso de que una casilla este vacio se pone un punto porque esa casila si se usara para jugar
        {
            //casilla clara o casilla que no usara para jugar
            tablero[i] = ' ';
        }
        else
        {
            //casilla oscura
            if (fila <= 2)
                tablero[i] = 'X';
            else if (fila >= 5)
                tablero[i] = 'O';
            else
                tablero[i] = '.';
        }
    }
}

void print_tablero(const char *tablero)
{
    int i,j,acomodar;
    for (i = 0; i < 8; i++)
    {
        for (j= 0; j < 8; j++)
        {
            acomodar = i * 8 + j; //acomoda las filas y las columnas 
            printf("| %c ",tablero[acomodar]);
        }
        printf("|\n");
}

void esperar_enter()
{
    getchar();
}

void seleccionar_ficha(const char *tablero, char jugador)
{
    int posicion;
    posicion = rand() % 64;
    do
    {

    } while ();
}

void mover_ficha(char *t, int pos, char jugador)
{

}

void jugar_turno(char *t, char jugador)
{

}
