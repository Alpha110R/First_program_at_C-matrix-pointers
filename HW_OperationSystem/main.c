#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "Q1PicManipulation.h"
#include "Q2NumberGame.h"

int main() {
  srand(time(0));
   char menu;
  char* menuPointer=&menu;
  do{
  printf("\nPlease choose one of the following options: \n");
  printf("P/p - Picture Manipulation\n");
  printf("N/n - Number Game\n");
  printf("E/e - Quit\n");
  scanf(" %c", menuPointer);
  switch(menu){
    case 'P':
    case 'p':
              Q1();
    break;
    case 'N':
              Q2();
    break;
    case 'e':
    case 'E':
        break;
    default: printf("Wrong Choice. Enter again");
    break;
  }
  }while(menu!='E' && menu!='e');
  printf("Thank you for the time");
  printf("\nAlon Ronder");
  return 0;
}