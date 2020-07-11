//
//  innerjoin.c
//
//
//  Created by Junheng on 2020-01-31.
//

#include "innerjoin.h"
#include <stdio.h>
#include <string.h>
#define MAX_STRING_LENGTH 128
#define MAX_ROW_COUNT 100
#define DELIMITER ','

int main(void) {

  char joined_table[MAX_ROW_COUNT][MAX_STRING_LENGTH * 2];
char example_nationalities_table[MAX_ROW_COUNT][MAX_STRING_LENGTH] = {
        "Paco Estrada,Mexico",
        "Joe Armitage,England",
        "Angela Zavaleta,Peru",
        "Nyah Way,Canada",
        "Anya Tafliovich,Ukraine",
        "Brian Harrington,Canada",
        "",                          // <-- Empty string signals end of table
    };
    char example_foods_table[MAX_ROW_COUNT][MAX_STRING_LENGTH] = {
        "Brian Harrington,Avocado Salad",
        "Paco Estrada,Chocolate",
        "Joe Armitage,Chocolate",
        "Angela Zavaleta,Green Eggs",
        "Jack Long,Ham",
        "",                         // <-- Empty string signals end of table
    };
char temp_name_nation [MAX_STRING_LENGTH];
strcpy(temp_name_nation,"");
char char_to_str_nation[2];
char_to_str_nation[1]='\0';

char temp_name_foods [MAX_STRING_LENGTH];
strcpy(temp_name_foods,"");
char char_to_str_foods[2];
char_to_str_foods[1]='\0';


char char_to_str_food[2];
char_to_str_food[1]='\0';

char food[MAX_STRING_LENGTH];
char nations[MAX_STRING_LENGTH];
int counter=0;
for (int i=0; strcmp(example_nationalities_table[i],"")!=0; i++){
  strcpy(nations,example_nationalities_table[i]);
  for (int j=0; example_nationalities_table[i][j]!=DELIMITER; j++){
    char_to_str_nation[0]=example_nationalities_table[i][j];
    strcat(temp_name_nation, char_to_str_nation);
 
  for (int k=0; strcmp(example_foods_table[k],"")!=0; k++){
    for(int l=0;example_foods_table[k][l]!=DELIMITER;l++){
          char_to_str_foods[0]=example_foods_table[k][l];
          strcat(temp_name_foods, char_to_str_foods);
    for(int m=l;m!='\0';m++){
      char_to_str_food[0]=example_foods_table[k][m];
      strcat(food, char_to_str_food);
           
            }


    if (strcmp(temp_name_foods, temp_name_nation)==0){
      strcat(nations,food);

   
   strcpy(joined_table[counter],nations);
   counter++;
 
  }

 
  }
}
}


}


printf("%s",joined_table[0]);
  return 0;

}





















































