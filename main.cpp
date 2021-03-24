#include <stdio.h>
#include <stdlib.h>

char matrix[3][3];
char p1[150];
char p2[150];
char ps1 = 'a';
char ps2 = 'b';
int counter = 9;

void initialize_matrix () {
    int i, j;
    char k = '1';
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            matrix[i][j] = k++;
        }
    }
}

void get_name(char *s, int num){
    system("cls");
    printf("\t\t\t\t\t\t\t\t==> Tic Tac Toe <==\n\n\n");
    s[0] = '\0';
    while(s[0] == '\0') {
        printf("\t\t\t\t\t\t\t\tEnter name player %d : ", num);
        gets(s);
    }
}
void take_symbol() {
    if(ps1 == 'a') {
        while(ps1 != 'X'  &&  ps1 != 'O') {
            printf("\t\t\t\t\t\t\t\t%s take a symbol (X or O) : ", p1);
            scanf("%c", &ps1);
            if(ps1 == 'x') ps1 = 'X';c
            else if(ps1 == 'o') ps1 = 'O';
            fflush(stdin);
        }
    }
    else {
        while(ps2 != 'X' && ps2 != 'O') {
            printf("\t\t\t\t\t\t\t\t%s take a symbol (X or O) : ", p2);
            scanf("%c", &ps2);
            if(ps2 == 'x') ps2 = 'X';
            else if(ps2 == 'o') ps2 = 'O';
            if(ps2 == ps1) {
                printf("\t\t\t\t\t\t\t\tAlready Taken !\n");
                ps2 = 'b';
            }
            fflush(stdin);
        }
    }
}

void display_board() {
    system("cls");
    printf("\t\t\t\t\t\t\t\t==> Tic Tac Toe <==\n\n\n");
    printf("\t\t\t\t\t\t\t\t %s(%c) : %s(%c)\n\n", p1, ps1, p2, ps2);
    printf("\t\t\t\t\t\t\t\t    %c | %c | %c \n", matrix[0][0], matrix[0][1], matrix[0][2]);
    printf("\t\t\t\t\t\t\t\t   ---|---|---\n");
    printf("\t\t\t\t\t\t\t\t    %c | %c | %c \n", matrix[1][0], matrix[1][1], matrix[1][2]);
    printf("\t\t\t\t\t\t\t\t   ---|---|---\n");
    printf("\t\t\t\t\t\t\t\t    %c | %c | %c \n", matrix[2][0], matrix[2][1], matrix[2][2]);
    fflush(stdout);
}

void take_input(char *s, char c) {
    int choice;
    int x, y;
   while(true) {
       fflush(stdin);
       printf("\t\t\t\t\t\t\t\t%s choose a cell number : ", s);
       scanf("%d", &choice);
       if(choice < 1 || choice > 9) {
           printf("\t\t\t\t\t\t\t\tInvalid cell number!! \n");
           continue ;
       }
       if(choice <= 3) x = 0;
       else if(choice <= 6) x = 1;
       else x = 2;
       if(x == 0) y = (choice - 1);
       else if(x == 1) y = (choice - 4);
       else y = choice - 7;
       if(matrix[x][y] == 'X' || matrix[x][y] == 'O') {
           printf("\t\t\t\t\t\t\t\tCell Taken!! \n");
           continue ;
       }
       matrix[x][y] = c;
       break;
   }
}

int check_board(char *s) {
    int ok = 0;
    int i;
    for(i = 0; i < 3; i++) {
        if(matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]) ok = 1;
        if(matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]) ok = 1;
    }
    if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]) ok = 1;
    if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) ok = 1;
    if(ok) {
        printf("\t\t\t\t\t\t\t\t%s wins !!!!!!!", s);
        fflush(stdout);
    }
    return ok;
}

int main() {
    get_name(p1, 1);
    get_name(p2, 2);
    char decision = 'Y';
    take_symbol();
    take_symbol();
    while(decision == 'Y' || decision == 'y') {
       initialize_matrix();
        counter = 9;
       while(true) {
           display_board();
           take_input(p1, ps1);
           display_board();
           counter--;
           if(check_board(p1)) break;
           if(counter == 0) {
               printf("Draw!!!!\n");
               break;
           }
           take_input(p2, ps2);
           counter--;
           if(check_board(p2)) break;
       }
       fflush(stdout);
       fflush(stdin);
       printf("\n\t\t\t\t\t\t\t\tWant to play again? (Y / N ) : ");
       scanf("%c" , &decision);
       if(decision == 'y') decision = 'Y';
    }
    return 0;
}