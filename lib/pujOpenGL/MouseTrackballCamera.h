#ifndef __pujOpenGL__MouseTrackballCamera__h__
#define __pujOpenGL__MouseTrackballCamera__h__

#include <pujOpenGL/BaseCamera.h>

namespace pujOpenGL {
  class MouseTrackballCamera : public BaseCamera {
  public:
    using Self = MouseTrackballCamera;
    using Superclass = BaseCamera;

  public:
    MouseTrackballCamera();
    virtual ~MouseTrackballCamera();

    //virtual void ConfigureFromBounds(const float* b) override;
    virtual void MouseEvent(int x, int y) override;
    //virtual void Draw( ) const override;

  //protected:
  //  virtual void _Reset( );
  //  virtual void _Update( );

  protected:
    float pitch = 0;
    float yaw = 0;
    
    float lastX = 0;
    float lastY = 0;
    bool neverEnteredMouse = true;
    
    std::array< float, 16 > Transform
      {
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1
      };
  };
} // end namespace

#endif // __pujOpenGL__MouseTrackballCamera__h__

// eof - MouseTrackballCamera.h
