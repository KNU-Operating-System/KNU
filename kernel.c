/* 
 * KERNEL - jadro
 */

#include <asm.h>
#include <global.h>
#include <init.h>
#include <string.h>
#include <video.h>

int main(void) {
char cmd[80];
  init();

  while(1) {
    puts("[KNU_Operating_system]/$ ");
    gets(cmd, 79);
    puts("Zadali ste: '");
    puts(cmd);
    puts("'\r\n");
  }
  return 0;
}
