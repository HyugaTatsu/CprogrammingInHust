#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX_STRUCT 200
int size_struct_list = 0;
typedef struct
{
    int id;
    char s1[31];
    char s2[60];
    int num1;
} structList;

void viewMenu();
int number_exist_element(structList a[]);
int check_string_as_positive_num(char a[]);
void insert_value_for_list(structList *a, int po);
void initial_list_struct(structList a[]);
void func1(structList *a);
void func2(structList *a);
void func3(structList a[]);
void func4(structList *a);
void func5(structList *a);

int main()
{
    structList stl[MAX_STRUCT];
    initial_list_struct(stl);
    viewMenu();
    printf("Please insert your choice 1-6: ");
    int n;
    char s[10];
    while (1)
    {
        fflush(stdin);
        gets(s);
        if (check_string_as_positive_num(s) == 0)
        {
            printf("Your choice does not exist. Please insert another choice\n");
            continue;
        }
        n = atoi(s);
//        scanf("%d", &n);
        switch (n)
        {
        case 1:
            func1(stl);
            break;
        case 2:
            func2(stl);
            break;
        case 3:
            func3(stl);
            break;
        case 4:
            func4(stl);
            break;
        case 5:
            func5(stl);
            break;
        case 6:
            printf("\n----------Goodbye----------");
            return 0;
        default:
            printf("Your choice does not exist. Please insert another choice\n");
            break;
        }
        viewMenu();
        printf("Please insert your choice: ");
    }
}

void viewMenu()
{
    printf("\n----------Menu----------\n");
    printf("1. Function 1\n");
    printf("2. Function 2\n");
    printf("3. Function 3\n");
    printf("4. Function 4\n");
    printf("5. Function 5\n");
    printf("6. Exit\n");
    printf("------------------------\n");
}

int check_string_as_positive_num(char a[])
{
    int i;
    for (i = 0; i < strlen(a); i++)
    {
       if (!isdigit(a[i])) return 0;
    }
    return 1;
}

void initial_list_struct(structList a[])
{
    int i;
    for (i = 0; i < MAX_STRUCT; i++)
    {
        a[i].id = -1;
        a[i].num1 = 0;
        strcpy(a[i].s1, "");
        strcpy(a[i].s2, "");
    }
}

int number_exist_element(structList a[])
{
    int count = 0, i;
    for (i = 0; i < MAX_STRUCT; i++)
    {
        if (a[i].id == -1) return count;
        count++;
    }
    return count;
}

void insert_value_for_list(structList a[], int po)
{
    a[po].id = po;
    fflush(stdin);
    printf("\nInsert the s1 of %d: ", po);
    gets(a[po].s1);
    printf("\nInsert the num1 of %d: ", po);
    char nS[10];
    do
    {
        fflush(stdin);
        gets(nS);
        if (check_string_as_positive_num(nS) == 0)
        {
            printf("\nThe num1 is invalid. Please insert num1 >= 0: ");
            continue;
        }
//        scanf("%d", &a[po].num1);
        a[po].num1 = atoi(nS);
        if (a[po].num1 <= 0) printf("\nThe num1 is invalid. Please insert num1 >= 0: ");
    } while (a[po].num1 <= 0);
}

//function 1: Input data
void func1(structList *a)
{
    printf("\nInsert the number of list: ");
    int n, i;
    char nS[10];
    do
    {
        fflush(stdin);
        gets(nS);
        if (check_string_as_positive_num(nS) == 0)
        {
            printf("\nThe input is invalid. Please insert data in (1,%d): ", MAX_STRUCT);
            continue;
        }
        n = atoi(nS);
//        scanf("%d", &n);
        if (n < 1 || n > MAX_STRUCT) printf("\nThe input is invalid. Please insert data in (1,%d): ", MAX_STRUCT);
    } while (n < 1 || n > MAX_STRUCT);
    for (i = 0; i < n; i++)
    {
        insert_value_for_list(a, i);
    }
}

//function 2: Add data
void func2(structList *a)
{
    int size = number_exist_element(a);
    do
    {
        if (size < MAX_STRUCT)
        {
            printf("\nPlease insert data for new list:\n");
            insert_value_for_list(a, size);

            size++;
            if (size != MAX_STRUCT)
            {
                printf("\nDo you want to insert one more list(Y/N):\n");
                char c;
                do
                {
                    fflush(stdin);
                    c = getchar();
                    if (c != 'Y' && c != 'N') printf("\nPlease choose again(Y/N): ");
                } while (c != 'Y' && c != 'N');
                if (c == 'N') break;
            }
        }
        // not else because size has increased in the first 'if'
        if (size >= MAX_STRUCT)
        {
            printf("\nThe shop is full of lists. Can not add more lists.\n");
        }
    } while (size < MAX_STRUCT);
}

//function 3: view data
void func3(structList a[])
{
    int size = number_exist_element(a);
    int i;
    if (size > 0)
    {
        printf("#\tString 1                     Num 1\n");
        for (i = 0; i < size; i++)
        {
            printf("%d\t%-30s%d\n", i, a[i].s1, a[i].num1);
        }
    }
    else printf("\nThere is no lists yet.\n");
}

void func4(structList *a)
{

}

void func5(structList *a)
{

}
