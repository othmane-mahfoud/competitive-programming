#include <bits/stdc++.h>

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
    
    // Area shit
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


}
