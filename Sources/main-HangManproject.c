#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//��� ����
#define NUM_WORDS 5
#define MAX_WORD_LENGTH 10
#define MAX_TRIES 6

//�ܾ��� ������ �ִ���̸� 2���� �迭�� �ϴ� words�� �ܾ� ��� ����
char words[NUM_WORDS][MAX_WORD_LENGTH] = {
    "apple",
    "banana",
    "cherry",
    "grape",
    "orange"
};

//���ڿ� �����͸� ��ȯ�ϴ� �Լ��� ���� -> ��ȯ�� �����ʹ� ���õ� ������ �ܾ��� ù��° ���ڸ� ����Ŵ
char* getRandomWord() {
    srand(time(NULL));
    int index = rand() % NUM_WORDS; //0���� NUM_WORDS - 1 ������ ������ ������ ����
    return words[index];
}

void playHangman() {
    //���ӿ� �ʿ��� ���� ���� �� �ʱ�ȭ
    char* wordToGuess = getRandomWord();
    int wordLength = strlen(wordToGuess);
    char guessedWord[MAX_WORD_LENGTH];
    int numTries = 0;


    char visibleWord[MAX_WORD_LENGTH];
    int numVisibleChars = wordLength / 2; //������ ���ڸ� ���̵��� 
    //���õ� �ܾ��� ���̸�ŭ �ݺ��Ǵ� ��������
    //���õ� �ܾ��� ������ visibleWord �迭�� �����ϰ� �������� �÷��̾�� ���������ʵ����Ѵ�.
    for (int i = 0; i < wordLength; i++) {
        if (i < numVisibleChars) {
            visibleWord[i] = wordToGuess[i];
        }
        else {
            visibleWord[i] = '_';
        }
    }

    //���� �� ���ڿ��� �� ����
    visibleWord[wordLength] = '\0';
    guessedWord[wordLength] = '\0';

    int numCorrectGuesses = 0;

    printf("��� ������ �����մϴ�. �ܾ ���纸����!\n");

    //�ܾ� ���¸� �÷��̾�� ������
    while (numTries < MAX_TRIES && numCorrectGuesses < wordLength) {
        printf("�ܾ�: %s\n", visibleWord);
        printf("������ �ܾ �Է��ϼ���: ");

        //�÷��̾�� �� ���� ��������
        char guess;
        scanf(" %c", &guess);

        //������ ���ڰ� �ܾ �ִ��� �ݺ����� ���ǹ��� ���� Ȯ��
        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (wordToGuess[i] == guess && visibleWord[i] == '_') {
                visibleWord[i] = guess;
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