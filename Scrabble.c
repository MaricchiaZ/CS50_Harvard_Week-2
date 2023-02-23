/* ************************************************************************** */
/*                                                                            */
/*   By: Maria Clara Zaine - 2022                                             */
/*   Follow-me: github.com/MaricchiaZ                                         */
/*                                                                            */
/* ************************************************************************** */

// Proposta do exercício: Determine qual das duas palavras do Scrabble vale mais.

/*
// No jogo Scrabble, os jogadores criam palavras para marcar pontos, e o número de pontos é a soma dos valores dos pontos de cada letra da palavra.
//A	B	C	D	E	F	G	H	I	J	K	L	M	N	O	P	Q	R	S	T	U	V	W	X	Y	Z
//1	3	3	2	1	4	2	4	1	8	5	1	3	1	1	3	10	1	1	1	1	4	4	8	4	10
*/
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 == score2)
    {
        printf("Tie!");
    }
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    return (0);
}

int compute_score(string word)
{
    int i;
    int sum;
    // TODO: Compute and return score for string
    
    i = 0;
    sum = 0;
    while (word[i])
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            sum = sum + (POINTS[word[i] - 'a']);
        }
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            sum = sum + (POINTS[word[i] - 'A']);
        }
        i++;
    }
    return (sum);
}