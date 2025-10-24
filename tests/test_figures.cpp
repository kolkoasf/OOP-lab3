#include <gtest/gtest.h>

#include <iostream>
#include <sstream>

#include "figure_array.hpp"
#include "point.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "trapezoid.hpp"

using namespace geometry;

class PointTest : public ::testing::Test {
 protected:
  Point p1{0.0, 0.0};
  Point p2{3.0, 4.0};
  Point p3{3.0, 4.0};
};

TEST_F(PointTest, DefaultConstructor) {
  Point p;
  EXPECT_EQ(p.x, 0.0);
  EXPECT_EQ(p.y, 0.0);
}

TEST_F(PointTest, ParametrizedConstructor) {
  Point p(5.0, 10.0);
  EXPECT_EQ(p.x, 5.0);
  EXPECT_EQ(p.y, 10.0);
}

TEST_F(PointTest, EqualityOperator) {
  EXPECT_EQ(p2, p3);
  EXPECT_FALSE(p1 == p2);
}

TEST_F(PointTest, InequalityOperator) {
  EXPECT_NE(p1, p2);
  EXPECT_FALSE(p2 != p3);
}

TEST_F(PointTest, DistanceTo) {
  double distance = p1.DistanceTo(p2);
  EXPECT_DOUBLE_EQ(distance, 5.0);
}

TEST_F(PointTest, DistanceToSelf) {
  double distance = p1.DistanceTo(p1);
  EXPECT_DOUBLE_EQ(distance, 0.0);
}

TEST_F(PointTest, OutputOperator) {
  std::ostringstream oss;
  oss << p2;
  EXPECT_EQ(oss.str(), "(3, 4)");
}

TEST_F(PointTest, InputOperator) {
  std::istringstream iss("7.5 2.5");
  Point p;
  iss >> p;
  EXPECT_EQ(p.x, 7.5);
  EXPECT_EQ(p.y, 2.5);
}

class SquareTest : public ::testing::Test {
 protected:
  Square sq1{Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)};
  Square sq2{Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)};
  Square sq3{Point(1, 1), Point(3, 1), Point(3, 3), Point(1, 3)};
};

TEST_F(SquareTest, DefaultConstructor) {
  Square sq;
  EXPECT_EQ(sq.GetVertexCount(), 4);
}

TEST_F(SquareTest, ParametrizedConstructor) {
  EXPECT_EQ(sq1.GetVertexCount(), 4);
}

TEST_F(SquareTest, GetArea) {
  double area = static_cast<double>(sq1);
  EXPECT_DOUBLE_EQ(area, 4.0);
}

TEST_F(SquareTest, GetCenter) {
  Point center = sq1.GetCenter();
  EXPECT_DOUBLE_EQ(center.x, 1.0);
  EXPECT_DOUBLE_EQ(center.y, 1.0);
}

TEST_F(SquareTest, EqualityOperator) {
  EXPECT_EQ(sq1, sq2);
  EXPECT_FALSE(sq1 == sq3);
}

TEST_F(SquareTest, OutputOperator) {
  std::ostringstream oss;
  oss << sq1;
  std::string output = oss.str();
  EXPECT_NE(output.find("0"), std::string::npos);
}

TEST_F(SquareTest, InputOperator) {
  std::istringstream iss("0 0 3 0 3 3 0 3");
  Square sq;
  iss >> sq;
  Point center = sq.GetCenter();
  EXPECT_DOUBLE_EQ(center.x, 1.5);
  EXPECT_DOUBLE_EQ(center.y, 1.5);
}

TEST_F(SquareTest, CopyConstructor) {
  Square copy = sq1;
  EXPECT_EQ(copy, sq1);
}

TEST_F(SquareTest, MoveConstructor) {
  Square original = sq1;
  Square moved = std::move(original);
  EXPECT_EQ(moved, sq1);
}

class RectangleTest : public ::testing::Test {
 protected:
  void SetUp() override {
    rect1 = new Rectangle(Point(0, 0), Point(4, 0), Point(4, 2), Point(0, 2));
    rect2 = new Rectangle(Point(0, 0), Point(4, 0), Point(4, 2), Point(0, 2));
    rect3 = new Rectangle(Point(1, 1), Point(5, 1), Point(5, 3), Point(1, 3));
  }

  void TearDown() override {
    delete rect1;
    delete rect2;
    delete rect3;
  }

  Rectangle* rect1;
  Rectangle* rect2;
  Rectangle* rect3;
};

TEST_F(RectangleTest, DefaultConstructor) {
  Rectangle rect;
  EXPECT_EQ(rect.GetVertexCount(), 4);
}

