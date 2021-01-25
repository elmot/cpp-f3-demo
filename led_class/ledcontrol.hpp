//
// Created by Ilia.Motornyi on 12/11/2019.
//

#ifndef CLION_F3_CPP_MEETING_LEDCONTROL_HPP
#define CLION_F3_CPP_MEETING_LEDCONTROL_HPP

#include <chrono>
using namespace std::literals::chrono_literals;

extern "C" [[noreturn]]  void cppMain();
extern "C" void HAL_Delay(uint32_t ms);

class Light {
public:
    Light operator-();

    Light operator>>(unsigned b);

    Light operator<<(unsigned  b);

    Light operator>>=(unsigned b);

    Light operator<<=(unsigned  b);

    friend Light operator-(const Light &light);

    friend Light operator+(const Light &lightA, const Light &lightB);

    Light &operator+=(const Light &light);

    Light &operator-=(const Light &light);

    friend Light operator-(const Light &lightA, const Light &lightB);

    bool operator||(const Light &light);

    bool operator&&(const Light &light);

    bool operator==(const Light &light);

    Light(const Light &light) {
        ledBits = light.ledBits;
    }

    const Light &lit() const;

    static const Light &N;
    static const Light &NE;
    static const Light &E;
    static const Light &SE;
    static const Light &S;
    static const Light &SW;
    static const Light &W;
    static const Light &NW;
    static const Light &BLUE;
    static const Light &RED;
    static const Light &ORANGE;
    static const Light &GREEN;
    static const Light &BLACK;

    Light() : Light(0) {}

private:
    explicit Light(unsigned char bits) noexcept {
        ledBits = bits;
    };
    unsigned char ledBits = 0;
};

inline void sleepTime(const std::chrono::duration<double, std::ratio<1,1000>> &t){
  HAL_Delay(t.count());
}

#endif //CLION_F3_CPP_MEETING_LEDCONTROL_HPP
