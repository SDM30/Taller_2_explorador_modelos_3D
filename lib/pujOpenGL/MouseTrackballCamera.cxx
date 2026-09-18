#include <pujOpenGL/MouseTrackballCamera.h>
#include <iostream>
#include <cmath>

pujOpenGL::MouseTrackballCamera::MouseTrackballCamera()
  : Superclass() {
}

pujOpenGL::MouseTrackballCamera::~MouseTrackballCamera() {
}

void pujOpenGL::MouseTrackballCamera::MouseEvent(int x, int y)
{
  if (neverEnteredMouse) {
    lastX = x;
    lastY = y;
    neverEnteredMouse = false;
    return;
  }
  
  static float rad = std::atan(float(1)) / float(45);
  static float speed = 0.3;
  
  float diffX = lastX - x;
  float diffY = lastY - y;
  
  yaw += diffX * speed;
  
  std::cout << yaw << std::endl;

  Eye[0] = std::cos(yaw * rad); // la multiplicacion convierte el angulo a radianes
  Eye[2] = std::sin(yaw * rad);
  
  lastX = x;
  lastY = y;
}
