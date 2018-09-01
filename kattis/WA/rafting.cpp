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

double cross(point P, point Q) {
    return real(P)*imag(Q) - imag(P)*real(Q);
}

double ccw(point a, point b, point c) {
    return cross(b - a, c - b);
}

point closest_point(line l, point p, bool segment = false) {
    if (segment) {
        if (dot(l.second - l.first, p - l.second) > 0) return l.second;
        if (dot(l.first - l.second, p - l.first) > 0) return l.first;
    }
    double t = dot(p - l.first, l.second - l.first) / norm(l.second - l.first);
    return l.first + t * (l.second - l.first);
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n;
        polygon inner(n);
        for (int i = 0; i < n; ++i){
            int x, y;
            cin >> x >> y;
            point p(x, y);
            inner[i] = p;
        }
        cin >> m;
        polygon outer(m);
        for (int i = 0; i < m; ++i){
            int x, y;
            cin >> x >> y;
            point p(x, y);
            outer[i] = p;
        }
        // if the points of outer polygon are given in clockwise order put them in counter clockwise order
        if (ccw(outer[0], outer[1], outer[2]) < 0)
            reverse(outer.begin(), outer.end());
        double min_dist = 10000.00;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m - 1; ++j){
                line edge = make_pair(outer[j], outer[j+1]);
                point closest = closest_point(edge, inner[i], true);
                min_dist = min(min_dist, distance(inner[i], closest));
            }
            // handle the last edge between last and first point
            line edge = make_pair(outer[m-1], outer[0]);
            point closest = closest_point(edge, inner[i], true);
            min_dist = min(min_dist, distance(inner[i], closest));
        }
        printf("%0.8lf\n", min_dist/2);
    }
}


















