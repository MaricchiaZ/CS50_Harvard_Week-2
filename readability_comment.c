/* ************************************************************************** */
/*                                                                            */
/*   By: Maria Clara Zaine - 2022                                             */
/*   Follow me: github.com/MaricchiaZ                                         */
/*                                                                            */
/* ************************************************************************** */

/*
Proposta do exercício: Implemente um programa que calcule o nível (ano escolar)
 aproximado necessário para compreender algum texto, usando o o índice Coleman-Liau.
*/


//Projete e implemente um programa, readability, que calcule o índice Coleman-Liau do texto.
#include <stdio.h>
#include <cs50.h>

int roundus(double number) // função que arredonda um número
{
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}

int main(void)
{
    char    *str; // vai receber o texto para ser avaliado
    int     i; // índice para percorrer a string
    float     letter; // vai contar quantas letras tem no texto
    float     sentence; // vai contar quantas frases tem no texto
    int     words; // vai contar quantas palavras tem no texto
    float  index_CL; // ercebe o cálculo do índice Coleman-Liau 
    
    do
    {
        str = get_string("Text: "); // recebe o texto a ser analisado
    }
    while (!str);
    i = 0; // zeramos o índice
    letter = 0; // zeramos os contadores
    sentence = 0; // zeramos os contadores
    words = 1; // palavra já começa em 1
    index_CL = 0; // zeramos o índice
    while (str[i])
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) // se for letra de a a z ou de A a Z, aumentamos a contagem das letras
        {
            letter++;
        }
        if (str[i] == '.' || str[i] == '!' || str[i] == '?') // se for pontuação, aumentamos a contagem das frases
        {
            sentence++;
        }
        if (str[i] == ' ') // se for espaço, aumentamos a contagem das palavras
        {
            words++;
        }
        i++;
    }

    letter = (letter / (words) * 100); // calculamos a porcentagem de letras 
    sentence = (sentence / (words) * 100); // calculamos a porcentagem de frases
    index_CL = ((0.0588 * letter) - (0.296 * sentence)) - 15.8; // calculamos o índide
    if (index_CL <= 1) // até 1
    {
        printf("Before Grade 1\n"); // nível 1
    }
    if ((index_CL > 1 && index_CL < 16)) // de 1 até 16
    {
        printf("Grade %d\n", roundus(index_CL)); // arredonda o valor do índice que representará a série
    }
    if (index_CL >= 16) // acima de 16
    {
        printf("Grade 16+\n");    // nível 16+
    }
    return (0); // saímos do programa
}