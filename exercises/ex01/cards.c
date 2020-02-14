#include <stdio.h>
#include <stdlib.h>

/*
this function displays the current card count
it only takes in the argument count of type int
and returns nothing
*/
void current_count(int count) {
  printf("Current count: %i\n", count);
  }

/*
this function is purely for the use of accepting user input
it takes in the "card_name" variable, which allows for 2 digits of char input
*/
void user_input(char card_name[3]){
  puts("Enter the card_name: ");
  scanf("%2s", card_name);
}

/*
this function checks to see whether the counter should increase or Decrease
it decides this based off of card value, which is passed in as int val
this function only returns one value, which is then added to the overall count
*/
int val_check(int val){
  int addition = 0;
  if ((val > 2) && (val < 7)) {
      addition = 1;
  }
  else if (val == 10) {
      addition = -1;
  }
  return addition;
  }

/* the main function, where everything is combined */
int main()
{
  char card_name[3];
  int count = 0;
  int val = 0;
  while (card_name[0]!= 'X'){
    user_input(card_name);
    switch(card_name[0]){
      case 'K':
      case 'Q':
      case 'J':
          val = 10;
          break;
      case 'A':
          val = 11;
          break;
      case 'X':
          continue;
      default:
          val = atoi(card_name);
          if((val < 1)||(val > 10)){
            puts("I don't understand that value!");
            continue;
          }
    }
    /*
    this count uses the return value from val_check to increase or Decrease
    */
    count = count + val_check(val);
    current_count(count);
  }
  return 0;
}
