#include<stdio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>
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
char reVal(int num)
{
    if (num >= 0 && num <= 9) // Verification par code ASCII
        return (char)(num + '0'); // Cast du int en char
    else
        return (char)(num - 10 + 'A');
}

char *deDeci(char res[],char* string){
    int dec = atoi(string);
    printf("%d",dec);
    int i;
    // Convertir un decimale a une base par
    // le deviser plusieurs fois en prenons le reste
    // comme resultat
    while (dec > 0)
    {
        res[i] = reVal(dec % 2);

        dec /= 2;
  
        i++;
    }
    res[i] = '\0';
    // Inverser le reste
    strev(res);
    printf("%s",res);
  
    return res;
}

int main(){
    
    char string[]="52";

    int reste = 1;
    int i = 0;
    int converted = 0;
    int rest;
    int dec = atoi(string);
    char res[100];
    
    if (string[0]=="-")
    {
        printf("fef");
    }
    else
    {

        printf("nombre en binaire:");
    }
    
    
  
    return 0;
}