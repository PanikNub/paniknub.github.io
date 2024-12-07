#include <stdio.h>
#include <stdlib.h>
#include "settings.h"

int main(void){
	srand((unsigned) time(NULL));

	// Header //
	G("\n", 1);
	G("-", 40);
	G("\n", 1);
	printf("-- PanikHub --\n");
	G("-", 40);
	G("\n", 1);

	printf("Welcome to PanikHub! A place for users of low-end devices to enjoy!\n");
	printf("Type in 'H' for a list of games and commands!\n\n");

	// Selection //
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
				G("\n", 1);
				
				printf("Type in 'H' for help!\n\n");
				struct Peza peza = {0, 10, 50, 0, 0, 0, 0};
				
				// Game loop //
				while(appRunning){
					printf("Action > ");
					scanf(" %c", &input);
					input = charUpr(input);

					switch(input){
						case '0': // Stats
							printf("\nMoney: $%lld\n", peza.money);
							printf("Can earn up to: $%lld\n", peza.earn);
							printf("Current promotion cost: $%lld\n\n", peza.promotion);

							printf("Orders: %lld\n", peza.orders);
							printf("Pizzas: %lld\n", peza.pizzas);
							printf("Boxes: %lld\n", peza.boxes);
							printf("Deliveries: %lld\n", peza.deliveries);
							break;
						case '1': // Order
							printf("Getting customer order...\n");
							peza.orders++;
							wait(1);

							printf("Done!\n");
							break;
						case '2': // Cook //
							printf("Cooking pizza...\n");
							peza.pizzas++;
							peza.orders--;
							wait(1);

							printf("Done!\n");
							break;
						case '3': // Box and cut //
							printf("Boxing and cutting pizza...\n");
							peza.boxes++;
							peza.pizzas--;
							wait(1);

							printf("Done!\n");
							break;
						case '4': // Deliver //
							printf("Delivering pizza...\n");
							peza.deliveries++;
							peza.boxes--;
							peza.money += rand() % peza.earn + 1;
							wait(1);

							printf("Done!\n");
							printf("Type in '0' for stats!\n");
							break;
						case 'P': // Promotion
							if(peza.money >= peza.promotion){
								peza.money -= peza.promotion;
								peza.earn *= 2;
								peza.promotion *= 2;
								printf("Getting promoted...\n");
								
								wait(1);
								printf("Successfully promoted!\n");
							}
							else{
								printf("You need $%lld more!\n", peza.promotion - peza.money);
							}
							break;
						case 'H':
							printf("(0): See your player stats\n");
							printf("(1): Get customer order\n(2): Cook pizza\n");
							printf("(3): Box and cut pizza\n(4): Deliver pizza\n");
							printf("\nObjective: Deliver as much pizza and earn as much money as possible!\n");
							break;
						case 'L':
							appRunning = false;
							break;
					}
					G("-", 30);
					G("\n", 1);
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
