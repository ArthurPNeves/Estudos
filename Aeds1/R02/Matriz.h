#include "io.h" // para definicoes proprias


void InitIntMatrix ( int linha, int columns, int matrix[ ][columns] )
{
    // definir dados locais
    int x = 0;
    int y = 0;
    int z = 0;
    chars text = IO_new_chars ( STR_SIZE );
    // ler e guardar valores em arranjo
    for ( x=0; x<linha; x=x+1 )
    {
        for ( y=0; y<columns; y=y+1 )
        {
                z = (rand() % 100);
                matrix [ x ][ y ] = z;
        }

    }

}

void printIntMatrix ( int linha, int columns,int matrix[ ][columns] )
{
    // definir dado local
    int x = 0;
    int y = 0;
    // mostrar valores na matriz
    for ( x=0; x<linha; x=x+1 )

    {
        for ( y=0; y<columns; y=y+1 )
        {
            // mostrar valor
            IO_printf ( "%3d\t", matrix [ x ][ y ] );
        } // fim repetir
        IO_printf ( "\n" );
    } // fim repetir
}

void fprintIntMatrix ( chars fileName, int linha, int columns, int matrix[ ][columns] )
{
    // definir dados locais
    FILE* arquivo = fopen ( fileName, "wt" );
    int x = 0;
    int y = 0;

    // gravar quantidade de dados
    IO_fprintf ( arquivo, "%d\n", linha );
    IO_fprintf ( arquivo, "%d\n", columns );

    // gravar valores no arquivo
    for ( x=0; x<linha; x=x+1 )
    {
        for ( y=0; y<columns; y=y+1 )
        {
            // gravar valor
            IO_fprintf ( arquivo, "%d\n", matrix [ x ][ y ] );
        } // fim repetir
    } // fim repetir

    // fechar arquivo
    fclose ( arquivo );
} // fprintIntMatrix ( )



void freadIntMatrix ( chars fileName, int linha, int columns, int matrix[ ][columns] )
{
    // definir dados locais
    int x = 0;
    int y = 0;
    int z = 0;
    FILE* arquivo = fopen ( fileName, "rt" );

    // ler a quantidade de dados
    IO_fscanf ( arquivo, "%d", &x );
    IO_fscanf ( arquivo, "%d", &y );

    if ( linha <= 0 || linha > x ||
    columns <= 0 || columns > y )
    {
        IO_println ( "ERRO: Valor invalido." );
    }
    else
    {
    // ler e guardar valores em arranjo
    x = 0;
    while ( ! feof ( arquivo ) && x < linha )
    {
        y = 0;
        while ( ! feof ( arquivo ) && y < columns )
        {
            // ler valor
            IO_fscanf ( arquivo, "%d", &z );
            // guardar valor
            matrix [ x ][ y ] = z;
            // passar ao proximo
            y = y + 1;
        } // fim repetir
    // passar ao proximo
    x = x + 1;
    } // fim repetir
    }//fim se

    // fechar arquivo
    fclose ( arquivo );
} // freadIntMatrix ( )
