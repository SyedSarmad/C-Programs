#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
int main() {

   FILE *fp;
   char ch;
   int a = 0;
   int e = 0;
   int i = 0;
   int o = 0;
   int u = 0;
   char filename[25];
   int consonants = 0;
   int punctuation = 0;
   double numOfChars = 0;
   printf("Enter a file name: ");
   scanf("%s", filename);
   fp = fopen(filename,"r");
   while ((ch = getc(fp)) != EOF)
   {
      ch = tolower(ch);
      if (isalpha(ch)) //checking for consonants
      {
         if(ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
	    consonants++;
      }    	    
      if (ch == 'a')
         a++;
      if (ch == 'e')
         e++;
      if (ch == 'i')
         i++;
      if (ch  == 'o')
         o++;
      if (ch == 'u')
         u++;
      else if (ispunct(ch))
         punctuation++;
          
      numOfChars++;  
   }
   //printing to console
   printf("chars\t\tQuantaties\t\t Percentages\n"); 
   printf("a\t\t%10d\t\t%10.2g%%\n",a,a/numOfChars * 100);
   printf("e\t\t%10d\t\t%10.2g%%\n",e,e/numOfChars * 100);
   printf("i\t\t%10d\t\t%10.2g%%\n",i,i/numOfChars * 100);
   printf("o\t\t%10d\t\t%10.2g%%\n",o,o/numOfChars * 100);
   printf("u\t\t%10d\t\t%10.2g%%\n",u,u/numOfChars * 100);
   printf("Consonants\t%10d\t\t%10.2g%%\n",consonants,consonants/numOfChars * 100);
   printf("Punctuation\t%10d\t\t%10.2g%%\n",punctuation,punctuation/numOfChars * 100);
   fclose(fp);
   
   fp = fopen("output.txt","w"); //writing to the output file
   if(fp == NULL)
   {
      printf("Error, could not create file!");   
      exit(1);             
   }
   
   fprintf(fp,"a\te\ti\to\tu\tconsonants punct\n");
   
   fprintf(fp,"%.2g%%\t%.2g%%\t%.2g%%\t%.2g%%\t%.2g%%\t",a/numOfChars*100,e/numOfChars*100, i/numOfChars*100,
               o/numOfChars*100,u/numOfChars*100);
   fprintf(fp,"%.2g%%\t   %.2g%%\t\n",consonants/numOfChars * 100, punctuation/numOfChars * 100);
   fclose(fp);
   return 0;
}
 
