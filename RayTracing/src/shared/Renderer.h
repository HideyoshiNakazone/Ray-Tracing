#pragma once

#include "Walnut/Random.h"
#include "Walnut/Image.h"

#include <glm/glm.hpp>
#include <memory>


class Renderer {
public:
    Renderer() = default;

    void OnResize(uint32_t width, uint32_t height);
    void Render();

    std::shared_ptr<Walnut::Image> GetFinalImage() const { return m_FinalImage; }
private:
    glm::vec4 PerPixel(glm::vec2 coord);
    
private:
    uint32_t* m_ImageData = nullptr;
    std::shared_ptr<Walnut::Image> m_FinalImage;
};