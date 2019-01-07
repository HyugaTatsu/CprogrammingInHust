#include <stdio.h>
#define LINE_LENGTH 80
typedef struct weather{
     int day;
     int month;
     int highestTemp;
     int lowestTemp;
     int dryest;
}Weather;

void strcpy(char dest[], const char source[])
{
    while   ((*dest++ = *source++) != '\0');
}
int main()
{
    FILE *fp = fopen("inputFile.txt", "r");
    if (fp == NULL)
    {
        perror("Can not find File\n");
        return 1;
    }
    char line[LINE_LENGTH];
    int count = 0;
    Weather w[365];
    while (fgets(line, LINE_LENGTH, fp) != NULL)
    {
        if (count == 0) rewind(fp);
        fscanf(fp, "%d/%d %d-%d %d", &w[count].day, &w[count].month, &w[count].lowestTemp, &w[count].highestTemp, &w[count].dryest);
        count++;
    }
    fclose(fp);
    printf("\n%-10s%-10s%-15s%-15s%-15s\n","Day", "Month", "Lowest Temp","Highest Temp","Humid");
    int i;
    for(i = 0; i < count; i++){
        printf("%-10d%-10d%-15d%-15d%-15d\n", w[i].day, w[i].month, w[i].lowestTemp, w[i].highestTemp, w[i].dryest);
    }
    printf("\nFile contains %d lines\n", count);
    return 0;

}
