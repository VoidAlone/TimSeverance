#ifndef MENU_H
#define MENU_H

typedef struct{
	char* name;

} MenuItem;

typedef enum{
	VERTICAL,
	HORIZONTAL
} MenuOrientation;

typedef struct{
	int index;
	int count;
	MenuOrientation orientation;
} Menu;

#endif // !MENU_H


