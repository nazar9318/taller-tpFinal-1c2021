#include "SoundHandler.h"
#include <iostream>

SoundHandler::SoundHandler() : sound(NULL), death(NULL), bomb_activated(false) {
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	music = Mix_LoadMUS(SOUND_MENU_WAV_PATH);
	Mix_VolumeMusic(MIX_MAX_VOLUME/3);
	Mix_PlayMusic(music, -1);
}

void SoundHandler::handleBomb(Event& event) {
	float distance = 0;
	std::vector<char> event_msg = event.get_msg();
	if ((BombState)event_msg[1] == BombState::ACTIVATED) {
		if (!bomb_activated) {
			this->play(SoundEvent::BOMB_PLACED_SOUND, distance);
			bomb_activated = true;
		}
	}
	if ((BombState)event_msg[2] == BombState::DEACTIVATED) {
		this->play(SoundEvent::BOMB_DEACTIVATED_SOUND, distance);
		bomb_activated = false;
	} else if ((BombState)event_msg[2] == BombState::EXPLOTED) {
		this->play(SoundEvent::BOMB_EXPLODED_SOUND, distance);
		bomb_activated = false;
	}
}

void SoundHandler::handleAttack(Event& event, GameMap& map) {
	std::vector<char> event_msg = event.get_msg();
	int number_attacks = (int)event_msg[1];
	int iterator = 2;
	for (int i = 0; i < number_attacks; i++) {
		char id_attacker = event_msg[iterator];
		float distance = map.distance(id_attacker);
		PositionType weapon = (PositionType)event_msg[iterator + 1];
		this->play(weapon, distance);
		int number_receivers = (int)event_msg[iterator + 2];
		iterator += 3;
		for (int j = 0; j < number_receivers; j++) {
			iterator++;
		}
	}
}

void SoundHandler::handleDeath(Event& event) {
	std::vector<char> event_msg = event.get_msg();
	for (auto it = event_msg.begin() + 1; it != event_msg.end(); it += 23) {
		char life = *(it + 13);
		if (life == 0) {
			if (death != NULL) {
				Mix_FreeChunk(death);
				death = NULL;
			}
			death = Mix_LoadWAV(SOUND_DIE_PATH);
			Mix_PlayChannel(-1, death, 0);
		}
	}
}

void SoundHandler::play(PositionType weapon, float distance) {
	switch (weapon) {
		case PositionType::AK47 : {
			SoundHandler::play(AK47_SOUND, distance);
			break;
		}
		case PositionType::KNIFE : {
			SoundHandler::play(KNIFE_SOUND, distance);
			break;
		}
		case PositionType::GLOCK : {
			SoundHandler::play(GLOCK_SOUND, distance);
			break;
		}
		case PositionType::AWP : {
			SoundHandler::play(AWP_SOUND, distance);
			break;
		}
		case PositionType::M3 : {
			SoundHandler::play(M3_SOUND, distance);
			break;
		}
		default : break;
	}
}

void SoundHandler::play(SoundEvent sound_event, float distance) {
	if (sound != NULL) {
		Mix_FreeChunk(sound);
		sound = NULL;
	}
	switch (sound_event) {
		case SoundEvent::AK47_SOUND : {
			if (distance/32 <= AK47_RANGE) {
				sound = Mix_LoadWAV(SOUND_AK47_PATH);
				if (distance/32 > 0) {Mix_VolumeChunk(sound, MIX_MAX_VOLUME/(distance/64));}
				Mix_PlayChannel(-1, sound, 0);
			}
			break;
		}
		case SoundEvent::AWP_SOUND : {
			if (distance/32 <= AWP_RANGE) {
				sound = Mix_LoadWAV(SOUND_AWP_PATH);
				if (distance/32 > 0) {Mix_VolumeChunk(sound, MIX_MAX_VOLUME/(distance/128));}
				Mix_PlayChannel(-1, sound, 0);
			}
			break;
		}
		case SoundEvent::M3_SOUND : {
			if (distance/32 <= M3_RANGE) {
				sound = Mix_LoadWAV(SOUND_M3_PATH);
				if (distance/32 > 0) {Mix_VolumeChunk(sound, MIX_MAX_VOLUME/(distance/64));}
				Mix_PlayChannel(-1, sound, 0);
			}
			break;
		}
		case SoundEvent::GLOCK_SOUND : {
			if (distance/32 <= GLOCK_RANGE) {
				sound = Mix_LoadWAV(SOUND_GLOCK_PATH);
				if (distance/32 > 0) {Mix_VolumeChunk(sound, MIX_MAX_VOLUME/(distance/32));}
				Mix_PlayChannel(-1, sound, 0);
			}
			break;
		}
		case SoundEvent::KNIFE_SOUND : {
			if (distance/32 <= KNIFE_RANGE) {
				sound = Mix_LoadWAV(SOUND_KNIFE_PATH);
				if (distance/32 > 0) {Mix_VolumeChunk(sound, MIX_MAX_VOLUME/(distance/128));}
				Mix_PlayChannel(-1, sound, 0);
			}
			break;
		}
		case SoundEvent::BOMB_PLACED_SOUND : {
			if (distance/32 <= BOMB_RANGE) {
				sound = Mix_LoadWAV(SOUND_BOMB_PLACED_PATH);
				if (distance/32 > 0) {Mix_VolumeChunk(sound, MIX_MAX_VOLUME/(distance/32));}
				Mix_PlayChannel(-1, sound, 0);
			}
			break;
		}
		case SoundEvent::BOMB_DEACTIVATED_SOUND : {
			if (distance/32 <= BOMB_RANGE) {
				sound = Mix_LoadWAV(SOUND_BOMB_DEACTIVATED_PATH);
				if (distance/32 > 0) {Mix_VolumeChunk(sound, MIX_MAX_VOLUME/(distance/32));}
				Mix_PlayChannel(-1, sound, 0);
			}
			break;
		}
		case SoundEvent::BOMB_EXPLODED_SOUND : {
			if (distance/32 <= BOMB_RANGE) {
				sound = Mix_LoadWAV(SOUND_BOMB_EXPLOTED_PATH);
				if (distance/32 > 0) {Mix_VolumeChunk(sound, MIX_MAX_VOLUME/(distance/128));}
				Mix_PlayChannel(-1, sound, 0);
			}
			break;
		}
		default : break;
	}
}

SoundHandler::~SoundHandler() {
	if (sound != NULL) {
		Mix_FreeChunk(sound);
		sound = NULL;
	}
	if (death != NULL) {
		Mix_FreeChunk(death);
		death = NULL;
	}
	Mix_CloseAudio();
	Mix_FreeMusic(music);
}
