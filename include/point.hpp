#pragma once

#include <cmath>
#include <iostream>

namespace geometry {

struct Point {
  static constexpr double EPSILON = 1e-9;

  double x;  // comment for pr
  double y;

  Point();
  Point(double x, double y);

  bool operator==(const Point& other) const;
  bool operator!=(const Point& other) const;

  double DistanceTo(const Point& other) const;

  friend std::istream& operator>>(std::istream& is, Point& point);
  friend std::ostream& operator<<(std::ostream& os, const Point& point);
};

}  // namespace geometry
