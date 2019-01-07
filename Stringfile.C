#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define pi 3.14
int calFactorial(int n, int startP)
{
    int rs = 1;
    if (startP == 0) startP = 1;
    for (int i = startP; i <= n; i++)
    {
        rs *= i;
    }
    return rs;
}

char * findFirstName(char *fullName)
{
    int i = strlen(fullName) - 1;
    while (i >= 0 && fullName[i] != ' ') i--;
    return fullName + i + 1;
}

char *findLastName(char *fullName)
{
    char rs[50];
    memset(rs, '\0', sizeof(rs));
    int i = 0;
    while (i <= strlen(fullName) - 1 && fullName[i] != ' ')
    {
        rs[i] = fullName[i];
        i++;
    }
    return rs;
}

char *RTrim(char *str)
{
    for (int i = strlen(str) - 1; str[i] == ' ' || str[i] == '\t'; i--)
    {
        str[i] = '\0';
    }
    return str;
}

char *LTrim(char *str)
{
    int i = 0, j = 0;
    char a[80] = "\0";
    for (i = 0; str[i] == ' ' || str[i] == '\t'; i++);
    while (str[i] != '\0')
    {
        a[j++] = str[i++];
    }
    strcpy(str, a);
    return str;
}

char* trimBlank(char * str)
{
    RTrim(str);
    LTrim(str);
    for (int i = 1; i < strlen(str) - 1; i++)
    {
        if (str[i] == '\t') str[i] = ' ';
        if (str[i] == ' ' && str[i - 1] == ' ')
        {
            memmove(&str[i], &str[i + 1], strlen(str) - i);
            i--;
        }
    }
    return str;
}

void reverseString(char *str)
{
    int i = 0, j = strlen(str) - 1;
    while (i < j)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    char *name = (char*)malloc(80 * sizeof(char));
    gets(name);
    puts(name);
    name = trimBlank(name);
    puts(name);
    printf("\nfirst name is: %s", findFirstName(name));
    printf("\nlast name is: %s\n", findLastName(name));
//    name = trimBlank(name);
    puts(name);
    reverseString(name);
    puts(name);
    free(name);
}
