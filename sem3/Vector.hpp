#include <iostream>
#include <math.h>

struct Vector2 {
    double x, y;
    Vector2(): x(0), y(0){}
    Vector2(double X, double Y): x(X), y(Y){}
    //Vector2(const Vector2 other);
    Vector2 operator+=(const Vector2& other);
    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-=(const Vector2& other);
    Vector2 operator-(const Vector2& other) const;
    double operator*(const Vector2& other) const;
    double operator^(const Vector2& other) const;
    Vector2 operator/(const double other) const;
    Vector2 operator=(const Vector2& other);
    double squareLen() const;
    double len() const;
    Vector2 norm() const;
    Vector2 per() const;
    Vector2 operator-() const;
    Vector2 getRotated(const double alfa) const;
    Vector2 rotate(const double alfa);

    friend Vector2 operator*(const Vector2& a, const double x);
    friend Vector2 operator*(const double x, const Vector2& a);
    friend std::istream& operator >>(std::istream& stream, Vector2& vec);
    friend std::ostream& operator <<(std::ostream& stream, const Vector2& vec);
};
