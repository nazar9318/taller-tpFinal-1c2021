#ifndef _CAMERA_H
#define _CAMERA_H

class Camera {

	public:
		Camera();
		~Camera();

	private:
		Camera(const Camera &other) = delete;
		Camera& operator=(const Camera &other) = delete;
};


#endif
