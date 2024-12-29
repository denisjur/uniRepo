// #####################################################################################
// = (Assignment operator. You assign a vlaue)
// x = 5;
// *************************************************************************************
// == (is equal value. It compares two values)
//  If(1 + 2 == 3){
//    Do something because it's true
//  }
// *************************************************************************************
// === (equivalent value and the datatype)
//  if(1 + 2 === "3"){
//    this will be false as "3" would be treated as a string and not an integer / number
//  }
// #####################################################################################

#include <stdio.h>

int main () {
  
  int age;

  printf("How old are you?\n");
  scanf("%d", &age);
  
  if(age >= 18) {
    printf("You are now signed up!\n");
  } else if (age == 0) {
    printf("You can't sign up! You were just born!\n");
  } else if (age < 0) {
    printf("You haven't been born yet!\n");
  } else {
    printf("You are too young!\n");
  };
  return 0;
};





