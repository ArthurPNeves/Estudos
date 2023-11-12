#include "io.h"
typedef struct s_array
{
  int x;      // indexador, para chegar na posicao
  int length; // tamanho
  ints data;  // referencia para o aramazenamento
} intarray;
typedef intarray *ref_intarray;

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

void fprint(ref_intarray array, char *filename)
{
  array->x = 0;
  FILE *arquivo = fopen(filename, "wt");
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

bool decrecente(ref_intarray array)
{
  bool resultado = false;
  int contador = 0;
  array->x = 0;
  while (array->x < array->length)
  {

    if (array->data[array->x + 1] < array->data[array->x])
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

void colocardecrecente(ref_intarray array)
{
  array->x = 0;
  for (array->x = 0; array->x < array->length - 1; array->x++)
  {
    for (int j = array->x; j < array->length; j++)
    {
      if (array->data[array->x] < array->data[j])
      {
        int temp = array->data[array->x];
        array->data[array->x] = array->data[j];
        array->data[j] = temp;
      }
    }
  }
}

void inverter(ref_intarray array)
{
  int i = 0;
  int temp = 0;

      printf("\nPAR\n");
      for (i = 0; i < array->length / 2 ; i++)
      {
        temp = array->data[i ];

        array->data[i ] = array->data[(array->length) -i -1];

        array->data[array->length -i -1] = temp;

      }

}

int menorvalorqnaoultrapasse(ref_intarray array, int valor)
{
  int temp = 100000;
  for (int i = 0; i < array->length; i++)
  {
    if (array->data[i] < valor)
    {
      if (temp > array->data[i])
      {
        temp = array->data[i];
      }
    }
    
  }
  return(temp);
}

int segundomenorvalorqnaoultrapasse(ref_intarray array, int valor, int menorvalor)
{
  int temp = 100000;
  for (int i = 0; i < array->length; i++)
  {
    if (array->data[i] < valor && array->data[i] > menorvalor)
    {
      if (temp > array->data[i])
      {
        temp = array->data[i];
      }
    }
    
  }
  return(temp);
}

void elementosComuns(ref_intarray array, ref_intarray array2, ref_intarray array3)
{
  int x =0;

  for (int i = 0; i < array->length; i++)
  {
    for (int z = 0; z < array2->length; z++)
    {
      if (array->data[i] == array2->data[z])
      {
        array3->data[x] = array2->data[z];
        x++;
      }
    }
    
  }
  
}

ref_intarray ler01(ref_intarray array)
{
  int y = 0;
  for (int i = 0; i < array->length; i++)
  {
        if (array->data[i]== 0 || array->data[i] == 1 )
    {
      
      y++;
    }
  }
  
  int x = 0;
  ref_intarray array2 = new_int_ArrayRef(y);
  for (int i = 0; i < array->length; i++)
  {
    if (array->data[i]== 0 || array->data[i] == 1 )
    {
      array2->data[x] = array->data[i];
      x++;
    }
  }
  return(array2);
}

