#include "fmt/core.h"
#include "tinyxml2.h"
#include "xmlreader.hpp"
#include "vector2d.hpp"

using namespace tinyxml2;

XmlReader::XmlReader(const std::string file_path){
    _document = std::make_unique<XMLDocument>();
    if(_document->LoadFile(file_path.c_str()) == XML_SUCCESS) {
        fmt::print("Loaded file correctly \n");
    }
}

XmlReader::~XmlReader() = default;

std::vector<Vector2d> XmlReader::get_points_vec2d(){
    XMLElement *points = _document->FirstChildElement("points");

    std::vector<Vector2d> res;

    for(XMLElement *point = points->FirstChildElement(); point != NULL; point = point->NextSiblingElement()){
        double x = point->FindAttribute("x")->DoubleValue();
        double y = point->FindAttribute("y")->DoubleValue();

        res.emplace_back(Vector2d(x,y));
    }

    XMLElement *ptm = _document->FirstChildElement("ptm_ratio");

    for(auto& vec : res) {
        vec = vec / ptm->FloatText();
        vec = Vector2d{ vec.x, -vec.y };
    }

    return res;
}