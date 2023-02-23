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
    char    *str;
    int     key;
    int     i;

    if (argc != 2)
    {
        return (1);
    }
    i = 0;
    while (argv[1][i] >= '0' && argv[1][i] <= '9')
    {
        i++;
    }
    if (argv[1][i] != '\0')
    {
        return (1);
    }
    key = atoi(argv[1]);
    do
    {
        str = get_string("plaintext: ");
    }
    while (!str);
    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = ((str[i] - 'a' + key) % 26) + 'a';
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = (((str[i] - 'A') + key) % 26) + 'A';
        }
        i++;
    }
    printf("ciphertext: %s\n", str);
    return (0);
}
