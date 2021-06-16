#ifndef _RENDERER_H
#define _RENDERER_H



class Renderer {
	public: 
		Renderer();
		void draw();
		~Renderer();

	private:
		Renderer(const Renderer &other) = delete;
		Renderer& operator=(const Renderer &other) = delete;
};

#endif
