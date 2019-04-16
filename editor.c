#include <stdio.h>
#include <termios.h>
#include <unistd.h>

/* TextEditor V0.1 */
/*
Commands:
	q - quit

*/

void enableRawMode() {
  struct termios raw;
  tcgetattr(STDIN_FILENO, &raw);
  raw.c_lflag &= ~(ECHO);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main(){
	enableRawMode();
	char c;
  	while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');	//STDIN_FILENO is a file descriptor, defined in unistd as 0. 
}
