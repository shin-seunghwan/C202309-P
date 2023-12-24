#include "player.h"

int main() {
    srand(time(NULL));

    int playAgain;
    do {
        playHangman();

        printf("게임을 다시 플레이하시겠습니까? (1:재시작, 0:종료): ");
        while (scanf_s("%d", &playAgain) != 1) {
            while (getchar() != '\n');
            printf("잘못된 입력입니다. 다시 입력해주세요 (1:재시작, 0:종료): ");
        }

        if (playAgain == 1) {
            printf("\n새 게임을 시작합니다.\n\n");
        }
        else if (playAgain == 0) {
            printf("게임을 종료합니다. 안녕히 가세요!\n");
        }
    } while (playAgain);

    return 0;
}