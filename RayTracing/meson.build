sources = [
    'src/WalnutApp.cpp',
    'src/shared/Camera/Camera.cpp',
    'src/shared/Renderer/Renderer.cpp',
    meson.source_root() + '/Walnut/Walnut/src/Walnut/Application.cpp',
    meson.source_root() + '/Walnut/Walnut/src/Walnut/Random.cpp',
    meson.source_root() + '/Walnut/Walnut/src/Walnut/Image.cpp',
    meson.source_root() + '/Walnut/Walnut/src/Walnut/ImGui/ImGuiBuild.cpp'
]

walnutlib_sources = [
    meson.source_root() + '/Walnut/Walnut/src/Walnut/Application.cpp',
    meson.source_root() + '/Walnut/Walnut/src/Walnut/Random.cpp',
    meson.source_root() + '/Walnut/Walnut/src/Walnut/Image.cpp',
    meson.source_root() + '/Walnut/Walnut/src/Walnut/Input/Input.cpp',
    meson.source_root() + '/Walnut/Walnut/src/Walnut/ImGui/ImGuiBuild.cpp'
]

imguilib_sources = [
    meson.source_root() + '/Walnut/vendor/imgui/imgui.cpp',
    meson.source_root() + '/Walnut/vendor/imgui/imgui_draw.cpp',
    meson.source_root() + '/Walnut/vendor/imgui/imgui_tables.cpp',
    meson.source_root() + '/Walnut/vendor/imgui/imgui_widgets.cpp',
    meson.source_root() + '/Walnut/vendor/imgui/imgui_demo.cpp'
]

imguilib = static_library(
    'ImGuilib',
    imguilib_sources
)

walnut_deps = [
    dependency('vulkan'),
    dependency('glfw3'),
    dependency('glm')
]

entrylib = static_library(
    'EntryLib',
    sources,
    link_with: [imguilib],
    link_args: ['-ldl', '-lpthread', '-lX11', '-lXxf86vm', '-lXrandr', '-lXi'],
    dependencies: [walnut_deps]
)

executable('Walnut',
    walnutlib_sources,
    install: true,
    cpp_args: ['-DWL_PLATFORM_WINDOWS'],
    link_args: ['-ldl', '-lpthread', '-lX11', '-lXxf86vm', '-lXrandr', '-lXi'],
    link_with: [entrylib, imguilib],
    dependencies: [walnut_deps]
)
