#include <stdio.h>

enum direction {
	UP, RIGHT, DOWN, LEFT
};

	int arr[1000][1000];
int main() {
	int N;
	int num;

	int x, y;
	int result_x = 0, result_y = 0;
	int direction = UP;

	int is_two = 0;
	int count = 0;
	int turn = 1;

	scanf("%d %d", &N, &num);

	x = y = N / 2 + 1;

	for (int i = 1; i <= N * N; i++) {
		if (count == turn) {
			direction = (direction + 1) % 4;
			count = 0;
			is_two++;
		}

		if (is_two == 2) {
			is_two = 0;
			turn++;
		}

		arr[y][x] = i;
		if (i == num) { result_x = x; result_y = y; }

		if (direction == UP) y--;
		if (direction == DOWN) y++;
		if (direction == LEFT) x--;
		if (direction == RIGHT) x++;

		count++;
	}

	for (int  y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			printf("%d ", arr[y][x]);
		}

		printf("\n");
	}

	printf("%d %d", result_y, result_x);

	return 0;
}