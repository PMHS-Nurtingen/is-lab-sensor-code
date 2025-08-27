#include "linetracking.h"

LineTracking::LineTracking(unsigned char leftPin, unsigned char centerPin, unsigned char rightPin)
        : m_leftPin{leftPin}, m_centerPin{centerPin}, m_rightPin{rightPin} {
    pinMode(leftPin, INPUT);
}

LineTracking::~LineTracking() = default;

bool LineTracking::all() const {
    return left() && center() && right();
}

bool LineTracking::any() const {
    return left() || center() || right();
}

bool LineTracking::left() const {
    return !digitalRead(m_leftPin);
}

bool LineTracking::center() const {
    return !digitalRead(m_centerPin);
}

bool LineTracking::right() const {
    return !digitalRead(m_rightPin);
}
