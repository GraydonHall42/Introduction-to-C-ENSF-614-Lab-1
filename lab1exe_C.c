/*
 * lab1exe_C.c
 * ENSF 614 Fall 2021 - Lab 1 - Execise C
 * An exercise to help you understand the use of pointer variables.
 */

#include <stdio.h>

int main(void)
{
  int foo; 
  int bar;
  int *fred;
  int *sam;

  bar = 100;
  foo = 200;
  fred = &foo;  // fred is pointer for foo

  /* point one */

  printf("point one: foo is %d and bar is %d.\n", foo, bar);
  sam = &bar;  // sam is pointer for bar
  *sam += 30;  // bar increased by 30
  *fred -= 40;  // fred decreased by 40

  /* point two */

  printf("point two: foo is %d and bar is %d.\n", foo, bar);
  fred = &bar;  // fred is now pointer for bar
  *fred += 5;  // bar is increased by 5

  /* point three */

  printf("point three: foo is %d and bar is %d.\n", foo, bar);
  printf("point three: *fred is %d and *sam is %d.\n", *fred, *sam);
  sam = &foo;  // sam is now pointer for foo
  *sam = *fred;  // foo becomes equal to bar

  /* point four */

  printf("point four: foo is %d and bar is %d.\n", foo, bar);
  *sam *= 100;  // foo multiplied by 100
  sam = fred;  //  sam now same as fred

  /* point five */

  printf("point five: foo is %d and bar is %d.\n", foo, bar);
  printf("point five: *fred is %d and *sam is %d.\n", *fred, *sam);  

  return 0;
}
