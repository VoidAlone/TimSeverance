#include "Actions.h"
#include <stdio.h>

Action select_action(ActionType type) {
    Action return_action;
    switch (type) {
        case ATTACK:
			//compound literal
            return_action = (Action){
				.type = type,
                .ActionImpl = {.Attack = {.crit_mod = 3.5, .damage = 5}},
                };
            break;
        case DEFEND:
            break;
        case HEAL:
            break;
        case REST:
            break;
        default:
            break;
    }
    return return_action;
}

void execute_action(Action action) {
    switch (action.type){
		case (ATTACK):
			int damage = action.ActionImpl.Attack.damage;
			printf("Dealt %d damage\n", damage);
			break;
		default:
			break;
	}
}
