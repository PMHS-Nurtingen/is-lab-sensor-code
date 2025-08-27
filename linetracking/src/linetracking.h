//
// Created by Dennis Burgermeister on 04.04.24.
//

#ifndef PMHS_BOT_01_LINETRACKING_H
#define PMHS_BOT_01_LINETRACKING_H

#include <Arduino.h>

class LineTracking {
private:
    const unsigned char m_leftPin;
    const unsigned char m_centerPin;
    const unsigned char m_rightPin;

public:
    LineTracking(unsigned char leftPin, unsigned char centerPin, unsigned char rightPin);
    ~LineTracking();
    bool all() const;
    bool any() const;
    bool left() const;
    bool center() const;
    bool right() const;
};

#endif //PMHS_BOT_01_LINETRACKING_H
