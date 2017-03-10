#include <iostream>
#include <math.h>

struct Vector2 {
    double x, y;
    
    /*
        fixit: вынесите реализацию конструкторов в cpp файл
    */
    Vector2(): x(0), y(0){}
    Vector2(double X, double Y): x(X), y(Y){}
    
    /*
        fixit: += должен вернуть ссылку на себя обносленного по аналогии со встроенными типами вроде int, float и т.д.
    */
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
    
    /*
     fixit: rotate должен вернуть ссылку на себя обновленного ... по аналогии с +=
    */
    Vector2 rotate(const double alfa);

    /*
        Почему вы vector*double сделали внешней ф-ей, а оператор + реализовали внутри класса?
    */
    friend Vector2 operator*(const Vector2& a, const double x);
    friend Vector2 operator*(const double x, const Vector2& a);
    friend std::istream& operator >>(std::istream& stream, Vector2& vec);
    friend std::ostream& operator <<(std::ostream& stream, const Vector2& vec);
};
