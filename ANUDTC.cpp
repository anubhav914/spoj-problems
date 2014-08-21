#include <stdio.h>


inline bool equalPieces(int K, int  N){
	return  K%N ? false : true;
}

inline bool pieces(int K, int  N){
	return  N > K ? false : true;
}

inline bool allUnequalPices(int K, int N){
	return  N*(N+1) > 2*K ? false : true;
}

int main(){
	int T, N;
	const char *ans = "ny";
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		printf("%c %c %c\n", 
				ans[equalPieces(360, N)],
				ans[pieces(360, N)],
				ans[allUnequalPices(360, N)]
			);
	}
}