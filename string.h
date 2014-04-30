/*
 *  putchar()
 *  vytiskne ASCII znak, pokiaľ je vstup 0x08
 *  (backspace), zmaže jeden znak
 */ 

void putchar(char s) {
  if(s == '\b') {          /* backspace alias mazanie v resp. tlačítko na mazanie znakov */
    putch('\b');
    putch(' ');
    putch('\b');
  } else {
    putch(s);
  }  
}


/*
 *  puts()
 *  vstup: ukazovateľ na string, ktorý sa bude tisknúť na výstup 
 *  výstup: void
 */
void puts(const char *str) {
  int i;
  for(i = 0; str[i] != '\0' ; i++) {
    putchar(str[i]);
  } 
}


char *strcpy(char * dest,const char *src) {
char *tmp = dest;
  while ((*dest++ = *src++) != '\0');
    return tmp;
}

char *strcat(char * pDst, const char *pSrc) {
    char *r = pDst;

    while (*pDst != '\0')
        pDst++;

    while ((*pDst++ = *pSrc++) != '\0')
        continue;

    return r;
}


/*
 *  gets() 
 *  vyjme string z klavesnice o maximálnu diaľku <size>,
 *  každý znak zobrazí na monitor
 */ 
 
char *gets(char *cs, int size) {
  unsigned int counter = 0;
  unsigned char c = '\0';
  char *s;

  s = cs;
  while (1) {
  if(counter >= size) break;
  c = getch();
  if(c == '\r') break;
  if(c == '\n') break;
  if(c == '\0') break;
  if(c == '\t') c = ' ';

    if(!(counter == 0 && c == '\b')) {
      putchar(c);
    }
    if( c == '\b' ) {
      if (counter > 0)
      counter--;
    }
    else {
      *(s+(counter++)) = c;
    }
  }
  puts("\r\n");
  *(s+(counter++)) = '\0';
  return s;
}
