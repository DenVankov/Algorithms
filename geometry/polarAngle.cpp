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

Vec operator * (Vec v1, ld a) {
    return Vec {v1.x * a, v1.y * a};
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed;
    cout.precision(10);

    Vec v1;
    Vec v2;

    cin >> v1.x >> v1.y >> v2.x >> v2.y;

    cout << abs(atan2(vecmul(v1, v2), scalmul(v1, v2))) << "\n";

    return 0;
}