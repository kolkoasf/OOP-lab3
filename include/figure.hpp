#pragma once

#include <cstddef>
#include <iostream>

#include "point.hpp"

namespace geometry {

class Figure {
 public:
  Figure() = default;
  virtual ~Figure() = default;

  virtual Point GetCenter() const = 0;
  virtual operator double() const = 0;
  virtual const Point* GetVertices() const = 0;
  virtual size_t GetVertexCount() const = 0;

  bool VerticesEqual(const Figure& other) const;

  friend std::istream& operator>>(std::istream& is, Figure& figure);
  friend std::ostream& operator<<(std::ostream& os, const Figure& figure);

 protected:
  static Point CalculateCenter(const Point* points, size_t count);
};

}  // namespace geometry
