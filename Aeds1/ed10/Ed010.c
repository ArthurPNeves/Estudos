/*
Theldo, os ultimos ed's eu estava entregando sem usar file, pois não esta entendendo como fazer ler o arquivo.
Apartir desse ed para frente ultilizarei, pois entendi, desculpe pelo transtorno
*/
#include "io.h"

void method00()
{
}

typedef struct s_array
{
  int x;      // indexador, para chegar na posicao
  int length; // tamanho
  ints data;  // referencia para o aramazenamento
} intarray;

typedef intarray *ref_intarray;

typedef struct s_int_Matrix
{
  int rows;
  int columns;
  ints *data;
  int ix, iy;
} int_Matrix;

typedef int_Matrix *ref_int_Matrix;

ref_intarray new_int_ArrayRef(int n)
{
  // reserva de espaco
  ref_intarray tmpArray = (ref_intarray)malloc(sizeof(intarray));
  // estabelecer valores padroes
  if (tmpArray == NULL)
  {
    IO_printf("\nERRO: Falta espaco.\n");
  }
  else
  {
    tmpArray->length = 0;
    tmpArray->data = NULL;
    tmpArray->x = -1;
    if (n > 0)
    {
      // guardar a quantidade de dados
      tmpArray->length = n;

      // reservar espaco para os dados
      tmpArray->data = (ints)malloc(n * sizeof(int));

      // definir indicador do primeiro elemento
      tmpArray->x = 0;
    } // fim se

  } // fim se
  // retornar referencia para espaco reservado
  return (tmpArray);
} // fim

void intArray_init(int superior, int inferior, ref_intarray array)
{

  int x = 0;
  while (array->length > array->x)
  {
    x = rand();
    if (x > inferior && x < superior)
    {
      array->data[array->x] = x;
      printf("%d\n", array->data[array->x]);
      array->x = array->x + 1;
    }
  }
  
}

void fprint(ref_intarray array)
{
  array->x = 0;
  FILE *arquivo = fopen("DADOS.TXT", "wt");
  fprintf(arquivo, "%d\n", array->length);
  while (array->length > array->x)
  {
    fprintf(arquivo, "%d\n", array->data[array->x]);
    array->x = array->x + 1;
  }
  fclose(arquivo);
}

ref_intarray freadintArray(chars fileName)
{
  // definir dados locais
  ref_intarray array = NULL;
  int linha = 0;
  FILE *arquivo = fopen(fileName, "rt");

  // ler a quantidade de dados
  fscanf(arquivo, "%d", &linha);

  if (linha <= 0)
  {
    IO_printf("\nERRO: Valor invalido.\n");
  }
  else
  {
    // reservar espaco para armazenar
    array = new_int_ArrayRef(linha);
    // testar se ha' espaco
    if (array != NULL && array->data == NULL)
    {
      // nao ha' espaco
      array->length = 0;

      array->x = 0;
    }
    else
    {
      // ler e guardar valores na matriz
      array->x = 0;
      while (!feof(arquivo) && array->x < array->length)
      {
        // guardar valor
        fscanf(arquivo, "%d", &array->data[array->x]);
        // passar ao proximo
        array->x = array->x + 1;
      } // fim repetir
      // passar ao proximo
      array->x = 0;
    } // fim se
  }   // fim se
  return (array);
} // fim freadintMatrix ( )

bool procurar(ref_intarray array, int valor)
{
  bool resultado = false;
  array->x = 0;
  while (array->length > array->x)
  {
    if (array->data[array->x] == valor)
    {
      resultado = true;
    }

    array->x++;
  }

  return (resultado);
}

bool comparararray(ref_intarray array1, ref_intarray array2)
{
  bool resultado = false;
  int contador = 0;
  if (array1->length == array2->length)
  {

    while (array1->length > array1->x)
    {
      if (array1->data[array1->x] == array2->data[array1->x])
      {
      }
      else
      {
        contador++;
      }
      array1->x++;
    }
  }

  if (contador != 0)
  {
    resultado = false;
  }
  else
  {
    resultado = true;
  }

  return (resultado);
}

int somar(ref_intarray array1, ref_intarray array2)

