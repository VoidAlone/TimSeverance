#ifndef MENU_H
#define MENU_H

typedef void (*ItemFunc)(void);

typedef struct{
	char* name;
	ItemFunc execute;
} MenuItem;

typedef enum{
	VERTICAL,
	HORIZONTAL
} MenuOrientation;

typedef struct{
	int index;
	int count;
	MenuItem* items; //array
	MenuOrientation orientation;
} Menu;

#endif // !MENU_H


