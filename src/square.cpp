#include "square.hpp"

namespace geometry {

Square::Square() : vertices_{Point(), Point(), Point(), Point()} {
}

Square::Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
    : vertices_{p1, p2, p3, p4} {
}

bool Square::operator==(const Square& other) const {
  return VerticesEqual(other);
}

Point Square::GetCenter() const {
  return CalculateCenter(vertices_, Square::VERTEX_COUNT);
}

Square::operator double() const {
  double side = vertices_[0].DistanceTo(vertices_[1]);
  return side * side;
}

const Point* Square::GetVertices() const {
  return vertices_;
}

size_t Square::GetVertexCount() const {
  return VERTEX_COUNT;
}

std::istream& operator>>(std::istream& is, Square& square) {
  return is >> static_cast<Figure&>(square);
}

std::ostream& operator<<(std::ostream& os, const Square& square) {
  return os << static_cast<const Figure&>(square);
}

}  // namespace geometry
