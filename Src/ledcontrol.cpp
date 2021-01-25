#include <climits>
//
// Created by Ilia.Motornyi on 12/11/2019.
//

#include "ledcontrol.hpp"
#include "main.h"

enum bits {
    BIT_N = 1u,
    BIT_NE = 2u,
    BIT_E = 4u,
    BIT_SE = 8u,
    BIT_S = 16u,
    BIT_SW = 32u,
    BIT_W = 64u,
    BIT_NW = 128u,
    BIT_BLUE = BIT_NW | BIT_SE,
    BIT_RED = BIT_N | BIT_S,
    BIT_ORANGE = BIT_NE | BIT_SW,
    BIT_GREEN = BIT_W | BIT_E,
};

const Light &Light::N = Light(BIT_N);
const Light __unused &Light::NE = Light(BIT_NE);
const Light __unused &Light::E = Light(BIT_E);
const Light __unused &Light::SE = Light(BIT_SE);
const Light __unused &Light::S = Light(BIT_S);
const Light __unused &Light::SW = Light(BIT_SW);
const Light __unused &Light::W = Light(BIT_W);
const Light __unused &Light::NW = Light(BIT_NW);
const Light __unused &Light::BLUE = Light(BIT_BLUE);
const Light __unused &Light::RED = Light(BIT_RED);
const Light __unused &Light::ORANGE = Light(BIT_ORANGE);
const Light __unused &Light::GREEN = Light(BIT_GREEN);
const Light __unused &Light::BLACK = Light(0);

const Light &Light::lit() const {
    HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, (ledBits & BIT_N) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LD7_GPIO_Port, LD7_Pin, (ledBits & BIT_E) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LD10_GPIO_Port, LD10_Pin, (ledBits & BIT_S) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LD6_GPIO_Port, LD6_Pin, (ledBits & BIT_W) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LD5_GPIO_Port, LD5_Pin, (ledBits & BIT_NE) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LD9_GPIO_Port, LD9_Pin, (ledBits & BIT_SE) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LD8_GPIO_Port, LD8_Pin, (ledBits & BIT_SW) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LD4_GPIO_Port, LD4_Pin, (ledBits & BIT_NW) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    return *this;
}

Light operator-(const Light &light) {
    return Light(~light.ledBits);
}

Light operator+(const Light &lightA, const Light &lightB) {
  return Light(lightA.ledBits | lightB.ledBits);
}

Light operator-(const Light &lightA, const Light &lightB) {
  return Light(lightA.ledBits & ~lightB.ledBits);
}

Light Light::operator-() {
  return Light(~ledBits);
}

Light &Light::operator+=(const Light &light) {
    this->ledBits |= light.ledBits;
    return *this;
}

Light &Light::operator-=(const Light &light) {
    this->ledBits &= ~light.ledBits;
    return *this;
}

bool Light::operator||(const Light &light) {
    return (bool) (ledBits | light.ledBits);
}

bool Light::operator&&(const Light &light) {
    return (bool) (ledBits & light.ledBits);
}

bool Light::operator==(const Light &light) {
    return (bool) (ledBits == light.ledBits);
}

Light Light::operator<<(unsigned int b) {
    return Light((ledBits >> b) | (ledBits << (8u - b)));
}

Light Light::operator>>(unsigned int b) {
    return Light((ledBits << b) | (ledBits >> (8u - b)));
}

Light Light::operator<<=(unsigned int b) {
    this->ledBits = (ledBits >> b) | (ledBits << (8u - b));
    return *this;
}

Light Light::operator>>=(unsigned int b) {
    this->ledBits = (ledBits << b) | (ledBits >> (8u - b));
    return *this;
}


