#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char reVal(int num)
{
    if (num >= 0 && num <= 9)     // Verification par code ASCII
        return (char)(num + '0'); // Cast du int en char
    else
        return (char)(num - 10 + 'A');
}

int val(char c)
{
    if (c >= '0' && c <= '9') // Verification par code ASCII
        return (int)c - '0';  // Cast du char en int
    else
        return (int)c - 'A' + 10;
}
// Fonction pour convertir un nombre d'une base au décimale
int aDeci(char *str, int base1)
{
    int len = strlen(str);
    int power = 1;
    int num = 0;
    int i;

    // Equivalent de decimale = str[len-1]*1 + str[len-2]*base + str[len-3]*(base^2) + ...
    for (i = len - 1; i >= 0; i--)
    {
        num += val(str[i]) * power;
        power = power * base1;
    }

    return num;
}
// Fonction pour inverser une chaine de char
void strev(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

// Fonction pour convertir un décimale
// a une base (base2)
char *deDeci(char res[], int base1, int base2, char *inputNum)
{
    int i = 0; // Initiation d'index
    int deci = aDeci(inputNum, base1);

    // Convertir un decimale a une base par
    // le deviser plusieurs fois en prenons le reste
    // comme resultat
    while (deci > 0)
    {
        res[i] = reVal(deci % base2);

        deci /= base2;

        i++;
    }
    res[i] = '\0';

    // Inverser le reste
    strev(res);

    return res;
}

// Program main
int main()
{

    char nbr[1000];
    int base1, base2;
    char res[1000]; // Initiation du resultat de conversion du decimale au bases
    int len = strlen(nbr);
  
    
    // Saisie

    printf("Donner le nombre: ");
    scanf("%s", nbr);

    printf("Donner son base: ");
    scanf("%d", &base1);

    for (int i = len - 1; i >= 0; i--)

    {
        // Verification de la validité du nombre entre au clavier
        if (val(nbr[i]) >= base1)
        {
            printf("Nombre invalide");
            return -1;
        }
    }

    printf("Donner la base desire: ");
    scanf("%d", &base2);
    // Resultat
    printf("L equivalent de %s en base %d est "
           " %s\n",
           nbr, base2, deDeci(res, base1, base2, nbr));

    return 0;
}