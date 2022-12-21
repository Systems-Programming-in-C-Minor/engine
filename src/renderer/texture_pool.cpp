#include "render/texture_pool.hpp"
#include "sdltexture.hpp"

#include "fmt/core.h"

#include <iostream>
#include <string>
#include <unordered_map>

std::shared_ptr<ITexture> TexturePool::add_texture(const std::string & path)
{
    fmt::print("TexturePool: Adding texture {}\n", path);

    auto texture = std::make_shared<SdlTexture>(path);
    auto temp_texture = std::weak_ptr<ITexture>(texture);
    _pool.insert(std::pair<const std::string, std::weak_ptr<ITexture>>(path, temp_texture));

    return texture;
}

std::shared_ptr<ITexture> TexturePool::load_texture(const std::string & path)
{
    std::shared_ptr<ITexture> texture;
	const std::unordered_map<std::string, std::weak_ptr<ITexture>>::const_iterator it = _pool.find(path);
    if (it == _pool.end())
    {
        fmt::print("TexturePool: Texture {} not found\n", path);

        texture = add_texture(path);
    }
    else
    {
	    const std::weak_ptr<ITexture> temp_texture = it->second;
        if(temp_texture.expired())
        {
            fmt::print("TexturePool: Texture {} found, but was destroyed\n", path);

            _pool.erase(path);
            texture = add_texture(path);
        }
        else
        {
            fmt::print("TexturePool: Texture {} found, reusing\n", path);

            texture = it->second.lock();
        }
    }
    return texture;
        
}
