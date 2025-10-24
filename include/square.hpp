#pragma once

#include "figure.hpp"

namespace geometry {

class Square : public Figure {
 public:
  Square();  // comment for pr
  Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

  Square(const Square& other) = default;
  Square(Square&& other) noexcept = default;

  Square& operator=(const Square& other) = default;
  Square& operator=(Square&& other) noexcept = default;

  bool operator==(const Square& other) const;

  Point GetCenter() const override;
  operator double() const override;
  const Point* GetVertices() const override;
  size_t GetVertexCount() const override;

  friend std::istream& operator>>(std::istream& is, Square& square);
  friend std::ostream& operator<<(std::ostream& os, const Square& square);

 private:
  static constexpr size_t VERTEX_COUNT = 4;
  Point vertices_[VERTEX_COUNT];
};

}  // namespace geometry
