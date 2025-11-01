#include <iostream>
#include <stdexcept>
#include <utility>

#include "figure_vector.hpp"

namespace geometry {

static const size_t INIT_CAPACITY = 4;

FigureArray::FigureArray() : sz_(0), capacity_(0), data_(nullptr) {
}

FigureArray::FigureArray(FigureArray&& other) noexcept
    : sz_(other.sz_), capacity_(other.capacity_), data_(other.data_) {
  other.sz_ = 0;
  other.capacity_ = 0;
  other.data_ = nullptr;
}

FigureArray& FigureArray::operator=(FigureArray&& other) noexcept {
  if (this != &other) {
    for (size_t i = 0; i < sz_; ++i) {
      delete data_[i];
    }

    delete[] data_;

    sz_ = other.sz_;
    capacity_ = other.capacity_;
    data_ = other.data_;

    other.sz_ = 0;
    other.capacity_ = 0;
    other.data_ = nullptr;
  }
  return *this;
}

FigureArray::~FigureArray() {
  for (size_t i = 0; i < sz_; ++i) {
    delete data_[i];
  }

  delete[] data_;
}

void FigureArray::Insert(size_t i, Figure* figure) {
  if (!figure) {
    throw std::invalid_argument("Nullptr figure");
  }

  if (i > sz_) {
    throw std::out_of_range("Insert position out of range");
  }

  if (sz_ == capacity_) {
    size_t new_capacity;
    if (capacity_ == 0) {
      new_capacity = INIT_CAPACITY;
    } else {
      new_capacity = capacity_ * 2;
    }
    Reserve(new_capacity);
  }

  data_[i] = figure;
  ++sz_;
}

void FigureArray::Erase(size_t i) {
  if (i >= sz_) {
    throw std::out_of_range("Erase position out of range");
  }

  delete data_[i];

  for (size_t j = i; j < sz_ - 1; ++j) {
    data_[j] = data_[j + 1];
  }

  --sz_;
}

size_t FigureArray::Size() const {
  return sz_;
}

Figure*& FigureArray::operator[](size_t i) {
  if (i >= sz_) {
    throw std::out_of_range("Index out of range");
  }
  return data_[i];
}

const Figure* FigureArray::operator[](size_t i) const {
  if (i >= sz_) {
    return nullptr;
  }
  return data_[i];
}

bool FigureArray::operator==(const FigureArray& other) const {
  if (sz_ != other.sz_) {
    return false;
  }

  for (size_t i = 0; i < sz_; ++i) {
    if (*data_[i] != *other.data_[i]) {
      return false;
    }
  }

  return true;
}

bool FigureArray::operator!=(const FigureArray& other) const {
  return !(*this == other);
}

double FigureArray::GetTotalArea() const {
  double total = 0.0;
  for (size_t i = 0; i < sz_; ++i) {
    total += static_cast<double>(*data_[i]);
  }
  return total;
}

std::ostream& operator<<(std::ostream& os, const FigureArray& arr) {
  arr.PrintAll(os);
  return os;
}

void FigureArray::Reserve(size_t new_capacity) {
  if (new_capacity <= capacity_) {
    return;
  }

  Figure** new_data = new Figure*[new_capacity];

  for (size_t i = 0; i < sz_; ++i) {
    new_data[i] = data_[i];
  }

  delete[] data_;

  data_ = new_data;
  capacity_ = new_capacity;
}

void FigureArray::Clear() {
  sz_ = 0;
}

void FigureArray::PrintAll(std::ostream& os) const {
  for (size_t i = 0; i < sz_; ++i) {
    os << "Figure " << i << ": " << *data_[i] << " | ";
    os << "Center: " << data_[i]->GetCenter() << " | ";
    os << "Area: " << static_cast<double>(*data_[i]) << "\n";
  }
}

}  // namespace geometry
