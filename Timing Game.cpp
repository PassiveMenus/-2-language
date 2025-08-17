#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_vongS 100

typedef struct {
    double muc_tieu;
    double thuc_te;
    double loi;
} Score;

int main() {
    srand(time(NULL));

    Score scoreboard[MAX_vongS];
    int vong = 0;
    char lua_chon;

    printf("=== Can thoi gian ===\n");
    printf("Xem BXH? (y/n): ");
    lua_chon = getchar();
    while (getchar() != '\n');  // Clear buffer

    if (lua_chon == 'y' || lua_chon == 'Y') {
        printf("Chua co diem, hay choi 1 tro truoc da.\n\n");
    }

    do {
        double muc_tieu = ((rand() % 701) + 300) / 100.0;

        printf("Vong %d\n", vong + 1);
        printf("Hay cho dung %.2f giay.\n", muc_tieu);
        printf("Nhan ENTER de bat dau.\n");
        getchar();

        printf("Nhan ENTER sau khi %.2f giay da qua...\n", muc_tieu);
        clock_t start = clock();
        getchar();
        clock_t end = clock();

        double thuc_te = (double)(end - start) / CLOCKS_PER_SEC;
        double loi = fabs(thuc_te - muc_tieu) / muc_tieu * 100.0;

        printf("\nBan da cho: %.2f giay\n", thuc_te);
        printf("Muc tieu %.2f giay\n", muc_tieu);
        printf("Lech: %.2f%% giay\n", loi);

        // Save to scoreboard
        if (vong < MAX_vongS) {
            scoreboard[vong].muc_tieu = muc_tieu;
            scoreboard[vong].thuc_te = thuc_te;
            scoreboard[vong].loi = loi;
            vong++;
        }

        // Teasing
        if (loi <= 2.0)
            printf("Bai luon do.\n");
        else if (loi <= 5.0)
            printf("Lan thu may r e?.\n");
        else if (loi <= 15.0)
            printf("Kha on\n");
        else if (loi <= 30.0)
            printf("Ga ak?\n");
        else
            printf("Ru ngu tao di\n");

        printf("\nLam van nua di e? (y/n): ");
        lua_chon = getchar();
        while (getchar() != '\n'); // Clear buffer
        printf("\n");

    } while (lua_chon == 'y' || lua_chon == 'Y');

    // Ask if they want to see the scoreboard
    printf("Xem BXH (y/n): ");
    lua_chon = getchar();
    while (getchar() != '\n');

    if (lua_chon == 'y' || lua_chon == 'Y') {
        printf("\n=== Bang xep hang ===\n");
        for (int i = 0; i < vong; i++) {
            printf("Vong %d: Muc tieu %.2fs | Da cho %.2fs | Lech %.2f%%\n",
                   i + 1,
                   scoreboard[i].muc_tieu,
                   scoreboard[i].thuc_te,
                   scoreboard[i].loi);
        }
    }

    printf("\nCam on vi da choi\n");
    return 0;
}

