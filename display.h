#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include "conio2.h"
#define NB_LINES 40
#define NB_COLONS 160

void clrscr();

void clrline();

void clrmenu(int length);

void entete();

void pied();

void strprintAnimate(char* str,int ms);

void inErrAnimate(char* str);

void esi_logo();

void reverse_esi_logo(int y);

void titre_logo();

void strprintblink (char* word, int blink_number , int blink_rate);

void strprintblinkkbhit(char* word,int blink_number,int blink_rate);

void intro();

void fade_in(char* word , int speed_ms, char* space);

void fade_out(char* word, int speed_ms);

void loading_page();

#endif
