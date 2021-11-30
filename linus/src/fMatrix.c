#include "fMatrix.h"

fMatrix *createMatrix(float f)
{
    fMatrix *m = (fMatrix *)calloc(ROWS * COLS, sizeof(float));
    if (m == NULL)
    {
        puts("Error: failed to allocate memory.");
        return NULL;
    }

    for (size_t r = 0; r < ROWS; r++)
    {
        for (size_t c = 0; c < COLS; c++)
        {
            *(m[r][c]) = f;
        }
    }
    return m;
}

void destroyMatrix(fMatrix *m)
{
    if (m != NULL)
    {
        free(m);
        m = NULL;
    }
}

void printMatrix(const fMatrix const *m)
{
    if (m == NULL)
    {
        return;
    }

    for (size_t r = 0; r < ROWS; r++)
    {
        for (size_t c = 0; c < COLS; c++)
        {
            printf(" %.2f ", *m[r][c]);
        }
        printf("\n");
    }
}

bool getMatrix(fMatrix *m)
{
}

bool checkCStrMatrix(char *str)
{
    if (*str == ',' || *str == '.') // checks the first element
    {
        return false;
    }

    size_t size = strlen(str);
    for (size_t i = 1; i < size - 1; i++) // initial check for dual commas
    {
        if (str[i] == ',' && str[i + 1] == ',') // "1,2,,3" counts as 3 tokens, not 4, hence this loop is needed
        {
            return false;
        }
    }

    char *token = strtok(str, ",");
    while (token)
    {
        printf("token: %s\n", token);
        if (!checkCStrMatrixSubstr(token))
        {
            return false;
        }
        token = strtok(NULL, ",");
    }

    if (str[size] == ',' || str[size] == '.') // checks the last element before SENTINEL
    {
        return false;
    }

    return true;
}

bool checkCStrMatrixSubstr(const char *str)
{
    size_t dotCounter = 0; // a token will never contain ','
    for (; *str != '\0'; str++)
    {
        if (*str == '.')
        {
            dotCounter++;
        }

        if ((!isdigit(*str) && (*str != '.')) || ((*str == '.') && !isdigit(*(str - 1))))
        {
            return false;
        }
    }
    if (dotCounter > 1)
    {
        return false;
    }
    return true;
}

void extractFloats(fMatrix m, char *str)
{
}