{
  int resultado = 0;
  int soma1 = 0;
  int soma2 = 0;
  array1->x = 0;
  array2->x = 0;

  while (array1->length > array1->x)
  {
    soma1 = array1->data[array1->x] + soma1;
    array1->x++;
  }

  while (array2->length > array2->x)
  {
    soma2 = array2->data[array2->x] + soma2;
    array2->x++;
  }

  resultado = soma1 + soma2;

  return (resultado);
}

bool crecente(ref_intarray array)
{
  bool resultado = false;
  int contador = 0;
  array->x = 0;
  while (array->x < array->length)
  {

    if (array->data[array->x] > array->data[array->x - 1])
    {
      contador++;
    }
    array->x++;
  }

  if (contador == array->length)
  {
    resultado = true;
  }
  return (resultado);
}

ref_int_Matrix new_int_Matrix(int rows, int columns)
{
  // reserva de espaco
  ref_int_Matrix tmpMatrix = (ref_int_Matrix)malloc(sizeof(int_Matrix));

  // estabelecer valores padroes
  if (tmpMatrix != NULL)
  {
    tmpMatrix->rows = 0;
    tmpMatrix->columns = 0;
    tmpMatrix->data = NULL;

    // reservar espaco
    if (rows > 0 && columns > 0)
    {
      tmpMatrix->rows = rows;
      tmpMatrix->columns = columns;
      tmpMatrix->data = malloc(rows * sizeof(ints));
      if (tmpMatrix->data)
      {
        for (tmpMatrix->ix = 0; tmpMatrix->ix < tmpMatrix->rows; tmpMatrix->ix = tmpMatrix->ix + 1)
        {
          tmpMatrix->data[tmpMatrix->ix] = (ints)malloc(columns * sizeof(int));
        }
      } // fim se
    }   // fim se
    tmpMatrix->ix = 0;
    tmpMatrix->iy = 0;
  } // fim se
  return (tmpMatrix);
}

ref_int_Matrix freadintMatrix(chars fileName)
{
  // definir dados locais
  ref_int_Matrix matrix = NULL;
  int rows = 0;
  int columns = 0;
  FILE *arquivo = fopen(fileName, "rt");

  // ler a quantidade de dados
  fscanf(arquivo, "%d", &rows);
  fscanf(arquivo, "%d", &columns);

  if (rows <= 0 || columns <= 0)
  {
    IO_printf("\nERRO: Valor invalido.\n");
  }
  else
  {
    // reservar espaco para armazenar
    matrix = new_int_Matrix(rows, columns);
    // testar se ha' espaco
    if (matrix != NULL && matrix->data == NULL)
    {
      // nao ha' espaco
      matrix->rows = 0;
      matrix->columns = 0;
      matrix->ix = 0;
      matrix->iy = 0;
    }
    else
    {
      // testar a existência
      if (matrix != NULL)
      {
        // ler e guardar valores na matriz
        matrix->ix = 0;
        while (!feof(arquivo) && matrix->ix < matrix->rows)
        {
          matrix->iy = 0;
          while (!feof(arquivo) && matrix->iy < matrix->columns)
          {
            // guardar valor
            fscanf(arquivo, "%d", &(matrix->data[matrix->ix][matrix->iy]));
            // passar ao proximo
            matrix->iy = matrix->iy + 1;
          } // fim repetir
          // passar ao proximo
          matrix->ix = matrix->ix + 1;
        } // fim repetir
        matrix->ix = 0;
        matrix->iy = 0;
      } // fim se
    }   // fim se
  }     // fim se
  return (matrix);
} // fim freadintMatrix ( )

void fprintIntMatrix(chars fileName, ref_int_Matrix matrix)
{

  FILE *arquivo = fopen(fileName, "wt");
  // testar se ha' dados
  if (matrix == NULL)
  {
    printf("\nERRO: Nao ha' dados.");
  }
  else
  {
    // gravar quantidade de dados
    fprintf(arquivo, "%d\n", matrix->rows);
    fprintf(arquivo, "%d\n", matrix->columns);
    if (matrix->data != NULL)
    {
      // gravar valores no arquivo
      for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
      {
        for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
        {
          // gravar valor
          fprintf(arquivo, "%d\n", matrix->data[matrix->ix][matrix->iy]);
        } // fim repetir } // fim repetir
      }   // fim se
      fclose(arquivo);
    } // fim se
  }
}

void transpostaMatriz(ref_int_Matrix matrix)
{

  printf("\n");
  for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
  {
    for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
    {
      printf("%d\t", matrix->data[matrix->iy][matrix->ix]);
    }
    printf("\n");
  }
  printf("\n");
}

