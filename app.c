#include "app.h"

int Playground[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};


int app(void){
    printf("Welcome To Tic-Tac-Toe\n");
    printf("Good Luck !!\n");

    int empty_cells = 9;
    char Winner = No_Winner;
    char current_player = Player_1;
    int choice = 0;
    int msg = 0;

    while(empty_cells != 0){
        Winner = judge();
        render_playground();
        if(msg == Not_Empty){
            printf("Cell is not Empty... Please Choose another Cell\n");
        }
        else if(msg == Invalid_Cell){
            printf("Cell number is not Valid... Please Choose another Cell\n");
        }
        if(Winner != No_Winner){
           printf("Player %c has won the Game\n", Winner);
           return 0;     
        }
        choice = get_player_input();
        msg = 0;
        if(choice == Not_Empty || choice == Invalid_Cell ){
            msg = choice;
        }
        else{
            Playground[((choice/10) -1)][((choice%10) -1)] = current_player;
            current_player = (current_player == Player_1)? Player_2:Player_1;
            empty_cells--;
        }
    }
    printf("The Game Ended in DRAW\n");
    return 0;
}

int get_player_input(void)
{
    int choice = 0;
    scanf("%d",&choice);
    
    switch (choice)
    {
    case 11:
    case 12:
    case 13:
    case 21:
    case 22:
    case 23:
    case 31:
    case 32:
    case 33:
        if((Playground[((choice/10)-1)][((choice%10)-1)]) != ' '){
            return Not_Empty;
        }
        break;
    
    default:
        return Invalid_Cell ;
        break;
    }
    return choice;

}
char judge(void)
{   
    
    //diagonal check
    if(Playground[0][0] == Playground[1][1] && Playground[1][1] == Playground[2][2]){
        if(Playground[0][0] != ' '){
            return Playground[0][0];
        }
    }
    else if(Playground[0][2] == Playground[1][1] && Playground[1][1] == Playground[2][0]){
        if(Playground[1][1] != ' '){
            return Playground[1][1];
        }
    }
    else{
    //row & col check

    for(int i = 0; i<3; i++){
        if(Playground[i][0] == Playground[i][1] && Playground[i][1] == Playground[i][2]){
            if(Playground[i][0] != ' '){
                return Playground[i][0];
            }          
        }
        else if(Playground[0][i] == Playground[1][i] && Playground[1][i] == Playground[2][i]){
            if(Playground[0][i] != ' '){
                return Playground[0][i];
            }
        }    
     }
    }
    return No_Winner;
}
void render_playground()
{
    system("clear");
    printf("\n");
    for(int i = 0; i<3; i++){
        printf("%c | %c | %c\n",Playground[i][0], Playground[i][1], Playground[i][2]);
    }

}