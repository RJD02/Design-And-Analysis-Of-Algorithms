#include<stdio.h>
#include<stdlib.h>

int main() {
	int start, end, key, n;
	scanf("%d %d %d %d", &n, &start, &end, &key);
	printf("%d\n", n);
	srand(key);
	for(int i = 0; i < n; i++)
		printf("%d ", start + rand() % (end - start));
	return 0;
}
