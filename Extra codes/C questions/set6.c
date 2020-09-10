int main()
{
	char a[2][3][3] = {'a','b','c','d','e','f','g',
						'h','i','j','k','l','m'};
	printf("%s \n", **a);

    printf("%c ", a[0][0][0]);  //  a[] [][]  == array of 2d array
    printf("%c ", a[0][0][1]);
    printf("%c ", a[0][0][2]);
    printf("%c ", a[0][1][0]);
    printf("%c ", a[0][1][1]);
    printf("%c ", a[0][1][2]);
    printf("%c ", a[0][2][0]);
    printf("%c ", a[0][2][1]);
    printf("%c ", a[0][2][2]);
    printf("%c ", a[1][0][0]);
    printf("%c ", a[1][0][2]);
    printf("%c ", a[1][1][0]);
	return 0;
}
