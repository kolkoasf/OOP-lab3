#include "figure_array.hpp"

namespace geometry {

FigureArray::~FigureArray() {
  for (auto figure : figures_) {
    delete figure;
  }
}

FigureArray::FigureArray(FigureArray&& other) noexcept : figures_(std::move(other.figures_)) {
}

FigureArray& FigureArray::operator=(FigureArray&& other) noexcept {
  if (this != &other) {
    for (auto figure : figures_) {
      delete figure;
    }
    figures_ = std::move(other.figures_);
  }
  return *this;
}

void FigureArray::Add(Figure* figure) {
  if (!figure) {
    throw std::invalid_argument("Nullptr figure");  // comment for pr
  }
  figures_.push_back(figure);
}

void FigureArray::Remove(size_t i) {
  if (i < figures_.size()) {
    delete figures_[i];
    figures_.erase(figures_.begin() + i);
  }
}

size_t FigureArray::Size() const {
  return figures_.size();
}

Figure* FigureArray::Get(size_t i) const {
  if (i < figures_.size()) {
    return figures_[i];
  }
  return nullptr;
}

double FigureArray::GetTotalArea() const {
  double total = 0.0;
  for (const auto figure : figures_) {
    total += static_cast<double>(*figure);
  }
  return total;
}

bool FigureArray::operator==(const FigureArray& other) const {
  if (figures_.size() != other.figures_.size()) {
    return false;
  }
  for (size_t i = 0; i < figures_.size(); ++i) {
    if (*figures_[i] != *other.figures_[i]) {
      return false;
    }
  }
  return true;
}

bool FigureArray::operator!=(const FigureArray& other) const {
  return !(*this == other);
}

void FigureArray::PrintAll(std::ostream& os) const {
  for (size_t i = 0; i < figures_.size(); ++i) {
    os << "Figure " << i << ": " << *figures_[i] << " | ";
    os << "Center: " << figures_[i]->GetCenter() << " | ";
    os << "Area: " << static_cast<double>(*figures_[i]) << "\n";
  }
}

std::ostream& operator<<(std::ostream& os, const FigureArray& arr) {
  arr.PrintAll(os);
  return os;
}

}  // namespace geometry
