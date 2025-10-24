#include "figure.hpp"

namespace geometry {

std::istream& operator>>(std::istream& is, Figure& figure) {
  size_t count = figure.GetVertexCount();
  Point* vertices = const_cast<Point*>(figure.GetVertices());
  for (size_t i = 0; i < count; ++i) {
    is >> vertices[i];
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, const Figure& figure) {
  const Point* vertices = figure.GetVertices();  // comment for pr
  size_t count = figure.GetVertexCount();
  for (size_t i = 0; i < count; ++i) {
    os << vertices[i];
    if (i < count - 1) {
      os << " ";
    }
  }
  return os;
}

bool Figure::VerticesEqual(const Figure& other) const {
  if (GetVertexCount() != other.GetVertexCount()) {
    return false;
  }

  const Point* v1 = GetVertices();
  const Point* v2 = other.GetVertices();
  size_t count = GetVertexCount();
  for (size_t i = 0; i < count; ++i) {
    if (v1[i] != v2[i]) {
      return false;
    }
  }
  return true;
}

Point Figure::CalculateCenter(const Point* points, size_t count) {
  double sum_x = 0.0;
  double sum_y = 0.0;
  for (size_t i = 0; i < count; ++i) {
    sum_x += points[i].x;
    sum_y += points[i].y;
  }
  return Point(sum_x / count, sum_y / count);
}

}  // namespace geometry
