#include "mbtilib.h" // 사용자 헤더

int main(void) {
	struct st_question qlist[32]; // 질문목록
	struct st_test tester;
	srand(time(0));  // 중간 테스트를 위해서.
	setMBTIQuestion("qlist.txt", qlist);

	
	runTest(&tester, qlist);
  printGraph(&tester);
	printResult(&tester);
	return 0;
}
