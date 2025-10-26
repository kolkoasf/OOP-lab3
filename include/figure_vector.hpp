#pragma once

#include <cstddef>
#include <iosfwd>

#include "figure.hpp"

namespace geometry {

class FigureArray {
 public:
  FigureArray();

  FigureArray(const FigureArray&) = delete;
  FigureArray& operator=(const FigureArray&) = delete;

  FigureArray(FigureArray&&) noexcept;
  FigureArray& operator=(FigureArray&&) noexcept;

  ~FigureArray();

  void Insert(size_t pos, Figure* figure);
  void Erase(size_t i);
  size_t Size() const;

  Figure*& operator[](size_t i);
  const Figure* operator[](size_t i) const;

  bool operator==(const FigureArray& other) const;
  bool operator!=(const FigureArray& other) const;

  double GetTotalArea() const;

  friend std::ostream& operator<<(std::ostream& os, const FigureArray& arr);

  void Reserve(size_t new_capacity);
  void Clear();

  void PrintAll(std::ostream& os) const;

 private:
  size_t sz_;
  size_t capacity_;
  Figure** data_;
};

}  // namespace geometry
