#include "curve.hpp"

Curve::Curve() : name{0}, numOfPoints{0}, array{nullptr} {}

Curve::Curve(char name, int numOfPoints, Point const *array) :
    name{name},
    numOfPoints{numOfPoints},
    array{new Point[numOfPoints]}
{
    for(int i = 0; i < numOfPoints; i++)
        this->array[i] = Point(array[i].getName(), array[i].getX(), array[i].getY());
}

Curve::Curve(Curve const &source) :
    name{source.name},
    numOfPoints{source.numOfPoints},
    array{new Point[source.numOfPoints]} {
    for(int i = 0; i < numOfPoints; i++)
        this->array[i] = source.getPoint(i);
}

Curve::~Curve() {
    delete [] array;
}

auto Curve::operator=(Curve const &source) -> Curve & {
    this->name = source.name;
    this->numOfPoints = source.numOfPoints;

    delete [] this->array;
    this->array = new Point[numOfPoints];
    for(int i = 0; i < numOfPoints; i++)
        this->array[i] = source.getPoint(i);

    return *this;
}

auto Curve::operator+(Curve const &source) -> Curve {
    int i;
    int newNumOfPoints = this->numOfPoints;
    auto *newArray = new Point[newNumOfPoints + source.getNumOfPoints()];

    for(i = 0; i < newNumOfPoints; i++)
        newArray[i] = this->array[i];

    newNumOfPoints += source.getNumOfPoints();

    for(; i < newNumOfPoints; i++) {
        newArray[i] = source.getPoint(i - this->numOfPoints);
        newArray[i].setName(newArray[i].getName() + numOfPoints);
    }

    auto curve = Curve(name, newNumOfPoints, newArray);
    return curve;
}

auto Curve::operator+(Point const &source) -> Curve {
    auto *newArray = new Point[this->numOfPoints + 1];
    for(int i = 0; i < numOfPoints; i++)
        newArray[i] = this->array[i];
    newArray[this->numOfPoints] = source;
    newArray[this->numOfPoints].setName('A' + this->numOfPoints);

    return Curve(this->name, this->numOfPoints + 1, newArray);
}

auto Curve::operator+=(Curve const &source) -> Curve {
    int i;
    int newNumOfPoints = this->numOfPoints;
    auto *newArray = new Point[newNumOfPoints + source.getNumOfPoints()];

    for(i = 0; i < newNumOfPoints; i++)
        newArray[i] = this->array[i];

    newNumOfPoints += source.getNumOfPoints();

    for(; i < newNumOfPoints; i++) {
        newArray[i] = source.getPoint(i - this->numOfPoints);
        newArray[i].setName(newArray[i].getName() + numOfPoints);
    }

    delete [] this->array;
    this->array = new Point[newNumOfPoints];
    for(i = 0; i < newNumOfPoints; i++)
        this->array[i] = newArray[i];

    this->numOfPoints = newNumOfPoints;
    return *this;
}

auto Curve::operator+=(const Point &source) -> Curve {
    auto *newArray = new Point[this->numOfPoints + 1];
    for(int i = 0; i < numOfPoints; i++)
        newArray[i] = this->array[i];
    newArray[this->numOfPoints] = source;
    newArray[this->numOfPoints].setName('A' + this->numOfPoints);

    delete [] this->array;
    this->numOfPoints++;
    this->array = new Point[this->numOfPoints];
    for(int i = 0; i < this->numOfPoints; i++)
        this->array[i] = newArray[i];

    return *this;
}

auto operator<<(std::ostream &os, Curve const &curve) -> std::ostream & {
    os << "Curve " << curve.name << ":\n";
    for(int i = 0; i < curve.numOfPoints; i++)
        os << "\t" << curve.array[i] << "\n";
    return os;
}

auto Curve::getNumOfPoints() const -> int {
    return this->numOfPoints;
}

auto Curve::getPoint(int i) const -> Point & {
    return this->array[i];
}

auto Curve::setName(char name) -> void {
    this->name = name;
}