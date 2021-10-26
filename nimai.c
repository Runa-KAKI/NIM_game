#include <stdio.h>
# define MAX 22

/* 20枚のコインを、CPUと交互に取っていくゲームです。 */
/* 最後の1枚を取ったほうが負けとなります。 */
/* CPUは必勝法を使用してくるため、プレイヤーに勝ち目はありません。 */

int main(void)
{
	char coin[MAX];
	int counter = 0; // 取ったコインの数
	int player = 0; // 現在のプレーヤー
	int i = 0;
	int input = 0;
	/* コインの初期化*/
	for (i = 0; i < MAX - 1; i++) {
		coin[i] = 'X';
	}
	coin[MAX - 1] = '\0';
	printf("%s\n", coin);
	while(1) {
		//プレイヤーのターン
		if (player % 2 == 0) {
			input = 0;
			printf("How many coins ?\n");
			scanf("%d", &input); /* コイン入力*/
			while (input > 3 || input < 1) {
				printf("please take 1-3 coins\n");
				scanf("%d", &input);
			}
		}
		//CPUのターン
		//必勝法：プレイヤーの取った数との合計が4になるように取る
		else {
			printf("CPU turn\n");
			input = 4 - input;
			printf("%d\n", input);
		}
		counter += input;
		//勝利条件を満たした場合、ループを抜ける
		if (counter >= MAX - 1) {
			player++;
			break;
		}

		*(coin + MAX - counter - 1) = '\0';
		printf("%s\n", coin); // 残っているコイン
		player++;
	}
	//勝利判定
	if (player % 2 == 0) printf("player won !\n");
	else printf("CPU won!\n");
	return 0;
}
