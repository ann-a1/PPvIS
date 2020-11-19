#pragma once

/**
\file
\authors Ann
\brief this library describes points
\see Point
*/

/*!  class of points */
/**
\authors Ann
\details this class stores points, which can be used to make vectores
*/

class Point {
public:
    float x; ///< stores coordinate x of point
    float y; ///< stores coordinate y of point
    float z; ///< stores coordinate z of point
    Point(float a, float b, float c);
    Point();
};