TEST_F(RectangleTest, GetArea) {
  double area = static_cast<double>(*rect1);
  EXPECT_GT(area, 0.0);
}

TEST_F(RectangleTest, GetCenter) {
  Point center = rect1->GetCenter();
  EXPECT_DOUBLE_EQ(center.x, 2.0);
  EXPECT_DOUBLE_EQ(center.y, 1.0);
}

TEST_F(RectangleTest, EqualityOperator) {
  EXPECT_EQ(*rect1, *rect2);
  EXPECT_FALSE(*rect1 == *rect3);
}

TEST_F(RectangleTest, InputOperator) {
  std::istringstream iss("0 0 5 0 5 3 0 3");
  Rectangle rect;
  iss >> rect;
  Point center = rect.GetCenter();
  EXPECT_DOUBLE_EQ(center.x, 2.5);
  EXPECT_DOUBLE_EQ(center.y, 1.5);
}

TEST_F(RectangleTest, CopyAssignment) {
  Rectangle copy;
  copy = *rect1;
  EXPECT_EQ(copy, *rect1);
}

class TrapezoidTest : public ::testing::Test {
 protected:
  void SetUp() override {
    trap1 = new Trapezoid(Point(0, 0), Point(4, 0), Point(3, 2), Point(1, 2));
    trap2 = new Trapezoid(Point(0, 0), Point(4, 0), Point(3, 2), Point(1, 2));
    trap3 = new Trapezoid(Point(1, 1), Point(5, 1), Point(4, 3), Point(2, 3));
  }

  void TearDown() override {
    delete trap1;
    delete trap2;
    delete trap3;
  }

  Trapezoid* trap1;
  Trapezoid* trap2;
  Trapezoid* trap3;
};

TEST_F(TrapezoidTest, DefaultConstructor) {
  Trapezoid trap;
  EXPECT_EQ(trap.GetVertexCount(), 4);
}

TEST_F(TrapezoidTest, GetArea) {
  double area = static_cast<double>(*trap1);
  EXPECT_GT(area, 0.0);
}

TEST_F(TrapezoidTest, GetCenter) {
  Point center = trap1->GetCenter();
  EXPECT_DOUBLE_EQ(center.x, 2.0);
  EXPECT_DOUBLE_EQ(center.y, 1.0);
}

TEST_F(TrapezoidTest, EqualityOperator) {
  EXPECT_EQ(*trap1, *trap2);
  EXPECT_FALSE(*trap1 == *trap3);
}

TEST_F(TrapezoidTest, InputOperator) {
  std::istringstream iss("0 0 5 0 4 3 1 3");
  Trapezoid trap;
  iss >> trap;
  Point center = trap.GetCenter();
  EXPECT_EQ(center.x, 2.5);
  EXPECT_EQ(center.y, 1.5);
}

class FigureArrayTest : public ::testing::Test {
 protected:
  FigureArray arr;

  void SetUp() override {
    arr.Add(new Square(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)));
    arr.Add(new Rectangle(Point(0, 0), Point(4, 0), Point(4, 2), Point(0, 2)));
    arr.Add(new Trapezoid(Point(0, 0), Point(4, 0), Point(3, 2), Point(1, 2)));
  }
};

TEST_F(FigureArrayTest, Add) {
  EXPECT_EQ(arr.Size(), 3);
}

TEST_F(FigureArrayTest, GetSize) {
  EXPECT_EQ(arr.Size(), 3);
}

TEST_F(FigureArrayTest, GetFigure) {
  Figure* fig = arr.Get(0);
  EXPECT_NE(fig, nullptr);
  EXPECT_EQ(static_cast<double>(*fig), 4.0);
}

TEST_F(FigureArrayTest, GetFigureOutOfBounds) {
  Figure* fig = arr.Get(10);
  EXPECT_EQ(fig, nullptr);
}

TEST_F(FigureArrayTest, Remove) {
  arr.Remove(1);
  EXPECT_EQ(arr.Size(), 2);
  EXPECT_NE(arr.Get(0), nullptr);
  EXPECT_NE(arr.Get(1), nullptr);
}

TEST_F(FigureArrayTest, RemoveOutOfBounds) {
  size_t original_size = arr.Size();
  arr.Remove(10);
  EXPECT_EQ(arr.Size(), original_size);
}

TEST_F(FigureArrayTest, GetTotalArea) {
  double total = arr.GetTotalArea();
  EXPECT_GT(total, 0.0);
}

TEST_F(FigureArrayTest, GetTotalAreaAfterRemove) {
  double total_before = arr.GetTotalArea();
  arr.Remove(0);
  double total_after = arr.GetTotalArea();
  EXPECT_LT(total_after, total_before);
}

