#pragma once
#include<stdio.h>
#define LENGTH 4

struct DeBrujin {
	int path[LENGTH][LENGTH];
	int weight[LENGTH][LENGTH];
};

struct ThreeTuple {
	int start;
	int end;
	int route;
};

void initDeBrujin(DeBrujin d);
