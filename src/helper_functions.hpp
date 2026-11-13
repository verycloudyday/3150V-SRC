#ifndef HELPER_FUNCTIONS_H
#define HELPER_FUNCTIONS_H

extern double get_dist_travelled(double degreesTravelled);
/**
 * Normalizes angle difference to range (-π, +π] for odometry.
 * @param a starting value (radians)
 * @param b reference value (radians)
 * @return normalized angular difference in radians
 */
extern double normalizeAngle(double a, double b);

/**
 * Normalizes angle difference to range (-180, +180] for odometry.
 * @param a starting value (degrees)
 * @param b reference value (degrees)
 * @return normalized angular difference in degrees
 */
extern double normalizeAngleDegrees(double a, double b);

/**
 * Fast normalized angle using integer division trick.
 * @param a starting value (radians)
 * @param b reference value (radians)
 * @return normalized angular difference in radians
 */
extern inline double normalizeAngleFast(double a, double b);

#endif // HELPER_FUNCTIONS_H
