#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld PI = acosl(-1.0);

struct Vec {
    ld x;
    ld y;
    ld len() const {
        return sqrtl(x * x + y * y);
    }
};

Vec operator + (Vec v1, Vec v2) {
    return Vec {v1.x + v2.x, v1.y + v2.y};
}

Vec operator - (Vec v1, Vec v2) {
    return Vec {v1.x - v2.x, v1.y - v2.y};
}

Vec operator * (ld a, Vec v1) {
    return Vec {a * v1.x, a * v1.y};
}

Vec operator / (Vec v1, ld a) {
    return Vec {v1.x / a, v1.y / a};
}

ld scalmul(Vec v1, Vec v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

ld vecmul(Vec v1, Vec v2) {
    return v1.x * v2.y - v1.y * v2.x;
}

ld dist(Vec v1, Vec v2) {
    return (v2 - v1).len();
}

Vec norm(Vec v) {
    return v / v.len();
}

Vec findLinesIntersection(Vec p1, Vec p2, Vec p3, Vec p4) {
    ld t = vecmul(p3 - p1, p4 - p3) / vecmul(p2 - p1, p4 - p3);
    return p1 + t * (p2 - p1);
}

bool areParallel(Vec v1, Vec v2) {
    return (vecmul(v1, v2) == 0);
}

int sign(ld x) {
    if (x == 0)
        return 0;
    else if (x < 0)
        return -1;
    else
        return 1;
}

bool isOnSegment(Vec p, Vec p1, Vec p2) {
    return vecmul(p - p1, p2 - p1) == 0 && scalmul(p1 - p, p2 - p) <= 0;
}

bool areSegmentsIntersecting(Vec p1, Vec p2, Vec p3, Vec p4) {
    if (areParallel(p2 - p1, p4 - p3)) {
        return isOnSegment(p1, p3, p4) || isOnSegment(p2, p3, p4) || isOnSegment(p3, p1, p2) || isOnSegment(p4, p1, p2);
    } else {
        return sign(vecmul(p2 - p1, p4 - p1)) * sign(vecmul(p2 - p1, p3 - p1)) <= 0 &&
               sign(vecmul(p4 - p3, p1 - p3)) * sign(vecmul(p4 - p3, p2 - p3)) <= 0;
    }
}

bool isPointInTriangle(Vec p, Vec p1, Vec p2, Vec p3) {
    int cnt = 0;
    Vec new_p;
    new_p.x = 10e5;
    new_p.y = p.y + 1;

    if (isOnSegment(p, p1, p2) || isOnSegment(p, p1, p3) || isOnSegment(p, p2, p3)) {
        return true;
    }

    cnt += areSegmentsIntersecting(p, new_p, p1, p2);
    cnt += areSegmentsIntersecting(p, new_p, p2, p3);
    cnt += areSegmentsIntersecting(p, new_p, p1, p3);

    return cnt == 1;
}

bool isPointInAngle(Vec p, Vec p1, Vec p2, Vec p3) {
    if (isOnSegment(p, p1, p2) || isOnSegment(p, p1, p3)) {
        return true;
    }

    return sign(vecmul(p - p1, p2 - p1)) * sign(vecmul(p - p1, p3 - p1)) <= 0;
}

bool isPointInConvexPolygon(Vec p, vector<Vec>& polygon) {
    if (!isPointInAngle(p, polygon[0], polygon[1], polygon.back()))
        return false;
    long long l = 1;
    long long r = polygon.size() - 1;
    while (l + 1 < r) {
        long long mid = (l + r) / 2;
        if (vecmul(polygon[mid] - polygon[0], p - polygon[0]) >= 0)
            l = mid;
        else
            r = mid;
    }

    return isPointInTriangle(p, polygon[0], polygon[l], polygon[r]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    Vec p1;
    Vec p2;

    cin >> p1.x >> p1.y;
    Vec first = p1;
    ld s = 0;

    // Gauss's formula for polygon square
    for (int i = 1; i < n; ++i) {
        cin >> p2.x >> p2.y;
        s += vecmul(p1, p2);
        p1 = p2;
    }
    s += vecmul(p2, first);
    cout << fabsl(s) / (long double) 2 << "\n";
    return 0;
}

/*
test:
5
2 4
5 5
7 3
4 1
4 3
ans:
17/2
*/