#include <iostream>
class Vector3D {
    private: float x, y, z;
    public: Vector3D(float x = 0.0, float y = 0.0, float z = 0.0) : x(x), y(y), z(z){}
    float getX() const {
        return x;
    };
    float getY() const {
        return y;
    };
    float getZ() const {
        return z;
    };
    void setX(float newX){
        x = newX;
    };
    void setY(float newY){
        y = newY;
    };
    void setZ(float newZ){
        z = newZ;
    };
    Vector3D operator + (const Vector3D& v) const {
        return Vector3D(x + v.x, y + v.y, z + v.z);
    };
    Vector3D operator - (const Vector3D& v) const {
        return Vector3D(x - v.x, y - v.y, z - v.z);
    };
    float dotProduct(const Vector3D& v) const {
        return x * v.x + y * v.y + z * v.z;
    };
    Vector3D crossProduct(const Vector3D& v) const {
        return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
    };
};
int main(){
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(4.0, 5.0, 6.0);
    Vector3D v3 = v1 + v2;
    std::cout << "v3 = (" << v3.getX() << ", " << v3.getY() << ", " << v3.getZ() << ")" << std::endl;
    Vector3D v4 = v1 - v2;
    std::cout << "v4 = (" << v4.getX() << ", " << v4.getY() << ", " << v4.getZ() << ")" << std::endl;
    float dotProd = v1.dotProduct(v2);
    std::cout << "Dot product of v1 and v2 = " << dotProd << std::endl;
    Vector3D crossProd = v1.crossProduct(v2);
    std::cout << "Cross product of v1 and v2 = (" << crossProd.getX() << ", " << crossProd.getY() << ", " << crossProd.getZ() << ")" << std::endl;
    return 0;
};