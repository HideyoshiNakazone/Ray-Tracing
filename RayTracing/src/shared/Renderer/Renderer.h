#pragma once

#include "../Camera/Camera.h"
#include "../Scene/Scene.h"
#include "../Ray/Ray.h"

#include "Walnut/Random.h"
#include "Walnut/Image.h"

#include <glm/glm.hpp>
#include <memory>


class Renderer {
public:
    Renderer() = default;

    void OnResize(uint32_t width, uint32_t height);
    void Render(const Scene& scene, const Camera& camera);

    std::shared_ptr<Walnut::Image> GetFinalImage() const { return m_FinalImage; }

private:
    struct HitPayload
    {
        float HitDistance;
        glm::vec3 WorldPosition;
        glm::vec3 WorldNormal;

        int ObjectIndex;
    };

    glm::vec4 PerPixel(uint32_t x, uint32_t y);
    HitPayload TraceRay(const Ray& coord);
    HitPayload ClosestHit(const Ray& coord, float hitDistance, int objectIndex);
    HitPayload Miss(const Ray& coord);

private:
    std::shared_ptr<Walnut::Image> m_FinalImage;
    
    const Scene* m_ActiveScene = nullptr;
    const Camera* m_ActiveCamera = nullptr;
    
    uint32_t* m_ImageData = nullptr;
};