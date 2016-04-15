#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "MT.h"

#define STR_NUMBER 4
#define N 4

int change_array(int ch_num)
{
  static int i, close_check[N] = {0};

  for(i=0;i<N-1;i++){
    close_check[i] = close_check[i+1];
  }
  close_check[N-1] = ch_num;

  return compare_array(close_check);
}

int compare_array(int cf_array[])
{ 
  int template[N] = {0, 1, 2, 3}, result = 0, i;

  for(i=0;i<N;i++){
    if(template[i] == cf_array[i])
      result += 1;
  }

  if(result == 4)
    return 1;

  return 0;
} 

int main()
{
  char* output_str[STR_NUMBER] = {"‚ ‚ŸO`", "‚±‚±‚ë‚ª", "‚Ò‚å‚ñ‚Ò‚å‚ñ", "‚·‚é‚ñ‚¶‚áO`"};
  int char_number = 0, count = 0;

  init_genrand((unsigned)time(NULL));

  while(change_array(char_number) != 1){
    char_number = genrand_int32() % 4;
    printf("%s", output_str[char_number]);
    count++;
  }
  printf("\n\n‚ ‚ŸO`‚±‚±‚ë‚ª %d ‰ñ‚Ò‚å‚ñ‚Ò‚å‚ñ‚µ‚½‚ñ‚¶‚áO`\n", count);

  return 0;
}
