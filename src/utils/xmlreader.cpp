#include "fmt/core.h"
#include "tinyxml2.h"
#include "utils/xmlreader.hpp"
#include "vector2d.hpp"

//using namespace tinyxml2;

XmlReader::XmlReader(const std::string file_path){
    _document = std::make_unique<tinyxml2::XMLDocument>();
//    _document = new XMLDocument();
    if(_document->LoadFile(file_path.c_str()) == tinyxml2::XML_SUCCESS) {
        fmt::print("Loaded file correctly \n");
    }
}

std::vector<Vector2d> XmlReader::get_points_vec2d(){
    tinyxml2::XMLElement *points = _document->FirstChildElement("points");

    std::vector<Vector2d> res;

    for(tinyxml2::XMLElement *point = points->FirstChildElement(); point != NULL; point = point->NextSiblingElement()){
        double x = point->FindAttribute("x")->DoubleValue();
        double y = point->FindAttribute("y")->DoubleValue();

        res.push_back(Vector2d(x,y));
    }

    tinyxml2::XMLElement *ptm = _document->FirstChildElement("ptm_ratio");

    for(auto& vec : res) {
        float p2m = ptm->FloatText();
        vec = vec / p2m;
}

    return res;
}