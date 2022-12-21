#ifndef TEXTURE_POOL_HPP
#define TEXTURE_POOL_HPP

#include "itexture.hpp"

#include <unordered_map>
#include <string>
#include <memory>

class TexturePool
{
private:
	std::unordered_map<std::string, std::weak_ptr<ITexture>> _pool;

	[[nodiscard]] std::shared_ptr<ITexture> add_texture(const std::string& path);
public:
	std::shared_ptr<ITexture> load_texture(const std::string& path);
};

#endif // TEXTURE_POOL_HPP