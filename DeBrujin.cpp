#include<stdio.h>
#include<stdlib.h>
#include"DeBrujin.h"
#define LENGTH 8
#define LENGTHOFSTRING 6


ThreeTuple* initDeBrujin(int *rules) {
	int i, j, k;
	ThreeTuple *t = (ThreeTuple*)malloc(LENGTH*sizeof(ThreeTuple));
	for (i = 0; i < LENGTH; i++) {
		t[i].start = i / 2;
		t[i].end = i % (LENGTH / 2);
		t[i].route = rules[i];
	}
	return t;
}


void getRoute(ThreeTuple* t, int* str, int* route, int start, int task) {
	//0000|01000111|0000
	//0000|********|0000
	int i, j, k;
	if (task == LENGTHOFSTRING) {
		if (start % 2 == 0) {//这里会因规则长度的不同发生改变
			//成功
			for (i = 0; i < LENGTHOFSTRING; i++) {
				printf("%d", str[i]);
			}
			printf("\n");
		}
		free(str);
		return;
	}
	//printf("%d", task);
	for (i = 0; i < LENGTH; i++) {
		if (t[i].start == start && t[i].route == route[task]) {
			str[task] = start % 2;//这里会因规则长度的不同发生改变
			int* newstr = (int*)malloc(LENGTH * sizeof(int));
			for (j = 0; j <= task; j++) {
				newstr[j] = str[j];
			}
			getRoute(t, newstr, route, t[i].end, task + 1);
		}
	}
	free(str);
}

int main() {
	int i, j, k;
	int rules[LENGTH] = { 0,0,0,0,1,1,1,1 };
	int route[LENGTHOFSTRING] = { 0,0,1,0,1,0 };
	
	ThreeTuple* t = initDeBrujin(rules);
	for (i = 0; i < LENGTH / 4; i++) {
		int* str = (int*)malloc(LENGTH * sizeof(int));
		getRoute(t, str, route, i, 0);
	}
}