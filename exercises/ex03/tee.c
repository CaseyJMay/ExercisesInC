#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/*this is my filepath, the second input will require finding the file path of
/* of the file you want to append to */
/* /home/cmay/Documents/ExercisesInC/exercises/ex03/text.txt */

/* The main function covers all of the important
functionality. It allows for the -a tag to be added, Otherwise
it uses its base case and assumes it's writing to a NEW file.*/
int main(int argc, char *argv[]) {
  char Text[40];
  char file_path[100];
  printf("Please enter the text you'd like to tee, and the filepath, one by one, in that order:\n");
  scanf("%s", Text);
  scanf("%s", file_path);
  int ch;
  FILE * fp;
  /* checking for an a flag, a doesn't require any arguments*/
  while((ch = getopt(argc, argv, "a")) != -1)
    switch(ch){
  case 'a':
    printf("%s\n",Text);
     /* open the file for writing*/
     fp = fopen (file_path,"a+");

     /* write the text to the file */
     fprintf (fp, "%s\n", Text);

     /* close the file*/
     fclose (fp);
     break;
  default:
    printf("%s\n",Text);
     /* open the file for writing*/
     fp = fopen (file_path,"w");

     /* write the text to the file */
     fprintf (fp, "%s\n", Text);

     /* close the file*/
     fclose (fp);
     break;
 }
 for(; optind < argc; optind++){
       printf("extra arguments: %s\n", argv[optind]);
   }
  return 0;
}

/* reflection
3. Understanding the documentation of argc and argv was incredibly confusing,
and although I was eventually able to get command line tags to work, I was never
able to get single line input to work! Therefore, I would certainly create a program
that allows text and file_path inputs to be in one line and registers them as extra
arguments next time.

4.  Oh so many differences! The professional code is so much more encompassing of
error cases, and it also does GREAT stuff with memory allocation that I was woefully
ignorant of. Not to mention the professional code has some great use of data structures
that I don't feel like I have enough understanding to implement myself. */
