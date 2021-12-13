#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

int money=100;
int bet;
int betOn;
int bets[6];
int ans;
int dice[3];

void flush();
void DoBet();
void DoRollDice();
void DoWinLose();



int main(void) {

	srand(time(NULL));

	while(money>0) {
	  DoBet();
	  if(bet==0) break;
		DoRollDice();
		DoWinLose();
	}

  printf("money: %d\n",money);

	printf("Game Over\n");

  return 0;
}



void flush() {
  int ch;
  while((ch=getchar())!='\n' && ch!=EOF);
}



void DoBet() {

	for(int i=0;i<6;i++) {
		bets[i]=0;
	}

  do {

    printf("money: %d\n",money);

    do {
      printf("bet (0 to quit): ");
      scanf("%d",&bet);
      flush();
      if(bet<0 || bet>money) {
        printf("invalid bet\n");
      }
    } while(bet<0 || bet>money);

		if(bet==0) break;

    do {
      printf("bet on (0 to cancel): ");
      scanf("%d",&betOn);
      flush();
      if(betOn<0 || betOn>6) {
        printf("invalid bet\n");
      }
    } while(betOn<0 || betOn>6);

    if(betOn>0) {
    	money-=bet;
    	bets[betOn-1]+=bet;
		}

	  printf("money: %d\n",money);

    printf("dice# bet\n");
    for(int i=0;i<6;i++) {
      printf("%5d %3d\n",i+1,bets[i]);
    }

		if(money<=0) break;

    do {
      printf("bet again (y/n)? ");
      ans=tolower(getchar());
      flush();
      if(ans!='y' && ans!='n') {
        printf("invalid answer\n");
      }
    } while(ans!='y' && ans!='n');

  } while(ans=='y');

}



void DoRollDice() {
	printf("press [enter] key to continue...");
	(void)getchar();
	for(int i=0;i<3;i++) {
		dice[i]=rand()%6+1;
	}
	printf("you roll: %d,%d,%d\n",dice[0],dice[1],dice[2]);
}



void DoWinLose() {
	int price=0,lose=0;

	for(int i=0;i<6;i++) {
		if(dice[0]!=i && dice[1]!=i && dice[2]!=i) lose+=bets[i];
	}

	for(int i=0;i<3;i++) {
		price+=bets[dice[i]-1]*2;
	}

	money+=price;

	if(lose>0)	printf("you lose %d\n",lose);
	if(price>0) printf("you win %d\n",price);

}
