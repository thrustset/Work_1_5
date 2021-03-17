#pragma once
#include <iostream>

class Point {
private:
    char name;
    double x;
    double y;
public:
    Point();
    Point(char name, double x, double y);
    Point(Point const &source);

    auto operator=(Point const &source) -> Point &;
    auto operator*(double coefficient) -> Point;
    auto operator*=(double coefficient) -> Point;

    friend auto operator<<(std::ostream &os, Point const &point) -> std::ostream &;

    auto getName() const -> char;
    auto getX() const -> double;
    auto getY() const -> double;

    auto setName(char name) -> void;
};