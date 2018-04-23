#pragma once

#include "Document.h"

class EraseVectorGraphicCommand final : public GraphicCommand
{

public:

  explicit EraseVectorGraphicCommand(const std::shared_ptr<Document>& document)
    : GraphicCommand{document} {}

  void Execute() override {
    auto vectorGraphics = _document->GetVectorGraphicByPosition(_document->GetCursorPosition());
    for(const auto& vectorGraphic : vectorGraphics)
      _document->EraseVectorGraphic(vectorGraphic);
  }

};
