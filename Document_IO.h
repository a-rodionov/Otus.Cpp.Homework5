#pragma once

#include "Document.h"

static const std::string FILE_EXTENSION_WMF{"WMF"};
static const std::string FILE_EXTENSION_CDR{"CDR"};

class Document_IO
{

public:

  virtual std::unique_ptr<Document> ReadDocument(const std::string& filename) const = 0;

  virtual void WriteDocument(const std::string& filename, const std::shared_ptr<Document>& document) const = 0;

};

class Document_IO_WMF final : public Document_IO
{

public:

  std::unique_ptr<Document> ReadDocument(const std::string& filename) const override {
    //read data from WMF file, parse, add vector graphics to document
    return std::make_unique<Document>();
  }

  void WriteDocument(const std::string& filename, const std::shared_ptr<Document>& document) const override {
    const auto& vectorGraphics = document->GetVectorGraphics();
    for(const auto& vectorGraphic : vectorGraphics) {
      //write each vectorGraphic to WMF file
    }
  }

};

class Document_IO_CDR final : public Document_IO
{

public:

  std::unique_ptr<Document> ReadDocument(const std::string& filename) const override {
    //read data from CDR file, parse, add vector graphics to document
    return std::make_unique<Document>();
  }

  void WriteDocument(const std::string& filename, const std::shared_ptr<Document>& document) const override {
    const auto& vectorGraphics = document->GetVectorGraphics();
    for(const auto& vectorGraphic : vectorGraphics) {
      //write each vectorGraphic to CDR file
    }
  }

};
