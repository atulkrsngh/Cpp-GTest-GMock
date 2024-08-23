#include "triangle.h"
/* Return values
* 1 for equilateral, 2 for isosceles, 3 for scalan
* 0 if triangle can't be formed with given sides
* -1 if any side value is invalid, say -ve
*/
int TypeOfTriangle(int a, int b, int c) {
    if (a < 0 || b < 0 || c < 0) 
        return -1;
    if (!(a + b > c && b + c > a && a + c > b))
        return 0;
    else if (a == b && b == c)
        return 1;
    else if (a == b || b == c || c == a)
        return 2;
    else // a!=b && b!=c && c!=a
        return 3;
}