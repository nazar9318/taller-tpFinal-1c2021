#ifdef USR_MODE
  /****************************CLIENT***************************************/

    // CLIENT_CONFIGURATION
    #define CLIENT_CONFIGURATION_PATH "ClientConfiguration.yaml"

    // WINDOW
    #define WINDOW_ICON_PATH "Assets/Window/gametitle.png"

    // ATTACK_EFFECT
    #define ATTACK_BLOOD_PATH "Assets/Attacks/blood.bmp"
    #define ATTACK_ARROW_PATH "Assets/Attacks/arrow.bmp"

    //CLIENT_BOMB
    #define PROGRESS_BARS_PATH "Assets/Bomb/progress_bars.png"
    #define BOMB_GROUND_PATH "Assets/Bomb/bomb_d.bmp"
    #define BOMB_EXPLOSION_PATH "Assets/Bomb/explosion.png"

    // HUD
    #define HUD_NUMS_PATH "Assets/Hud/hud_nums.bmp"
    #define HUD_SIMBOLS_PATH "Assets/Hud/hud_symbols.bmp"
    #define HUD_AK47_PATH "Assets/Hud/ak47_k.bmp"
    #define HUD_M3_PATH "Assets/Hud/m3_k.bmp"
    #define HUD_AWP_PATH "Assets/Hud/awp_k.bmp"
    #define HUD_GLOCK_PATH "Assets/Hud/glock_k.bmp"
    #define HUD_KNIFE_PATH "Assets/Hud/knife_k.bmp"

    // INITIAL PHASE
    #define JAPANESE_FONT_PATH "Assets/Fonts/japanese.ttf"
    #define BACKGROUND_PATH "Assets/InitialPhase/background.png"
    #define BUY_WINDOW_PATH "Assets/InitialPhase/buyWindow.png"
    #define INIT_FASE_BUTTON_PATH "Assets/InitialPhase/button.png"
    #define INIT_FASE_OVER_BUTTON_PATH "Assets/InitialPhase/over_button.png"
    #define INIT_FASE_PRESSED_BUTTON_PATH "Assets/InitialPhase/pressed_button.png"


    // FINAL PHASE
    #define FINAL_PHASE_VICTORY_PATH "Assets/FinalPhase/Victory.png"
    #define FINAL_PHASE_DEFEAT_PATH "Assets/FinalPhase/Defeat.png"


    // SOUND HANDLER
    #define SOUND_MENU_WAV_PATH "Assets/Sounds/menu.wav"
    #define SOUND_WALK_PATH "Assets/Sounds/pl_dirt1.wav"
    #define SOUND_AK47_PATH "Assets/Sounds/ak47.wav"
    #define SOUND_AWP_PATH "Assets/Sounds/awp.wav"
    #define SOUND_M3_PATH "Assets/Sounds/m3.wav"
    #define SOUND_GLOCK_PATH "Assets/Sounds/glock18.wav"
    #define SOUND_KNIFE_PATH "Assets/Sounds/knife_hit.wav"
    #define SOUND_BOMB_PLACED_PATH "Assets/Sounds/c4.wav"
    #define SOUND_BOMB_DEACTIVATED_PATH "Assets/Sounds/c4_disarm.wav"
    #define SOUND_BOMB_EXPLOTED_PATH "Assets/Sounds/c4_explode.wav"
    #define SOUND_DIE_PATH "Assets/Sounds/die1.wav"

    // SPRITE CONTAINER

    #define SPRITE_AWP_PATH "Assets/Sprites/Weapons/awp.bmp"
    #define SPRITE_M3_PATH "Assets/Sprites/Weapons/m3.bmp"
    #define SPRITE_AK47_PATH "Assets/Sprites/Weapons/ak47.bmp"
    #define SPRITE_GLOCK_PATH "Assets/Sprites/Weapons/glock.bmp"
    #define SPRITE_KNIFE_PATH "Assets/Sprites/Weapons/knife.bmp"
    #define SPRITE_BOMB_PATH "Assets/Sprites/Weapons/bomb.bmp"
    #define SPRITE_NPC_KNIFE_PATH "Assets/NPC/knife.bmp"
    #define SPRITE_NPC_GLOCK_PATH "Assets/NPC/glock.bmp"
    #define SPRITE_NPC_M3_PATH "Assets/NPC/m3.bmp"
    #define SPRITE_NPC_AK47_PATH "Assets/NPC/ak47.bmp"
    #define SPRITE_NPC_AWP_PATH "Assets/NPC/awp.bmp"
    #define SPRITE_POINTER_PATH "Assets/Sprites/Weapons/pointer.bmp"

    #define SPRITE_NPC_PHEONIX_PATH "Assets/NPC/pheonix.bmp"
    #define SPRITE_NPC_L337_KREW_PATH "Assets/NPC/l337_krew.bmp"
    #define SPRITE_NPC_ARTIC_AVENGER_PATH "Assets/NPC/artic_avenger.bmp"
    #define SPRITE_NPC_GUERRILLA_PATH "Assets/NPC/guerrilla.bmp"
    #define SPRITE_NPC_SEAL_FORCE_PATH "Assets/NPC/seal_force.bmp"
    #define SPRITE_NPC_GERMAN_GSG9_PATH "Assets/NPC/german_gsg9.bmp"
    #define SPRITE_NPC_UKSAS_PATH "Assets/NPC/uksas.bmp"
    #define SPRITE_NPC_FRENCH_GIGN_PATH "Assets/NPC/french_gign.bmp"


    // TILE CONTAINER
    #define TILE_AZTEC_PATH "Assets/Tiles/aztec.png"
    #define TILE_INFERNO_PATH "Assets/Tiles/inferno.png"
    #define TILE_DUST_PATH "Assets/Tiles/dust.png"
    #define TILE_BOMB_A_PATH "Assets/Tiles/bomb_area_a.png"
    #define TILE_BOMB_B_PATH "Assets/Tiles/bomb_area_b.png"
    #define TILE_BOMB_C_PATH "Assets/Tiles/bomb_area_c.png"
    #define TILE_BOX_BLACK_PATH "Assets/Tiles/box_black.png"
    #define TILE_BOX_BROWN_PATH "Assets/Tiles/box_brown.png"
    #define TILE_BOX_METAL_PATH "Assets/Tiles/box_metal.png"
    #define TILE_BOX_WOOD_METAL_PATH "Assets/Tiles/box_wood_metal.png"
    #define TILE_BOX_WOOD_PATH "Assets/Tiles/box_wood.png"

    /****************************SERVER***************************************/

    // MAP PARSER
    #define MAPS_PATH "configs/"

    // CONFIGURATION
    #define SERVER_CONFIGS_PATH "Configuration.yaml"

