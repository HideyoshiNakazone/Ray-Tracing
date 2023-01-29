project('RayTracing', 'cpp',
          version: '0.1.0',
    meson_version: '>= 0.53.0',
  default_options: [ 'warning_level=2',
                     'cpp_std=c++17',
                   ],
)

add_project_arguments([
  '-I' + meson.current_source_dir() + '/RayTracing/src/shared/Ray',
  '-I' + meson.current_source_dir() + '/RayTracing/src/shared/Scene',
  '-I' + meson.current_source_dir() + '/RayTracing/src/shared/Camera',
  '-I' + meson.current_source_dir() + '/RayTracing/src/shared/Renderer',
  '-I' + meson.current_source_dir() + '/Walnut/vendor/GLFW/include',
  '-I' + meson.current_source_dir() + '/Walnut/vendor/glm',
  '-I' + meson.current_source_dir() + '/Walnut/vendor/imgui',
  '-I' + meson.current_source_dir() + '/Walnut/vendor/stb_image',
  '-I' + meson.current_source_dir() + '/Walnut/Walnut/src',
  '-I' + meson.current_source_dir() + '/Walnut/Walnut/src/Walnut/Input',
  '-DWL_PLATFORM_WINDOWS',
  '-O3'
], language: 'cpp')

subdir('RayTracing')
