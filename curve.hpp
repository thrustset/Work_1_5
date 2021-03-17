#pragma once
#include "point.hpp"

class Curve {
private:
    char name;
    int numOfPoints;
    Point *array;
public:
    Curve();
    Curve(Curve const &source);
    Curve(char name, int numOfPoints, Point const *array);
    ~Curve();

    auto operator=(Curve const &source) -> Curve &;
    auto operator+(Curve const &source) -> Curve;
    auto operator+(Point const &source) -> Curve;
    auto operator+=(Curve const &source) -> Curve;
    auto operator+=(Point const &source) -> Curve;

    friend auto operator<<(std::ostream &os, Curve const &curve) -> std::ostream &;

    auto getNumOfPoints() const -> int;
    auto getPoint(int i) const -> Point &;

    auto setName(char name) -> void;
};