bool zeroMatriz(ref_int_Matrix matrix)
{
  int contador = 0;
  bool resultado = false;
  matrix->ix = 0;
  matrix->iy = 0;
 
      printf("\n");
  for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
  {
    for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
    {
      printf("%d\t", matrix->data[matrix->ix][matrix->iy]);

      if (matrix->data[matrix->ix][matrix->iy] == 0)
      {
        contador++;
      }

    }
    printf("\n");
  }
  printf("\n");


  if (contador == matrix->rows * matrix->columns )
  {
    resultado = true;
  }
  return (resultado);
}

bool compararMatrix(ref_int_Matrix matrix1, ref_int_Matrix matrix2)

{
  bool resultado = false;
  int contador = 0;
  if (matrix1->columns  == matrix2->columns && matrix1->rows == matrix2->rows )
  {
      for (matrix1->ix = 0, matrix2->ix = 0 ; matrix1->ix < matrix1->rows; matrix1->ix = matrix1->ix + 1, matrix2->ix = matrix1->ix)
  {
    for (matrix1->iy = 0, matrix2->iy = 0 ; matrix1->iy < matrix1->columns; matrix1->iy = matrix1->iy + 1, matrix2->iy = matrix1->iy )
    {

       if (matrix1->data[matrix1->ix] [matrix1->iy] == matrix2->data[matrix2->ix] [matrix2->iy] )
      {
          contador++;
      }
    }
  }

  }
  if (contador == matrix1->columns * matrix1->rows)
  {
    resultado = true;
  }

  return (resultado);
}

int somarmatrix(ref_int_Matrix matrix1, ref_int_Matrix matrix2)
{
  int resultado = 0;
  int soma1 = 0;
  int soma2 = 0;
  int contador = 0;
  if (matrix1->columns  == matrix2->columns && matrix1->rows == matrix2->rows )
  {
      for (matrix1->ix = 0, matrix2->ix = 0 ; matrix1->ix < matrix1->rows; matrix1->ix = matrix1->ix + 1, matrix2->ix = matrix1->ix)
  {
    for (matrix1->iy = 0, matrix2->iy = 0 ; matrix1->iy < matrix1->columns; matrix1->iy = matrix1->iy + 1, matrix2->iy = matrix1->iy )
    {
        soma1 = soma1 + matrix1->data[matrix1->ix][matrix1->iy];
        soma2 = soma2 + matrix2->data[matrix2->ix][matrix2->iy];
    }
  }

  }

    resultado = soma1 + soma2;
  

  return (resultado);
}

int produtoMatrix(ref_int_Matrix matrix1, ref_int_Matrix matrix2)
{
  int resultado = 0;
  int soma1 = 0;
  int soma2 = 0;
  int contador = 0;
  if (matrix1->columns  == matrix2->columns && matrix1->rows == matrix2->rows )
  {
      for (matrix1->ix = 0, matrix2->ix = 0 ; matrix1->ix < matrix1->rows; matrix1->ix = matrix1->ix + 1, matrix2->ix = matrix1->ix)
  {
    for (matrix1->iy = 0, matrix2->iy = 0 ; matrix1->iy < matrix1->columns; matrix1->iy = matrix1->iy + 1, matrix2->iy = matrix1->iy )
    {
        soma1 = soma1 + matrix1->data[matrix1->ix][matrix1->iy];
        soma2 = soma2 + matrix2->data[matrix2->ix][matrix2->iy];
    }
  }

  }

    resultado = soma1 * soma2;
  

  return (resultado);
}

void method01()
{
  int n = 0;
  n = IO_readint("insira o tamanho do array:\n");
  while (n <= 0)
  {
    printf("nao Ã© um valor valido ensira novamente");
    n = IO_readint("inisira valor do array positivo :\n");
  }

  intarray *array = new_int_ArrayRef(n);

  // ref_intarray tamanho = (ref_intarray) malloc(n * sizeof(int));

  int superior = 0;
  int inferior = 0;

  inferior = IO_readint("insira o limite inferior:\n");
  superior = IO_readint("insira o limite superior:\n");

  intArray_init(superior, inferior, array);
  fprint(array);
  free(array->data);
  IO_pause("Apertar ENTER para terminar");
}

