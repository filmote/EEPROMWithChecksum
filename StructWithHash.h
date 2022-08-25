#pragma once

#include <Arduboy2.h>

class StructWithHash {

    private:
        uint16_t hash = 0;

    public:
        void reset() {}


    template <typename T> T &get(int idx, T &t) {

        EEPROM.get(idx, t);


        // Calculate hash ..

        uint16_t calcHash = 0;

        for (int i = 2; i < sizeof(T); i++) {
            calcHash = calcHash + EEPROM.read(idx + i);
        }


        // If hashes differ then reset and rewrite ..

        if (this->hash != calcHash) {
            (static_cast<StructWithHash>(t)).reset();
            this->put(idx, t);
        }

        return t;

    }

    template <typename T> const T &put(int idx, const T &t) {

        uint16_t calcHash = 0;
        EEPROM.put(idx, t);

        for (int i = 2; i < sizeof(T); i++) {
            calcHash = calcHash + EEPROM.read(idx + i);
        }

        this->hash = calcHash;
        EEPROM.put(idx, this->hash);

        return t;
        
    }

};
