#include <glm/glm.hpp>
using namespace glm;

class MyTriangle
{
    private:
        vec3 vectors[3];
        vec3 position;
        vec3 color;

    public:
        MyTriangle(vec3 point1, vec3 point2, vec3 point3, vec3 pos, vec3 col);
        void drawTriangle(vec3 pos, vec3 col, vec4 rot, bool init);
};