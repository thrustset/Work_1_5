#include "point.hpp"

Point::Point()  {
    this->name = 0;
    this->x = 0;
    this->y = 0;
}

Point::Point(char name, double x, double y) : name{name}, x{x}, y{y} {}

Point::Point(const Point &source) : name{source.name}, x{source.x}, y{source.y} {}

auto Point::operator=(Point const &source) -> Point & {
    name = source.name;
    x = source.x;
    y = source.y;
    return *this;
}

auto Point::operator*(double coefficient) -> Point {
    auto point = Point(*this);
    point.x *= coefficient;
    point.y *= coefficient;
    return point;
}

auto Point::operator*=(double coefficient) -> Point {
    this->x *= coefficient;
    this->y *= coefficient;
    return *this;
}

auto operator<<(std::ostream &os, Point const &point) -> std::ostream & {
    os << "Point " << point.name << ":\t(" << point.x << "; " << point.y << ")";
    return os;
}

auto Point::getName() const -> char {
    return name;
}

auto Point::getX() const -> double {
    return x;
}

auto Point::getY() const -> double {
    return y;
}

auto Point::setName(char name) -> void {
    this->name = name;
}