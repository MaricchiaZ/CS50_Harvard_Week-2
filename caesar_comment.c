/* ************************************************************************** */
/*                                                                            */
/*   By: Maria Clara Zaine - 2022                                             */
/*   Follow-me: github.com/MaricchiaZ                                         */
/*                                                                            */
/* ************************************************************************** */

// Proposta do exercício: Implemente um programa que criptografa mensagens usando a 
// cifra de César, recebendo a chave passada por argumento.

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char    *str; // vai receber o texto que será criptografado
    int     key; // vai receber a chave passada por argumento
    int     i; // índice para percorrer a string

    if (argc != 2) // se o número dos argumentos for diferente de a.out + 1
    {
        return (1); // ESTÁ ERRADO, então saímos do programa
    }
    i = 0; // zeramos o índice
    while (argv[1][i] >= '0' && argv[1][i] <= '9') // enquanto o argumento[1] for números/dígitos do 0 ao 9
    {
        i++; //avançamos
    }
    if (argv[1][i] != '\0') // se não chegarmos ao fim do arg[1] quer dizer que encontramos algum caractere diferente de número
    {
        return (1);  // ESTÁ ERRADO, então saímos do programa
    }
    key = atoi(argv[1]); //a chave recebe o argv[1] transformado em int pela atoi
    do
    {
        str = get_string("plaintext: "); // recebemos o texto que será criptografado
    }
    while (!str); 
    i = 0; // zeramos o índice
    while (str[i]) // enquanto não acabarmos de percorrer a string
    {
        if (str[i] >= 'a' && str[i] <= 'z') // se for letra minúscula
        {
            str[i] = ((str[i] - 'a' + key) % 26) + 'a'; //somamos a letra com a chave
        }
        if (str[i] >= 'A' && str[i] <= 'Z') // se for letra maiúscula
        {
            str[i] = (((str[i] - 'A') + key) % 26) + 'A'; //somamos a letra com a chave
        }
        i++; // avançamos na string
    }
    printf("ciphertext: %s\n", str); // imprimimos a string criptografada
    return (0); // saímos do programa
}
