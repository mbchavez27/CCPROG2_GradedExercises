#include <stdio.h>
#include <string.h>

typedef struct {
  char[26] firstName;
  char[26] lastName;
  char[26] middleInitial;
} Name;

typedef struct {
  int month;
  int year;
  int day;
} Birthday;

typedef struct {
  int month;
  int year;
  int day;
} Date;

typedef struct {
  char[26] name;
  Date date;
} Bill;

typedef struct {
  Name name;
  Birthday birthday;

} Candidate;

typedef struct {
  float confidenceVotes;
  float possibleVotes;
  float percentage = confidenceVotes / possibleVotes;
  char[26] orgName;
  Date date;
} Rating;

void getName(Candidate *candidate) {
  char name;
  printf("Give Candidate Name: ");
  scanf("%s", &name);
  strcpy()
}

int main() { return 0; }
