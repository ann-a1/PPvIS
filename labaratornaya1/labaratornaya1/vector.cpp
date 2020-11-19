#include "Vector.h"

Vector::Vector(Point* b, Point* e) :begin(b), end(e), length_x(e->x - b->x), length_y(e->y - b->y), length_z(e->z - b->z) {}
Vector::Vector() {
    begin = new Point;
    end = new Point;
    length_x = 0;
    length_y = 0;
    length_z = 0;
}
Vector::Vector(float x1, float y1, float z1, float x2, float y2, float z2) {
    begin = new Point;
    end = new Point;
    this->begin->x = x1;
    this->begin->y = y1;
    this->begin->z = z1;
    this->end->x = x2;
    this->end->y = y2;
    this->end->z = z2;
    length_x = x2 - x1;
    length_y = y2 - y1;
    length_z = z2 - z1;
}
Vector::Vector(const Vector& other) {
    begin = new Point;
    end = new Point;
    *this->begin = *other.begin;
    *this->end = *other.end;
    length_x = other.end->x - other.begin->x;
    length_y = other.end->y - other.begin->y;
    length_z = other.end->z - other.begin->z;
}
Vector::~Vector() {
    begin = nullptr;
    end = nullptr;
    delete begin;
    delete end;
}
Vector Vector::changeBeginPoint(Point* newpoint) {
    this->begin = newpoint;
    this->length_x = this->end->x - this->begin->x;
    this->length_y = this->end->y - this->begin->y;
    this->length_z = this->end->z - this->begin->z;
    return *this;
}
Vector Vector::changeEndPoint(Point* newpoint) {
    this->end = newpoint;
    this->length_x = this->end->x - this->begin->x;
    this->length_y = this->end->y - this->begin->y;
    this->length_z = this->end->z - this->begin->z;
    return *this;
}
Vector Vector::changeBegin(float a, float b, float c) {
    this->begin->x = a;
    this->begin->y = b;
    this->begin->z = c;
    this->length_x = this->end->x - this->begin->x;
    this->length_y = this->end->y - this->begin->y;
    this->length_z = this->end->z - this->begin->z;
    return *this;
}
Vector Vector::changeEnd(float a, float b, float c) {
    this->end->x = a;
    this->end->y = b;
    this->end->z = c;
    this->length_x = this->end->x - this->begin->x;
    this->length_y = this->end->y - this->begin->y;
    this->length_z = this->end->z - this->begin->z;
    return *this;
}
Vector Vector::getSum(const Vector& a, const Vector& b) {
    Vector temp = b;
    float xv = a.end->x - b.begin->x;
    float yv = a.end->y - b.begin->y;
    float zv = a.end->z - b.begin->z;
    temp.end->x += xv;
    temp.end->y += yv;
    temp.end->z += zv;
    Vector c(a.begin, temp.end);
    return c;
}
Vector Vector::getSubtraction(const Vector& a, const Vector& b) {
    Vector temp = b;
    float xv = a.begin->x - b.begin->x;
    float yv = a.begin->y - b.begin->y;
    float zv = a.begin->z - b.begin->z;
    temp.end->x += xv;
    temp.end->y += yv;
    temp.end->z += zv;
    Vector c(temp.end, a.end);
    return c;
}
Vector Vector::getVectorsMultiplication(const Vector& a, const Vector& b) {
    float cx = a.length_y * b.length_z - a.length_z * b.length_y;
    float cy = a.length_z * b.length_x - a.length_x * b.length_z;
    float cz = a.length_x * b.length_y - a.length_y * b.length_x;
    Vector c(0, 0, 0, cx, cy, cz);
    return c;
}
Vector Vector::getNumberMultiplication(float number, const Vector& a) {
    Vector c(number * (a.begin->x), number * (a.begin->y), number * (a.begin->z), number * (a.end->x), number * (a.end->y), number * (a.end->z));
    return c;
}
float Vector::getDivision(const Vector& a, const Vector& b) {
    if ((a.length_x / b.length_x) == (a.length_y / b.length_y) && (a.length_y / b.length_y) == (a.length_z / b.length_z))
        return (a.end->x - a.begin->x) / (b.end->x - b.begin->x);
    else return 0;
}
float Vector::getCosinus(const Vector& a, const Vector& b) {
    float cosin = (a.length_x * b.length_x + a.length_y * b.length_y + a.length_z * b.length_z) / (sqrt(a.length_x * a.length_x + a.length_y * a.length_y
        + a.length_z * a.length_z) * sqrt(b.length_x * b.length_x + b.length_y * b.length_y + b.length_z * b.length_z));
    return cosin;
}
Vector Vector::operator+(const Vector& b) {
    return getSum(*this, b);
}
Vector Vector::operator+=(const Vector& b) {
    *this = *this + b;
    return *this;
}
Vector Vector::operator-(const Vector& b) {
    return getSubtraction(*this, b);
}
Vector Vector::operator-=(const Vector& b) {
    *this = *this - b;
    return *this;
}
Vector Vector::operator*(const Vector& b) {
    return getVectorsMultiplication(*this, b);
}
Vector Vector::operator*=(const Vector& b) {
    *this = *this * b;
    return *this;
}
Vector Vector::operator*(float number) {
    return getNumberMultiplication(number, *this);
}
Vector Vector::operator*=(float number) {
    *this = *this * number;
    return *this;
}
float Vector::operator/(const Vector& b) {
    return getDivision(*this, b);
}
float Vector::operator^(const Vector& b) {
    return getCosinus(*this, b);
}

