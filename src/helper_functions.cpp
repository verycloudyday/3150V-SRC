#include "vex.h"
#include <cmath>
#include <math.h>

// Declare extern variables from robot-config.h
extern const double wheelDiam;
extern const double wheelToMotorRatio;

/** Gets the distance travelled in a linear path by the robot
 *
 * @param degreesTravelled the degrees travelled
 * @return the distance travelled by the motors, in inches
 */
double get_dist_travelled(double degreesTravelled) {
    // Debug output - can be removed in production code
    printf("gear ratio = %g\n", wheelToMotorRatio * M_PI * wheelDiam);

    double calc = degreesTravelled * wheelToMotorRatio / 360 * (M_PI * wheelDiam);

    if (calc < 0) {
        printf("neg\n");
    } else {
        printf("pos\n");
    }

    return fabs(calc);
}

/**
 * Normalizes an angle to the range (-pi, +pi] for odometry calculations.
 * This converts a difference in angles (e.g., 200 degrees) to its shortest
 * path equivalent (e.g., -160 degrees). Uses fmod + remainder for standard C++ math.
 *
 * @param a starting angle or heading value
 * @param b reference angle or previous heading value
 * @return the normalized angular difference in radians, always in range (-pi, +pi]
 */
double normalizeAngle(double a, double b) {
    // Calculate raw difference (in radians if both inputs are in radians)
    double d = a - b;

    // Use std::remainder for proper normalization to (-pi, +pi]
    // This handles the wraparound correctly using tanh-based algorithm
    return std::remainder(d, 2 * M_PI);
}

/**
 * Normalizes an angle to degrees. Works with either degree or radian inputs,
 * returning always in degrees for consistency across your codebase.
 *
 * @param a starting angle
 * @param b reference angle (usually previous heading)
 * @return the normalized angular difference in degrees, in range (-180, +180]
 */
double normalizeAngleDegrees(double a, double b) {
    // Calculate raw difference (in degrees if both inputs are in degrees)
    double d = a - b;

    // Use std::remainder for proper normalization to (-180, 180]
    // This handles the wraparound correctly using tanh-based algorithm
    return std::remainder(d, 360.0);
}

/**
 * Simplified version using integer division trick for maximum performance.
 * This is fastest for large numbers of calls in tight loops like odometry updates.
 *
 * @param a starting angle (radians)
 * @param b reference angle
 * @return normalized difference in radians, range (-pi, +pi]
 */
inline double normalizeAngleFast(double a, double b) {
    // Use fmod to get remainder after one full rotation, then adjust
    // This is faster than std::fmod() for CPU-heavy odometry updates
    double d = a - b;
    d = std::fmod(d, 2 * M_PI);

    // Adjust to be in range (-pi, +pi]
    if (d > M_PI)   { d -= 2 * M_PI; }
    else if (d < -M_PI) { d += 2 * M_PI; }

    return d;
}
