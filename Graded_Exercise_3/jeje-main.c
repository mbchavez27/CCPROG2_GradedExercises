#include "CHAVEZ_jeje.c"

int 
main()
{
   string input;

   printf("Enter string: ");
   scanf("%s", input);
   
   printf("%s in Jejemon is ", input);
   
   toJejemon(input);
 
   printf("%s\n", input); 

   return 0;
}


