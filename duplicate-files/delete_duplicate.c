#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    int testCases;
    char number_file[50];
    char input[50];

    FILE *fp;
    // open the file  and read first line for the number of test cases N

    fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Error, File does not exist");
        exit(0);
    }

    // STRING ARRAY AND INTEGER ARRAY TO STORE STRING AND INTEGER VALUE RESPECTIVELY OF EACH TEST CASE
    char strArray[50][50];
    int intArray[20];

    // Read in number of testcases
    fscanf(fp, "%d", &testCases);

    // Print out number of testcases
    printf("%d \n", testCases);

    // READ IN EACH INPUT IN THE FILE, SPLIT IT AND STORE THE STRING IN ONE ARRAY AND THE INTEGER VALUE IN ANOTHER ARRAY

    int a = 0;
    while (fgets(input, sizeof(input), fp))
    {
        char newString[10][10];
        int i, j, count;

        j = 0;
        count = 0;

        for (i = 0; i <= (strlen(input)); i++)
        {
            if (input[i] == ' ' || input[i] == '\0')
            {
                newString[count][j] = '\0';
                count++;
                j = 0;
            }
            else
            {
                newString[count][j] = input[i];
                j++;
            }
        }
        if (count == 2)
        {
            char strRes[50];
            strcpy(strRes, newString[0]);
            strcpy(strArray[a], strRes);

            intArray[a] = atoi(newString[1]);

            a++;
        }
    }

    int lowest_id;
    int comparable;
    int temp;

    // LOOP THROUGH THE STRING ARRAY, COMPARE EACH VALUE WITH THE OTHER VALUES AND GET THE LOWEST VALUE FOR COMPARABLE STRINGS
    for (int i = 0; i < testCases; i++)
    {
        lowest_id = intArray[i];
        for (int j = i + 1; j < testCases; j++)
        {
            comparable = strcmp(strArray[i], strArray[j]);
            if (comparable == 0 && lowest_id > intArray[j])
            {
                lowest_id = intArray[j];
            }
            else if ((strcmp(strArray[i], strArray[j]) != 0) && (intArray[i] > intArray[j]))
            {
                temp = intArray[i];
                intArray[i] = intArray[j];
                intArray[j] = temp;
            }
        }
    }
    for (int j = 0; j < testCases; j++)
    {
        if (comparable != 0)
        {
            printf("%d   ", intArray[j]);
        }
    }
    if (comparable == 0)
    {
        printf("%d  ", lowest_id);
    }

    return 0;
}
