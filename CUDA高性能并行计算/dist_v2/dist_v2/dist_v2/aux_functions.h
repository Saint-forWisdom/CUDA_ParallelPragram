#ifndef AUX_FUNCTIONS_H
#define AUX_FUNCTIONS_H

// scale data to (0, 1)
float scale(int i, int n);
 // compute the distance between 2 points on a line
float distance(float x1, float x2);
// compute scaled distance for an array of input values;
void distanceArray(float* out, float* in, float ref, int n);

#endif // AUX_FUNCTIONS_H
