#include "intarray.h"
#include "fMatrix.h"

int main()
{
    /*
    char str[256] = "1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9"; // valid
    printf("%d\n", checkCStrMatrix(str));

    char str1[256] = "1.1,22.,3.3,4.4,5.5,6.6,7.7,8.8,9.9"; // a token ends in '.'
    printf("%d\n", checkCStrMatrix(str1));

    char str2[256] = "1.1,2..2,3.3,4.4,5.5,6.6,7.7,8.8,9.9"; // two '.'
    printf("%d\n", checkCStrMatrix(str2));

    char str3[256] = "1.1,.22,3.3,4.4,5.5,6.6,7.7,8.8,9.9"; // leading '.'
    printf("%d\n", checkCStrMatrix(str3));

    char str4[256] = "1.1,2.2,3.3,4.4,5a.5,6.6,7.7,8.8,9.9"; // a non-number char
    printf("%d\n", checkCStrMatrix(str4));

    char str5[256] = "1.1,2.2,3.3,4.4,,5.5,6.6,7.7,8.8,9.9"; // two ','
    printf("%d\n", checkCStrMatrix(str5));

    char str6[256] = "1.1,2.2,3.3,4.4,6.6,7.7,8.8,9.9"; // only 8 floats (missing one)
    printf("%d\n", checkCStrMatrix(str6));

    char str7[256] = "1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10"; // 10 floats (one extra)
    printf("%d\n", checkCStrMatrix(str7));

    char str8[256] = ",1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9"; // leading ',' in the very beginning
    printf("%d\n", checkCStrMatrix(str8));

    char str9[256] = "1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,"; // trailing ',' at very end
    printf("%d\n", checkCStrMatrix(str9));

    char str10[256] = ".1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9"; // leading '.' in the very beginning
    printf("%d\n", checkCStrMatrix(str10));

    char str11[256] = "1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9."; // trailing '.' at very end
    printf("%d\n", checkCStrMatrix(str11));
    */

    /*
    fMatrix *m = createMatrix(0.0f);
    printMatrix(m);
    char str[256] = "1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9";
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
    char dest[256] = {0};
    char src[256] = "hejsan";
    printf("%s\n%s\n", dest, src);
    copyStr(dest, src);
    printf("\n%s\n%s\n", dest, src);
    */
}
