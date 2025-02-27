#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 20
#define MAX_BILLS 10

typedef char String25[26];

typedef struct {
  String25 firstName;
  String25 lastName;
  String25 middleInitial;
} Name;

typedef struct {
  int month;
  int year;
  int day;
} Date, Birthday;

typedef struct {
  String25 name;
  Date date;
} Bill;

typedef struct {
  float confidenceVotes;
  float possibleVotes;
  float percentage;
  String25 orgName;
  Date date;
} Rating;

typedef struct {
  Name name;
  String25 position;
  String25 party;
  Bill billsPassed[MAX_BILLS];
  int numOfBillsPassed;
  Birthday birthday;
  Rating rating;
} Candidate;

void toLower(char *word) {
  int length = strlen(word);
  int i = 0;

  for (i = 0; i < length; i++) {
    if (word[i] >= 'A' && word[i] <= 'Z')
      word[i] += 32;
  }
}

void convertMonthtoWord(int month) {
  switch (month) {
  case 1:
    printf("January");
    break;
  case 2:
    printf("February");
    break;
  case 3:
    printf("March");
    break;
  case 4:
    printf("April");
    break;
  case 5:
    printf("May");
    break;
  case 6:
    printf("June");
    break;
  case 7:
    printf("July");
    break;
  case 8:
    printf("August");
    break;
  case 9:
    printf("September");
    break;
  case 10:
    printf("October");
    break;
  case 11:
    printf("November");
    break;
  case 12:
    printf("December");
    break;
  }
}

void getName(Name *name) {
  char nameInput[26];
  printf("Give Candidate First Name: ");
  scanf("%s", nameInput);
  strcpy(name->firstName, nameInput);
  printf("Give Candidate Middle Intial: ");
  scanf("%s", nameInput);
  strcpy(name->middleInitial, nameInput);
  printf("Give Candidate Last Name : ");
  scanf("%s", nameInput);
  strcpy(name->lastName, nameInput);
}

void getDate(Date *date) {
  int numDate;

  printf("Give Year: ");
  scanf("%d", &numDate);
  date->year = numDate;
  printf("Give Month: ");
  scanf("%d", &numDate);
  date->month = numDate;
  printf("Give Day: ");
  scanf("%d", &numDate);
  date->day = numDate;
}

void getBill(Bill *bill) {
  String25 input;

  printf("Give Bill Name: ");
  scanf("%s", input);
  strcpy(bill->name, input);

  printf("Give Bill Date:\n");
  getDate(&bill->date);
}

void getRating(Rating *rating) {
  String25 input;
  int inputInt;

  printf("Give Confidence Votes: ");
  scanf("%d", &inputInt);
  rating->confidenceVotes = inputInt;

  printf("Give Possible Votes: ");
  scanf("%d", &inputInt);
  rating->possibleVotes = inputInt;

  rating->percentage = rating->confidenceVotes / rating->possibleVotes;

  printf("Give Organization Name: ");
  scanf("%s", input);
  strcpy(rating->orgName, input);

  printf("Give Date of Survey:\n");
  getDate(&rating->date);
}

void getInput(Candidate *candidate) {
  int i = 0;
  int stop = 0;
  String25 input;

  printf("Give Candidate Name:\n");
  getName(&candidate->name);

  printf("Give Candidate Birthday:\n");
  getDate(&candidate->birthday);
  printf("Give Position: ");
  scanf("%s", input);
  strcpy(candidate->position, input);
  printf("Give Party: ");
  scanf("%s", input);
  strcpy(candidate->party, input);
  while (i < MAX_BILLS && !stop) {
    char input[2];
    getBill(&candidate->billsPassed[candidate->numOfBillsPassed]);
    candidate->numOfBillsPassed++;
    printf("Add again: [y/n]");
    scanf(" %c", input);
    if (input[0] == 'n')
      stop = 1;
  }
  getRating(&candidate->rating);
  printf("\n\n");
}

void displayDate(Date date) {
  convertMonthtoWord(date.month);
  printf(" %d, %d\n", date.day, date.year);
}

void displayBill(Bill bill[], int numOfBillsPassed) {
  int i = 0;
  for (i = 0; i < numOfBillsPassed; i++) {
    printf("Bill Passed: %s\n", bill[i].name);
    printf("Date Passed: ");
    displayDate(bill[i].date);
  }
}

void display(Candidate candidate) {
  printf("Candidate: \n");
  printf("Name: %s %s. %s\n", candidate.name.firstName,
         candidate.name.middleInitial, candidate.name.lastName);
  printf("Birthday: ");
  displayDate(candidate.birthday);
  printf("Position: %s\n", candidate.position);
  printf("Party: %s\n", candidate.party);
  displayBill(candidate.billsPassed, candidate.numOfBillsPassed);
  printf("Number of Bills Passed: %d\n", candidate.numOfBillsPassed);
  printf("Rating:\n");
  printf("Confidence Votes: %.2f%%\n", candidate.rating.confidenceVotes);
  printf("Possible Votes: %.2f%%\n", candidate.rating.possibleVotes);
  printf("Percentage: %.2f%%\n", candidate.rating.percentage);
  printf("Organization who Administered the Survey: %s\n",
         candidate.rating.orgName);
  displayDate(candidate.rating.date);
  printf("\n\n");
}

void swapCandidates(Candidate *candidate1, Candidate *candidate2) {
  Candidate temp = *candidate1;
  *candidate1 = *candidate2;
  *candidate2 = temp;
}

int main() {
  Candidate candidates[MAX_CANDIDATES];
  int numOfCandidates = 0;
  int input;

  do {
    printf("Candidates Menu\n");
    printf("1. Add Candidate Info\n");
    printf("2. Display All candidates\n");
    printf("3. Display by Rating\n");
    printf("4. Display by Party\n");
    printf("5. Exit\n");
    printf("\n");
    printf("Give Action: ");
    scanf("%d", &input);
    printf("\n\n");

    switch (input) {
    case 1:
      getInput(&candidates[numOfCandidates]);
      numOfCandidates++;
      break;

    case 2:
      int i = 0;
      for (i = 0; i < numOfCandidates; i++) {
        display(candidates[i]);
      }
      break;

    case 5:
      printf("GoodBye!\n");
      break;
    default:
      printf("Invalid Option!\n");
      break;
    }
  } while (input != 5);

  return 0;
}
