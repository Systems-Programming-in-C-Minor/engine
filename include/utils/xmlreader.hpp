#ifndef UTILS_HPP_XMLREADER_HPP
#define UTILS_HPP_XMLREADER_HPP

#include <string>
#include <memory>
#include <vector>
#include "vector2d.hpp"

namespace tinyxml2 {
    class XMLDocument;
}

class XmlReader {
private:
    std::unique_ptr<tinyxml2::XMLDocument> _document;

public:
    XmlReader(const std::string file_path);
    virtual ~XmlReader();

    std::vector<Vector2d> get_points_vec2d();
};


#endif //UTILS_HPP_XMLREADER_HPP