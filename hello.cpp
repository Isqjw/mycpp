#include <iostream>

using namespace std;

class Point3d {
    public:
        int x, y, z;
};

int main()
{
    cout << "hello world." << endl;
    printf("&Point3d::x = %p\n", &Point3d::x);
    printf("&Point3d::y = %p\n", &Point3d::y);
    printf("&Point3d::z = %p\n", &Point3d::z);
    int Point3d::*p1 = NULL;
    int Point3d::*p2 = &Point3d::x;
    int Point3d::*p3 = &Point3d::y;
    printf("p1 = %p\n", p1);
    printf("p2 = %p\n", p2);
    printf("p3 = %p\n", p3);
    if (0 == p2) {
        cout << "true" << endl;
    }

    system("pause");

    return 0;
}