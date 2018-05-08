//
// Created by thekatze on 1/05/18.
//

#ifndef SDLOGL_LOCALIZER_H
#define SDLOGL_LOCALIZER_H


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

    Music getMusic(std::string);

};


#endif //SDLOGL_LOCALIZER_H
