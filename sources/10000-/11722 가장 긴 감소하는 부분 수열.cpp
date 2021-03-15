/*
문제
수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 가장 긴 감소하는 부분 수열은 A = {10, 30, 10, 20, 20, 10}  이고, 길이는 3이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 감소하는 부분 수열의 길이를 출력한다.
*/

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int input[1001];
	int result[1001];
	int answer = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
		int length = 0;
		for (int j = 0; j < i; j++) {
			if (input[j] > input[i] && length < result[j])
				length = result[j];
		}
		result[i] = length + 1;
		if (answer < result[i])
			answer = result[i];
	}
	printf("%d", answer);
}