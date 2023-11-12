#define _MYMATRIX_H_
#include "io.hpp"
using namespace std;

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

template <typename T>
class Matrix
{
private: // area reservada
    T optional;
    int rows;
    int columns;
    T **data;

public: // area aberta
    Matrix()
    {
        // definir valores iniciais
        this->rows = 0;
        this->columns = 0;
        // sem reservar area
        data = nullptr;
    } // end constructor
    Matrix(int rows, int columns, T initial)
    {
        // definir dado local
        bool OK = true;
        // definir valores iniciais
        this->optional = initial;
        this->rows = rows;
        this->columns = columns;
        // reservar area
        data = new T *[rows];
        if (data != nullptr)
        {
            for (int x = 0; x < rows; x = x + 1)
            {
                data[x] = new T[columns];
                OK = OK && (data[x] != nullptr);
            } // end for
            if (!OK)
            {
                data = nullptr;
            } // end if
        }     // end if
    }         // end constructor
    ~Matrix()
    {
        if (data != nullptr)
        {
            for (int x = 0; x < rows; x = x + 1)
            {
                delete (data[x]);
            } // end for
            delete (data);
            data = nullptr;
        } // end if
    }     // end destructor ( )
    void set(int row, int column, T value)
    {
        if (row < 0 || row >= rows ||
            column < 0 || column >= columns)
        {
            cout << "\nERROR: Invalid position.\n";
        }
        else
        {
            data[row][column] = value;
        } // end if
    }     // end set ( )

