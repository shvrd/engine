//
// Created by thekatze on 1/05/18.
//

#ifndef SHVRDENGINE_SRC_LOCALIZER_H
#define SHVRDENGINE_SRC_LOCALIZER_H


#include <string>
#include "LanguageCodes.h"
#include "../Audio/Sound.h"
#include "../Audio/Music.h"

class Localizer {
    LanguageCode currentLanguage = LanguageCode::EN;

public:
    explicit Localizer(LanguageCode language);

    ~Localizer();

    std::string getText(std::string identifier);

    Sound getSound(std::string identifier);

    Music getMusic(std::string identifier);
};

#endif //SHVRDENGINE_SRC_LOCALIZER_H
