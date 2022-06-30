#include "Math.h"

bool Math::DoesLineIntersect(const Vector2 &a1, const Vector2 &a2,
                             const Vector2 &a3, const Vector2 &a4,
                             Vector2 *intersection)
{
    float v14; // xmm3_4
    float v17; // xmm0_4
    float v18; // xmm2_4

    v14 = ((a4.y - a3.y) * (a2.x - a1.x)) - ((a4.x - a3.x) * (a2.y - a1.y));

    if (fabs(v14) >= 0.000001f)
    {
        v17 = (((a4.x - a3.x) * (a1.y - a3.y)) - ((a4.y - a3.y) * (a1.x - a3.x))) / v14;

        if (v17 >= 0f && v17 <= 1f)
        {
            v18 = (((a1.y - a3.y) * (a2.x - a1.x)) - ((a1.x - a3.x) * (a2.y - a1.y))) / v14;

            if (v18 > 0f && v18 < 1f)
            {
                if (intersection)
                {
                    intersection->x = a1.x + ((a2.x - a1.x) * v17);
                    intersection->y = a1.y + (v17 * (a2.y - a1.y));
                }

                return true;
            }
        }
    }

    return false;
}

bool Math::DoesRayIntersect(const Vector2 &a1, const Vector2 &a2,
                            const Vector2 &a3, const Vector2 &a4,
                            Vector2 *intersection)
{
    float v11; // xmm1_4
    float v13; // xmm0_4

    v11 = ((a2.x - a1.x) * a4.y) - ((a2.y - a1.y) * a4.x);

    if (fabs(v11) >= 0.000001f)
    {
        v13 = ((a4.x * (a1.y - a3.y)) - (a4.y * (a1.x - a3.x))) / v11;

        if (v13 >= 0f && v13 <= 1f)
        {
            if (intersection)
            {
                intersection->x = ((a2.x - a1.x) * v13) + a1.x;
                intersection->y = (v13 * (a2.y - a1.y)) + a1.y;
            }

            return true;
        }
    }

    return false;
}

float Math::DistancePointToLine(const Vector2 &a1, const Vector2 &a2,
                                const Vector2 &a3, Vector2 *a4)
{
    // TODO: Double check if this is correct.
    float f1 = ((a1.x - a2.x) * (a3.x - a2.x)) + ((a1.y - a2.y) * (a3.y - a2.y));
    
    if (f1 <= 0f)
    {
        if (a4)
        {
            a4->x = a2.x;
            a4->y = a2.y;
        }

        return fsqrt(((a2.y - a1.y) * (a2.y - a1.y)) + 
                     ((a2.x - a1.x) * (a2.x - a1.x)));
    }

    float f2 = ((a3.y - a2.y) * (a3.y - a2.y)) + 
               ((a3.x - a2.x) * (a3.x - a2.x));
    
    if (f1 < f2)
    {
        if (a4)
        {
            a4->x = a2.x + ((f1 / f2) * (a3.x - a2.x));
            a4->y = a2.y + ((a3.y - a2.y) * (f1 / f2));
        }

        // This may be incorrect.
        a2.x = a2.x + ((f1 / f2) * (a3.x - a2.x));
        return fsqrt((((((a3.y - a2.y) * (f1 / f2)) + a2.y) - a1.y) *
                      ((((a3.y - a2.y) * (f1 / f2)) + a2.y) - a1.y)) +
                     ((a2.x - a1.x) * (a2.x - a1.x)));
    }

    if (a4)
    {
        a4->x = a3.x;
        a4->y = a3.y;
    }

    return fsqrt(((a3.y - a1.y) * (a3.y - a1.y)) + ((a3.x - a1.x) * (a3.x - a1.x)));
}

bool Math::AreLinesOverlapping(const Vector2 &a1, const Vector2 &a2,
                               const Vector2 &a3, const Vector2 &a4)
{
    if (fabs(((a2.x - a1.x) * (a4.y - a3.y)) - ((a2.y - a1.y) * (a4.x - a3.x))) >= 0.000001f)
    {
        return false;
    }

    return Math::DistancePointToLine(a1, a3, a4, 0LL) < 0.01f ||
           Math::DistancePointToLine(a2, a3, a4, 0LL) < 0.01f ||
           Math::DistancePointToLine(a3, a1, a2, 0LL) < 0.01f ||
           Math::DistancePointToLine(a4, a1, a2, 0LL) < 0.01f;
}

bool Math::PointInsidePolygon2d(const Vector2 &a1, Vector2 *a2, int a3)
{
    // TODO: Math::PointInsidePolygon2d
}

const Vector3 &Math::RaySphereIntersection(const Vector3 &a1, const Vector3 &a2,
                                           float a3, const Vector3 &a4, float a5)
{
    // TODO: Math::RaySphereIntersection
}

bool Math::PointInsideSphere(const Vector3 &a1, const Vector3 &a2, float radius)
{
    return ((first.z - second.z) * (first.z - second.z)) + 
           ((first.y - second.y) * (first.y - second.y)) + 
           ((first.x - second.x) * (first.x - second.x)) <= (radius * radius);
}

bool Math::PointInsideCone(const Vector3 &a1, const Vector3 &a2,
                           const Vector3 &a3, float a4)
{
    // TODO: Math::PointInsideCone
}

