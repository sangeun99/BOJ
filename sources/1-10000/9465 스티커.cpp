/*
문제
상근이의 여동생 상냥이는 문방구에서 스티커 2n개를 구매했다. 스티커는 그림 (a)와 같이 2행 n열로 배치되어 있다. 상냥이는 스티커를 이용해 책상을 꾸미려고 한다.

상냥이가 구매한 스티커의 품질은 매우 좋지 않다. 스티커 한 장을 떼면, 그 스티커와 변을 공유하는 스티커는 모두 찢어져서 사용할 수 없게 된다. 즉, 뗀 스티커의 왼쪽, 오른쪽, 위, 아래에 있는 스티커는 사용할 수 없게 된다.

모든 스티커를 붙일 수 없게된 상냥이는 각 스티커에 점수를 매기고, 점수의 합이 최대가 되게 스티커를 떼어내려고 한다. 먼저, 그림 (b)와 같이 각 스티커에 점수를 매겼다. 상냥이가 뗄 수 있는 스티커의 점수의 최댓값을 구하는 프로그램을 작성하시오. 즉, 2n개의 스티커 중에서 점수의 합이 최대가 되면서 서로 변을 공유 하지 않는 스티커 집합을 구해야 한다.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫째 줄에는 n (1 ≤ n ≤ 100,000)이 주어진다. 다음 두 줄에는 n개의 정수가 주어지며, 각 정수는 그 위치에 해당하는 스티커의 점수이다. 연속하는 두 정수 사이에는 빈 칸이 하나 있다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다. 

출력
각 테스트 케이스 마다, 2n개의 스티커 중에서 두 변을 공유하지 않는 스티커 점수의 최댓값을 출력한다.
*/


#include <stdio.h>

int main() {
	int n, t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int** input = new int* [2];
		for (int i = 0; i < 2; i++)
			input[i] = new int[n + 1];
		input[0][0] = 0;
		input[1][0] = 0;

		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++)
				scanf("%d", &input[i][j]);
		}

		for (int j = 2; j <= n; j++){
			for (int i = 0; i < 2; i++) {
				int max = (input[1 - i][j - 1] > input[1 - i][j - 2]) ? input[1 - i][j - 1] : input[1 - i][j - 2];
				input[i][j] += max;
			}
		}

		printf("%d\n", (input[0][n] > input[1][n])? input[0][n] : input[1][n]);

		for (int i = 0; i < 2; i++)
			delete[] input[i];
		delete[] input;
	}
}