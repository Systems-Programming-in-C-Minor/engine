#ifndef UTILS_HPP_XMLREADER_HPP
#define UTILS_HPP_XMLREADER_HPP

#include <string>
#include <memory>
#include <vector>

class Vector2d;

namespace tinyxml2 {
    class XMLDocument;
}

/**
 * @brief Class to read an xml file.
 */
class XmlReader {
private:
    std::unique_ptr<tinyxml2::XMLDocument> _document;

public:
    /**
     * @brief Constructor.
     * @param file_path The path to the xml file.
     */
    XmlReader(const std::string file_path);

    /**
     * @brief Virtual destructor.
     */
    virtual ~XmlReader();

    /**
     * @brief Getter method vor Vector2d points.
     * @return A vector containing the Vector2d points.
     */
    std::vector<Vector2d> get_points_vec2d();
};


#endif //UTILS_HPP_XMLREADER_HPP