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
    char* wordToGuess = getRandomWord();
    int wordLength = strlen(wordToGuess);
    char guessedWord[MAX_WORD_LENGTH];
    int numTries = 0;


    char visibleWord[MAX_WORD_LENGTH];
    int numVisibleChars = wordLength / 2; //절반의 문자만 보이도록 
    //선택된 단어의 길이만큼 반복되는 과정에서
    //선택된 단어의 절반은 visibleWord 배열에 복사하고 나머지는 플레이어에게 보여주지않도록한다.
    for (int i = 0; i < wordLength; i++) {
        if (i < numVisibleChars) {
            visibleWord[i] = wordToGuess[i];
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

    //단어 상태를 플레이어에게 보여줌
    while (numTries < MAX_TRIES && numCorrectGuesses < wordLength) {
        printf("단어: %s\n", visibleWord);
        printf("추측한 단어를 입력하세요: ");

        //플레이어에게 한 글자 추측받음
        char guess;
        scanf(" %c", &guess);

        //추측한 글자가 단어에 있는지 반복문과 조건문을 통해 확인
        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (wordToGuess[i] == guess && visibleWord[i] == '_') {
                visibleWord[i] = guess;
                found = 1;
                numCorrectGuesses++;
            }
        }
        //추측 결과에 따라서 플레이어에게 힌트 제공
        if (!found) {
            numTries++;
            printf("틀렸습니다. 남은 시도 횟수: %d\n", MAX_TRIES - numTries);
        }
        else {
            printf("맞췄습니다!\n");
        }
    }
    //게임 종료 메시지 출력
    if (numCorrectGuesses == wordLength) {
        printf("축하합니다! 정답은 \"%s\" 였습니다!\n", wordToGuess);
    }
    else {
        printf("아쉽습니다. 정답은 \"%s\" 였습니다.\n", wordToGuess);
    }

}