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
            printf("%8.2f", *m[r][c]);
        }
        printf("\n");
    }
}

bool getMatrix(fMatrix *m)
{
    char str[SIZE - 1] = {0};
    scanf("%s", str);
    char originalStr[SIZE - 1] = {0}; // all the ',' in str gets set to '\0' for some reason, messes with extractFloats()
    copyStr(originalStr, str);        // copies the str entered by user
    if (checkCStrMatrix(str))
    {
        extractFloats(m, originalStr);
        return true;
    }
    else
    {
        return false;
    }
}

bool checkCStrMatrix(char *str)
{
    size_t size = strlen(str);
    if (*str == ',' || *str == '.' || str[size - 1] == ',' || str[size - 1] == '.') // checks first and last element
    {
        return false;
    }

    for (size_t i = 1; i < size - 1; i++) // initial check for dual commas
    {
        if (str[i] == ',' && str[i + 1] == ',') // "1,2,,3" counts as 3 tokens, not 4, hence this loop is needed
        {
            return false;
        }
    }

    size_t tokenCount = 0;
    char *token = strtok(str, ",");
    while (token) // extract all tokens and check them one by one
    {
        tokenCount++;
        if (!checkCStrMatrixToken(token)) // check each token
        {
            return false;
        }
        token = strtok(NULL, ",");
    }

    if (tokenCount != ROWS * COLS) // and if there is correct # of floats
    {
        return false;
    }
    return true;
}

bool checkCStrMatrixToken(const char *str) // a token will never contain ','
{
    size_t size = strlen(str);
    if (*str == '.' || str[size - 1] == '.') // checks the first and last element
    {
        return false;
    }

    size_t dotCounter = 0;
    for (; *str != '\0'; str++)
    {
        if (*str == '.')
        {
            dotCounter++;
            if (dotCounter > 1)
            {
                return false;
            }
        }
        // if non-digit, only '.' is valid             a '.' must be surrounded by a digit on both sides
        if ((!isdigit(*str) && (*str != '.')) || ((*str == '.') && (!isdigit(*(str - 1)) || !isdigit(*(str + 1)))))
        {
            return false;
        }
    }
    return true;
}

void extractFloats(fMatrix *m, char *str)
{
    size_t index = 0;                       // 0 1 2   -> 0
    char *strPtr = str;                     // 3 4 5   -> 1
    for (; *strPtr != '\0'; str++, index++) // 6 7 8   -> 2
    {
        switch (index)
        {
        case 0:
        case 1:
        case 2:
            *m[0][index] = strtod(str, &strPtr); // no need to check if strtod returns 0 since str is already verified
            break;
        case 3:
        case 4:
        case 5:
            *m[1][index % 3] = strtod(str, &strPtr);
            break;
        default: // 6, 7, 8
            *m[2][index % 3] = strtod(str, &strPtr);
            break;
        }
        str = strPtr;
    }
}

void copyStr(char *dest, char *src)
{
    for (; *src != '\0'; src++, dest++)
    {
        *dest = *src;
    }
}