#pragma once

#include <iostream>
#include <math.h>
#include "Point.h"

/**
\file
\authors Ann
\brief this library describes vectors and operations on them
\see Vector
*/

/*!  class of vectors */
/**
\authors Ann
\details this class stores vectores and operations on them
*/
class Vector {
private:
    Point* begin; ///< stores the address of the begin point of vector
    Point* end; ///< stores the address of the end point of vector
    float length_x; ///< stores coordinate x of vector
    float length_y; ///< stores coordinate y of vector
    float length_z; ///< stores coordinate z of vector
public:
    Vector(Point* b, Point* e);
    Vector();
    Vector(float x1, float y1, float z1, float x2, float y2, float z2);
    Vector(const Vector& other);
    ~Vector();
    Point getbegin() {
        return *this->begin;
    }
    Point getend() {
        return *this->end;
    }

    /*!
    change the begin point of vector
    \details change the address of begin point of vector to the address of new begin point
    \param[in] newpoint address of new begin point
    \return vector with new begin point
    */
    Vector changeBeginPoint(Point* newpoint);

    /*!
    change the end point of vector
    \details change the address of end point of vector to the address of new end point
    \param[in] newpoint new end point
    \return vector with new end point
    */
    Vector changeEndPoint(Point* newpoint);

    /*!
    change the begin point of vector
    \details changes coordinates of begin point of vector
    \param[in] a coordinate x of new begin point
    \param[in] b coordinate y of new begin point
    \param[in] c coordinate z of new begin point
    \return vector with new coordinates of begin point
    */
    Vector changeBegin(float a, float b, float c);

    /*!
    change the end point of vector
    \details changes coordinates of end point of vector
    \param[in] a coordinate x of new end point
    \param[in] b coordinate y of new end point
    \param[in] c coordinate z of new end point
    \return vector with new coordinates of end point
    */
    Vector changeEnd(float a, float b, float c);
private:
    /*!
    sums vectors
    \param[in] a first vector
    \param[in] b second vector
    \return vector which is a result of sum of two vectors
    */
    Vector getSum(const Vector& a, const Vector& b);

    /*!
    subtracts vectors
    \param[in] a first vector
    \param[in] b second vector
    \return vector which is a result of subtraction of two vectors
    */
    Vector getSubtraction(const Vector& a, const Vector& b);

    /*!
    calculates the multiplication of two vectors
    \param[in] a first vector
    \param[in] b second vector
    \return vector which is a result of multiplication of two vectors
    */
    Vector getVectorsMultiplication(const Vector& a, const Vector& b);

    /*!
    calculates the multiplication of vector and number
    \param[in] number number
    \param[in] a vector
    \return vector which is a result of multiplication of vector and number
    */
    Vector getNumberMultiplication(float number, const Vector& a);

    /*!
    calculates the division of two vectors
    \param[in] a first vector
    \param[in] b second vector
    \return number which is a result of division of two vectors
    */
    float getDivision(const Vector& a, const Vector& b);

    /*!
    calculates the cos of angle between two vectors
    \param[in] a first vector
    \param[in] b second vector
    \return number which is a cos of angle between two vectors
    */
    float getCosinus(const Vector& a, const Vector& b);

public:
    Vector operator+(const Vector& b);
    Vector operator+=(const Vector& b);
    Vector operator-(const Vector& b);
    Vector operator-=(const Vector& b);
    Vector operator*(const Vector& b);
    Vector operator*=(const Vector& b);
    Vector operator*(float number);
    Vector operator*=(float number);
    float operator/(const Vector& b);
    float operator^(const Vector& b);

    bool operator>(const Vector& b);
    bool operator<(const Vector& b);
    bool operator>=(const Vector& b);
    bool operator<=(const Vector& b);
    bool operator==(const Vector& b);
    bool operator!=(const Vector& b);

    friend std::ostream& operator<<(std::ostream& stream, const Vector& other);
    friend std::istream& operator>>(std::istream& stream, Vector& a);
};
std::ostream& operator<<(std::ostream& stream, const Vector& other);
std::istream& operator>>(std::istream& stream, Vector& a);