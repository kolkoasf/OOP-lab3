#pragma once

#include "figure.hpp"

namespace geometry {

class Rectangle : public Figure {
 public:
  Rectangle();
  Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

  Rectangle(const Rectangle& other) = default;
  Rectangle(Rectangle&& other) noexcept = default;

  Rectangle& operator=(const Rectangle& other) = default;
  Rectangle& operator=(Rectangle&& other) noexcept = default;

  bool operator==(const Rectangle& other) const;

  Point GetCenter() const override;
  operator double() const override;
  const Point* GetVertices() const override;
  size_t GetVertexCount() const override;

  friend std::istream& operator>>(std::istream& is, Rectangle& rectangle);
  friend std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle);

 private:
  static constexpr size_t VERTEX_COUNT = 4;
  Point vertices_[VERTEX_COUNT];
};

}  // namespace geometry
