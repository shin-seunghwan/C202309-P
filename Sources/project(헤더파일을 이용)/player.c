#include "player.h"

#define NUM_WORDS 5
#define MAX_WORD_LENGTH 10
#define MAX_TRIES 6

char words[NUM_WORDS][MAX_WORD_LENGTH] = {
    "apple",
    "banana",
    "cherry",
    "grape",
    "orange"
};

char* getRandomWord() {
    int index = rand() % NUM_WORDS;
    return words[index];
}

void playHangman() {
    //���ӿ� �ʿ��� ���� ���� �� �ʱ�ȭ
    char* wordToGuess = getRandomWord();
    int wordLength = strlen(wordToGuess);
    char visibleWord[MAX_WORD_LENGTH];
    int numTries = 0;
    int numCorrectGuesses = 0;

    // ������ ���ڸ� ���̵��� ����
    for (int i = 0; i < wordLength; i++) {
        visibleWord[i] = (i < wordLength / 2) ? wordToGuess[i] : '_';
    }
    visibleWord[wordLength] = '\0';

    printf("��� ������ �����մϴ�. �ܾ ���纸����!\n");

    //�ܾ� ���¸� �÷��̾�� ������
    while (numTries < MAX_TRIES && numCorrectGuesses < wordLength) {
        printf("�ܾ�: %s\n", visibleWord);
        printf("������ �ܾ �Է��ϼ���: ");

        //�÷��̾�� �� ���� ��������
        char guess;
        scanf_s(" %c", &guess);
        while (getchar() != '\n');

        //��ҹ��� ���� ���ֱ�
        guess = tolower(guess);

        //������ ���ڰ� �ܾ �ִ��� �ݺ����� ���ǹ��� ���� Ȯ��
        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (tolower(wordToGuess[i]) == guess && visibleWord[i] == '_') {
                visibleWord[i] = wordToGuess[i];  // ���� �ܾ��� ��ҹ��� ����
                found = 1;
                numCorrectGuesses++;
            }
        }
        //���� ����� ���� �÷��̾�� ��Ʈ ����
        if (!found) {
            numTries++;
            printf("Ʋ�Ƚ��ϴ�. ���� �õ� Ƚ��: %d\n", MAX_TRIES - numTries);
        }
        else {
            printf("������ϴ�!\n");
        }
    }
    //���� ���� �޽��� ���
    if (numCorrectGuesses == wordLength) {
        printf("�����մϴ�! ������ \"%s\" �����ϴ�!\n", wordToGuess);
    }
    else {
        printf("�ƽ����ϴ�. ������ \"%s\" �����ϴ�.\n", wordToGuess);
    }

}
