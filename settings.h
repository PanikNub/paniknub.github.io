#ifndef SETTINGS_H
#define SETTINGS_H

#include <time.h>

// Boolean definition //
#define true 1
#define false 0
typedef char bool;

void wait(short seconds){
	time_t start, end;
	time(&start);

	do(time(&end)); while(end - start <= seconds);
}
char charUpr(char c){
	if(c != '\0' && c >= 'a' && c <= 'z'){
		c -= 32;
	}
	return c;
}
void G(char* c, unsigned short amount){ // Output graphics 
	for(int i = 0; i < amount; i++){
		printf("%s", c);
	}
}

struct Peza{
	unsigned long long int money;
	unsigned long long int earn;
	unsigned long long int promotion;

	unsigned long long int orders;
	unsigned long long int pizzas;
	unsigned long long int boxes;
	unsigned long long int deliveries;
};

#endif
