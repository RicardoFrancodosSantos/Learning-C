#include <cs50.h>
#include <stdio.h>

 int main (void)

 {
    char c = get_char(" do you agree?");
      if (c == 'y')
  {
     printf("Agreed");
  }

  else
  {
   printf("Not agreed");
  }

 }