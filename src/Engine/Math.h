class Vector2
{
public:
    float x, y;

    void Normalise();
    void Rotate(float rotationAmount);
};

class Vector3
{
public:
    float x, y, z;

    Vector3()
    {
        x = 0f;
        y = 0f;
        z = 0f;
    }
    
    Vector3(float _x, float _y, float _z)
    {
        x = _x;
        y = _y;
        z = _z;
    }
    
    Vector3(const Vector2 &vec2)
    {
        x = vec2.x;
        y = vec2.y;
        z = 0f;
    }

    const bool Compare(const Vector3 &other)
    {
        return (x == other.x && y == other.y && z == other.z);
    }

    void Zero();
    void Set(float x, float y, float z);

    const Vector3 operator^(const Vector3 &rhs)
    {
        x = rhs.y * z - y * rhs.z;
        y = rhs.z * x - z * rhs.x;
        z = rhs.x * y - x * rhs.y;

        return this;
    }
    
    const float operator*(const Vector3 &rhs)
    {
        return y * rhs.y + rhs.x * x + z * rhs.z;
    }
    
    const Vector3 operator/(float rhs)
    {
        x *= (1f / rhs);
        y *= (1f / rhs);
        z *= (1f / rhs);

        return this;
    }
    
    Vector3 operator*=(float rhs)
    {
        x *= rhs;
        y *= rhs;
        z *= rhs;

        return this;
    }
    
    Vector3 operator/=(float rhs)
    {
        x *= (1f / rhs);
        y *= (1f / rhs);
        z *= (1f / rhs);
        
        return this;
    }
    
    Vector3 operator-=(const Vector3 &rhs)
    {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;

        return this;
    }

    void Normalise()
    {
        float magNorm = (y * y) + (x * x) + (z * z);

        if (magNorm > 0f)
        {
            magNorm = 1f / fsqrt(magNorm);

            // x = x * magNorm;
            // y = y * magNorm;
            // z = z * magNorm;
            this *= magNorm;
        }
        else
        {
            x = 0f;
            y = 0f;
            z = 1f;
        }
    }

    void SetLength(float length)
    {
        // TODO
    }

    const void Mag()
    {
        return fsqrt((z * z) + (y * y) + (x * x));
    }

    void HorizontalAndNormalise()
    {
        float norm = 1f / fsqrt(z * z + x * x);

        x *= norm;
        y = 0f;
        z *= norm;
    }

    Vector3 *GetData()
    {
        return this;
    }

    const Vector3 *GetDataConst()
    {
        return this;
    }

    void RotateAround(const Vector3 &other);
    void RotateAroundX(float rotationAmount);
    void RotateAroundY(float rotationAmount);
    void RotateAroundZ(float rotationAmount);
    void FastRotateAround(const Vector3 &other, float rotationAmount);

    const bool operator==(const Vector3 &rhs)
    {
        return Compare(rhs);
    }

    const bool operator!=(const Vector3 &rhs)
    {
        return !Compare(rhs);
    }
};

namespace Math
{
    bool DoesLineIntersect(const Vector2 &a1, const Vector2 &a2,
                           const Vector2 &a3, const Vector2 &a4,
                           Vector2 *intersection);

    bool DoesRayIntersect(const Vector2 &a1, const Vector2 &a2,
                          const Vector2 &a3, const Vector2 &a4,
                          Vector2 *intersection);

    float DistancePointToLine(const Vector2 &a1, const Vector2 &a2,
                              const Vector2 &a3, Vector2 *a4);

    bool AreLinesOverlapping(const Vector2 &a1, const Vector2 &a2,
                             const Vector2 &a3, const Vector2 &a4);

    bool PointInsidePolygon2d(const Vector2 &a1, Vector2 *a2, int a3);

    const Vector3 &RaySphereIntersection(const Vector3 &a1, const Vector3 &a2,
                                         float a3, const Vector3 &a4, float a5);

    bool PointInsideSphere(const Vector3 &a1, const Vector3 &a2, float radius);

    bool PointInsideCone(const Vector3 &a1, const Vector3 &a2,
                         const Vector3 &a3, float a4);

    const Vector3 &RayTriIntersection(const Vector3 &a1, const Vector3 &a2, float a3, 
                                      const Vector3 &a4, const Vector3 &a5, 
                                      const Vector3 &a6);

    const Vector3 &RayQuadIntersection(const Vector3 &a1, const Vector3 &a2, float a3, 
                                       const Vector3 &a4, const Vector3 &a5, 
                                       const Vector3 &a6, const Vector3 &a7);

    const Vector3 &RayPlaneIntersection(const Vector3 &a1, const Vector3 &a2, float a3,
                                        const Vector3 &a4, const Vector3 &a5);

    bool DoesRayIntersectBox(const Vector3 &a1, const Vector3 &a2,
                             float a3, const Vector3 &a4, const Vector3 &a5);
    
    bool DoesBoxIntersectBox(const Vector3 &a1, const Vector3 &a2,
                             const Vector3 &a3, const Vector3 &a4);

    void BoxIntersectBox(Vector3 &a1, Vector3 &a2,
                         const Vector3 &a3, const Vector3 &a4,
                         const Vector3 &a5, const Vector3 &a6);

    float Log2(float val);
    double RampUpAndDown(double a1, double a2, double a3);
    void TruncateFloatPrecision(float *f);
    float MapRangeClamp(float a1, float a2, float a3, float a4, float a5);
    bool AABBIntersect2D(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8);
    float NormaliseRange(float a1, float a2, float a3);
    bool MoveToTarget(Vector2 &currentPos, const Vector2 &targetPos, float speed);
}

