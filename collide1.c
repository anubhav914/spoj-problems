// COLLIDE

#include <stdio.h>

#define gc getchar_unlocked
inline int getn(){
	int n = 0, c = gc(), f = 1;
	while(c != '-' && (c < '0' || c > '9')) c = gc();
	if(c == '-') f = -1, c = gc();
	while(c >= '0' && c <= '9')
		n = (n<<3) + (n<<1) + c - '0', c = gc();
	return n * f;
}

float m;
void setm(float n){
	if(n < m)
		m = n;
}
int main(){
	char ed,ad;
	int T = getn(),N,ex,ey,ax,ay, i;
	while(T--){
		ex = getn(), ey = getn(), ed = gc(), N = getn(), m = 201;
		while(N--){
			ax = getn(), ay = getn(), ad = gc();
			// a NW of e
			if(ex>ax && ey<ay && ex-ax==ay-ey && ((ed=='U'&&ad=='R') ||
				(ed=='L'&&ad=='D'))) setm(ex-ax);
			// a N of e
			else if(ex==ax && ey<ay && ed=='U' && ad=='D') setm((float)(ay-ey)/2);
			// a NE of e
			else if(ex<ax && ey<ay && ax-ex==ay-ey && ((ed=='U'&&ad=='L') ||
				(ed=='R'&&ad=='D'))) setm(ax-ex);
			// a E of e
			else if(ex<ax && ey==ay && ed=='R' && ad=='L') setm((float)(ax-ex)/2);
			// a SE of e
			else if(ex<ax && ey>ay && ax-ex==ey-ay && ((ed=='R'&&ad=='U') ||
				(ed=='D'&&ad=='L'))) setm(ax-ex);
			// a S of e
			else if(ex==ax && ey>ay && ed=='D' && ad=='U') setm((float)(ey-ay)/2);
			// a SW of e
			else if(ex>ax && ey>ay && ex-ax==ey-ay && ((ed=='D'&&ad=='R') ||
				(ed=='L'&&ad=='U'))) setm(ex-ax);
			// a W of e
			else if(ex>ax && ey==ay && ed=='L' && ad=='R') setm((float)(ex-ax)/2);
		}
		printf(m==201?"SAFE\n":"%.1f\n",m);
	}
	return 0;
}