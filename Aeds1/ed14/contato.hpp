/*
 Contato.hpp - v0.0. - __ / __ / _____
 Author: ______________________
*/
// ----------------------------------------------- definicoes globais
#ifndef _CONTATO_H_
#define _CONTATO_H_
// dependencias
#include <iostream>
using std::cin;  // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ifstream; // para ler arquivo
using std::ofstream; // para gravar arquivo
#include "io.hpp"
// outras dependencias

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
} // end pause (
#include "Erro.hpp"
// ---------------------------------------------- definicao de classe
/**
 * Classe para tratar contatos, derivada da classe Erro.
 */
class Contato : public Erro
{
   /**
    * atributos privados.
    */
private:
   string nome;
   string fone1;
   string fone2;

   bool telefone1Valido()
   {

      bool resultado = false;
      int contador = 0;

      for (int i = 0; i < fone1.length(); i++)
      {
         if ((fone1[i] > '0' && fone1[i] < '9') || fone1[i] == '-')
         {
            contador++;
         }
      }

      if (contador == fone1.length())
      {
         resultado = true;
      }
      return resultado;
   }

      bool telefone2Valido()
   {

      bool resultado = false;
      int contador = 0;

      for (int i = 0; i < fone2.length(); i++)
      {
         if ((fone2[i] > '0' && fone2[i] < '9') || fone2[i] == '-')
         {
            contador++;
         }
      }

      if (contador == fone2.length())
      {
         resultado = true;
      }
      return resultado;
   }

   /**
    * definicoes publicas.
    */
public:
   /**
    * Destrutor.
    */
   ~Contato()
   {
   }
   /**
    * Construtor padrao.
    */
   Contato()
   {
      setErro(0); // nenhum erro, ainda
      // atribuir valores iniciais vazios
      nome = "";
      fone1 = "";
      fone2= "";
   } // fim construtor padrao

   /**
    * Metodo para atribuir nome.
    * @param nome a ser atribuido
    */
   void setNome(std::string nome)
   {
      if (nome.empty())
         setErro(1); // nome invalido
      else
         this->nome = nome;
   } // fim setNome ( )
   /**
    * Metodo para atribuir telefone1.
    * @param fone a ser atribuido
    */
   void setfone1(std::string fone1)
   {
      if (fone1.empty())
         setErro(2); // fone1 invalido
      else
         this->fone1 = fone1;
   } // fim setfone1 ( )


      void setfone2(std::string fone2)
   {
      if (fone2.empty())
         setErro(2); // fone1 invalido
      else
         this->fone2 = fone2;
   } // fim setfone1 ( )


   void fromFile(std::string filename)
   {
      std::string x;
      std::string y;
      std::string z;
      ifstream afile;
      afile.open(filename);
      afile >> x;
      afile >> y;
      afile >> z;
      setNome(x);
      setfone1(y);
      setfone1(z);
      afile.close();
   }

   void toFile(std::string filename)
   {
      ofstream afile;
      afile.open(filename);
      afile << getNome();
      afile << endl;
      afile << getfone1();
      afile << endl;
      afile << getfone2();
      afile.close();
   }

   void readNome(std::string texto)
   {
      std::string x;
      cout << texto;
      cin >> x;
      setNome(x);
   }

   void readfone1(std::string texto)
   {
      std::string x;
      do
      {
         cout << texto;
         cin >> x;
         setfone1(x);

      } while (telefone1Valido() == false);
   }

      void readfone2(std::string texto)
   {
      std::string x;
      do
      {
         cout << texto;
         cin >> x;
         setfone2(x);

      } while (telefone2Valido() == false);
   }


   /*
    * Construtor alternativo.
    * @param nome_inicial a ser atribuido
    * @param fone_inicial a ser atribuido
    */
   Contato(std::string nome_inicial, std::string fone1_inicial, std::string fone2_inicial)
   {
      setErro(0); // nenhum erro, ainda
      // atribuir valores iniciais
      setNome(nome_inicial); // nome = nome_inicial;
      setfone1(fone1_inicial); // fone1 = fone1_inicial;
      setfone2(fone2_inicial);
   }                         // fim construtor alternativo

   /**
    * Construtor alternativo baseado em copia.
    */
   Contato(Contato const &another)
   {
      // atribuir valores iniciais por copia
      setErro(0);            // copiar erro
      setNome(another.nome); // copiar nome
      setfone1(another.fone1); // copiar fone1
      setfone2(another.fone2); // copiar fone1
   }                         // fim construtor alternativo

   int telefones(){
      int contador = 0;
      if (fone1.empty())
      {
      }
      else
      contador++;
      if(fone2.empty())
      {
         
      }
      else
      contador++;
   return(contador);
   }
   /**
    * Funcao para obter nome.
    * @return nome armazenado
    */
   std::string getNome()
   {
      return (this->nome);
   } // fim getNome ( )
   /**
    * Funcao para obter fone1.
    * @return fone1 armazenado
    */
   std::string getfone1()
   {
      return (this->fone1);
   } // fim getfone1 ( )

      std::string getfone2()
   {
      return (this->fone2);
   } // fim getfone1 ( )

   /**
    * Funcao para obter dados de uma pessoa.
    * @return dados de uma pessoa
    */
   std::string toString()
   {
      return ("{ " + getNome() + ", " + getfone1() + ", "  + getfone2() + "}");
   } // fim toString ( )


   /**
    * indicar a existencia de erro.
    */
   bool hasErro()
   {
      return (getErro() != 0);
   } // end hasErro ( )

};                             // fim da classe Contato
using ref_Contato = Contato *; // similar a typedef Contato* ref_Contato;
#endif