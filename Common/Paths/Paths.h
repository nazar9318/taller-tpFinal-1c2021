#ifndef _PATHS_H
#define _PATHS_H 

/****************************CLIENT***************************************/

// CLIENT_CONFIGURATION
#define CLIENT_CONFIGURATION_PATH "../Client/ClientConfiguration/ClientConfiguration.yaml"

// ATTACK_EFFECT
#define ATTACK_BLOOD_PATH "../Client/Assets/Attacks/blood.bmp"

//CLIENT_BOMB
#define PROGRESS_BARS_PATH "../Client/Assets/Bomb/progress_bars.png"
#define BOMB_GROUND_PATH "../Client/Assets/Bomb/bomb_d.bmp"
#define BOMB_EXPLOSION_PATH "../Client/Assets/Bomb/explosion.png"

// HUD
#define HUD_NUMS_PATH "../Client/Assets/Hud/hud_nums.bmp"
#define HUD_SIMBOLS_PATH "../Client/Assets/Hud/hud_symbols.bmp"
#define HUD_AK47_PATH "../Client/Assets/Hud/ak47_k.bmp"
#define HUD_M3_PATH "../Client/Assets/Hud/m3_k.bmp"
#define HUD_AWP_PATH "../Client/Assets/Hud/awp_k.bmp"
#define HUD_GLOCK_PATH "../Client/Assets/Hud/glock_k.bmp"
#define HUD_KNIFE_PATH "../Client/Assets/Hud/knife_k.bmp"

// INITIAL PHASE
#define JAPANESE_FONT_PATH "../Client/Assets/Fonts/japanese.ttf"
#define BACKGROUND_PATH "../Client/Assets/InitialPhase/background.png"
#define INIT_FASE_BUTTON_PATH "../Client/Assets/InitialPhase/button.png"
#define INIT_FASE_OVER_BUTTON_PATH "../Client/Assets/InitialPhase/over_button.png"
#define INIT_FASE_PRESSED_BUTTON_PATH "../Client/Assets/InitialPhase/pressed_button.png"


// FINAL PHASE
#define FINAL_PHASE_VICTORY_PATH "../Client/Assets/FinalPhase/Victory.png"
#define FINAL_PHASE_DEFEAT_PATH "../Client/Assets/FinalPhase/Defeat.png"


// SOUND HANDLER
#define SOUND_MENU_WAV_PATH "../Client/Assets/Sounds/menu.wav"
#define SOUND_WALK_PATH "../Client/Assets/Sounds/pl_dirt1.wav"
#define SOUND_AK47_PATH "../Client/Assets/Sounds/ak47.wav"
#define SOUND_AWP_PATH "../Client/Assets/Sounds/awp.wav"
#define SOUND_M3_PATH "../Client/Assets/Sounds/m3.wav"
#define SOUND_GLOCK_PATH "../Client/Assets/Sounds/glock18.wav"
#define SOUND_KNIFE_PATH "../Client/Assets/Sounds/knife_hit.wav"
#define SOUND_BOMB_PLACED_PATH "../Client/Assets/Sounds/c4.wav"
#define SOUND_BOMB_DEACTIVATED_PATH "../Client/Assets/Sounds/c4_disarm.wav"
#define SOUND_BOMB_EXPLOTED_PATH "../Client/Assets/Sounds/c4_explode.wav"
#define SOUND_DIE_PATH "../Client/Assets/Sounds/die1.wav"

// SPRITE CONTAINER

#define SPRITE_AWP_PATH "../Client/Assets/Sprites/Weapons/awp.bmp"
#define SPRITE_M3_PATH "../Client/Assets/Sprites/Weapons/m3.bmp"
#define SPRITE_AK47_PATH "../Client/Assets/Sprites/Weapons/ak47.bmp"
#define SPRITE_GLOCK_PATH "../Client/Assets/Sprites/Weapons/glock.bmp"
#define SPRITE_KNIFE_PATH "../Client/Assets/Sprites/Weapons/knife.bmp"
#define SPRITE_BOMB_PATH "../Client/Assets/Sprites/Weapons/bomb.bmp"
#define SPRITE_NPC_T2_PATH "../Client/Assets/NPC/t2.bmp"
#define SPRITE_NPC_CT2_PATH "../Client/Assets/NPC/ct2.bmp"
#define SPRITE_NPC_KNIFE_PATH "../Client/Assets/NPC/knife.bmp"
#define SPRITE_NPC_GLOCK_PATH "../Client/Assets/NPC/glock.bmp"
#define SPRITE_NPC_M3_PATH "../Client/Assets/NPC/m3.bmp"
#define SPRITE_NPC_AK47_PATH "../Client/Assets/NPC/ak47.bmp"
#define SPRITE_NPC_AWP_PATH "../Client/Assets/NPC/awp.bmp"


// TILE CONTAINER
#define TILE_AZTEC_PATH "../Client/Assets/Tiles/aztec.png"
#define TILE_INFERNO_PATH "../Client/Assets/Tiles/inferno.png"
#define TILE_DUST_PATH "../Client/Assets/Tiles/dust.png"
#define TILE_BOMB_A_PATH "../Client/Assets/Tiles/bomb_area_a.png"
#define TILE_BOMB_B_PATH "../Client/Assets/Tiles/bomb_area_b.png"
#define TILE_BOMB_C_PATH "../Client/Assets/Tiles/bomb_area_c.png"
#define TILE_BOX_BLACK_PATH "../Client/Assets/Tiles/box_black.png"
#define TILE_BOX_BROWN_PATH "../Client/Assets/Tiles/box_brown.png"
#define TILE_BOX_METAL_PATH "../Client/Assets/Tiles/box_metal.png"
#define TILE_BOX_WOOD_METAL_PATH "../Client/Assets/Tiles/box_wood_metal.png"
#define TILE_BOX_WOOD_PATH "../Client/Assets/Tiles/box_wood.png"



/****************************SERVER***************************************/

// CONFIGURATION
#ifdef DEV 
#define SERVER_CONFIGS_PATH "../Server/src/Configuration/Configuration.yaml"
#else
#define SERVER_CONFIGS_PATH "Configuration.yaml"
// MAP PARSER
#define MAPS_PATH "../Editor/configs/"



#endif
