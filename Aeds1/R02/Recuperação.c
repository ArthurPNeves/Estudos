
#include "io.h"
#include "Matriz.h"
#include "array2.h"

void method00()
{
}

void method01()
{

  ref_intarray array = null;
  array = freadintArray("DADOS.TXT");

  if (decrecente(array))
  {
    printf("\ne Decrecente\n");
  }
  else
  {
    colocardecrecente(array);
  }

  fprint(array, "DECRESCENTE.TXT");

  free(array->data);
  IO_pause("Apertar ENTER para terminar");
}

void method02()
{

  ref_intarray array = null;
  array = freadintArray("DECRESCENTE.TXT");
  inverter(array);
  array->x = 0;
  while (array->length > array->x)
  {
    printf("\n%d\n", array->data[array->x]);
    array->x++;
  }
  fprint(array, "INVERTIDO.TXT");

  free(array->data);
  IO_pause("Apertar ENTER para terminar");
}

void method03()
{
  ref_intarray array = null;
  array = freadintArray("DADOS1.TXT");
  
   printf("%d", segundomenorvalorqnaoultrapasse (array, 50, menorvalorqnaoultrapasse(array, 50)));
  IO_pause("Apertar ENTER para continuar");
}

void method04()
{
    ref_intarray array = null;
  array = freadintArray("DADOS1.TXT");
    ref_intarray array2 = null;
  array2 = freadintArray("DADOS1.TXT");
  ref_intarray array3 = new_int_ArrayRef(array2->length);
  elementosComuns(array, array2, array3);
  fprint(array3, "FILTRADOS.TXT");

  IO_pause("Apertar ENTER para continuar");
}

void method05()
{
  ref_intarray array = null;
  array = freadintArray("BINARIOS1.TXT");
  fprint(ler01(array), "TESTE.TXT");
  
  IO_pause("Apertar ENTER para continuar");
}
 
void method06()
{

  IO_pause("Apertar ENTER para continuar");
}

void method07()
{

  IO_pause("Apertar ENTER para continuar");
}

void method08()
{

  IO_pause("Apertar ENTER para continuar");
}

void method09()
{

  IO_pause("Apertar ENTER para continuar");
}

void method10()
{

  IO_pause("Apertar ENTER para continuar");
}

int main()
{

  int x = 0;

  do
  {
    IO_printf("\nOpcoes \n");
    IO_printf(" 0 - parar \n");
    IO_printf(" 1- 1 \n");
    IO_printf(" 2 -  2\n ");
    IO_printf(" 3 -  3\n");
    IO_printf(" 4 -  4  \n");
    IO_printf(" 5 -  5\n");
    IO_printf(" 6 -  6 \n");
    IO_printf(" 7 -  7\n");
    IO_printf(" 8 -  8 \n");
    IO_printf(" 9 -  9 \n");
    IO_printf(" 10 -  10 \n");

    x = IO_readint("Entrar com uma opcao: \n");
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
      method10();
      break;
    default:
      printf("%d", x);
      IO_printf("ERRO: value invalido.");
    }

  } while (x != 0);

  IO_pause("Apertar ENTER para terminar");
  return (0);
}