    void print()
    {
        cout << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                cout << data[x][y] << "\t";
            } // end for
            cout << endl;
        } // end for
        cout << endl;
    } // end print ( )

    void read()
    {
        cout << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                cout << setw(2) << x << ", "
                     << setw(2) << y << " : ";
                cin >> data[x][y];
            } // end for
        }     // end for
        cout << endl;
    } // end read ( )

    void fprint(string fileName)
    {
        ofstream afile;
        afile.open(fileName);
        afile << rows << endl;
        afile << columns << endl;
        for (int x = 0; x < rows; x = x + 1)
        {
            for (int y = 0; y < columns; y = y + 1)
            {
                afile << data[x][y] << endl;
            } // end for
        }     // end for
        afile.close();
    } // end fprint ( )

    void fread(string fileName)
    {
        ifstream afile;
        int m = 0;
        int n = 0;
        afile.open(fileName);
        afile >> m;
        afile >> n;
        if (m <= 0 || n <= 0)
        {
            cout << "\nERROR: Invalid dimensions for matrix.\n"
                 << endl;
        }
        else
        {
            // guardar a quantidade de dados
            rows = m;
            columns = n;
            // reservar area
            data = new T *[rows];
            for (int x = 0; x < rows; x = x + 1)
            {
                data[x] = new T[columns];
            } // end for
            // ler dados
            for (int x = 0; x < rows; x = x + 1)
            {
                for (int y = 0; y < columns; y = y + 1)
                {
                    afile >> data[x][y];
                } // end for
            }     // end for
        }         // end if
        afile.close();
    } // end fread ( )

    void gerarint(int superior, int inferior, int N, int M)
    {
        for (int i = 0; i < N; i++)
        {
            for (int x = 0; x < M;)
            {
                data[i][x] = rand();
                if (data[i][x] > inferior && data[i][x] < superior)
                {
                    x++;
                }
            }
        }
    }

    void escalar(int constante)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int x = 0; x < columns; x++)
            {
                data[i][x] = data[i][x] * constante;
            }
        }
    }

    bool identidade()
    {
        bool resultado = false;
        double contador1 = 0;
        double contador2 = 0;
        if (rows == columns)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int x = 0; x < columns; x++)
                {
                    if (x == i && data[i][x])
                    {
                        contador1++;
                    }

                    if (x != i && data[i][x] == 0)
                    {
                        contador2++;
                    }
                }
            }
        }

        if (contador1 == rows * pow(2, 1 / 2) && contador2 == (rows * columns - contador1))
        {
            resultado = true;
        }

        return (resultado);
    }

    bool operator!=(const Matrix<T> other)
    {
        bool result = false;
        int x = 0;
        int y = 0;
        if (other.rows == 0 || rows != other.rows ||
            other.columns == 0 || columns != other.columns)
        {
            cout << "\nERROR: Missing data.\n"
                 << endl;
        }
        else
        {
            x = 0;
            while (x < rows && !result)
            {
                y = 0;
                while (y < columns && !result)
                {
                    result = (data[x][y] != other.data[x][y]);
                    y = y + 1;
                } // end for
                x = x + 1;
            } // end for
        }     // end if
        return (result);
    } // end operator!= ( )

    Matrix &operator+(const Matrix<T> other)
    {
        static Matrix<T> result(1, 1, 0);
        int x = 0;
        int y = 0;

        if (rows <= 0 || columns == 0 ||
            other.rows <= 0 || other.columns == 0 ||
            columns != other.rows)
        {
            cout << endl
                 << "ERROR: Invalid data." << endl;
            result.data[0][0] = 0;
        }
        else
        {
            result.rows = rows;
            result.columns = other.columns;
            result.data = new T *[result.rows];

            for (int x = 0; x < result.rows; x = x + 1)
            {
                result.data[x] = new T[result.columns];
            } // end for

            for (x = 0; x < rows; x++)
            {
                for (y = 0; y < columns; y++)
                {
                    result.data[x][y] = data[x][y] + other.data[x][y];
                }
            }

        } // end if
        return (result);
    }

    void somarLinhas(int row1, int row2, int constante)
    {
        int soma = 0;
        for (int x = 0; x < rows; x++)
        {
            for (int y = 0; y < columns; y++)
            {
                soma = 0;
                if (x == row1)
                {
                    soma = (data[x][y] + data[row2][y]) * constante;
                    data[x][y] = soma;
                }
            }
        }
    }

    void subtrairLinhas(int row1, int row2, int constante)
    {
        int soma = 0;
        for (int x = 0; x < rows; x++)
        {
            for (int y = 0; y < columns; y++)
            {
                soma = 0;
                if (x == row1)
                {
                    soma = (data[x][y] - data[row2][y]) * constante;
                    data[x][y] = soma;
                }
            }
        }
    }

    int procurarLinha(int procurado = 0)
    {
        int resultado = 0;
        for (int x = 0; x < rows; x++)
        {
            for (int y = 0; y < columns; y++)
            {
                if (data[x][y] == procurado)
                {
                    resultado = x + 1;
                }
            }
        }

        return (resultado);
    }

    int procurarColuna(int procurado = 0)
    {
        int resultado = 0;
        for (int x = 0; x < rows; x++)
        {
            for (int y = 0; y < columns; y++)
            {
                if (data[x][y] == procurado)
                {
                    resultado = y + 1;
                }
            }
        }

        return (resultado);
    }

    void transpor()
    {
        int matrixtemporaria[rows][columns];
        for (int x = 0; x < columns; x++)
        {
            for (int y = 0; y < rows; y++)
            {
                matrixtemporaria[y][x] = data[x][y];
            }
        }

        
        for (int x = 0; x < columns; x++)
        {
            for (int y = 0; y < rows; y++)
            {
               data[x][y]  = matrixtemporaria[x][y];
            }
        }
    }

    bool Extra1()
    {

        int resultado1 = 0;
        bool resultado2 = false;
        int contador = 0;
        if (columns != rows)
        {
            cout << "erro" << endl;
        }
        else
        {
            for (int x = 0; x < columns; x++)
            {
                for (int y = 0; y < rows; y++)
                {
                    contador++;
                    if (data[x][y] == contador)
                    {
                        resultado1++;
                    }
                }
            }

            if (rows * columns == resultado1)
            {
                resultado2 = true;
            }
        }
        return resultado2;
    }

    bool Extra2()
    {

        int resultado1 = 0;
        bool resultado2 = false;
        int contador = 0;
        if (columns != rows)
        {
            cout << "erro" << endl;
        }
        else
        {
            for (int x = 0; x < rows; x++)
            {
                for (int y = 0; y < columns; y++)
                {
                    contador++;
                    if (data[y][x] == contador)
                    {
                        resultado1++;
                    }
                }
            }
            if (rows * columns == resultado1)
            {
                resultado2 = true;
            }
        }

        return (resultado2);
    }

}; // end class
