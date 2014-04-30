#define _Cdecl
void    _Cdecl	__int__   (int interruptnum);

/*
 *  getch()
 *  počká na stisknutie klávesy, vráti jej ASCII hodnotu 
 */ 

char getch() {
  _AX = 0x00;
  __int__(0x16);
  return _AL;
}

/*
 *  putch()
 *  vytiskne ASCII znak
 */ 
void putch(char s) {
  if((s!='\r') && (s!='\n') && (s!='\t') && (s!='\b')) { 
  
  /* farebné netisknú tieto znaky */
    
    _AL = 0;
    _CX = 1;
    _BH = 0;
    _BL = TEXT_COL;
    _AH = 0x09;
    __int__(0x10);
  }
  
  _AL = s;
  _AH = 0x0e;
  _BL = 0x07;
  __int__(0x10);
}
