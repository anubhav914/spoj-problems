#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;

/**
nSequenceXorK checks if the the given sequence 
contains n consecutive ints whose XOR is K
S is the sequence
*/
bool binarySearch(ull *A, int N, ull k){
	if (N == 0) return false;
	if(A[N/2] == k) return true;
	if(A[N/2] < k) return binarySearch(A + N-N/2, N/2,  k);
	return binarySearch(A, N/2, k);
}

bool checkXOR(ull *A, int N){

	ull Xor = 0;
	if( N >= 130 ) return true;
	for(int i = 0; i < N; i++){
		for(int j= i+1; j < N; j++){
			for(int k = j+1; k < N; k++){
				Xor = A[i]^A[j]^A[k];
				if(binarySearch(A + k+1, N - k - 1, Xor))
					return true;
			}
		}
	}
	return false;
}

int main(){
	int N;
	scanf("%d", &N);
	char *result[] = {"No", "Yes"};
	ull *A = (ull *)calloc(N, sizeof(ull));
	for (int i = 0; i < N; ++i)
		scanf("%llu", &A[i]);
	// for (int i = 0; i < N; ++i)
	// 	printf("%llu", A[i]);
	// printf("\n");
	printf("%s\n", result[checkXOR(A, N)]);
}