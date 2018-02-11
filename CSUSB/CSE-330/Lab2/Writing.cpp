#include <iostream>
using namespace std;
template <typename T>

    CPoint :: CPoint (T a, T b, T c) : x(a), y(b), z(c) {}
    CPoint operator- (const CPoint& param) {
        CPoint temp;
        temp.x = x - param.x;
        temp.y = y - param.y;
        temp.z = z - param.z;
        return temp;
    }
};
template <typename T>
class CVec3 {
public:
    T x,y,z;
    CVec3 () {};
    CVec3 (T a, T b, T c) : x(a), y(b), z(c) {}
    CVec3 operator + (const CPoint& lhs, const CVec3& rhs) {
        CPoint temp;
        temp.x = lhs.x + rhs.x;
        temp.y = lhs.y + rhs.y;
        temp.z = lhs.z + rhs.z;
        return temp;
    }
    CVec3 operator+ (const CVec3& param) {
        CVec3 temp;
        temp.x = x + param.x;
        temp.y = y + param.y;
        temp.z = z + param.z;
        return temp;
    }
};

int main () {
    CPoint <int> p1 (34,15,87);
    CPoint <int> p2 (14,22,53);
    CPoint <int> pntRslt = p2 - p1;
    cout << "Difference between two CPoint objects: "
         << pntRslt.x <<','
         << pntRslt.y <<','
         << pntRslt.z <<'\n';
    CPoint <int> p0 (34,15,87);
    CVec3 <int> v0 (14,22,53);
    CPoint <int> rslt = p0 + v0;
    cout << "Sum of CPoint and CVec3: "
         << rslt.x <<','
         << rslt.y <<','
         << rslt.z <<'\n';
    CVec3 <int> v1 (34,15,87);
    CVec3 <int> v2 (14,22,53);
    CVec3 <int> vecRslt = v1 + v2;
    cout << "Sum of two CVec3 objects: "
         << vecRslt.x <<','
         << vecRslt.y <<','
         << vecRslt.z <<'\n';

    return 0;
}