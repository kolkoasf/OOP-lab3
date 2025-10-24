#pragma once

#include "figure.hpp"

namespace geometry {

class Trapezoid : public Figure {
 public:
  Trapezoid();  // comment for pr
  Trapezoid(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

  Trapezoid(const Trapezoid& other) = default;
  Trapezoid(Trapezoid&& other) noexcept = default;

  Trapezoid& operator=(const Trapezoid& other) = default;
  Trapezoid& operator=(Trapezoid&& other) noexcept = default;

  bool operator==(const Trapezoid& other) const;

  Point GetCenter() const override;
  operator double() const override;
  const Point* GetVertices() const override;
  size_t GetVertexCount() const override;

  friend std::istream& operator>>(std::istream& is, Trapezoid& trapezoid);
  friend std::ostream& operator<<(std::ostream& os, const Trapezoid& trapezoid);

 private:
  static constexpr size_t VERTEX_COUNT = 4;
  Point vertices_[VERTEX_COUNT];
};

}  // namespace geometry
