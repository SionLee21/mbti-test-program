#include "mbtilib.h" // 사용자 헤더

char* allocStr(char str[]){
  char* newstr = (char*) malloc(strlen(str)); 
  strcpy(newstr, str);
  newstr[strlen(newstr)-1]='\0';
  return newstr;
}

void setMBTIQuestion(char* filename, struct st_question list[]){
  // filename으로부터 32개의 질문을 입력받아서 list배열에 메모리할당하면서 채운다.
    FILE* file;
    char common[200], q1[200], q2[200], newline;
    file = fopen(filename, "r");
    int total,type;
    fscanf(file, "%d%c", &total, &newline);
    for(int i=0; i<total; i++){
        fscanf(file, "%d%c", &type, &newline);
        fgets(common, 200, file);
        fgets(q1, 200, file);
        fgets(q2, 200, file);
        list[i].type=type;
        list[i].common=allocStr(common);
        list[i].q1=allocStr(q1);
        list[i].q2=allocStr(q2);
    }
    fclose(file);
    printf("%d Questions are loaded!!\n\n==== Test begins. ====\n\n", total);
}


void runTest(struct st_test* who, struct st_question q[]){
  int ans;
  int i=1;
  for (int i=0; i<4; i++) who->answer[q[i].type-1]=24;
  printf("What is your name? > ");
  scanf("%s",who->testername);
  while(1){
    ans=askQuestion(q, i);
    if(ans>5||ans<0){ //range에서 벗어난 input이 들어오면 다시 그 문항을 출력하고 사용자에게 알림
      printf("Wrong Input!\n");
      i--;
      }
    else if (ans>=3)who->answer[q[i].type-1]+=ans-2; //input이 3보다 큰 숫자일 경우 그리고 3보다 작을때 각각의 숫자만큼 1,2,3점을 더하거나 뺌
    else who->answer[q[i].type-1]-=(3-ans);
    i++;
    if (i==32) break;
  }
  printf("==== Test ended. ====\n");
}

int askQuestion(struct st_question list[], int i){
// list질문세트 중에 no번째 질문을 물어보고, 그 답을 리턴한다.
  int ans;
  printf("\n[질문%2d/32] %s\n^ 5 v %s\n^ 4 v\n^ 3 v\n^ 2 v\n^ 1 v\n^ 0 v %s\nEnter 0~5 > ", i+1,list[i].common,list[i].q1,list[i].q2);
 //return getRandom(); //랜덤 수를 return하기 이 부분 주석처리 없앨시 코드 테스트 가능
  scanf("%d", &ans);
	return ans;
}

void printGraph(struct st_test* who){
  char mbti[8][10]={"I","E","N","S","F","T","P","J"};
  for(int j=0,count=0; j<4; j++, count+=2){
    printf("%s", mbti[count]);
    for(int i=0; i<49; i++){
      if(who->answer[j]==i) printf("|*|"); //해당 항목 -을 출력 및 점수에 해당하는 번호에 -대신 |*|출력
      else printf("-");
      }
    printf("%s\n", mbti[count+1]);
  }
}

void finalResult(char* filename){
  char* result;
  char now[200];
  FILE* file = fopen(filename, "r");
  while(fgets(now, 200, file)) printf("%s", now); //now로 라인을 읽고 출력. 
  

  fclose(file);
}

void printResult(struct st_test* who) {
  char mbtiName[100];
  int num;
  char mbtiType[5];
  char mbti[8][10] = {"I", "E", "N", "S", "F", "T", "P", "J"};
  int yourMbti[4];
  for (int i = 0, count = 0; i < 4; i++, count += 2) {
    if (who->answer[i] < 24) yourMbti[i] = count;
    else yourMbti[i] = count + 1;
  }
  for (int i = 0; i < 4; i++) {
    strcat(mbtiType, mbti[yourMbti[i]]);
  }
  printf("%s your MBTI type is: %s.\n", who->testername,mbtiType);
  sprintf(mbtiName, "%s.txt", mbtiType);
  char* filename = (char*) malloc(strlen(mbtiName)); 
  strcpy(filename, mbtiName);
  finalResult(filename);
}

int getRandom(){
  return rand()%6;
}
