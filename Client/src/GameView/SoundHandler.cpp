#include "SoundHandler.h"
#include <iostream>

SoundHandler::SoundHandler() : sound(NULL), bomb_activated(false) {
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
}

void SoundHandler::handleBomb(Event& event) {
	std::vector<char> event_msg = event.get_msg();
	if ((BombState)event_msg[1] == BombState::ACTIVATED) {
		if (!bomb_activated) {
			this->play(SoundEvent::BOMB_PLACED_SOUND);
			bomb_activated = true;
		}
	}
	if ((BombState)event_msg[2] == BombState::DEACTIVATED) {
		this->play(SoundEvent::BOMB_DEACTIVATED_SOUND);
		bomb_activated = false;
	} else if ((BombState)event_msg[2] == BombState::EXPLOTED) {
		this->play(SoundEvent::BOMB_EXPLODED_SOUND);
		bomb_activated = false;
	}
}

void SoundHandler::handle(Event& event) {
	std::vector<char> event_msg = event.get_msg();
	int number_attacks = (int)event_msg[1];
	int iterator = 2; 
	if (number_attacks > 0)
	for (int i = 0; i < number_attacks; i++) {
		PositionType weapon = (PositionType)event_msg[iterator + 1];
		this->play(weapon);
		int number_receivers = (int)event_msg[iterator + 2];
		iterator += 3;
		for (int j = 0; j < number_receivers; j++) {
			iterator++;
		}
	}
}

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
	switch (sound_event) {
		case SoundEvent::AK47_SOUND : {
			sound = Mix_LoadWAV("../Client/Assets/Sounds/ak47.wav");
			sounds.push_back(sound);
			Mix_PlayChannel(-1, sound, 0);
			break;
		}
		case SoundEvent::AWP_SOUND : {
			sound = Mix_LoadWAV("../Client/Assets/Sounds/awp.wav");
			sounds.push_back(sound);
			Mix_PlayChannel(-1, sound, 0);
			break;
		}
		case SoundEvent::M3_SOUND : {
			sound = Mix_LoadWAV("../Client/Assets/Sounds/m3.wav");
			sounds.push_back(sound);
			Mix_PlayChannel(-1, sound, 0);
			break;
		}
		case SoundEvent::GLOCK_SOUND : {
			sound = Mix_LoadWAV("../Client/Assets/Sounds/glock18.wav");
			sounds.push_back(sound);
			Mix_PlayChannel(-1, sound, 0);
			break;
		}
		case SoundEvent::KNIFE_SOUND : {
			sound = Mix_LoadWAV("../Client/Assets/Sounds/knife_hit.wav");
			sounds.push_back(sound);
			Mix_PlayChannel(-1, sound, 0);
			break;
		}
		case SoundEvent::BOMB_PLACED_SOUND : {
			sound = Mix_LoadWAV("../Client/Assets/Sounds/c4.wav");
			Mix_PlayChannel(-1, sound, 0);
			sounds.push_back(sound);
			break;
		}
		case SoundEvent::BOMB_DEACTIVATED_SOUND : {
			sound = Mix_LoadWAV("../Client/Assets/Sounds/c4_disarm.wav");
			Mix_PlayChannel(-1, sound, 0);
			sounds.push_back(sound);
			break;
		}
		case SoundEvent::BOMB_EXPLODED_SOUND : {
			sound = Mix_LoadWAV("../Client/Assets/Sounds/c4_explode.wav");
			Mix_PlayChannel(-1, sound, 0);
			sounds.push_back(sound);
			break;
		}
		default : break;
	}
}

SoundHandler::~SoundHandler() {
	for (auto sound : sounds) { Mix_FreeChunk(sound); }
	Mix_CloseAudio();
}
