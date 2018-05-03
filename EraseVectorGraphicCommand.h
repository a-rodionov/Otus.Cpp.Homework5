#pragma once

#include "Document.h"

class EraseVectorGraphicCommand final : public GraphicCommand
{

public:

  explicit EraseVectorGraphicCommand(const std::shared_ptr<Document>& document)
    : GraphicCommand{document} {}

  void Execute() override {
  	std::shared_ptr<Document> document{_document};
    auto vectorGraphics = document->GetVectorGraphicByPosition(document->GetCursorPosition());
    for(const auto& vectorGraphic : vectorGraphics)
      document->EraseVectorGraphic(vectorGraphic);
  }

};
