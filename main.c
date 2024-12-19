#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

// For printing chars multiple times
void G(char c[], short amount){
	for(int i = 0; i < amount; i++){
		printf("%s", c);
	}
}
void header(char text[]){
	G("-", 50); G("\n", 1);
	printf("-- %s --\n", text);
	G("-", 50); G("\n", 1);
}

void sleep(short seconds){ // The amount of seconds isn't accurate sadly
	time_t start, end;
	time(&start);

	do(time(&end)); while(end - start <= seconds);
}

// Main //
int main(int argc, char** argv){
	header("PanikHub");
	printf("Type in H for help!\n\n");

	char select;
	bool running = true;

	while(running){
		printf("Game > ");
		scanf(" %c", &select);
		select = toupper(select);

		switch(select){
			case '1':
				
				break;
			case 'H':
				printf("1: Game 1\n\nCommands:\nL: Exit\n");
				break;
			case 'L':
				printf("Exitting PanikHub...\n");
				running = false;
				sleep(1);

				break;
		}
		G("-", 30); G("\n", 1);
	}
	return 0;
}
