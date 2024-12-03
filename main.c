#include <stdio.h>
#include "settings.h"

int main(void){
	// Header //
	G("\n", 1);
	G("-", 40);
	G("\n", 1);
	printf("-- PanikHub --\n");
	G("-", 40);
	G("\n", 1);

	printf("Welcome to PanikHub! A place for users of low-end devices to enjoy!\n");
	printf("Type in 'H' for a list of games and commands!\n\n");

	// Loop //
	char select;
	bool running = true;

	char input;
	bool appRunning = true;

	while(running){
		printf("Select > ");
		scanf(" %c", &select);
		select = charUpr(select);

		switch(select){
			case '1': // Peza!
				G("\n", 1);
				G("-", 40);
				G("\n", 1);
				printf("-- Peza! --\n");
				G("-", 40);
				G("\n", 2);

				while(appRunning){
					printf("Action > ");
					scanf(" %c", &input);
					input = charUpr(input);

					switch(input){
						case '1':
							printf("Getting");
							break;
						case 'L':
							appRunning = false;
							break;
					}
				}
				appRunning = true;
				printf("Exitting Peza!...\n");
				wait(1);
				break;
			case 'H': // Help
				printf("Games:\n");
				printf("(1) Peza!\n\n");

				printf("Commands:\n");
				printf("(L) Leave\n");
				break;
			case 'L': // Exit
				running = false;
				printf("Exitting PanikHub...\n");
				wait(1);
				break;
			default:
				printf("Invalid input!\n");
		}
		G("-", 30);
		G("\n", 1);
	}
	return 0;
}
