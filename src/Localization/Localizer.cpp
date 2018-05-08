//
// Created by thekatze on 1/05/18.
//

#include "Localizer.h"

Localizer::Localizer(LanguageCode language) : currentLanguage(language) {
    //TODO: Open language file, create map...
}

Localizer::~Localizer() {

}

std::string Localizer::getText(std::string identifier) {
    return std::__cxx11::string();
}

Sound Localizer::getSound(std::string identifier) {
    return Sound();
}

Music Localizer::getMusic(std::string) {
    return Music();
}