bool Vector::operator>(const Vector& b) {
    float la = sqrt(this->length_x * this->length_x + this->length_y * this->length_y + this->length_z * this->length_z);
    float lb = sqrt(b.length_x * b.length_x + b.length_y * b.length_y + b.length_z * b.length_z);
    if (la > lb) return 1;
    else return 0;
}
bool Vector::operator<(const Vector& b) {
    float la = sqrt(this->length_x * this->length_x + this->length_y * this->length_y + this->length_z * this->length_z);
    float lb = sqrt(b.length_x * b.length_x + b.length_y * b.length_y + b.length_z * b.length_z);
    if (la < lb) return 1;
    else return 0;
}
bool Vector::operator>=(const Vector& b) {
    float la = sqrt(this->length_x * this->length_x + this->length_y * this->length_y + this->length_z * this->length_z);
    float lb = sqrt(b.length_x * b.length_x + b.length_y * b.length_y + b.length_z * b.length_z);
    if (la >= lb) return 1;
    else return 0;
}
bool Vector::operator<=(const Vector& b) {
    float la = sqrt(this->length_x * this->length_x + this->length_y * this->length_y + this->length_z * this->length_z);
    float lb = sqrt(b.length_x * b.length_x + b.length_y * b.length_y + b.length_z * b.length_z);
    if (la <= lb) return 1;
    else return 0;
}
bool Vector::operator==(const Vector& b) {
    if ((this->length_x == b.length_x) && (this->length_y == b.length_y) && (this->length_z == b.length_z)) return 1;
    else return 0;
}
bool Vector::operator!=(const Vector& b) {
    if ((this->length_x != b.length_x) || (this->length_y != b.length_y) || (this->length_z != b.length_z)) return 1;
    else return 0;
}

std::ostream& operator<< (std::ostream& stream, const Vector& other) {
    stream << "(" << other.length_x << ", " << other.length_y << ", " << other.length_z << "); begin: (" << other.begin->x << ", " << other.begin->y
        << ", " << other.begin->z << "); end: (" << other.end->x << ", " << other.end->y << ", " << other.end->z << ")";
    return stream;
}
std::istream& operator>>(std::istream& stream, Vector& a) {
    stream >> a.length_x >> a.length_y >> a.length_z >> a.begin->x >> a.begin->y >> a.begin->z >> a.end->x >> a.end->y >> a.end->z;
    return stream;
}