TEST_F(FigureArrayTest, AddNullptr) {
  EXPECT_THROW(arr.Add(nullptr), std::invalid_argument);
}

TEST_F(FigureArrayTest, PrintAll) {
  std::ostringstream oss;
  arr.PrintAll(oss);
  std::string output = oss.str();
  EXPECT_NE(output.find("Figure 0"), std::string::npos);
  EXPECT_NE(output.find("Figure 1"), std::string::npos);
  EXPECT_NE(output.find("Figure 2"), std::string::npos);
  EXPECT_NE(output.find("Center"), std::string::npos);
  EXPECT_NE(output.find("Area"), std::string::npos);
}

TEST_F(FigureArrayTest, OutputOperator) {
  std::ostringstream oss;
  oss << arr;
  std::string output = oss.str();
  EXPECT_GT(output.length(), 0);
}

TEST_F(FigureArrayTest, EqualityOperator) {
  FigureArray arr2;
  arr2.Add(new Square(Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2)));
  arr2.Add(new Rectangle(Point(0, 0), Point(4, 0), Point(4, 2), Point(0, 2)));
  arr2.Add(new Trapezoid(Point(0, 0), Point(4, 0), Point(3, 2), Point(1, 2)));
  EXPECT_EQ(arr, arr2);
}

TEST_F(FigureArrayTest, InequalityOperator) {
  FigureArray arr2;
  arr2.Add(new Square(Point(1, 1), Point(3, 1), Point(3, 3), Point(1, 3)));
  EXPECT_NE(arr, arr2);
}

TEST_F(FigureArrayTest, MoveConstructor) {
  FigureArray arr_copy = std::move(arr);
  EXPECT_EQ(arr_copy.Size(), 3);
}

TEST_F(FigureArrayTest, MoveAssignment) {
  FigureArray arr2;
  arr2.Add(new Square(Point(1, 1), Point(3, 1), Point(3, 3), Point(1, 3)));
  arr2 = std::move(arr);
  EXPECT_EQ(arr2.Size(), 3);
}

class IntegrationTest : public ::testing::Test {
 protected:
  FigureArray shapes;
};

TEST_F(IntegrationTest, CreateMultipleFigures) {
  shapes.Add(new Square(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)));
  shapes.Add(new Rectangle(Point(0, 0), Point(2, 0), Point(2, 1), Point(0, 1)));
  shapes.Add(new Trapezoid(Point(0, 0), Point(2, 0), Point(1.5, 1), Point(0.5, 1)));
  EXPECT_EQ(shapes.Size(), 3);
  EXPECT_GT(shapes.GetTotalArea(), 0.0);
}

TEST_F(IntegrationTest, AllFiguresHaveCenters) {
  shapes.Add(new Square(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)));
  shapes.Add(new Rectangle(Point(0, 0), Point(2, 0), Point(2, 1), Point(0, 1)));
  shapes.Add(new Trapezoid(Point(0, 0), Point(2, 0), Point(1.5, 1), Point(0.5, 1)));
  for (size_t i = 0; i < shapes.Size(); ++i) {
    Figure* fig = shapes.Get(i);
    Point center = fig->GetCenter();
    EXPECT_TRUE(std::isfinite(center.x));
    EXPECT_TRUE(std::isfinite(center.y));
  }
}

TEST_F(IntegrationTest, AllFiguresHaveAreas) {
  shapes.Add(new Square(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)));
  shapes.Add(new Rectangle(Point(0, 0), Point(2, 0), Point(2, 1), Point(0, 1)));
  shapes.Add(new Trapezoid(Point(0, 0), Point(2, 0), Point(1.5, 1), Point(0.5, 1)));
  for (size_t i = 0; i < shapes.Size(); ++i) {
    Figure* fig = shapes.Get(i);
    double area = static_cast<double>(*fig);
    EXPECT_GT(area, 0.0);
  }
}

TEST_F(IntegrationTest, InputOutputConsistency) {
  std::istringstream iss1("0 0 2 0 2 2 0 2");
  Square sq;
  iss1 >> sq;
  std::ostringstream oss;
  oss << sq;
  std::string output = oss.str();
  EXPECT_GT(output.length(), 0);
}

TEST_F(IntegrationTest, RemoveAndRecalculateArea) {
  shapes.Add(new Square(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)));
  shapes.Add(new Square(Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)));
  double area_before = shapes.GetTotalArea();
  shapes.Remove(0);
  double area_after = shapes.GetTotalArea();
  EXPECT_LT(area_after, area_before);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
