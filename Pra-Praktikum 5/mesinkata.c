#include <stdio.h>
#include "mesinkata.h"
#include "mesinkarakter.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks() {
   while (currentChar == BLANK) {
    ADV();
   }
}

void STARTWORD() {
  START();
  IgnoreBlanks();

  if (EOP) EndWord = true;
  else {
    EndWord = false;
    ADVWORD();
  }
}

void ADVWORD() {
  IgnoreBlanks();
  if (EOP) {
    EndWord = true;
  }
  else {
    CopyWord();
    IgnoreBlanks();
  }
}

void CopyWord() {
  int i = 0;
  while (i < NMax && !EndWord && !EOP && currentChar != BLANK) {
    currentWord.TabWord[i] = currentChar;
    ADV();
    i++;
  }
  currentWord.Length = i;
}