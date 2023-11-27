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
    char* wordGuess = getRandomWord();
    int wordLength = strlen(wordGuess);
    char guessedWord[MAX_WORD_LENGTH];
    int numTries = 0;


    char visibleWord[MAX_WORD_LENGTH];
    int numVisibleChars = wordLength / 2; //������ ���ڸ� ���̵��� 
    //���õ� �ܾ��� ���̸�ŭ �ݺ��Ǵ� ��������
    //���õ� �ܾ��� ������ visibleWord �迭�� �����ϰ� �������� �÷��̾�� ���������ʵ����Ѵ�.
    for (int i = 0; i < wordLength; i++) {
        if (i < numVisibleChars) {
            visibleWord[i] = wordGuess[i];
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


}