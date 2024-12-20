#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

void sleep(short seconds);
void G(char s[], short amount);
void header(char text[]);

// Main //
int main(void){
  header("PanikHub");
  printf("Type in H for a list of commands!\n\n");

  char select;
  bool running = true;

  while(running){
    printf("Game > ");
    scanf(" %c", &select);
    select = toupper(select);

    switch(select){
      case '1': // Peza!
        header("Peza!");
	printf("Type in H for a list of commands!\n\n");
	
	// Load data //
	char data[1000];
	
	FILE* loginFile = fopen("data/pezaLogin.txt", "a+");
	fgets(data, 1000, loginFile);
	unsigned long long int logins = atoi(data);
	logins++;

	FILE* moneyFile = fopen("data/pezaMoney.txt", "a+");
	fgets(data, 1000, moneyFile);
	unsigned long long int money = atoi(data);
	fclose(moneyFile);
	
	FILE* earnFile = fopen("data/pezaEarn.txt", "a+");
	fgets(data, 1000, earnFile);
	unsigned long long int earn = atoi(data);
	fclose(earnFile);

	FILE* promFile = fopen("data/pezaProm.txt", "a+");
	fgets(data, 1000, promFile);
	unsigned long long int promotion = atoi(data);
	fclose(promFile);

	switch(logins){
	  case 1:
	    earn = 10;
	    promotion = 50;
            break;
	}
	fclose(loginFile);

	char input;
	bool gameRunning = true;

	while(gameRunning){
		printf("Action > ");
		scanf(" %c", &input);
		input = toupper(input);

		switch(input){
		  case '0': // Stats
		    printf("Logins: %lld\n", logins);
		    printf("Money: $%lld\n", money);
		    printf("Earn: $%lld\n", earn);
		    break;
		  case 'L':
		    printf("Exitting Peza!\n");
		    gameRunning = false;
		    break;
		}
	}
        break;
      case 'L': // Exit
        printf("Exitting PanikHub...\n");
        running = false;

	// Save data //
	loginFile = fopen("data/pezaLogin.txt", "w");
	fprintf(loginFile, "%lld", logins);
	fclose(loginFile);
	
	moneyFile = fopen("data/pezaMoney.txt", "w");
	fprintf(moneyFile, "%lld", money);
	fclose(moneyFile);

	earnFile = fopen("data/pezaEarn.txt", "w");
	fprintf(earnFile, "%lld", earn);
	fclose(earnFile);

	promFile = fopen("data/pezaProm.txt", "w");
	fprintf(promFile, "%lld", promotion);
	fclose(promFile);

        sleep(1);

	break;
    }
    G("-", 30);
    G("\n", 1);
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
