//
// Created by Ilia.Motornyi on 15/11/2019.
//
#include "ledcontrol.hpp"

[[noreturn]]void cppMain() {

  Light led = Light::RED;
  led.lit();
  for(Light led = Light::N;true; led >>=1) {
    led.lit();
    sleepTime(50000us);
  }
}
