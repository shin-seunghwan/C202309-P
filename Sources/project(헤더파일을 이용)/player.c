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
    //게임에 필요한 변수 선언 및 초기화
    char* wordToGuess = getRandomWord();
    int wordLength = strlen(wordToGuess);
    char visibleWord[MAX_WORD_LENGTH];
    int numTries = 0;
    int numCorrectGuesses = 0;

    // 절반의 문자만 보이도록 설정
    for (int i = 0; i < wordLength; i++) {
        visibleWord[i] = (i < wordLength / 2) ? wordToGuess[i] : '_';
    }
    visibleWord[wordLength] = '\0';

    printf("행맨 게임을 시작합니다. 단어를 맞춰보세요!\n");

    //단어 상태를 플레이어에게 보여줌
    while (numTries < MAX_TRIES && numCorrectGuesses < wordLength) {
        printf("단어: %s\n", visibleWord);
        printf("추측한 단어를 입력하세요: ");

        //플레이어에게 한 글자 추측받음
        char guess;
        scanf_s(" %c", &guess);
        while (getchar() != '\n');

        //대소문자 구분 없애기
        guess = tolower(guess);

        //추측한 글자가 단어에 있는지 반복문과 조건문을 통해 확인
        int found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (tolower(wordToGuess[i]) == guess && visibleWord[i] == '_') {
                visibleWord[i] = wordToGuess[i];  // 원래 단어의 대소문자 유지
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
