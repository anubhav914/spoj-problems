#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rC(){
	return (2*(rand()%2) - 1)*(rand()%10);
}

int main(){
	srand(time(NULL));
	int T = 5, N;
	const char *dir = "RLUD";
	printf("%d\n", T);
	while(T--){
		printf("%d %d %c\n", rC(), rC(), dir[rand()%4]);
		N = rand()%10 + 1;
		printf("%d\n", N);
		while(N--)
			printf("%d %d %c\n", rC(), rC(), dir[rand()%4]);
	}
}