#ifndef MENU_H
#define MENU_H

typedef void (*MenuAction)(void);

typedef struct{
	char* name;
	MenuAction action;
} MenuItem;

typedef enum{
	VERTICAL,
	HORIZONTAL
} MenuOrientation;

typedef struct{
	int index;
	int count;
	MenuItem* items;
	MenuOrientation orientation;
} Menu;

#endif // !MENU_H


