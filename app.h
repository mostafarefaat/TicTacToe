#ifndef APP_H_
#define APP_H_

#include <stdio.h>
#include <stdlib.h>

#define Player_1    'X'
#define Player_2    'O'
#define No_Winner   'N'
#define Not_Empty    0xFF
#define Invalid_Cell 0xFE

int app(void);
int get_player_input(void);
char judge(void);
void render_playground(void);

#endif
