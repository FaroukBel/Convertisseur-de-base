#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>


char reVal(int num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

int toDeci(char *str, int base1)
{
    int len = strlen(str);
    int power = 1;
    int num = 0;  
    int i;
    
    // Equivalent de decimale = str[len-1]*1 + str[len-2]*base + str[len-3]*(base^2) + ...
    for (i = len - 1; i >= 0; i--)
    {
        // Verification de la validité du nombre entre au clavier
        if (val(str[i]) >= base1)
        {
           printf("Nombre invalide");
           return -1;
        }
 
        num += val(str[i]) * power;
        power = power * 10;
    }

    return num;
}
// Utility function to reverse a string
void strev(char *str)
{
    int len = strlen(str);
    int i;
    for (i = 0; i < len/2; i++)
    {
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

// Function to convert a given decimal number
// to a base 'base' and
char* fromDeci(char res[], int base1,int base2, char *inputNum)
{
    int i = 0;  // Initialize index of result
    int deci = toDeci(inputNum, base1);
    char str[100];
    
    // Convert input number is given base by repeatedly
    // dividing it by base and taking remainder
    while (deci > 0)
    {
       
        res[i] = reVal(deci % base2);

        deci /= base2;
  
        i++;
    }
    res[i] = '\0';

    strev(res);
    return res;
}

int* saisir( int *taille){
    int i=0, *t ;
    char c, tmp[2];
    c=getchar();
    t=malloc(sizeof(int));
    while(c!='\n'){
        t=(int*)realloc(t,(i+1)*sizeof(int));
        tmp[0]=c;
        t[i]=atoi(tmp);
        i++;
        c = getchar();
    } 
    *taille=i;
    return t ;
 
 }
// Driver program
int main()
{
    char inputNum[] = "25", base1 = 6, base2 = 6;
    char res[100];
    printf("%s\n", inputNum);
    printf("Equivalent of %s in base %d is "
           " %s\n", inputNum, base1, fromDeci(res, base1, base2, inputNum));
    return 0;
}