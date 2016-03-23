#version 330 core
#define POSITION_LOCATION 0
#define VELOCITY_LOCATION 1
#define SPAWNTIME_LOCATION 2
#define COLOR_LOCATION 3

precision highp float;
precision highp int;
layout(std140, column_major) uniform;

uniform float u_time;
uniform vec3 u_accel;

layout(location = POSITION_LOCATION) in vec3 a_position;
layout(location = VELOCITY_LOCATION) in vec3 a_velocity;
layout(location = SPAWNTIME_LOCATION) in float a_spawntime;
layout(location = COLOR_LOCATION) in vec4 a_color;

out vec3 v_position;
out vec3 v_velocity;
out float v_spawntime;
out vec4 v_color;

float rand(vec2 co){
    return fract(sin(dot(co.xy ,vec2(12.9898,78.233))) * 43758.5453);
}

void main()
{
    v_velocity = a_velocity + vec3(0.0, 0.01, 0.0);// u_time * u_accel + vec3(0.0, 0.1, 0.0);
    v_position = a_position + u_time * v_velocity + vec3(0.0, 0.1, 0.0);
    v_spawntime = a_spawntime;
    v_color = a_color;
}
