#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

void sleep(short seconds);
void G(char s[], short amount);
void header(char text[]);
void line();

// Structs //
struct Peza{
	unsigned long long int logins;
	unsigned long long int money;
	unsigned long long int earn;
	unsigned long long int promotion;
	unsigned short energy;
	unsigned short rest;
	unsigned short stop;

	unsigned long long int orders;
	unsigned long long int pizzas;
	unsigned long long int boxes;
	unsigned long long int deliveries;
};

// Main //
int main(void){
  header("PanikHub");
  printf("Type in H for a list of commands!\n\n");
  srand((unsigned) time(NULL));

  char select;
  bool running = true;
  char input;
  bool gameRunning = true;

  while(running){
    printf("Game > ");
    scanf(" %c", &select);
    select = toupper(select);

    switch(select){
      case '1': // Peza!
        header("Peza!");
	printf("Type in H for a list of commands!\n\n");
	
	// Load data //
	struct Peza peza;
	char data[1000];
	
	FILE* loginFile = fopen("data/pezaLogin.txt", "a+");
	fgets(data, 1000, loginFile);
	peza.logins = atoi(data);
	peza.logins++;

	FILE* moneyFile = fopen("data/pezaMoney.txt", "a+");
	fgets(data, 1000, moneyFile);
	peza.money = atoi(data);
	fclose(moneyFile);
	
	FILE* energyFile = fopen("data/pezaEnergy.txt", "a+");
	fgets(data, 1000, energyFile);
	peza.energy = atoi(data);
	fclose(energyFile);

	FILE* earnFile = fopen("data/pezaEarn.txt", "a+");
	fgets(data, 1000, earnFile);
	peza.earn = atoi(data);
	fclose(earnFile);

	FILE* promFile = fopen("data/pezaProm.txt", "a+");
	fgets(data, 1000, promFile);
	peza.promotion = atoi(data);
	fclose(promFile);

	FILE* delFile = fopen("data/pezaDelivery.txt", "a+");
	fgets(data, 1000, delFile);
	peza.deliveries = atoi(data);
	fclose(delFile);

	switch(peza.logins){
	  case 1:
	    peza.money = 0;
	    peza.energy = 100;
	    peza.earn = 10;
	    peza.promotion = 50;
	    peza.deliveries = 0;
            break;
	}
	fclose(loginFile);

	peza.orders = 0;
	peza.pizzas = 0;
	peza.boxes = 0;

	while(gameRunning){
		printf("Action > ");
		scanf(" %c", &input);
		input = toupper(input);

		switch(input){
		  case '0': // Stats
		    printf("Logins: %lld\n", peza.logins);
		    printf("Money: $%lld\n", peza.money);
		    printf("Earn: $%lld\n", peza.earn);
		    printf("Promotion cost: $%lld\n", peza.promotion);
		    printf("Energy: %d\n\n", peza.energy);

		    printf("Orders: %lld\n", peza.orders);
		    printf("Pizzas: %lld\n", peza.pizzas);
		    printf("Boxes: %lld\n", peza.boxes);
		    printf("Deliveries: %lld\n", peza.deliveries);
		    break;
		  case '1': // Order
		    if(peza.energy > 0){
		      printf("Getting customer order...\n");
		      peza.orders++;
		      peza.energy--;
		      sleep(1);
		    
		      printf("Done!\n");
		    }
		    else{
		      printf("You need more energy!\n");
		    }
		    break;
		  case '2': // Cook
		    if(peza.orders > 0 && peza.energy > 0){
		      printf("Cooking pizza...\n");
		      peza.orders--;
		      peza.energy--;
		      peza.pizzas++;
		      sleep(1);

		      printf("Done!\n");
		    }
		    else if(peza.orders <= 0){
		      printf("You need an order to fulfill!\n");
		    }
		    else{
		      printf("You need more energy!\n");
		    }
		    break;
		  case '3': // Cut and box
		    if(peza.pizzas > 0 && peza.energy > 0){
	              printf("Cutting and boxing pizza...\n");
		      peza.pizzas--;
		      peza.energy--;
		      peza.boxes++;
		      sleep(1);

		      printf("Done!\n");
		    }
		    else if(peza.pizzas <= 0){
		      printf("You need a pizza to box!\n");
		    }
		    else{
		      printf("You need more energy!\n");
		    }
		    break;
		  case '4': // Delivery
		    if(peza.boxes > 0 && peza.energy > 0){
                      printf("Deliverying pizza...\n");
		      peza.boxes--;
		      peza.energy--;
		      peza.deliveries++;
		      peza.money += rand() % peza.earn + 1;
		      sleep(1);

		      printf("Done! Type in 0 for stats.\n");
		    }
		    else if(peza.boxes <= 0){
		      printf("You need a pizza box to deliver!\n");
		    }
		    else{
		      printf("You need more energy!\n");
		    }
		    break;
		  case '5': // Rest
		    if(peza.energy < 100){
		      printf("Resting time (0-100) > ");
		      scanf(" %hd", &peza.rest); G("\n", 1);
		      peza.stop = peza.rest + peza.energy;
		      
		      if(peza.rest >= 0 && peza.rest <= 100 && peza.stop <= 100){
		        for(int i = peza.energy; i != peza.stop; i++){
		          printf("Energy: %d/100\n", i + 1);
		          peza.energy++;
			  sleep(0.5);
		        }
		      }
		      else{
		        printf("Invalid amount!\n");
		      }
		    }
		    else{
		      printf("You have enough energy!\n");
		    }
		    break;
		  case 'P': // Promotion
		    if(peza.money >= peza.promotion){
		      printf("Getting promoted...\n");
		      peza.money -= peza.promotion;
		      peza.promotion *= 2;
		      peza.earn *= 2;
		      sleep(1);

		      printf("Successfully promoted!\n");
		      break;
		    }
		    else{
		      printf("You need $%lld more!\n", peza.promotion - peza.money);
		    }
		    break;
		  case 'H':
		    printf("0: Stats\n1: Get customer order\n2: Cook pizza\n");
		    printf("3: Cut and box pizza\n4: Deliver pizza\n5: Rest\nP: Promotion\nL: Exit Peza (SAVES DATA)\n");
		    break;
		  case 'L':
		    printf("Exitting Peza!\n");
		    gameRunning = false;
		    sleep(1);
			
		    // Save data //
		    loginFile = fopen("data/pezaLogin.txt", "w");
	            fprintf(loginFile, "%lld", peza.logins);
	            fclose(loginFile);
	
	            moneyFile = fopen("data/pezaMoney.txt", "w");
	            fprintf(moneyFile, "%lld", peza.money);
	            fclose(moneyFile);

		    energyFile = fopen("data/pezaEnergy.txt", "w");
		    fprintf(energyFile, "%d", peza.energy);
		    fclose(energyFile);

	            earnFile = fopen("data/pezaEarn.txt", "w");
		    fprintf(earnFile, "%lld", peza.earn);
		    fclose(earnFile);

		    promFile = fopen("data/pezaProm.txt", "w");
		    fprintf(promFile, "%lld", peza.promotion);
	 	    fclose(promFile);

		    delFile = fopen("data/pezaDelivery.txt", "w");
		    fprintf(delFile, "%lld", peza.deliveries);
		    fclose(delFile);
		    break;
		}
		line();
	}
	gameRunning = true;
        break;
      case 'H': // Help //
	printf("1. Peza!\n2. Coming soon...\n\nCommands:\nL: Exit\n");
	break;
      case 'L': // Exit
        printf("Exitting PanikHub...\n");
        running = false;

        sleep(1);
	break;
    }
    line();
  }
  return 0;
}

// Functions //
void sleep(short seconds){
  time_t start, end;
  time(&start);

  do(time(&end)); while(end - start <= seconds);
}

void G(char s[], short amount){
  for(int i = 0; i < amount; i++){
    printf("%s", s);
  }
}
void header(char text[]){
  G("-", 50); G("\n", 1);
  printf("-- %s --\n", text);
  G("-", 50); G("\n", 1);
}
void line(){
	G("-", 30); G("\n", 1);
}
