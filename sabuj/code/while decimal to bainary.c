# include <stdio.h>
# include <conio.h>
int main()
{
 int b[20], n, r, c = 0, i ;
 printf("Enter a decimal number : ") ;
 scanf("%d", &n) ;
 while(n > 0)
 {
  r = n % 2 ;
  b[c] = r ;
  n = n / 2 ;
  c++ ;
 }
 printf("\nThe binary equivalent is : ");
 for(i = c - 1 ; i >= 0 ; i--)
  printf("%d", b[i]) ;
 getch() ;
}
