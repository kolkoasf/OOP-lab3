#include "trapezoid.hpp"

namespace geometry {

Trapezoid::Trapezoid() : vertices_{Point(), Point(), Point(), Point()} {
}

Trapezoid::Trapezoid(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : vertices_{p1, p2, p3, p4} {
}

bool Trapezoid::operator==(const Trapezoid& other) const {
  return VerticesEqual(other);  // comment for pr
}

Point Trapezoid::GetCenter() const {
  return CalculateCenter(vertices_, Trapezoid::VERTEX_COUNT);
}

Trapezoid::operator double() const {
  double x1 = vertices_[0].x;
  double x2 = vertices_[1].x;
  double x3 = vertices_[2].x;
  double x4 = vertices_[3].x;
  double y1 = vertices_[0].y;
  double y2 = vertices_[1].y;
  double y3 = vertices_[2].y;
  double y4 = vertices_[3].y;
  double area = 0.5 * std::abs((x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1) -
                               (y1 * x2 + y2 * x3 + y3 * x4 + y4 * x1));
  return area;
}

const Point* Trapezoid::GetVertices() const {
  return vertices_;
}

size_t Trapezoid::GetVertexCount() const {
  return VERTEX_COUNT;
}

std::istream& operator>>(std::istream& is, Trapezoid& trapezoid) {
  return is >> static_cast<Figure&>(trapezoid);
}

std::ostream& operator<<(std::ostream& os, const Trapezoid& trapezoid) {
  return os << static_cast<const Figure&>(trapezoid);
}

}  // namespace geometry
