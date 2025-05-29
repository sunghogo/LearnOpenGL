#version 330 core
in vec3 vertex_position;
in vec3 vertex_color;
// uniform vec4 our_color;

out vec4 frag_color;

void main() {
    float wave = vertex_position.x;
    if (wave < 0) {
        wave *= -1;
    }
    frag_color = vec4(vertex_color * wave, 1.0);
    // frag_color = our_color;
}
