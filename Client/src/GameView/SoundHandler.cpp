#include "SoundHandler.h"

SoundHandler::SoundHandler() : sound(NULL) {}

void SoundHandler::play(PositionType weapon) {
	switch (weapon) {
		case PositionType::AK47 : {
			SoundHandler::play(AK47_SOUND);
			break;
		}
		case PositionType::KNIFE : {
			SoundHandler::play(KNIFE_SOUND);
			break;
		}
		case PositionType::GLOCK : {
			SoundHandler::play(GLOCK_SOUND);
			break;
		}
		case PositionType::AWP : {
			SoundHandler::play(AWP_SOUND);
			break;
		}
		case PositionType::M3 : {
			SoundHandler::play(M3_SOUND);
			break;
		}
		default : break;
	}
}

void SoundHandler::play(SoundEvent sound_event) {
	Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
	Mix_Chunk* sound = NULL;
	switch (sound_event) {
		case SoundEvent::AK47_SOUND : {
			sound = Mix_LoadWAV("../Client/Assets/Sounds/ak47.wav");
			Mix_PlayChannel(-1, sound, 0);
			break;
		}
		case SoundEvent::AWP_SOUND : {
			sound = Mix_LoadWAV("../Client/Assets/Sounds/awp.wav");
			Mix_PlayChannel(-1, sound, 0);
			break;
		}
		case SoundEvent::M3_SOUND : {
			sound = Mix_LoadWAV("../Client/Assets/Sounds/m3.wav");
			Mix_PlayChannel(-1, sound, 0);
			break;
		}
		case SoundEvent::GLOCK_SOUND : {
			sound = Mix_LoadWAV("../Client/Assets/Sounds/glock18.wav");
			Mix_PlayChannel(-1, sound, 0);
			break;
		}
		case SoundEvent::KNIFE_SOUND : {
			sound = Mix_LoadWAV("../Client/Assets/Sounds/knife_hit.wav");
			Mix_PlayChannel(-1, sound, 0);
			break;
		}
		case SoundEvent::BOMB_PLACED_SOUND : {
			sound = Mix_LoadWAV("../Client/Assets/Sounds/c4.wav");
			Mix_PlayChannel(-1, sound, 0);
			break;
		}
		case SoundEvent::BOMB_DEACTIVATED_SOUND : {
			sound = Mix_LoadWAV("../Client/Assets/Sounds/c4_disarm.wav");
			Mix_PlayChannel(-1, sound, 0);
			break;
		}
		case SoundEvent::BOMB_EXPLODED_SOUND : {
			sound = Mix_LoadWAV("../Client/Assets/Sounds/c4_explode.wav");
			Mix_PlayChannel(-1, sound, 0);
			break;
		}
		default : break;
	}
	//SDL_Delay(1000);
	//Mix_FreeChunk(sound);
}

SoundHandler::~SoundHandler() {
	if (sound) {free(sound);}
}
