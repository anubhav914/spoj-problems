#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	return *(int *)a  - *(int *)b ;
}


int main(){
	int T, N, *A;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		A = (int *)calloc(N, sizeof(int));
		for(int i = 0; i < N; i++)
			scanf("%d", &A[i]);
		qsort(A, N, sizeof(int), compare);
		for(int i = 0; i + i < N; i++){
			printf("%d ", A[i]);
			if(i != N-i-1) printf("%d ", A[N-i-1]);
		}
		printf("\n");
	}
}