#else

    // CLIENT_CONFIGURATION
    #define CLIENT_CONFIGURATION_PATH "../Client/src/ClientConfiguration/ClientConfiguration.yaml"

    // WINDOW
    #define WINDOW_ICON_PATH "../Client/Assets/Window/gametitle.png"

    // ATTACK_EFFECT
    #define ATTACK_BLOOD_PATH "../Client/Assets/Attacks/blood.bmp"
    #define ATTACK_ARROW_PATH "../Client/Assets/Attacks/arrow.bmp"

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
    #define BUY_WINDOW_PATH "../Client/Assets/InitialPhase/buyWindow.png"
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
    #define SPRITE_NPC_KNIFE_PATH "../Client/Assets/NPC/knife.bmp"
    #define SPRITE_NPC_GLOCK_PATH "../Client/Assets/NPC/glock.bmp"
    #define SPRITE_NPC_M3_PATH "../Client/Assets/NPC/m3.bmp"
    #define SPRITE_NPC_AK47_PATH "../Client/Assets/NPC/ak47.bmp"
    #define SPRITE_NPC_AWP_PATH "../Client/Assets/NPC/awp.bmp"
    #define SPRITE_POINTER_PATH "../Client/Assets/Sprites/Weapons/pointer.bmp"

    #define SPRITE_NPC_PHEONIX_PATH "../Client/Assets/NPC/pheonix.bmp"
    #define SPRITE_NPC_L337_KREW_PATH "../Client/Assets/NPC/l337_krew.bmp"
    #define SPRITE_NPC_ARTIC_AVENGER_PATH "../Client/Assets/NPC/artic_avenger.bmp"
    #define SPRITE_NPC_GUERRILLA_PATH "../Client/Assets/NPC/guerrilla.bmp"
    #define SPRITE_NPC_SEAL_FORCE_PATH "../Client/Assets/NPC/seal_force.bmp"
    #define SPRITE_NPC_GERMAN_GSG9_PATH "../Client/Assets/NPC/german_gsg9.bmp"
    #define SPRITE_NPC_UKSAS_PATH "../Client/Assets/NPC/uksas.bmp"
    #define SPRITE_NPC_FRENCH_GIGN_PATH "../Client/Assets/NPC/french_gign.bmp"


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

    // MAP PARSER
    #define MAPS_PATH "../Editor/configs/"


    // CONFIGURATION
    #define SERVER_CONFIGS_PATH "../Server/src/Configuration/Configuration.yaml"

#endif
