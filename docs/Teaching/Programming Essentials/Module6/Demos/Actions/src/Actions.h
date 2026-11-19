
typedef enum ActionType { ATTACK, DEFEND, HEAL, REST } ActionType;

typedef struct Action {
    ActionType type;

    union {
        struct {
            int damage;
            float crit_mod;
        } Attack;

        struct {
            int defense;
        } Defend;

        struct {
            float heal_percent;
        } Heal;

        struct {
            float stamina_percent;
        } Rest;

    } ActionImpl;
} Action;

Action select_action(ActionType type);
void execute_action(Action action);
