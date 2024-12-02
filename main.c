#include <stdio.h>
#include "settings.h"

int main(void){
	// Header //
	G("\n", 1);
	G("-", 40);
	G("\n", 1);
	printf("-- PanikHub --\n");
	G("-", 40);
	G("\n", 2);

	// Loop //
	char select;
	bool running = true;

	char input;
	bool appRunning = false;

	while(running){
		printf("Select > ");
		scanf(" %c", &select);
		select = charUpr(select);

		switch(input){
			case '1': // Peza!
				
				break;
			case 'L': // Exit
				running = false;
				printf("Exitting...\n");
				wait(1);
				break;
			default:
				printf("Invalid input!\n");
		}
		G("-", 25);
		G("\n", 1);
	}
	return 0;
}
