// #include "minitalk.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int *ft_dec_to_bin(int nbr)
{
    int *array_int;
    int *temp_array;
    int i;
    int j;
    int k;
    int dividende;
    int diviseur;
    int quotient;
    int mod;

    array_int = malloc(sizeof(int) * 1000000);
    if(!array_int)
        write(1, "Error\n", 6);
    dividende = nbr;
    diviseur = 2;
    quotient = 42;
    i = 0;
    while (quotient != 0)
    {
        quotient = dividende / diviseur;
        mod = dividende % diviseur;
        if (dividende > diviseur)
        {
            array_int[i] = mod;
            i++;
            printf("1. array_int[i] = %d | dividende = %d | diviseur = %d | quotient = %d | mod = %d | i = %d\n", array_int[i], dividende, diviseur, quotient, mod, i);
        }
        if (dividende < diviseur)
        {
            i++; // semble parfois donner des résultats différents en fonction de si je commente ou pas
            array_int[i] = dividende % diviseur;
            printf("2. array_int[i] = %d | dividende = %d | diviseur = %d | quotient = %d | mod = %d | i = %d\n", array_int[i], dividende, diviseur, quotient, mod, i);
            printf("END : array_int[idx] = %d %d %d %d %d %d %d %d %d %d | i = %d\n", array_int[0], array_int[1], array_int[2], array_int[3], array_int[4], array_int[5], array_int[6], array_int[7], array_int[8], array_int[9], i);
            return (array_int);
        }
        dividende = quotient;
    }

    return (0);
}

int main(int argc, char *argv[])
{
    //ft_dec_to_bin(7);     // 1 1 1 => SANS i++

    //ft_dec_to_bin(8);     // 1 0 0 0 => AVEC i++
    //ft_dec_to_bin(9);     // 1 0 0 1 => AVEC i++
    //ft_dec_to_bin(10);    // 1 0 1 0 => AVEC i++
    //ft_dec_to_bin(11);    // 1 0 1 1 => AVEC i++
    
    //ft_dec_to_bin(12);    // 1 1 0 0 => SANS i++
    //ft_dec_to_bin(13);    // 1 1 0 1 => SANS
    //ft_dec_to_bin(15);    // 1 1 1 1 => SANS

    //ft_dec_to_bin(16);    // 1 0 0 0 0 => AVEC
    //ft_dec_to_bin(17);    // 1 0 0 0 1 => AVEC
    //ft_dec_to_bin(18);    // 1 0 0 1 0 => AVEC
    //ft_dec_to_bin(23);    // 1 0 1 1 1 => AVEC
    
    //ft_dec_to_bin(24);    // 1 1 0 0 0 => SANS
    //ft_dec_to_bin(30);    // 1 1 1 1 0 => SANS
    //ft_dec_to_bin(31);    // 1 1 1 1 1 => SANS

    //ft_dec_to_bin(32);    // 1 0 0 0 0 0 => AVEC
    //ft_dec_to_bin(47);    // 1 0 1 1 1 1 => AVEC

    //ft_dec_to_bin(48);    // 1 1 0 0 0 0 => SANS
    
    // ft_dec_to_bin(97);      // 1 1 0 0 0 0 1 => SANS
    // ft_dec_to_bin(98);      // 1 1 0 0 0 1 0 => SANS
    ft_dec_to_bin(99);      // 1 1 0 0 0 1 1 => SANS

// 97  =   1 1 0 0 0 0 1
// 98  =   1 1 0 0 0 1 0
// 99  =   1 1 0 0 0 1 1
/*
    int *array_int;
    array_int = 9,2,1,8,4;
    reverse_array(array_int, 5);
    // printf("END : array_int[idx] = %d %d %d %d %d\n", array_int[0], array_int[1], array_int[2], array_int[3], array_int[4]);
*/
    return (0);
}


// int *ft_dec_to_bin(int nbr)
// {
//     int *array_int;
//     int i;
//     int dividende;
//     int diviseur;
//     int quotient;
//     int mod;

//     array_int = malloc(sizeof(int) * 1000000);
//     if(!array_int)
//         write(1, "Error\n", 6);
//     dividende = nbr;
//     diviseur = 2;
//     quotient = 42;
//     i = 0;
//     while (quotient != 0)
//     {
//         quotient = dividende / diviseur;
//         printf("quotient = %d\n", quotient);
//         mod = dividende % diviseur;
//         if (dividende > diviseur)
//         {
//             array_int[i] = mod;
//             printf("1. array_int[i] = %d | dividende = %d | diviseur = %d | quotient = %d | mod = %d | i = %d\n", array_int[i], dividende, diviseur, quotient, mod, i);
//             i++;
//         }
//         if (dividende < diviseur)
//         {
//             // i++; // semble parfois donner des résultats différents en fonction de si je commente ou pas
//             array_int[i] = dividende % diviseur;
//             printf("2. array_int[i] = %d | dividende = %d | diviseur = %d | quotient = %d | mod = %d | i = %d\n", array_int[i], dividende, diviseur, quotient, mod, i);
//             printf("END : array_int[idx] = %d %d %d %d %d %d %d %d %d %d | i = %d\n", array_int[0], array_int[1], array_int[2], array_int[3], array_int[4], array_int[5], array_int[6], array_int[7], array_int[8], array_int[9], i);
//             return (array_int);
//         }
//         dividende = quotient;
//         // printf("dividende = %d\n", dividende);
//     }
//     return (0);
// }


/*
int *reverse_array(int *array_int, int size)
{
    int *temp_array;
    int i;
    int j;

    // temp_array = malloc(sizeof(int) * 1000000);
    // if(!temp_array)
    //     write(1, "Error\n", 6);

    i = 0;
    j = size;
    while (i < size)
    {
        temp_array[i] = array_int[j];
        // printf("temp_array[j] = %d | array_int[i] = %d | i = %d | j = %d\n", temp_array[j], array_int[i], i, j);
        i++;
        j--;
    }
    printf("array_int[0] = %d", array_int[0]);
    // printf("END in ft : temp_array[idx] = %d %d %d %d %d %d %d %d %d %d | i = %d | j = %d\n", temp_array[0], temp_array[1], temp_array[2], temp_array[3], temp_array[4], temp_array[5], temp_array[6], temp_array[7], temp_array[8], temp_array[9], i, j);
    return (temp_array);
}
*/