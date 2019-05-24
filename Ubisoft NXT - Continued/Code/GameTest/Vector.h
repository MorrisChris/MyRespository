#ifndef _VECTOR_H
#define _VECTOR_H

#include "stdafx.h"

class Vector2
{
public:
    float x;
    float y;

public:
    Vector2() {};
    Vector2(float nx, float ny) { x = nx; y = ny; }

    void Set(float nx, float ny) { x = nx, y = ny; }

    inline float const Distance() {return sqrt(float(x * x + y * y)); }

    inline Vector2 operator *(const Vector2& v) const { return Vector2(this->x * v.x, this->y * v.y); }
    inline Vector2 operator /(const Vector2& v) const { return Vector2(this->x / v.x, this->y / v.y); }
    inline Vector2 operator +(const Vector2& v) const { return Vector2(this->x + v.x, this->y + v.y); }
    inline Vector2 operator -(const Vector2& v) const { return Vector2(this->x - v.x, this->y - v.y); }
    inline Vector2 operator *(const float& v) const { return Vector2(this->x * v, this->y * v); }
    inline Vector2 operator /(const float& v) const { return Vector2(this->x / v, this->y / v); }
    inline Vector2 operator +(const float& v) const { return Vector2(this->x + v, this->y + v); }
    inline Vector2 operator -(const float& v) const { return Vector2(this->x - v, this->y - v); }

    inline Vector2 operator *=(const Vector2& v) { this->x *= v.x, this->y *= v.y; return *this; }
    inline Vector2 operator /=(const Vector2& v) { this->x /= v.x, this->y /= v.y; return *this; }
    inline Vector2 operator +=(const Vector2& v) { this->x += v.x, this->y += v.y; return *this; }
    inline Vector2 operator -=(const Vector2& v) { this->x -= v.x, this->y -= v.y; return *this; }
    inline Vector2 operator *=(const float& v) { this->x *= v; this->y *= v; return *this; }
    inline Vector2 operator /=(const float& v) { this->x /= v; this->y /= v; return *this; }
    inline Vector2 operator +=(const float& v) { this->x += v; this->y += v; return *this; }
    inline Vector2 operator -=(const float& v) { this->x -= v; this->y -= v; return *this; }

    inline bool operator ==(const Vector2 &v) { if (this->x == v.x && this->y == v.y) { return true; } return false; }
    inline bool operator !=(const Vector2 &v) { if (this->x != v.x || this->y != v.y) { return true; } return false; }
};

class Vector3
{
public:
    float x;
    float y;
    float z;

public:
    Vector3() {  };
    Vector3(float nx, float ny, float nz) { x = nx; y = ny; z = nz; };

    inline Vector3 operator *(const Vector3& v) const { return Vector3(this->x * v.x, this->y * v.y, this->z * v.z); }
    inline Vector3 operator /(const Vector3& v) const { return Vector3(this->x / v.x, this->y / v.y, this->z / v.z); }
    inline Vector3 operator +(const Vector3& v) const { return Vector3(this->x + v.x, this->y + v.y, this->z + v.z); }
    inline Vector3 operator -(const Vector3& v) const { return Vector3(this->x - v.x, this->y - v.y, this->z - v.z); }
    inline Vector3 operator *(const float& v) const { return Vector3(this->x * v, this->y * v, this->z * v); }
    inline Vector3 operator /(const float& v) const { return Vector3(this->x / v, this->y / v, this->z / v); }
    inline Vector3 operator +(const float& v) const { return Vector3(this->x + v, this->y + v, this->z + v); }
    inline Vector3 operator -(const float& v) const { return Vector3(this->x - v, this->y - v, this->z - v); }

    inline Vector3 operator *=(const Vector3& v) { this->x *= v.x, this->y *= v.y; this->z *= v.z; return *this; }
    inline Vector3 operator /=(const Vector3& v) { this->x /= v.x, this->y /= v.y; this->z /= v.z; return *this; }
    inline Vector3 operator +=(const Vector3& v) { this->x += v.x, this->y += v.y; this->z += v.z; return *this; }
    inline Vector3 operator -=(const Vector3& v) { this->x -= v.x, this->y -= v.y; this->z -= v.z; return *this; }
    inline Vector3 operator *=(const float& v) { this->x *= v; this->y *= v; this->z *= v; return *this; }
    inline Vector3 operator /=(const float& v) { this->x /= v; this->y /= v; this->z /= v; return *this; }
    inline Vector3 operator +=(const float& v) { this->x += v; this->y += v; this->z += v; return *this; }
    inline Vector3 operator -=(const float& v) { this->x -= v; this->y -= v; this->z -= v; return *this; }

    inline bool operator ==(const Vector3 &v) { if (this->x == v.x && this->y == v.y && this->z == v.z) { return true; } return false; }
    inline bool operator !=(const Vector3 &v) { if (this->x != v.x || this->y != v.y || this->z != v.z) { return true; } return false; }
};

class Vector2Int
{
public:
    int x;
    int y;

public:
    Vector2Int() {};
    Vector2Int(int nx, int ny) { x = nx, y = ny; }

    inline Vector2Int operator *(const Vector2Int& v) const { return Vector2Int(this->x * v.x, this->y * v.y); }
    inline Vector2Int operator /(const Vector2Int& v) const { return Vector2Int(this->x / v.x, this->y / v.y); }
    inline Vector2Int operator +(const Vector2Int& v) const { return Vector2Int(this->x + v.x, this->y + v.y); }
    inline Vector2Int operator -(const Vector2Int& v) const { return Vector2Int(this->x - v.x, this->y - v.y); }
    inline Vector2Int operator *(const float& v) const { return Vector2Int(this->x * v, this->y * v); }
    inline Vector2Int operator /(const float& v) const { return Vector2Int(this->x / v, this->y / v); }
    inline Vector2Int operator +(const float& v) const { return Vector2Int(this->x + v, this->y + v); }
    inline Vector2Int operator -(const float& v) const { return Vector2Int(this->x - v, this->y - v); }

    inline Vector2Int operator *=(const Vector2Int& v) { this->x *= v.x, this->y *= v.y; return *this; }
    inline Vector2Int operator /=(const Vector2Int& v) { this->x /= v.x, this->y /= v.y; return *this; }
    inline Vector2Int operator +=(const Vector2Int& v) { this->x += v.x, this->y += v.y; return *this; }
    inline Vector2Int operator -=(const Vector2Int& v) { this->x -= v.x, this->y -= v.y; return *this; }
    inline Vector2Int operator *=(const float& v) { this->x *= v; this->y *= v; return *this; }
    inline Vector2Int operator /=(const float& v) { this->x /= v; this->y /= v; return *this; }
    inline Vector2Int operator +=(const float& v) { this->x += v; this->y += v; return *this; }
    inline Vector2Int operator -=(const float& v) { this->x -= v; this->y -= v; return *this; }

    inline bool operator ==(const Vector2Int &v) { if (this->x == v.x && this->y == v.y) { return true; } return false; }
    inline bool operator !=(const Vector2Int &v) { if (this->x != v.x || this->y != v.y) { return true; } return false; }
};

#endif // !_VECTOR_H
