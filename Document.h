#pragma once

#include <iostream>
#include "VectorGraphic.h"
#include "GraphicCommand.h"

class Document
{

public:

  void SetCommand(const std::shared_ptr<GraphicCommand>& command) {
    _command = command;
  }

  void Click() {
    if(nullptr != _command.get())
      _command->Execute();
  }

  void Draw() const {
    for(const auto& vectorGraphic : _vectorGraphics)
      vectorGraphic->Draw();
  }

  Point GetCursorPosition() const {
    return Point{};
  }

  std::vector<std::shared_ptr<VectorGraphic>> GetVectorGraphicByPosition(const Point& point) const {
    return std::vector<std::shared_ptr<VectorGraphic>>{};
  }

  const std::vector<std::shared_ptr<VectorGraphic>>& GetVectorGraphics() const {
    return _vectorGraphics;
  }

  void AddVectorGraphic(const std::shared_ptr<VectorGraphic>& vectorGraphic) {}

  void EraseVectorGraphic(const std::shared_ptr<VectorGraphic>& vectorGraphic) {}

private:

  std::vector<std::shared_ptr<VectorGraphic>> _vectorGraphics;
  std::shared_ptr<GraphicCommand> _command;
};
