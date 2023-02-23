/* ************************************************************************** */
/*                                                                            */
/*   By: Maria Clara Zaine - 2022                                             */
/*   Follow me: github.com/MaricchiaZ                                         */
/*                                                                            */
/* ************************************************************************** */

/*
Proposta do exercício: Em uma cifra de substituição, “criptografamos” (ou seja, 
ocultamos de forma reversível) uma mensagem substituindo cada letra por outra. 
Para isso, usamos uma chave : neste caso, um mapeamento de cada uma das letras do 
alfabeto à letra correspondente quando criptografada. Para “decifrar” a mensagem, 
o receptor da mensagem precisaria saber a chave, para que pudesse reverter o processo: 
traduzir o texto criptografado (geralmente chamado de texto cifrado ) de volta na 
mensagem original (geralmente chamado de texto simples ).

Uma chave, por exemplo, pode ser a sequencia NQXPOMAFTRHLZGECYJIUWSKDVB. 
Esta chave de 26 caracteres significa que A (a primeira letra do alfabeto) 
deve ser convertido em N (o primeiro caractere da chave), B (a segunda letra 
do alfabeto) deve ser convertido em Q (o segundo caractere do chave), e assim 
por diante..
*/


//Implemente um programa que implemente uma cifra de substituição passada por argumento
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include<string.h>

char    *ft_strlowcase(char *str) // transforma uma string toda em letras minísculas
{
    int i; // índice para percorrer a string

    i = 0; // índice inicia em zero
    while (str[i] != '\0') // enquanto não acabar a string
    {
        while (str[i] >= 65 && str[i] <= 90) // se for letra e for maiúscula
        {
            str[i] = str[i] + 32; // transforma em letra minúscula
            i++;
        }
        i++;
    }
    return (str); // retorna a string transformada
}

int check_key(char *str) // confere se a str tem caracteres repetidos
{
    char *copy_str; // copia a str passada
    char *aux; // char auxuliar para receber uma cópia do str
    int i;

    copy_str = ft_strlowcase(str);
    aux = ft_strlowcase(str);
    i = 0;
    copy_str++; // avançamos uma unidade do str_cpy
    while (strchr(copy_str, aux[i]) == NULL) // comparamos o primeiro caractere do str_copy com o aux[i] 
    // e vemos se os caracteres são iguais, enquanto forem diferentes
    {    
        copy_str++; // avançamos
        i++;
    }
    if (aux[i] == '\0') // se percorremos tudo sem achar nenhum caractere igual
    { 
        return (0); // retornamos 0
    }
    return (1); // se tiver caracteres repetidos, retornamos 1
}

char    char_lowcase(char c) // transforma a letra recebida em minúscula
{
    if (c >= 65 && c <= 90) // se for letra e for maiúscula
    {
        c = c + 32; // transforma em minúscula
    }
    return (c);
}

char    char_upperase(char c) // transforma a letra recebida em maiúscula
{
    if (c >= 97 && c <= 122) // se for letra e for minúscula
    {
        c = c - 32; // transforma em maiúscula
    }
    return (c);
}

int main(int argc, char *argv[])
{
    char    *str; // vai receber o texto a ser cifrado
    int     i; // vai percorrer o arg[1]

    if (argc != 2)  // se o número de argumentos for diferente de ./a.out + 1
    {
        printf("Invalid number of arguments! :(\n"); // avisamos o erro e
        return (1);// saímos do programa
    }
    i = 0; // zeramos o índice
    while ((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z')) // enquanto for só letra, percorremos o argv[1]
    {
        i++;
    }
    if (argv[1][i] != '\0' || i != 26) // se ele não acabou, encontramos algo diferente de letra, e está errado OU se i não for 26, está faltando letra
    {
        printf("Invalid key! :(\n");  // avisamos o erro e
        return (1);// saímos do programa
    }
    if (check_key(argv[1]) == 1) // se o check_key retornar 1, encontramos letras repetidas, e está errado
    {
        return (1);  // saímos do programa
    }
    do
    {
        str = get_string("plaintext: "); // pegamos a string para criptografar
    }
    while (!str); 
    i = 0; // zeramos o índice
    while (str[i]) // enquanto houver algo na string
    {
        if (str[i] >= 'a' && str[i] <= 'z') // se for letra minúscula
        {
            str[i] =  char_lowcase(argv[1][str[i] - 'a']); // criptografamos e deixamos em miníscula
        }
        if (str[i] >= 'A' && str[i] <= 'Z') // se for letra maiúscula
        {
            str[i] = char_upperase(argv[1][str[i] - 'A']); // criptografamos e deixamos em maiúscula
        }
        i++;
    }
    printf("ciphertext: %s\n", str); // printamos o texto criptografado
    return (0); // e saímos do programa
}