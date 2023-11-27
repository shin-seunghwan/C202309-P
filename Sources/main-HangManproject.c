#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//상수 선언
#define NUM_WORDS 5
#define MAX_WORD_LENGTH 10
#define MAX_TRIES 6

//단어의 개수와 최대길이를 2차원 배열로 하는 words에 단어 목록 저장
char words[NUM_WORDS][MAX_WORD_LENGTH] = {
    "apple",
    "banana",
    "cherry",
    "grape",
    "orange"
};

//문자열 포인터를 반환하는 함수를 생성 -> 반환된 포인터는 선택된 무작위 단어의 첫번째 문자를 가리킴
char* getRandomWord() {
    srand(time(NULL));
    int index = rand() % NUM_WORDS; //0부터 NUM_WORDS - 1 사이의 무작위 정수를 생성
    return words[index];
}

void playHangman() {
    //게임에 필요한 변수 선언 및 초기화
    char* wordGuess = getRandomWord();
    int wordLength = strlen(wordGuess);
    char guessedWord[MAX_WORD_LENGTH];
    int numTries = 0;


    char visibleWord[MAX_WORD_LENGTH];
    int numVisibleChars = wordLength / 2; //절반의 문자만 보이도록 
    //선택된 단어의 길이만큼 반복되는 과정에서
    //선택된 단어의 절반은 visibleWord 배열에 복사하고 나머지는 플레이어에게 보여주지않도록한다.
    for (int i = 0; i < wordLength; i++) {
        if (i < numVisibleChars) {
            visibleWord[i] = wordGuess[i];
        }
        else {
            visibleWord[i] = '_';
        }
    }

    //선언 및 문자열의 끝 선언
    visibleWord[wordLength] = '\0';
    guessedWord[wordLength] = '\0';

    int numCorrectGuesses = 0;

    printf("행맨 게임을 시작합니다. 단어를 맞춰보세요!\n");


}