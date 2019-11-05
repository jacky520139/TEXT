
#include "ALL_Includes.h"
#if CURVE_MOTION_ENABLED

// Hermite timing parameters.厄米特定时参数
 u16 curve_t0;
 u16 curve_t1;
 u16 curve_duration;
static float curve_duration_float;
 u16 Curve_Delta=0;//曲线运动时间
 u16 Curve_Position=0;//曲线运动位置
 u16 Curve_In_Velocity=0;//曲线运动开始速度
 u16 Curve_Out_Velocity=0;//曲线运动结束速度
 
 u16 Curve_Reserved=0;
// Hermite curve parameters.埃尔米特曲线参数
float curve_p0;
float curve_p1;
float curve_v0;
float curve_v1;

//Hermite curve cubic polynomial coefficients.曲线三次多项式系数
static float curve_a;
static float curve_b;
static float curve_c;
static float curve_d;

void curve_init(u16 t0, u16 t1, float p0, float p1, float v0, float v1)
{
    // Set the time parameters.设置时间参数。
    curve_t0 = t0;
    curve_t1 = t1;
    curve_duration = t1 - t0;
    curve_duration_float = (float) curve_duration;

    // The tangents are expressed as slope of value/time.  The time span will
    // be normalized to 0.0 to 1.0 range so correct the tangents by scaling
    // them by the duration of the curve.
//	斜率表示为值/时间。时间跨度将被归到0至1的范围内，正确的切线通过缩放曲线的持续时间。
    v0 *= curve_duration_float;
    v1 *= curve_duration_float;

    // Set the curve parameters.
    curve_p0 = p0;
    curve_p1 = p1;
    curve_v0 = v0;
    curve_v1 = v1;

    // Set the cubic coefficients by multiplying the matrix form of
    // the Hermite curve by the curve parameters p0, p1, v0 and v1.
    //
    // | a |   |  2  -2   1   1 |   |       p0       |
    // | b |   | -3   3  -2  -1 |   |       p1       |
    // | c | = |  0   0   1   0 | . | (t1 - t0) * v0 |
    // | d |   |  1   0   0   0 |   | (t1 - t0) * v1 |
    //
    // a = 2p0 - 2p1 + v0 + v1
    // b = -3p0 + 3p1 -2v0 - v1
    // c = v0
    // d = p0

    curve_a = (2.0 * p0) - (2.0 * p1) + v0 + v1;
    curve_b = -(3.0 * p0) + (3.0 * p1) - (2.0 * v0) - v1;
    curve_c = v0;
    curve_d = p0;
}


void curve_solve(u16 t, float *x, float *dx)
{
    // Handle cases where t is outside and indise the curve.
    if (t <= curve_t0)
    {
        // Set x and in and out dx.
        *x = curve_p0;
        *dx = t < curve_t0 ? 0.0 : curve_v0;
    }
    else if (t >= curve_t1)
    {
        // Set x and in and out dx.
        *x = curve_p1;
        *dx = t > curve_t1 ? 0.0 : curve_v1;
    }
    else
    {
        // Subtract out the t0 value from t.
        float t1 = ((float) (t - curve_t0)) / curve_duration_float;
        float t2 = t1 * t1;
        float t3 = t2 * t1;

        // Determine the cubic polynomial.三次多项式的确定。
        // x = at^3 + bt^2 + ct + d
        *x = (curve_a * t3) + (curve_b * t2) + (curve_c * t1) + curve_d;

        // Determine the cubic polynomial derivative.求三次多项式导数
        // dx = 3at^2 + 2bt + c
        *dx = (3.0 * curve_a * t2) + (2.0 * curve_b * t1) + curve_c;

        // The time span has been normalized to 0.0 to 1.0 range so correct
        // the derivative to the duration of the curve.
//			   时间跨度被标准化到0到1范围，所以修正导数到曲线的持续时间。
        *dx /= curve_duration_float;
    }
}

#endif // CURVE_MOTION_ENABLED

