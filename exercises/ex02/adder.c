#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sum_maker(char* int_array){
  int sum = 0;
  int len = strlen(int_array);
  int i;
  for (i=0; i<len; i++){
    printf(" %d\n",int_array[i]);
    sum += int_array[i];
  }
  printf("Final Sum: %2d\n", sum);
}

char main(){
  char single_int[2];
  char int_array[18];
  // int i;
  int len = strlen(int_array);
  int actual_int;
  int sum;
  // int flag = 0;
  // while(flag != EOF) {
  //   flag = scanf("%s",int_array);
  //   if(flag == EOF) {continue;}
  int i = 0;
  printf("Press Enter to Begin");
  while (fgets(single_int, sizeof(10), stdin)!= NULL) {
    if (i <= 6){
      puts("Enter a single integer");
      scanf("%2s", single_int);
      printf("You entered: %2s\n", single_int);
      actual_int = atoi(single_int);
      int_array[i] = actual_int;
      printf("%d\n", int_array[i]);
      i += 1;
    }
    else {
      break;
    }
    }
  // }
  printf("Final Array: %2s\n", int_array);
  sum_maker(int_array);
  return 1;
}

/*
DISCLAIMER! My function still requires triggering EOF twice to
trigger early adding for some reason. eek!
*/
