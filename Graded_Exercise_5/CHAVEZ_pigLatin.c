#include "pig.h"

int isVowel(char aLetter)
{
  char vowels[VOWELS] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  int vowel = 0;
  int isVowel = 0;

  for (vowel = 0; vowel < VOWELS; vowel++)
  {
    if (aLetter == vowels[vowel])
    {
      isVowel = 1;
    }
  }

  return isVowel;
}

void split(string aWords[], int *pElem, longString sentence)
{
  int i = 0;
  int character = 0;
  int word = 0;
  *pElem += 1;
  while (sentence[i] != '\0')
  {
    if (sentence[i] == ' ')
    {
      aWords[word][character] = '\0';
      word++;
      character = 0;
      *pElem += 1;
    }
    else
    {
      aWords[word][character] = sentence[i];
      character++;
    }
    i++;
  }
  aWords[word][character] = '\0';
}

/* Note that the original word should not be modified.
   Apart from placing the pig latin equivalent in result,
   the function also returns the starting address to result.
*/
char *toPigLatin(char *result, char *word)
{
  int i = 0;
  int stop = 0;
  int remove = 0;
  strcpy(result, word);
  if (isVowel(word[0]))
  {
    strcat(result, "way");
  }
  else
  {
    for (i = 0; i < strlen(word) && !stop; i++)
    {
      if (!isVowel(result[i]))
      {
        strcat(result, " ");
        result[strlen(result) - 1] = result[i];
        remove++;
      }
      else
      {
        stop = 1;
      }
    }
    strcat(result, "ay");
    for (i = 0; i < remove; i++)
    {
      result = result + 1;
    }
  }

  return result;
}

/* This function displays the contents of aWords, separating each entry
   in the display with one space.
*/
void display(string aWords[], int nElem)
{
  int i = 0;
  for (i = 0; i < nElem; i++)
  {
    printf("%s ", aWords[i]);
  }
}

/* This function concatenates the contents of aWords into the
   result (thereby forming a new sentence).  Concatenation of
   words is separated by one space after each element of aWords.
*/
void concatenate(longString result, string aWords[], int nElem)
{
  int i = 0;
  strcpy(result, aWords[i]);
  strcat(result, " ");
  for (i = 1; i < nElem; i++)
  {
    strcat(result, aWords[i]);
    strcat(result, " ");
  }
  result[strlen(result) - 1] = '\0';
}
