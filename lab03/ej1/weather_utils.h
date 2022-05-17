/*
  @file weather_utils.h
  @brief defines weather utils methods. These methods operates over multidimensional (year, month, day) array of weather
*/
#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include "array_helpers.h"

int minHistoricTemp(WeatherTable a);
void annualMaxTemp(WeatherTable a, int output[YEARS]);
void monthWithMorePrec(WeatherTable a, month_t output[YEARS]);

#endif