const Vector3 &Math::RayTriIntersection(const Vector3 &a1, const Vector3 &a2, float a3,
                                        const Vector3 &a4, const Vector3 &a5,
                                        const Vector3 &a6)
{
    // TODO: Math::RayTriIntersection
}

const Vector3 &Math::RayQuadIntersection(const Vector3 &a1, const Vector3 &a2, float a3,
                                         const Vector3 &a4, const Vector3 &a5,
                                         const Vector3 &a6, const Vector3 &a7)
{
    // TODO: Math::RayQuadIntersection
}

const Vector3 &Math::RayPlaneIntersection(const Vector3 &a1, const Vector3 &a2, float a3,
                                          const Vector3 &a4, const Vector3 &a5)
{
    // TODO: Math::RayPlaneIntersection
}

bool Math::DoesRayIntersectBox(const Vector3 &a1, const Vector3 &a2,
                         float a3, const Vector3 &a4, const Vector3 &a5)
{
    // TODO: Math::DoesRayIntersectBox
}

bool Math::DoesBoxIntersectBox(const Vector3 &a1, const Vector3 &a2,
                               const Vector3 &a3, const Vector3 &a4)
{
    if (fminf(a2.x, a1.x) <= fmaxf(a4.x, a3.x) &&
        fminf(a2.y, a1.y) <= fmaxf(a4.y, a3.y) &&
        fminf(a2.z, a1.z) <= fmaxf(a4.z, a3.z) &&
        fminf(a4.x, a3.x) <= fmaxf(a2.x, a1.x) &&
        fminf(a4.y, a3.y) <= fmaxf(a2.y, a1.y))
    {
        return fminf(a4.z, a3.z) <= fmaxf(a2.z, a1.z);
    }

    return 0;
}

void Math::BoxIntersectBox(Vector3 &a1, Vector3 &a2,
                           const Vector3 &a3, const Vector3 &a4,
                           const Vector3 &a5, const Vector3 &a6)
{
    a1.z = fmaxf(fminf(a6.z, a5.z), fminf(a4.z, a3.z));
    a1.y = fmaxf(fminf(a6.y, a5.y), fminf(a4.y, a3.y));
    a1.x = fmaxf(fminf(a6.x, a5.x), fminf(a4.x, a3.x));
    a2.z = fminf(fmaxf(a6.z, a5.z), fmaxf(a4.z, a3.z));
    a2.y = fminf(fmaxf(a6.y, a5.y), fmaxf(a4.y, a3.y));
    a2.x = fminf(fmaxf(a6.x, a5.x), fmaxf(a4.x, a3.x));
}

float Math::Log2(float val)
{
    return logf(val) * 1.442695f;
}

double Math::RampUpAndDown(double a1, double a2, double a3)
{
    double d; // xmm2_8

    if (a3 > (a1 + a2))
    {
        return 1.000100016593933;
    }

    d = (a3 - a1) / a2;

    /*
        if (d > 0.5)
        {
            d = (1.0 - d) + (1.0 - d);
            return 1.0 - d * d * 0.5;
        }

        return (d + d) * (d + d) * 0.5;
    */
    return (d < 0.5)
        ? (0.5 * ((d + d) * (d + d)))
        : (1.0 - 0.5 * ((1.0 - d + 1.0 - d) * (1.0 - d + 1.0 - d)));
}

void Math::TruncateFloatPrecision(float *f)
{
    // *f = (float)((unsigned int)*f & 0xfffffff8);
    *f &= 0xFFFFFFF8;
}

float Math::MapRangeClamp(float min, float max, float val, float a4, float a5)
{
    float normalized = (min - max) / (val - max);

    if (normalized <= 1f)
    {
        // return (a5 - a4) * 1f + a4;
        return fmaxf(0f, normalized);
    }

    return ((normalized > 0f) ? normalized : 0f) * (a5 - a4) + a4;
}

bool Math::AABBIntersect2D(float a11, float a12, float b11, float b12,
                           float a21, float a22, float b21, float b22)
{
    if (a21 <= (b11 + a11) && a11 <= (b21 + a21) && a22 <= (b12 + a12))
    {
        return a12 <= b22 + a22;
    }

    return false;
}

float Math::NormaliseRange(float max, float min, float val)
{
    if (max > min)
    {
        return 0f;
    }

    float normalized = (max - min) / (val - min);

    return (normalized <= 1f) ? fmaxf(0.0, normalized) : 1f;
}

bool Math::MoveToTarget(Vector2 &currentPos, const Vector2 &targetPos, float speed)
{
    float dx = targetPos.x - currentPos.x;
    float dy = targetPos.y - currentPos.y;

    float distSqr = dx * dx + dy * dy;
    float dist = sqrtf(distSqr);

    if (speed < dist)
    {
        if (distSqr > 0f)
        {
            dist = 1f / dist;
            dx *= dist;
            dy *= dist;
        }
        else
        {
            dx = 0f;
            dy = 1f;
        }
        
        currentPos.x = dx * speed + currentPos.x;
        currentPos.y = dy * speed + currentPos.y;

        return false;
    }

    currentPos.x = targetPos.x;
    currentPos.y = targetPos.y;

    return true;
}