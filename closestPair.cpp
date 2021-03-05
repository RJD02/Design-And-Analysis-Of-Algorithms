#include<bits/stdc++.h>
using namespace std;

class Point {
	public:
		int x, y;
};

int compareX(const void* a, const void* b) {
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return p1 -> x - p2 -> x;
}

int compareY(const void* a, const void* b) {
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return p1 -> y - p2 -> y;
}

float dist(Point p1, Point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

// A brute force method to return the 
// smallest distance between two points
// in P[] of size n
float bruteForce(Point p[], int n) {
	float min = FLT_MAX;
	for(int i = 0; i < n; i++) {
		for(int ii = i + 1; ii < n; ii++) {
			if(dist(p[i], p[ii]) < min)
				min = dist(p[i], p[ii]);
		}
	}
	return min;
}

float min(float a, float b) {
	return (a < b) ? a : b;
}
// A utility function to find the 
// distance between the closest points of strip of given
// size.
float stripClosest(Point strip[], int size, float d) {
	float min = d;
	qsort(strip, size, sizeof(Point), compareY);
	for(int i = 0; i < size; ++i)
		for(int ii = i + 1; ii < size && (strip[ii].y - strip[ii].y) < min; ++ii)
			if(dist(strip[i], strip[ii]) < min)
					min = dist(strip[i], strip[ii]);
	return min;
}

float closestUtil(Point p[], int n) {
	if(n <= 3)
		return bruteForce(p, n);
	int mid = n / 2;
	Point midpoint = p[mid];
	float dl = closestUtil(p, mid);
	float dr = closestUtil(p + mid, n - mid);
	float d = min(dl, dr);
	Point strip[n];
	int j = 0;
	for(int i = 0; i < n; i++) {
		if(abs(p[i].x - midpoint.x) < d)
			strip[j] = p[i], j++;
	}
	return min(d, stripClosest(strip, j, d));
}

float closest(Point p[], int n) {
	qsort(p, n, sizeof(Point), compareX);
	return closestUtil(p, n);
}

int main() {
	Point p[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	int n = 6;
	cout << "The smallest distance is: " << closest(p, n);
	return 0;
}
