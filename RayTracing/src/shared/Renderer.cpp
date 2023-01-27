#include "Renderer.h"


namespace Utils {
    static uint32_t ConvertToRGBA(glm::vec4 color) {
        color = glm::clamp(color, glm::vec4(0.0f), glm::vec4(1.0f));

        uint8_t r = (uint8_t)(color.r * 255.0f);
        uint8_t g = (uint8_t)(color.g * 255.0f);
        uint8_t b = (uint8_t)(color.b * 255.0f);
        uint8_t a = (uint8_t)(color.a * 255.0f);

        return (a << 24) | (b << 16) | (g << 8) | r;
    }
}

void Renderer::OnResize(uint32_t width, uint32_t height) {
    
    if (m_FinalImage) {
        // No Resize needed
        if (m_FinalImage->GetWidth() == width || m_FinalImage->GetHeight() == height)
            return;
        
        m_FinalImage->Resize(width, height);
    } else {
        m_FinalImage = std::make_shared<Walnut::Image>(width, height, Walnut::ImageFormat::RGBA);
    }
    
    delete[] m_ImageData;
    m_ImageData = new uint32_t[width * height];
}

void Renderer::Render() {
    float aspectRat = m_FinalImage->GetWidth() / (float)(m_FinalImage->GetHeight());
    for (uint32_t y = 0; y < m_FinalImage->GetHeight(); y++) {
        for (uint32_t x = 0; x < m_FinalImage->GetWidth(); x++) {   
            
            glm::vec2 coord = {
                (float)x / (float)m_FinalImage->GetWidth(),
                (float)y / (float)m_FinalImage->GetHeight()
            };
            coord = coord * 2.0f - 1.0f; // -1 -> 1
            coord.x *= aspectRat;

            glm::vec4 color = PerPixel(coord);

            m_ImageData[x + y * m_FinalImage->GetWidth()] = Utils::ConvertToRGBA(color);
        }
    }

    m_FinalImage->SetData(m_ImageData);
}

glm::vec4 Renderer::PerPixel(glm::vec2 coord) {

    glm::vec3 sphereColor(1, 0, 1);
    
    float radius = 0.5f;

    glm::vec3 rayOrigin(0.0f, 0.0f, 1.0f);
    glm::vec3 rayDirection(coord.x, coord.y, -1.0f);

    glm::vec3 lightDirection = glm::normalize(glm::vec3(-1, -1, -1));

    float a = glm::dot(rayDirection, rayDirection);
    float b = 2.0f * glm::dot(rayOrigin, rayDirection);
    float c = glm::dot(rayOrigin, rayOrigin) - radius * radius;

    float descriminant = b * b - 4.0f * a * c;
    
    if (descriminant < 0.0f)
        return glm::vec4(0, 0, 0, 1);

    // float t0 = (-b + glm::sqrt(descriminant)) / (2.0f * a);
    float closestT = (-b - glm::sqrt(descriminant)) / (2.0f * a);

    // glm::vec3 h1 = rayOrigin + rayDirection * t1;
    glm::vec3 hitPoint = rayOrigin + rayDirection * closestT;
    glm::vec3 hitPointNormal = glm::normalize(hitPoint);

    float lightIntensity = glm::max(
        glm::dot(hitPointNormal, -lightDirection),
        0.0f
    );

    sphereColor *= lightIntensity;
    return glm::vec4(sphereColor, 1.0f);
    
}