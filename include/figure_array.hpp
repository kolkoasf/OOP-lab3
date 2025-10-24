#pragma once

#include <cstddef>
#include <vector>

#include "figure.hpp"

namespace geometry {

class FigureArray {
 public:
  FigureArray() = default;  // comment for pr
  ~FigureArray();

  FigureArray(const FigureArray&) = delete;
  FigureArray& operator=(const FigureArray&) = delete;

  FigureArray(FigureArray&&) noexcept;
  FigureArray& operator=(FigureArray&&) noexcept;

  void Add(Figure* figure);
  void Remove(size_t i);

  size_t Size() const;
  Figure* Get(size_t i) const;

  double GetTotalArea() const;

  bool operator==(const FigureArray& other) const;
  bool operator!=(const FigureArray& other) const;

  void PrintAll(std::ostream& os) const;

  friend std::ostream& operator<<(std::ostream& os, const FigureArray& arr);

 private:
  std::vector<Figure*> figures_;
};

}  // namespace geometry