#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

ll Sum(ll *A, ll N){
	ll sum = 0;
	for(int i = 0; i < N; sum+=A[i],i++);
	return sum;
}

ll Max(ll *A, ll N){
	ll max = A[0];
	for(int i = 0; i < N; i++)
		if(max < A[i]) max = A[i];
	return max;
}

ll Min(ll *A, ll N){
	ll min = A[0];
	for(int i = 0; i < N; i++)
		if(min > A[i]) min = A[i];
	return min;
}

int index(ll *A, ll N, ll val){
	for(int i = 0; i < N; i++)
		if(A[i] == val) return i;
	return -1;
}


void performOp(ll *A, ll N, int minIndex, int maxIndex){
	ll temp = A[maxIndex] - A[minIndex];
	if(temp%2) temp++;
	temp = temp/2;
	A[minIndex] += temp;
	A[maxIndex] -= temp;
}

int compareMytype(const void *a, const void *b){
	if(*(ll *)a - *(ll *)b > (ll)0) return 1;
	if(*(ll *)a - *(ll *)b < (ll)0) return -1;
	return 0;
}

int main(){
	ll T, N, *A;
	scanf("%lld", &T);
	while(T--){
		scanf("%lld", &N);
		A = (ll *)calloc(N, sizeof(ll));
		for (int i = 0; i < N; ++i)
			scanf("%lld", &A[i]);
		if(Sum(A,N)%N != 0){
			printf("%d\n", -1);
			continue;
		}
		ll count = 0;
		while(Max(A,N) != Min(A,N)){
			performOp(A, N, index(A, N, Max(A,N)), index(A, N, Min(A,N)));
			count++;
		}
		printf("%lld\n", count);
	}
}
