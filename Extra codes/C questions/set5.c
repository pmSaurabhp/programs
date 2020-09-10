#include<stdio.h>
int main()
{

    int a = 5, b = 9;

    printf("a<<1 = %d\n", a<<1);  // left shift x<<y  =  x*(2^y)
    printf("b<<1 = %d\n", b>>1);  // right shift x>>y  = x/(2^y)
    // left shift and right shift are only applied on integers not in -ve , float

    enum{i,j,k};  // i=0 j=1 k=2  are initialised
                  // enum are constants they cannot be modified i++ will give error
    printf("%d %d %d",i,j,k);

    return 0;
}
