#pragma once
#include <iostream>

class GeometryVector {
private:
    size_t dimension;
    double* data;

    void copyFrom(const GeometryVector& other);
    void free();

    void checkIndex(size_t index) const;
    void checkSameDimension(const GeometryVector& other) const;

public:
    explicit GeometryVector(size_t n);

    GeometryVector(const GeometryVector& other);
    GeometryVector& operator=(const GeometryVector& other);
    ~GeometryVector();

    size_t getDimension() const;

    double& operator[](size_t index);
    const double& operator[](size_t index) const;

    operator bool() const;

    GeometryVector operator+() const;
    GeometryVector operator-() const;

    GeometryVector& operator+=(const GeometryVector& other);
    GeometryVector& operator-=(const GeometryVector& other);
    GeometryVector& operator*=(double scalar);
    GeometryVector& operator/=(double scalar);

    double dot(const GeometryVector& other) const;
    bool isOrthogonalTo(const GeometryVector& other) const;

    bool operator==(const GeometryVector& other) const;
    bool operator!=(const GeometryVector& other) const;
};

GeometryVector operator+(const GeometryVector& lhs, const GeometryVector& rhs);
GeometryVector operator-(const GeometryVector& lhs, const GeometryVector& rhs);
GeometryVector operator*(const GeometryVector& v, double scalar);
GeometryVector operator*(double scalar, const GeometryVector& v);
GeometryVector operator/(const GeometryVector& v, double scalar);

std::ostream& operator<<(std::ostream& os, const GeometryVector& v);
std::istream& operator>>(std::istream& is, GeometryVector& v);
