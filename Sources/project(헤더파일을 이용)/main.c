#include "player.h"

int main() {
    srand(time(NULL));

    int playAgain;
    do {
        playHangman();

        printf("������ �ٽ� �÷����Ͻðڽ��ϱ�? (1:�����, 0:����): ");
        while (scanf_s("%d", &playAgain) != 1) {
            while (getchar() != '\n');
            printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ��� (1:�����, 0:����): ");
        }

        if (playAgain == 1) {
            printf("\n�� ������ �����մϴ�.\n\n");
        }
        else if (playAgain == 0) {
            printf("������ �����մϴ�. �ȳ��� ������!\n");
        }
    } while (playAgain);

    return 0;
}