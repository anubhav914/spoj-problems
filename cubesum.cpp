#include <stdio.h>
#include <stdlib.h>


int ***new3DMatrix(int X, int Y, int Z){
	int ***M = (int ***)calloc(X, sizeof(int **));
	for(int i = 0; i < X; i++){
		M[i] = (int **)calloc(Y, sizeof(int *));
		for (int j = 0; j < Y; ++j) 
			M[i][j] = (int *)calloc(Z, sizeof(int));
	}
	return M;
}

int formula(int***CS, int X, int Y, int Z){
	return ( CS[X][Y][Z] - ( CS[X-1][Y][Z] + CS[X][Y-1][Z] + CS[X][Y][Z-1] )
			 + ( CS[X-1][Y-1][Z] + CS[X][Y-1][Z-1] + CS[X-1][Y][Z-1] ) -
			 CS[X-1][Y-1][Z-1] );
}

/**
CS is cubeSum
CO is the cubeOrignal
*/
int ***origCubFromCubeSum(int ***CS, int X, int Y, int Z){
	int ***CO = new3DMatrix(X+1,Y+1,Z+1);
	for(int i = 1; i <= X; i++)
		for(int j = 1; j <= Y; j++)
			for(int k = 1; k <= Z; k++) CO[i][j][k] = formula(CS, i, j, k);
	return CO;
}

void print3DMatrix(int ***M, int X, int Y, int Z){
	for(int i = 1; i <= X; i++){
			for(int j = 1; j <= Y; j++){
				for(int k = 1; k <= Z; k++)
					printf("%d ", M[i][j][k]);
				printf("\n");
			}
	}
	return;
}

int main(){
	int T,X,Y,Z;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &X, &Y, &Z);
		// printf("%d %d %d\n", X, Y, Z);
		int ***B = new3DMatrix(X+1, Y+1, Z+1);
		for(int i = 1; i <= X; i++)
			for(int j = 1; j <= Y; j++)
				for(int k = 1; k <= Z; k++)
					scanf("%d", &B[i][j][k]);
		// print3DMatrix(B,X,Y,Z);
		print3DMatrix(origCubFromCubeSum(B, X, Y, Z), X, Y, Z);
	}
}