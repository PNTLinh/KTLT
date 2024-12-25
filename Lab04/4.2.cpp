double area(Point a, Point b, Point c) {
    return 0.5 * abs(a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second));
}
//NguyenThuyLinh_20225031
