#pragma once

#include "Document.h"

static const size_t DEFAULT_OFFSET = 10;




class AddVectorGraphicCommand : public GraphicCommand
{

public:

  explicit AddVectorGraphicCommand(const std::shared_ptr<Document>& document)
    : GraphicCommand{document} {}

  void Execute() override {
    _document->AddVectorGraphic(CreateVectorGraphic(_document->GetCursorPosition()));
  }

protected:

  virtual std::shared_ptr<VectorGraphic> CreateVectorGraphic(const Point& cursorPosition) const = 0;

};




class AddVectorPointCommand final : public AddVectorGraphicCommand
{

public:

  explicit AddVectorPointCommand(const std::shared_ptr<Document>& document)
    : AddVectorGraphicCommand{document} {}

private:

  std::shared_ptr<VectorGraphic> CreateVectorGraphic(const Point& cursorPosition) const override {
    return std::make_shared<VectorPoint>(cursorPosition);
  }

};




class AddVectorTextCommand final : public AddVectorGraphicCommand
{

public:

  explicit AddVectorTextCommand(const std::shared_ptr<Document>& document)
    : AddVectorGraphicCommand{document} {}

private:

  std::shared_ptr<VectorGraphic> CreateVectorGraphic(const Point& cursorPosition) const override {
    return std::make_shared<VectorText>(cursorPosition);
  }

};




class AddVectorLineCommand final : public AddVectorGraphicCommand
{

public:

  explicit AddVectorLineCommand(const std::shared_ptr<Document>& document)
    : AddVectorGraphicCommand{document} {}

private:

  std::shared_ptr<VectorGraphic> CreateVectorGraphic(const Point& cursorPosition) const override {
    return std::make_shared<VectorLine>(cursorPosition, Point{cursorPosition.x + DEFAULT_OFFSET, cursorPosition.y + DEFAULT_OFFSET});
  }

};




class AddVectorRectangleCommand final : public AddVectorGraphicCommand
{

public:

  explicit AddVectorRectangleCommand(const std::shared_ptr<Document>& document)
    : AddVectorGraphicCommand{document} {}

private:

  std::shared_ptr<VectorGraphic> CreateVectorGraphic(const Point& cursorPosition) const override {
    return std::make_shared<VectorRectangle>(cursorPosition, Point{cursorPosition.x + DEFAULT_OFFSET, cursorPosition.y + DEFAULT_OFFSET});
  }

};
