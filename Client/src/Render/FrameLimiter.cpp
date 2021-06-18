#include "FrameLimiter.h"

#include <SDL2/SDL.h>


FrameLimiter::FrameLimiter()
	:frame_start(SDL_GetTicks()),
	iteration(0),
	fps(30),// HARCODEADO  FALTA HACER EL YAML
	frame_rate(1000 / fps) {}

void FrameLimiter::sleep() {
	long long frame_time, rest_time, behind, lost;
	frame_time = SDL_GetTicks();
	rest_time = frame_rate - (frame_time - frame_start);
	if (rest_time < 0) {
		behind = -rest_time;
		rest_time = frame_rate - behind % frame_rate;
		lost = behind + rest_time;
		frame_start += lost;
		iteration += floor(double(lost / frame_rate)); 
 	}

 	SDL_Delay(rest_time);
 	frame_start += frame_rate;
 	iteration++;
}

FrameLimiter::~FrameLimiter() {}
