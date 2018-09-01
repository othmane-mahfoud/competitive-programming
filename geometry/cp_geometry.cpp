#include <bits/stdc++.h>

#define MAXN 1000

using namespace std;

// data types defs
typedef complex<double> point;
typedef vector<point> polygon;
typedef pair<point, double> circle;
typedef pair<point, point> line;

// global vars
const double pi = acos(-1.0);
const double EPS = 1e-9;

double distance(point P, point Q){
	return sqrt(pow(real(P) - real(Q), 2.0) + pow(imag(P) - imag(Q), 2.0));
}

double dot(point P, point Q) {
    return real(P) * real(Q) + imag(P) * imag(Q);
}

double angle(point P, point Q, point R) {
    return acos(dot(Q - P, R - Q) / (abs(Q - P) * abs(R - Q)));
}

double cross(point P, point Q) {
    return real(P)*imag(Q) - imag(P)*real(Q);
}

double ccw(point a, point b, point c) {
    return cross(b - a, c - b);
}

double triangle_area(point P, point Q){
    return cross(P, Q) / 2;
}

double polygon_area(polygon pol){
    point S = pol[0];
    double area = 0;
    for (int i = 1; i < pol.size() - 1; i++) {
        area += triangle_area(pol[i] - S, pol[i+1] - S);
    }
    return area;
}

bool parallel(line a, line b) { 
    return abs(cross(a.second - a.first, b.second - b.first)) < EPS; 
}

point closest_point(line l, point p, bool segment = false) {
    if (segment) {
        if (dot(l.second - l.first, p - l.second) > 0) return l.second;
        if (dot(l.first - l.second, p - l.first) > 0) return l.first;
    }
    double t = dot(p - l.first, l.second - l.first) / norm(l.second - l.first);
    return l.first + t * (l.second - l.first);
}

// convex hull
point hull[MAXN];

bool cmp(const point &a, const point &b) {
    return abs(real(a) - real(b)) > EPS ? real(a) < real(b) : imag(a) < imag(b);
}

int convex_hull(vector<point> p) {
    int n = p.size(), l = 0;
    sort(p.begin(), p.end(), cmp);
    for (int i = 0; i < n; i++) {
        if (i > 0 && p[i] == p[i - 1])
            continue;
        while (l >= 2 && ccw(hull[l - 2], hull[l - 1], p[i]) >= 0)
            l--;
        hull[l++] = p[i];
    }
    int r = l;
    for (int i = n - 2; i >= 0; i--) {
        if (p[i] == p[i + 1])
            continue;
        while (r - l >= 1 && ccw(hull[r - 2], hull[r - 1], p[i]) >= 0)
            r--;
        hull[r++] = p[i];
    }
    return l == 1 ? 1 : r - 1;
}

int main(){
    point p(0, 1);
    point q(1, 0);
    point r(0, 3);
    point t(2, 0);
    point sum = p + q;
    cout << real(sum) << " " << imag(sum) << endl;
    cout << distance(p, q) << endl;
    
    // This pair defines a line or segment -- it is just two points
    line l1 = make_pair(p, q);
    line l2 = make_pair(r, t);
    if (parallel(l1, l2))
	    cout << "parallel" << endl;
	else
		cout << "intersect" << endl;
    
    // Circle is a point and radius
    double radius = 2.0;
    point center(0, 0);
    circle c = make_pair(center, radius);
    
    // Working with vectors using complex class
    point P(1.0, 0.0);
    point Q(0.0, 0.0);
    point R(0.0, 1.0);
    cout << dot(P, R) << endl;
    cout << angle(P, Q, R) << endl;
    cout << cross(P - Q, R - Q) << endl;
    
    // points to test polygon/triangle area
    point A(3.0, 1.0);
    point B(0.0, 0.0);
    point C(3.0, 0.0);
    point D(0.0, 1.0);
    
    // vector holding points of polygon
    polygon pol;
    
    // pushing points in counter clockwise order
    pol.push_back(C);
    pol.push_back(A);
    pol.push_back(D);
    pol.push_back(B);
    
    cout << triangle_area(C-B, A-B) << endl;
    
    cout << "polygon area is: " << polygon_area(pol) << endl;

    // checking order of points
    if (ccw(A, C, D) > 0)
    	cout << "counter clockwise" << endl;
    else
    	cout << "clockwise" << endl;

    // checking closest point on a line to point
    line l = make_pair(P, Q);
    point test(0.7, 0.2);
    point closest = closest_point(l, test, false);
    cout << "closest point is: (" << real(closest) << ", " << imag(closest) << ")" << endl;
    
    
    // testing convex hull func
    point p1(0, 3);
    point p2(2, 2);
    point p3(1, 1);
    point p4(2, 1);
    point p5(3, 0);
    point p6(0, 0);
    point p7(3, 3);
    
    vector<point> ch;
    
    ch.push_back(p1);
    ch.push_back(p2);
    ch.push_back(p3);
    ch.push_back(p4);
    ch.push_back(p5);
    ch.push_back(p6);
    ch.push_back(p7);
    
    cout << convex_hull(ch) << endl;

}
