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
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10}; // tabela contendo os pontos e cada letra do alfabeto

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: "); // recebe a palavra do jogador 1
    string word2 = get_string("Player 2: "); // recebe a palavra do jogador 2

    // Score both words
    int score1 = compute_score(word1); //recebe os pontos do jogador 1
    int score2 = compute_score(word2); // recebe os pontos do jogador 2

    // TODO: Print the winner
    if (score1 == score2) //se fizerem a mesma pontuação
    {
        printf("Tie!");
    }
    if (score1 > score2) // se o jogador 1 fizer mais pontos
    {
        printf("Player 1 wins!");
    }
    if (score1 < score2) // se o jogador 2 fizer mais pontos
    {
        printf("Player 2 wins!");
    }
    return (0); // saímos do programa
}

int compute_score(string word)
{
    int i; // índice que vai percorrer a string
    int sum; // variável que receberá a soma dos pontos das letras da palavra
    // TODO: Compute and return score for string
    
    i = 0; //índice inicia mo zero
    sum = 0; // a soma inicia em zero tb
    while (word[i]) //enquanto tiver caractere para olhar na string
    {
        if (word[i] >= 'a' && word[i] <= 'z') // se fot letra minúscula
        {
            sum = sum + (POINTS[word[i] - 'a']); // somamos os pontos
        }
        if (word[i] >= 'A' && word[i] <= 'Z') // se for letra maiúscula
        {
            sum = sum + (POINTS[word[i] - 'A']); // somamos os pontos
        }
        i++; // seguimos para o próximo caractere
    }
    return (sum); //retornamos a soma
}
