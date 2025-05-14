#include <stdio.h>
#include <conio.h>
#include <dos.h>

int main() {
    char ch;
    int dino_pos = 0;
    int obstacle_pos = 20;
    int score = 0;
    int game_over = 0;
    int i;

    clrscr();

    while (!game_over) {
        clrscr();
        if (dino_pos == 0) {
            gotoxy(5, 20);
            textcolor(GREEN);
            printf("I");
        } else {
            gotoxy(5, 18);
            textcolor(GREEN);
            printf("I");
        }

        gotoxy(obstacle_pos, 20);
        textcolor(RED);
        printf("O");

        textcolor(WHITE);
        for (i = 1; i <= 80; i++) {
            gotoxy(i, 21);
            printf("=");
        }

        gotoxy(1, 1);
        textcolor(WHITE);
        printf("Score: %d", score);

        if (kbhit()) {
            ch = getch();
            if (ch == ' ') {
                dino_pos = 1;
            }
        } else {
            dino_pos = 0;
        }

        obstacle_pos--;
        if (obstacle_pos < 1) {
            obstacle_pos = 20;
            score++;
        }

        if (obstacle_pos == 5 && dino_pos == 0) {
            game_over = 1;
        }

        delay(150);
    }

    clrscr();
    textbackground(BLUE);
    textcolor(WHITE);
    gotoxy(30, 10);
    printf("Game Over!");
    gotoxy(30, 12);
    printf("Your Score: %d", score);
    gotoxy(30, 14);
    printf("Press any key to exit...");
    getch();

    return 0;
}