void method02()
{

  ref_intarray array = null;
  array = freadintArray("DADOS.TXT");

  int valor = 0;
  valor = IO_readint("Insira valor:\n");

  if (procurar(array, valor))
  {
    printf("Tem valor");
  }
  else
  {
    printf("nao Tem valor");
  }
  free(array->data);
}

void method03()
{
  ref_intarray array = null;
  array = freadintArray("DADOS.TXT");
  ref_intarray array2 = null;
  array2 = freadintArray("DADOS2.TXT");

  if (comparararray(array, array2))
  {
    printf("\nSao Iguais");
  }
  else
  {
    printf("Nao sao iguais");
  }
  free(array->data);
  free(array2->data);
}

void method04()
{
  ref_intarray array = null;
  array = freadintArray("DADOS.TXT");
  ref_intarray array2 = null;
  array2 = freadintArray("DADOS2.TXT");

  printf("%d", somar(array, array2));
  free(array->data);
  free(array2->data);
}

void method05()
{
  ref_intarray array = null;
  array = freadintArray("DADOS.TXT");
  // theldo nao ta funcionando na minha maquina, mas testei na do colega o mesmo codigo e funcionou.
  bool resultado = false;
  resultado = crecente(array);
  printf("(%d)", resultado);

  if (resultado == true)
  {
    printf("\ne crecente\n");
  }
  else
  {
    printf("\nnao e crecente\n");
  }
  free(array->data);
}

void method06()
{
  ref_int_Matrix matrix = null;
  matrix = freadintMatrix("DADOS.TXT");
  transpostaMatriz(matrix);
}

void method07()
{
  ref_int_Matrix matrix = null;
  matrix = freadintMatrix("DADOS.TXT");

    if (zeroMatriz(matrix) == true)
  {
    printf("Todos valores sao 0");
  }
  else
  {
    printf("Nao sao todos valores iguais a 0");
  }
  free(matrix->data);
}

void method08()
{
      ref_int_Matrix matrix1 = null;
  matrix1 = freadintMatrix("DADOS.TXT");

  ref_int_Matrix matrix2 = null;
  matrix2 = freadintMatrix("DADOS2.TXT");


    if (compararMatrix(matrix1, matrix2) == true)
  {
    printf("Iguais");
  }
  else
  {
    printf("Nao sao Iguais");
  }

  free(matrix1->data);
  free(matrix2->data);
}
void method09()
{
    ref_int_Matrix matrix1 = null;
  matrix1 = freadintMatrix("DADOS.TXT");

  ref_int_Matrix matrix2 = null;
  matrix2 = freadintMatrix("DADOS2.TXT");

  printf("\n%d", somarmatrix(matrix1, matrix2));
}

void method010()
{
    ref_int_Matrix matrix1 = null;
  matrix1 = freadintMatrix("DADOS.TXT");

  ref_int_Matrix matrix2 = null;
  matrix2 = freadintMatrix("DADOS2.TXT");

  printf("\n%d", produtoMatrix(matrix1, matrix2));
}

int main()
{

  int x = 0;

  do
  {
    IO_printf("\nOpcoes \n");
    IO_printf(" 0 - parar   ");
    IO_printf(" 1011 - 1 \n");
    IO_printf(" 1012 -  2 ");
    IO_printf(" 1013 -  3\n");
    IO_printf(" 1014 -  4  ");
    IO_printf(" 1015 -  5\n");
    IO_printf(" 1016 -  6  ");
    IO_printf(" 1017 -  7\n");
    IO_printf(" 1018 -  8 ");
    IO_printf(" 1019 -  9 \n");
    IO_printf(" 1020 -  10 \n");


    x = IO_readint("Entrar com uma opcao: \n");
    printf("%d", x);
    switch (x)
    {
    case 0:
      method00();
      break;
    case 1:
      method01();
      break;
    case 2:
      method02();
      break;
    case 3:
      method03();
      break;
    case 4:
      method04();
      break;
    case 5:
      method05();
      break;
    case 6:
      method06();
      break;
    case 7:
      method07();
      break;
    case 8:
      method08();
      break;
    case 9:
      method09();
      break;
    case 10:
      method010();
      break;
    default:
      printf("%d", x);
      IO_printf("ERRO: Valor invalido.");
    }

  } while (x != 0);

  IO_pause("Apertar ENTER para terminar");
  return (0);
}