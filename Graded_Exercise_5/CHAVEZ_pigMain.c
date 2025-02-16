#include "CHAVEZ_pigLatin.c" //replace with your actual filename

int main() {
  longString sentence, result;
  string aWords[MAX], aLatin[MAX], temp;
  int nElem = 0, i;
  char ch;

  i = 0;
  do {
    scanf("%c", &ch);
    if (ch != '\n') {
      sentence[i] = ch;
      i++;
    }
  } while (i < (MAX + 4) * MAX - 1 && ch != '\n');
  sentence[i] = '\0';

  split(aWords, &nElem, sentence);
  printf("\nContents of original sentence:\n");
  display(aWords, nElem);
  printf("word count = %d\n\n", nElem);

  for (i = 0; i < nElem; i++)
    strcpy(aLatin[i], toPigLatin(temp, aWords[i]));

  printf("Per word in pig latin:\n");
  display(aLatin, nElem);

  concatenate(result, aLatin, nElem);
  printf("\n\nConcatenated:\n%s\n", result);
  printf("Number of characters in new sentence: %ld\n", strlen(result));

  return 0;
}
