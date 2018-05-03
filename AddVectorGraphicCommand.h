#pragma once

#include "Document.h"

static const size_t DEFAULT_OFFSET = 10;




class AddVectorGraphicCommand : public GraphicCommand
{

public:

  explicit AddVectorGraphicCommand(const std::weak_ptr<Document>& document)
    : GraphicCommand{document} {}

  void Execute() override {
    std::shared_ptr<Document> document{_document};
    document->AddVectorGraphic(CreateVectorGraphic(document->GetCursorPosition()));
  }

protected:

  virtual std::unique_ptr<VectorGraphic> CreateVectorGraphic(const Point& cursorPosition) const = 0;

};




class AddVectorPointCommand final : public AddVectorGraphicCommand
{

public:

  explicit AddVectorPointCommand(const std::weak_ptr<Document>& document)
    : AddVectorGraphicCommand{document} {}

private:

  std::unique_ptr<VectorGraphic> CreateVectorGraphic(const Point& cursorPosition) const override {
    return std::make_unique<VectorPoint>(cursorPosition);
  }

};




class AddVectorTextCommand final : public AddVectorGraphicCommand
{

public:

  explicit AddVectorTextCommand(const std::weak_ptr<Document>& document)
    : AddVectorGraphicCommand{document} {}

private:

  std::unique_ptr<VectorGraphic> CreateVectorGraphic(const Point& cursorPosition) const override {
    return std::make_unique<VectorText>(cursorPosition);
  }

};




class AddVectorLineCommand final : public AddVectorGraphicCommand
{

public:

  explicit AddVectorLineCommand(const std::weak_ptr<Document>& document)
    : AddVectorGraphicCommand{document} {}

private:

  std::unique_ptr<VectorGraphic> CreateVectorGraphic(const Point& cursorPosition) const override {
    return std::make_unique<VectorLine>(cursorPosition, Point{cursorPosition.x + DEFAULT_OFFSET, cursorPosition.y + DEFAULT_OFFSET});
  }

};




class AddVectorRectangleCommand final : public AddVectorGraphicCommand
{

public:

  explicit AddVectorRectangleCommand(const std::weak_ptr<Document>& document)
    : AddVectorGraphicCommand{document} {}

private:

  std::unique_ptr<VectorGraphic> CreateVectorGraphic(const Point& cursorPosition) const override {
    return std::make_unique<VectorRectangle>(cursorPosition, Point{cursorPosition.x + DEFAULT_OFFSET, cursorPosition.y + DEFAULT_OFFSET});
  }

};
