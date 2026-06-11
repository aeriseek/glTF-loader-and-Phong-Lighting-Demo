

find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

include(FetchContent)

FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
)

FetchContent_MakeAvailable(json)

add_executable (PhongLighting)


add_library(GLAD "${CMAKE_CURRENT_SOURCE_DIR}/glad.c")
target_include_directories(GLAD PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../inc")
target_link_libraries(GLAD PUBLIC ${OPENGL_LIBRARIES})


target_sources(PhongLighting PRIVATE 
		PhongLighting.cpp 
		VBO.cpp VAO.cpp EBO.cpp 
		Shader.cpp
		Texture.cpp Mesh.cpp Model.cpp
		Camera.cpp
)


target_include_directories(PhongLighting PRIVATE
		../inc
		../headers
	)
target_link_libraries(PhongLighting PRIVATE glfw GLAD OpenGL::GL nlohmann_json::nlohmann_json)
