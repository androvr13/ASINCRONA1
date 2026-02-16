#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void iniciar_tablero(char *tablero); //crea el tablero inicial para jugar con sus fichas y casillas respectivas
void print_tablero(const char *tablero);//muestra el tablero
void esperar_enter(void);//espera que el usuario presione una tecla para que se haga el movimiento de X o O
int seleccionar_ficha(const char *tablero, char jugador); //no mueve nada solo valida que la casilla este disponible para poder usarse 
void mover_ficha(char *tablero, int posicion, char jugador);//asume que la casilla si se puede usar

int main()
{
    char tablero[64];
    int turno;
    char jugador;
    srand((unsigned)time(NULL));
    iniciar_tablero(tablero);
    print_tablero(tablero);
    jugador = 'X';
    for (turno = 0; turno < 20; turno++)
    {
        printf("\nTurno de %c\n", jugador);
        printf("Presiona ENTER para continuar...");
        esperar_enter();
        mover_ficha(tablero, seleccionar_ficha(tablero, jugador), jugador);
        print_tablero(tablero);
        jugador = (jugador == 'X') ? 'O' : 'X';
    }
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
            {
                tablero[i] = 'X';
            }

            else if (fila >= 5)
            {
                tablero[i] = 'O';
            }
               
            else
            {
                tablero[i] = '.';
            }
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
}

void esperar_enter(void)
{
    while (getchar() != '\n');
}

int seleccionar_ficha(const char *tablero, char jugador)
{
    int posicion;
    int fila;       
    int columna;        
    int casilla_final;
    while (1)
    {
        posicion = rand() % 64;//geneera un numero aleatorio de alguna casilla siguiendo esta logica
        /* 0 1 2 3 4 5 6 7 
           8 9 10 11 12 13 14 15 y sucesivamente
        */
        if (*(tablero + posicion) != jugador)
        {
            continue;
        }
        fila = posicion / 8;
        columna  = posicion % 8;
        if (jugador == 'X')
        {
            casilla_final = posicion + 7;
            if (casilla_final < 64 && columna > 0 && *(tablero + casilla_final) == '.')
            {
                 return posicion;
            }

            casilla_final = posicion + 9;
            if (casilla_final < 64 && columna < 7 && *(tablero + casilla_final) == '.')
            {
                return posicion;
            }
        }
        else
        {
            casilla_final= posicion - 7;
            if (casilla_final >= 0 && columna < 7 && *(tablero + casilla_final) == '.')
            {
                return posicion;
            }
            casilla_final = posicion - 9;
            if (casilla_final >= 0 && columna > 0 && *(tablero + casilla_final) == '.')
            {
                return posicion;
            }
        }
    }
}

void mover_ficha(char *tablero, int posicion, char jugador)
{
    int columna, casilla;
    columna = posicion % 8;
    if (jugador == 'X')
    {
        if (columna > 0 && *(tablero + posicion + 7) == '.')
        {
            casilla= posicion + 7;
        }
        else
        {
            casilla = posicion + 9;
        }
    }
    else
    {
        if (columna < 7 && *(tablero + posicion - 7) == '.')
        {
            casilla= posicion - 7;
        }
            
        else
        {
            casilla = posicion - 9;
        }  
    }

    *(tablero + casilla) = jugador;
    *(tablero + posicion) = '.';
}
