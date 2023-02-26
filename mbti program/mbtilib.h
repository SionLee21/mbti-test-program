// 사용자헤더 mbtilib.h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct st_question{
	int type; // 1:E/I, 2:S/N, 3:T/F, 4:J/P 
	char* common;// 공통문장
	char* q1; // 문장1
	char* q2; // 문장2
};
struct st_test{
    char testername[20];  // 검사자 이름
    int answer[4];		// 검사자의 입력한 답변 (0~5)
    int mbti_type;		// 검사결과로 결정된 MBTI 유형 (16개 중 1)
};

// 필요하다면 전역변수, 매크로상수 이런것들도 정의..

void setMBTIQuestion(char* filename, struct st_question list[]);
// filename으로부터 32개의 질문을 입력받아서 list배열에 메모리할당하면서 채운다.

void runTest(struct st_test* who, struct st_question q[]);
// who에 해당되는 검사자에게 q배열의 질문을 물어보면서 답변을 저장한다.

int askQuestion(struct st_question list[], int no);
// list질문세트 중에 no번째 질문을 물어보고, 그 답을 리턴한다.

void finalResult(char* filename);
//각 mbti별 세부 텍스트 출력

char* allocStr(char str[]);
//구조체 포인터 char에 메모리 할당

void evalTest(struct st_test* who);
void printResult(struct st_test* who);
void printGraph(struct st_test* who);
void toString(int no);
char* getMBTIName(int no);
char* copyString(char* str);
int getRandom();
