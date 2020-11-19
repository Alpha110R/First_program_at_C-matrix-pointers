#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "Q2HelpFunc.h"
void initMatQ2(int* mat, int sizeRow, int sizeCol)
{
  for(int i=0 ; i<sizeRow*sizeCol ; i++)
  {
    if(i==(sizeRow*sizeCol-1)) *(mat+i)=0;
     else{
          *(mat+i) = i+1;
     } 
  }
}