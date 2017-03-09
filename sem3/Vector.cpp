#include <cmath>
#include <fstream>
#include "main.hpp"

Vector2 Vector2::operator+=(const Vector2& other) {
	x += other.x;
	y += other.y;
	return (*this);
}
	
Vector2 Vector2::operator+(const Vector2& other) const{
	Vector2 ans(*this);
	ans += other;
	return ans;
}

Vector2 Vector2::operator-=(const Vector2& other) {
	x -= other.x;
	y -= other.y;
	return (*this);
}

Vector2 Vector2::operator-(const Vector2& other) const {
	Vector2 ans(*this);
	ans -= other;
	return ans;
}

double Vector2::operator*(const Vector2& other) const {
	return x * other.x + y * other.y;
}

double Vector2::operator^(const Vector2& other) const {
	return x * other.y - y * other.x;
}
Vector2 Vector2::operator/(const double other) const {
	Vector2 ans(*this);
	ans.x /= other;
	ans.y /= other;
	return ans;
}

Vector2 Vector2::operator=(const Vector2& other) {
	x = other.x;
	y = other.y;
	return (*this);
}
	
double Vector2::squareLen() const {
	return x * x + y * y;
}
	
double Vector2::len() const {
	return sqrt(squareLen());
}
	
Vector2 Vector2::norm() const {
	return (*this) / len();
}
	
Vector2 Vector2::per() const {
	return Vector2(y, -x);
}
	
Vector2 Vector2::operator-() const {
	Vector2 ans(*this);
	ans.x *= -1;
	ans.y *= -1;
	return ans;
}
Vector2 Vector2::getRotated(const double alfa) const {
	return Vector2(x * cos(alfa) - y * sin(alfa), x * sin(alfa) + y * cos(alfa));
}
Vector2 Vector2::rotate(const double alfa) {
	(*this) = getRotated(alfa);
	return (*this);
}

Vector2 operator*(const Vector2& a, const double x) {
	Vector2 ans(a);
	ans.x *= x;
	ans.y *= x;
	return ans;
}

Vector2 operator*(const double x, const Vector2& a) {
	Vector2 ans(a);
	ans.x *= x;
	ans.y *= x;
	return ans;
}

std::istream& operator >>(std::istream& stream, Vector2& vec) {
    stream >> vec.x;
    stream >> vec.y;
    return stream;
}

std::ostream& operator <<(std::ostream& stream, const Vector2& vec) {
    stream << "[" << vec.x << "," << vec.y << "]";
    return stream;
}
