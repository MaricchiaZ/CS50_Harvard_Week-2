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

int roundus(double number)
{
    return (number >= 0) ? (int)(number + 0.5) : (int)(number - 0.5);
}

int main(void)
{
    char    *str;
    int     i;
    float     letter;
    float     sentence;
    int     words;
    float  index_CL;
    
    do
    {
        str = get_string("Text: ");
    }
    while (!str);
    i = 0;
    letter = 0;
    sentence = 0;
    words = 1;
    index_CL = 0;
    while (str[i])
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            letter++;
        }
        if (str[i] == '.' || str[i] == '!' || str[i] == '?')
        {
            sentence++;
        }
        if (str[i] == ' ')
        {
            words++;
        }
        i++;
    }

    letter = (letter / (words) * 100);
    sentence = (sentence / (words) * 100);
    index_CL = ((0.0588 * letter) - (0.296 * sentence)) - 15.8;
    if (index_CL <= 1)
    {
        printf("Before Grade 1\n");
    }
    if ((index_CL > 1 && index_CL < 16))
    {
        printf("Grade %d\n", roundus(index_CL));
    }
    if (index_CL >= 16)
    {
        printf("Grade 16+\n");    
    }
    return (0);
}