#include "intarray.h"
#include "fMatrix.h"

int main()
{
    /*
    char str[SIZE] = "1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9"; // valid
    printf("%d\n", checkCStrMatrix(str));

    char str1[SIZE] = "1.1,22.,3.3,4.4,5.5,6.6,7.7,8.8,9.9"; // a token ends in '.'
    printf("%d\n", checkCStrMatrix(str1));

    char str2[SIZE] = "1.1,2..2,3.3,4.4,5.5,6.6,7.7,8.8,9.9"; // two '.'
    printf("%d\n", checkCStrMatrix(str2));

    char str3[SIZE] = "1.1,.22,3.3,4.4,5.5,6.6,7.7,8.8,9.9"; // leading '.'
    printf("%d\n", checkCStrMatrix(str3));

    char str4[SIZE] = "1.1,2.2,3.3,4.4,5a.5,6.6,7.7,8.8,9.9"; // a non-number char
    printf("%d\n", checkCStrMatrix(str4));

    char str5[SIZE] = "1.1,2.2,3.3,4.4,,5.5,6.6,7.7,8.8,9.9"; // two ','
    printf("%d\n", checkCStrMatrix(str5));

    char str6[SIZE] = "1.1,2.2,3.3,4.4,6.6,7.7,8.8,9.9"; // only 8 floats (missing one)
    printf("%d\n", checkCStrMatrix(str6));

    char str7[SIZE] = "1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10"; // 10 floats (one extra)
    printf("%d\n", checkCStrMatrix(str7));

    char str8[SIZE] = ",1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9"; // leading ',' in the very beginning
    printf("%d\n", checkCStrMatrix(str8));

    char str9[SIZE] = "1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,"; // trailing ',' at very end
    printf("%d\n", checkCStrMatrix(str9));

    char str10[SIZE] = ".1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9"; // leading '.' in the very beginning
    printf("%d\n", checkCStrMatrix(str10));

    char str11[SIZE] = "1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9."; // trailing '.' at very end
    printf("%d\n", checkCStrMatrix(str11));
    */

    /*
    fMatrix *m = createMatrix(0.0f);
    printMatrix(m);
    char str[SIZE] = "1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9";
    extractFloats(m, str);
    printf("\n");
    printMatrix(m);
    */

    /*
    fMatrix *m = createMatrix(0.0f);
    printMatrix(m);
    printf("%s", "Please enter a comma-seperated list of 9 floats: ");
    getMatrix(m);
    printMatrix(m);

    printf("%s", "Please enter a comma-seperated list of 9 floats: ");
    getMatrix(m);
    printMatrix(m);
    */

    /*
    char dest[SIZE] = {0};
    char src[SIZE] = "hejsan";
    printf("%s\n%s\n", dest, src);
    copyStr(dest, src);
    printf("\n%s\n%s\n", dest, src);
    */

    fMatrix *a = createMatrix(0.0f);
    fMatrix *b = createMatrix(0.0f);

    /*printf("%s", "Please enter a comma-seperated list of 9 floats: ");
    getMatrix(a);
    printMatrix(a);
    
    printf("%s", "Please enter a comma-seperated list of 9 floats: ");
    getMatrix(b);
    printMatrix(b);

    matadd(a, b);
    printf("Result:\n");
    printMatrix(a);

    destroyMatrix(a);
    destroyMatrix(b);*/
}
