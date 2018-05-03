#pragma once

#include <memory>
#include <vector>
#include "Point.h"

enum class VECTOR_GRAPHIC_ID
{
  POINT,
  TEXT,
  LINE,
  RECTANGLE,
  COMPOSITE
};

class VectorGraphic
{

public:

  virtual ~VectorGraphic(){};

  virtual void Draw() const = 0;

  virtual void Add(std::unique_ptr<VectorGraphic>) {}

  virtual VECTOR_GRAPHIC_ID GetId() const = 0;

};

class CompositeVectorGraphic : public VectorGraphic
{

public:

  void Draw() const override {
    for(const auto& vectorGraphic : vectorGraphics)
      vectorGraphic->Draw();
  }

  void Add(std::unique_ptr<VectorGraphic> vectorGraphic) override {
    vectorGraphics.push_back(std::move(vectorGraphic));
  }

  VECTOR_GRAPHIC_ID GetId() const override {
    return VECTOR_GRAPHIC_ID::COMPOSITE;
  }

private:

  std::vector<std::unique_ptr<VectorGraphic>> vectorGraphics;
};

class VectorPoint final : public VectorGraphic
{

public:

  explicit VectorPoint(const Point& position)
    : _position{position} {}

  void Draw() const override
  {}

  VECTOR_GRAPHIC_ID GetId() const override {
    return VECTOR_GRAPHIC_ID::POINT;
  }

private:

  Point _position;
};

class VectorText final : public VectorGraphic
{

public:

  explicit VectorText(const Point& position, const std::string text = "")
    : _position{position} , _text{text} {}

  void Draw() const override
  {}

  VECTOR_GRAPHIC_ID GetId() const override {
    return VECTOR_GRAPHIC_ID::TEXT;
  }

  void SetText(const std::string text) {
    _text = text;
  }

private:

  Point       _position;
  std::string _text;
};

class VectorLine final : public VectorGraphic
{

public:

  VectorLine(const Point& point_1, const Point& point_2)
    : _point_1{point_1}, _point_2{point_2} {}

  void Draw() const override
  {}

  VECTOR_GRAPHIC_ID GetId() const override {
    return VECTOR_GRAPHIC_ID::LINE;
  }

private:

  Point _point_1;
  Point _point_2;
};

class VectorRectangle final : public CompositeVectorGraphic
{

public:

  VectorRectangle(const Point& point_1, const Point& point_2)
  {
    Point point_3{point_1.x, point_2.y};
    Point point_4{point_2.x, point_1.y};
    CompositeVectorGraphic::Add(std::make_unique<VectorLine>(point_1, point_3));
    CompositeVectorGraphic::Add(std::make_unique<VectorLine>(point_1, point_4));
    CompositeVectorGraphic::Add(std::make_unique<VectorLine>(point_2, point_3));
    CompositeVectorGraphic::Add(std::make_unique<VectorLine>(point_2, point_4));
  }

  void Add(std::unique_ptr<VectorGraphic> vectorGraphic) override
  {}

  VECTOR_GRAPHIC_ID GetId() const override {
    return VECTOR_GRAPHIC_ID::RECTANGLE;
  }

};
