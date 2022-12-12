#include "fmt/core.h"
#include "utils/xmlreader.hpp"
#include "tinyxml2.h"
#include "vector2d.hpp"

using namespace tinyxml2;

XmlReader::XmlReader(const std::string file_path){
    _document = new XMLDocument;
    if(_document->LoadFile(file_path.c_str()) == XML_SUCCESS) {
        fmt::print("Loaded file correctly \n");
    }
}

XmlReader::~XmlReader() {
    delete _document;
    _document = nullptr;
}

std::vector<Vector2d> XmlReader::get_points_vec2d(){
    XMLElement *points = _document->FirstChildElement("points");

    std::vector<Vector2d> res;

    for(XMLElement *point = points->FirstChildElement(); point != NULL; point = point->NextSiblingElement()){
        double x = point->FindAttribute("x")->DoubleValue();
        double y = point->FindAttribute("y")->DoubleValue();

        res.push_back(Vector2d(x,y));
    }

    points = nullptr;
    return res;
}