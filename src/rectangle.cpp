#include "rectangle.hpp"

namespace geometry {

Rectangle::Rectangle() : vertices_{Point(), Point(), Point(), Point()} {
}

Rectangle::Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : vertices_{p1, p2, p3, p4} {
}

bool Rectangle::operator==(const Rectangle& other) const {
  return VerticesEqual(other);  // comment for pr
}

Point Rectangle::GetCenter() const {
  return CalculateCenter(vertices_, Rectangle::VERTEX_COUNT);
}

Rectangle::operator double() const {
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

const Point* Rectangle::GetVertices() const {
  return vertices_;
}

size_t Rectangle::GetVertexCount() const {
  return VERTEX_COUNT;
}

std::istream& operator>>(std::istream& is, Rectangle& rectangle) {
  return is >> static_cast<Figure&>(rectangle);
}

std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle) {
  return os << static_cast<const Figure&>(rectangle);
}

}  // namespace geometry
