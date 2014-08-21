#include <stdio.h>
#include <stdlib.h>

struct cordinate{
	int x;
	int y;
};

bool hori[] = {false, true, false, true};
bool verti[] = {true, false, true, false};

int iDir(char dir){
	const char *dirs = "ULDR";
	for(int i = 0; i < 4; i++)
		if(dirs[i] == dir) return i;
}

int opposite(int dir){
	return (dir+2)%4;
}

int relVelocity(int earthDir, int asteroidDir, bool *axis, int axisCoeff){
	if(axis[asteroidDir]){
		if(earthDir == opposite(asteroidDir)) return 2*(asteroidDir - axisCoeff);
		if(earthDir == asteroidDir) return 0;
		return asteroidDir - axisCoeff;
	}
	if(axis[earthDir]) return -1 * (earthDir - axisCoeff);
	return 0;
}


float timeToReachGoalin1D(int end, int start, int velocity){
	if(velocity == 0)
		return start == end ? 0.0 : -1.0;
	if(start == end) return -1.0;
	if( (float(end - start))/velocity < 0 ) return -1.0;
	return (float(end - start))/velocity;
}

float timeToReachGoal( cordinate goal, cordinate start, 
				   int goalDir, int startDir){

	int velocityX = relVelocity(goalDir, startDir, hori, 2);
	int velocityY = relVelocity(goalDir, startDir, verti, 1);
	float timeX = timeToReachGoalin1D(goal.x, start.x, velocityX);
	float timeY = timeToReachGoalin1D(goal.y, start.y, velocityY);
	if(timeX == timeY) return timeX;
	if(timeX == 0 or timeY == 0) return timeY + timeX;
	return -1.0;
}

float minTimeToReachGoal(cordinate goal, cordinate* starts, 
						 int goalDir, int* startDirs, int N){

	float minTime = -1.0, timeToHit;
	for(int i = 0; i < N; i++){
		timeToHit = timeToReachGoal(goal, starts[i], goalDir, startDirs[i]);
		if((minTime == -1.0 or minTime > timeToHit) and timeToHit != -1.0)
			minTime = timeToHit;
	}
	return minTime;
}

int main(){
	int T, earthDir, N; cordinate earth; char dir; float minTime;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %c", &earth.x, &earth.y, &dir); earthDir = iDir(dir);
		scanf("%d", &N);
		cordinate *asteroids = (cordinate *)calloc(N, sizeof(cordinate));
		int *asteroidDirs = (int *)calloc(N, sizeof(int));
		for (int i = 0; i < N; ++i){
			scanf("%d %d %c", &asteroids[i].x, &asteroids[i].y, &dir);
			asteroidDirs[i] = iDir(dir);
		}
		minTime = minTimeToReachGoal(earth, asteroids, earthDir, asteroidDirs, N);
		if(minTime != -1.0) printf("%.1f\n", minTime);
		else printf("%s\n", "SAFE");
	}
}