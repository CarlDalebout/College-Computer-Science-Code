//Author: Carl Dalebout
//File : mystring.h

#ifndef MYSTRING_H
#define MYSTRING_H

int str_len(char []);//find the length of the given array

void str_car(char x[], char y[]);//adds y to x

bool str_cmp(char [], char []); //outputs 0 if the two arrays are the same and 1 if they are different

void str_cpy(char x[], char y[]);//copys y into x

int  str_chr(char [], char);//finds where the first char is and returns its location. if not found will return -1

int  str_str(char [], char []);//find where the first matching string is and returns it location. if not found will return -1.

void str_lower(char x[], char y[]);//Will take y and copy the it to x and lowercase all its letters. 

bool str_tok(char x[], char y[], char d[]);//Will find the first value of d and spilt y into x and y

void str_capitalize(char x[], int i = 0);//Will capitalize the first letter of a word or string

void str_lstrip(char []);//strips the extra spacing from the left of the array

void str_rstrip(char []);//strips the extra spacing from the right of the array

void str_strip(char []);//strips the extra spacing from both the left and right of the array

void str_flip(char []);//takes a char array and flips the letters

#endif
