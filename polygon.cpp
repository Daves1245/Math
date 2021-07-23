#include <iostream>
#include <vector>
#include <stdio.h>
#include <utility>

using namespace std;

typedef pair<int, int> point;
typedef vector<point> polygon;

/*
 * area_triangle - implementation of shoelace theorem for a triangle
 */
double area_triangle(polygon &p, int offset) {
    double area = 0;
    for (int i = 0; i < 3; i++) {
        area += (double) p[offset + i].first * p[offset + i + 1].second - p[offset + i + 1].first * p[offset + i].second;
    }
    return area / 2;
}

/*
 * sign - return whether the area is positive, 0, or negative
 */
int sign(double a) {
    return a == 0 ? a : a / abs(a);
}

/*
 * inbounds - return true iff point p lies within the convex polygon poly
 */
bool inbounds(polygon &poly, point &p) {
    int n = poly.size();
    int s = sign(area_triangle(poly, 0));
    for (int i = 0; i < n - 3; i++) {
        swap(poly[i], p);
        if (sign(area_triangle(poly, i)) != s) {
            return false;
        }
        swap(poly[i], p);
    }
    return true;
}

int main() {
    int n;
    point p;

    cout << "Number of vertices: " << endl;
    cin >> n;
    cout << n << endl;
    polygon poly(n + 1);
    cout << "Points of convex polygon: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> poly[i].first >> poly[i].second;
    }
    poly[n] = poly[0];

    cout << "Point: " << endl;
    cin >> p.first >> p.second;
    if (inbounds(poly, p)) {
        cout << "p lies within the polygon" << endl;
    } else {
        cout << "p does not lie within the polygon" << endl;
    }
    return 0;
}
