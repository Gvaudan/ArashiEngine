//
// Created by David on 04/05/2018.
//

#ifndef ARASHIENGINE_DEFS_H
#define ARASHIENGINE_DEFS_H

#include <SFML/Audio.hpp>
#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Main.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <Thor/Animations.hpp>
#include <Thor/Config.hpp>
#include <Thor/Graphics.hpp>
#include <Thor/Input.hpp>
#include <Thor/Math.hpp>
#include <Thor/Particles.hpp>
#include <Thor/Resources.hpp>

#include <boost/log/trivial.hpp>

#define VERSION 01

#define PATH_ROOT
#define CONFIG_FILE "config.json"
#define PATH_RESSOURCES "ressources/"
#define FOLDER_TEXTURE "ressources/graphics/"
#define FOLDER_FONTS "ressources/font/"
#define FOLDER_ENTITIES "ressources/entities/"
#define FOLDER_STAGES "ressources/stages/"

#define BASE_WINDOW_WIDTH 640
#define BASE_WINDOW_HEIGHT 480
#define WINDOW_NAME "ArashiEngine"

#endif //ARASHIENGINE_DEFS_H
