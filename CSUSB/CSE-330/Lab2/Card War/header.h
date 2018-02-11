#ifndef HEADER_H
#define HEADER_H
class CPoint {
public:
    T x,y,z;
    CPoint ();
    CPoint (T a, T b, T c) : x(a), y(b), z(c) {}
};

class CVec3 {
public:
    T x,y,z;
    CVec3 ();
    CVec3 (T a, T b, T c) : x(a), y(b), z(c) {}
};

#endif