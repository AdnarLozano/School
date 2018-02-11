#include <iostream>
using namespace std;

class CVec3;

template <typename T>
class CPoint {
public:
	T x,y,z;
	CPoint () {}
    CPoint (T a, T b, T c) : x(a), y(b), z(c) {}
    CVec3<int> operator- (const CPoint& param) {
        CVec3<int> temp;
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
    friend CVec3 operator+ (const CVec3& lhs, const CVec3& rhs) {
        CVec3 temp;
        temp.x = lhs.x + rhs.x;
        temp.y = lhs.y + rhs.y;
        temp.z = lhs.z + rhs.z;
        return temp;
    }
    // CVec3 operator+ (const CVec3& param) {
    //     CVec3 temp;
    //     temp.x = x + param.x;
    //     temp.y = y + param.y;
    //     temp.z = z + param.z;
    //     return temp;
    // }
    // CVec3 operator+ (const CPoint<int>& param) {
    //     CVec3 temp;
    //     temp.x = x + param.x;
    //     temp.y = y + param.y;
    //     temp.z = z + param.z;
    //     return temp;
    // }

};

int main () {
    CPoint <int> p1 (34,15,87);
    CPoint <int> p2 (14,22,53);
    CPoint <int> pntRslt = p2 - p1;
    cout << "Difference between two CPoint objects: "
         << pntRslt.x <<','
         << pntRslt.y <<','
         << pntRslt.z <<'\n';
    CVec3 <int> p0 (3,1,8);
    CVec3 <int> v0 (4,2,5);
    CVec3 <int> rslt = p0 + v0;
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