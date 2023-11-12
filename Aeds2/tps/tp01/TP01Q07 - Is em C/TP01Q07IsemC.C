#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// verifica se todas as letras da palavra sao vogal
static bool isVogal(char palavra[100])
{
    bool result = false;
    for (int i = 0; i < strlen(palavra); i++)
    {
        if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u')
        {
            result = true;
        }
        else
        {
            return false;
        }
    }
    return result;
}
// verifica se todas as letras da palavra sao consoante
static bool isConsoante(char palavra[100])
{
    bool result = false;
    for (int i = 0; i < strlen(palavra); i++)
    {
        if (palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || palavra[i] == 'o' || palavra[i] == 'u' || palavra[i] > 'z' || palavra[i] < 'a')
        {
            return false;
        }
        else
        {
            result = true;
        }
    }
    return result;
}
// verifica se é um nomero a String
static bool isInt(char palavra[100])
{
    bool result = false;
    for (int i = 0; i < strlen(palavra); i++)
    {
        if (palavra[i] >= '0' && '9' >= palavra[i])
        {
            result = true;
        }
        else
        {
            return false;
        }
    }
    return result;
}
    // verifica se é um numero real a string
static bool isReal(char palavra[100])
{
    bool result = false;
    int contador = 0;
    for (int i = 0; i < strlen(palavra); i++)
    {
        if ((palavra[i] >= '0' && '9' >= palavra[i]) || palavra[i] == '.' || palavra[i] == ',')
        {
            if (palavra[i] == '.' || palavra[i] == ',')
            {
                contador++;
            }
            result = true;
        }
        else
        {
            return false;
        }
    }
    if (contador > 1)
    {
        return false;
    }
    else
    {
        return result;
    }
}
    // Funcao quer verifica se entrada é igual a FIM, ultiziando charAt nas posicoes0,1,2 , (Sera ultilizada na Main)
static bool isFim(char palavra[100])
{
    bool result = false;
    if (palavra[0] == 'F' && palavra[1] == 'I' && palavra[2] == 'M')
        result = true;
    return result;
}
int main()
{
    
    // inciando variaveis
    char palavra[100];
    // Lendo todas as saidas, imprindo Sim e Nao, caso seja verdadeira um dos methodo e parando quando Fim for achado

       fgets(palavra, 100, stdin);
       palavra[strlen(palavra)-1] = '\0';
        while(isFim(palavra) == false)
        {
            if(isVogal(palavra)) { printf("SIM "); }
            else{ printf("NAO ");}
            
            
            if(isConsoante(palavra)) { printf("SIM "); }
            else{ printf("NAO ");}

            if(isInt(palavra)) { printf("SIM "); }
            else{ printf("NAO ");}

            if(isReal(palavra)) { printf("SIM\n"); }
            else{ printf("NAO\n");}
            fgets(palavra, 100, stdin);
            palavra[strlen(palavra)-1] = '\0';
        }

    return 0;
}