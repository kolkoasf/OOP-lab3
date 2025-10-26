#include "point.hpp"

namespace geometry {

Point::Point() : x(0.0), y(0.0) {
}

Point::Point(double x, double y) : x(x), y(y) {
}

bool Point::operator==(const Point& other) const {
  return std::abs(x - other.x) < EPSILON && std::abs(y - other.y) < EPSILON;
}

bool Point::operator!=(const Point& other) const {
  return !(*this == other);
}

double Point::DistanceTo(const Point& other) const {
  double dx = x - other.x;
  double dy = y - other.y;
  return std::sqrt(dx * dx + dy * dy);
}

std::istream& operator>>(std::istream& is, Point& point) {
  is >> point.x >> point.y;
  return is;
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
  os << "(" << point.x << ", " << point.y << ")";
  return os;
}

}  // namespace geometry
