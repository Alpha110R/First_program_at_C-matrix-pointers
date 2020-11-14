#include <stdio.h>
#include <string.h>
#include "Q1PicManipulation.h"

int main(void) {
   char menu;
  char* menuPointer=&menu;
  do{
  printf("\nPlease choose one of the following options: \n");
  printf("P/p - Picture Manipulation\n");
  printf("N/n - Number Game\n");
  printf("E/e - Quit\n");
  scanf(" %c", menuPointer);
  switch(menu){
    case 'P': Q1();
        break;
    case 'p': printf("p");
    break;
    case 'N':printf("N");
    break;
    case 'e': printf("asdfsadfasdf");
    break;
    default: printf("Wrong Choice. Enter again");
    break;
  }
  }while(menu!='E' && menu!='e');
  return 0;
}