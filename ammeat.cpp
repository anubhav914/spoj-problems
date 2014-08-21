#include <stdio.h>
#include <stdlib.h>
#include <math.h>


bool MiteminKPlates(long long *items, int N, long long M, int K){
	long long sum = 0, count = 0;
	while(K){
		if(K%2) sum += items[count];
		count++; K = K/2;
		if(sum >= M) return true;
	}
	return false;
}

int setBits(int N){
	int count = 0;
	while(N){
		if(N%2) count++;
		N = N/2;
	}
	return count;
}

int MItemsinMinPlates(long long *items, int N, long long M){
	int plateCombinations = pow(2,N);
	int minplates = -1;
	for(int i = 1; i < plateCombinations; i++){
		if(MiteminKPlates(items, N, M, i)){
			if(minplates == -1 or setBits(i) <= minplates)
				minplates = setBits(i);
		}	
	}
	return minplates;
}

int main(){
	int T, N;
	long long M;
	scanf("%d", &T);
	while(T--){
		scanf("%d %lld", &N, &M);
		long long *meatballs = (long long *)calloc(N, sizeof(long long));
		for (int i = 0; i < N; ++i) scanf("%lld", &meatballs[i]);
		printf("%d\n", MItemsinMinPlates(meatballs, N, M));
	}
}