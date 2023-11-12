#include "io.hpp"
#include <iostream>
#include <limits>
#include <string>

void pause(std::string text)
{
  std::string dummy;
  std::cin.clear();
  std::cout << std::endl
            << text;
  std::cin.ignore();
  std::getline(std::cin, dummy);
  std::cout << std::endl
            << std::endl;
}
#include "mymatrix.hpp"
using namespace std;

void method00()
{
  // nao faz nada
} // fim method00 ( )

void method01()
{
  int superior = 0;
  int inferior = 0;
  cout << "insira valor inferior:\n";
  cin >> inferior;
  cout << endl;
  cout << "insira valor superior:\n";
  cin >> superior;
  cout << endl;
  int N = 0;
  int M = 0;
  cout << "insira valor de colunas da matrix:\n";
  cin >> N;
  cout << "Insira valor de linhas da matrix:\n";
  cin >> M;
  Matrix<int> matrix(M, N, 0);
  matrix.gerarint(superior, inferior, N, M);

  matrix.fprint("DADOS.TXT");

  pause("Apertar ENTER para continuar");
}

void method02()
{
  // definir dados
  Matrix<int> matrix(3, 3, 0);

  matrix.fread("DADOS.TXT");
  int constante = 0;
  cout << "Escreva por quanto vai ser multiplicado os valores:\n";
  cin >> constante;
  matrix.escalar(constante);
  matrix.print();
  // encerrar
  pause("Apertar ENTER para continuar");
} // fim method02 (

void method03()
{

  // definir dados
  Matrix<int> matrix(3, 3, 0);

  matrix.fread("DADOS.TXT");
  if (matrix.identidade())
  {
    cout << "\ne identidade\n";
  }
  else
  {
    cout << "\nNao e indentidade\n";
  }

  matrix.print();
  // encerrar
  pause("Apertar ENTER para continuar");
}
void method04()
{
  Matrix<int> matrix1(3, 3, 0);
  Matrix<int> matrix2(3, 3, 0);
  matrix1.fread("DADOS.TXT");
  matrix2.fread("DADOS2.TXT");

  cout << "Diferentes = " << (matrix1 != matrix2) << endl;
}

void method05()
{
  Matrix<int> matrix1(3, 3, 0);
  Matrix<int> matrix2(3, 3, 0);
  Matrix<int> matrix3(3, 3, 0);
  matrix1.fread("DADOS.TXT");
  matrix2.fread("DADOS2.TXT");
  matrix3 = matrix1 + matrix2;

  matrix3.print();
}
void method06()
{
  
  Matrix <int> matrix1 ( 3, 3, 0 );
  matrix1.fread("DADOS.TXT");
  matrix1.print();
  matrix1.somarLinhas ( 0, 1, (-1) );
  printf("\n\n\n");
  matrix1.print();
  
}
void method07()
{

  Matrix <int> matrix1 ( 3, 3, 0 );
  matrix1.fread("DADOS.TXT");
  matrix1.print();
  matrix1.subtrairLinhas ( 0, 1, (2) );
  printf("\n\n\n");
  matrix1.print();

}

void method08()
{
  Matrix <int> matrix1 ( 3, 3, 0 );
  matrix1.fread("DADOS.TXT");
  matrix1.print();
  printf("\n\n\n");
  
  int valor = 0;
  valor = matrix1.procurarLinha (4);
  if  (valor != 0)
  {
    cout << "\nNumero esta na linha: " << valor << endl ;
  }
  else{
    cout << "\nNao existe tal numero nessa matrix\n";
  }
  
}

void method09()
{

  Matrix <int> matrix1 ( 3, 3, 0 );
  matrix1.fread("DADOS.TXT");
  matrix1.print();
  printf("\n\n\n");
  
  int valor = 0;
  valor = matrix1.procurarColuna (4);
  if  (valor != 0)
  {
    cout << "\nNumero esta na Coluna: " << valor << endl ;
  }
  else{
    cout << "\nNao existe tal numero nessa matrix\n";
  }
  
}

void method10()
{
  Matrix <int> matrix1 ( 3, 3, 0 );
  matrix1.fread("DADOS.TXT");
  matrix1.print();
  printf("\n\n\n");
  matrix1.transpor();
  matrix1.print();
}

void method11()
{
  Matrix <int> matrix1 ( 3, 3, 0 );
  matrix1.fread("DADOS.TXT");
  matrix1.print();
  printf("\n\n");
  if (matrix1.Extra1())
  {
    cout << endl << "Apresenta essa caracteristica" << endl;
  }
 else
 {
  cout << endl << "Nao Apresenta essa caracteristica" << endl;
 }
 
}

void method12()
{

  Matrix <int> matrix1 ( 3, 3, 0 );
  matrix1.fread("DADOS.TXT");
  matrix1.print();
  printf("\n\n");
  if (matrix1.Extra2())
  {
    cout << endl << "Apresenta essa caracteristica" << endl;
  }
 else
 {
  cout << endl << "Nao Apresenta essa caracteristica" << endl;
 }

}

int main(int argc, char **argv)
{

  int x = 0;
  do
  {

    cout << "ED11\n " << endl;
    // mostrar opcoes
    cout << "Opcoes " << endl;
    cout << " 0 - parar " << endl;
    cout << " 1 - ex1" << endl;
    cout << " 2 - ex2" << endl;
    cout << " 3 - ex3" << endl;
    cout << " 4 - ex4" << endl;
    cout << " 5 - ex5" << endl;
    cout << " 6 - ex6" << endl;
    cout << " 7 - ex7" << endl;
    cout << " 8 - ex8" << endl;
    cout << " 9 - ex9" << endl;
    cout << "10 - ex10" << endl;
    cout << "11 - Extra1" << endl;
    cout << "12 - Extra2" << endl;
    // ler do teclado
    cout << endl
         << "Entrar com uma opcao: ";
    cin >> x;
    // escolher acao
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
      case 11:
      method11();
      break;
      case 12:
      method12();
      break;
    default:
      cout << endl
           << "ERRO: Valor invalido." << endl;
    } // fim escolher
  } while (x != 0);
  // encerrar
  pause("Apertar ENTER para terminar");
  return (0);
} // fim main(