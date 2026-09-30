#ifndef ACTION_H
#define ACTION_H

typedef enum{
	TYPE_BOOL,
	TYPE_AXIS1D
} EActionType;

typedef union {
	bool boolean;
	float axis1d;
} UActionValue;

typedef struct{
	char* name;
	EActionType type;
	UActionValue value;
} Action;

#endif // !ACTION_H
