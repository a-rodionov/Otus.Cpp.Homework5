#pragma once

class Document;

class GraphicCommand
{

public:

  explicit GraphicCommand(const std::weak_ptr<Document>& document)
    : _document{document} {}
    
  virtual ~GraphicCommand(){};

  virtual void Execute() = 0;

protected:

  std::weak_ptr<Document> _document;

};
