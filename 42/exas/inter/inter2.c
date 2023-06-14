#include "libft.h"

/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "nothing" "This sentence hides nothing" | cat -e
nothig$
$>./inter | cat -e
$

Ecrire un programme qui prend deux strings en paramètres, et affiche, sans doublons, les caractères
qui apparaîssent dans les deux strings, dans l'ordre qu'elles apparaissent dans la première string
*/

char    *inter(char *s1, char *s2)
{
    char    *s3;
    char    reservoir[255] = {0};
    int     i;
    int     j;

    i = 0;
    while (s1[i] != '\0')
    {
        while 
        i++;
    }


    return (s3);
}


int main(void)
{
    char    *str1 = "salutations";
    char    *str2 = "utins";
    char    *str3;

    str3 = inter(str1, str2);

    return (0);
}
