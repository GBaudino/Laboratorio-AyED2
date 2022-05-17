/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

static const int AMOUNT_OF_WEATHER_VARS = 6;

Weather weather_from_file(FILE *file)
{
    Weather weather;

    int averageTemp = 0;
    int tempHigh = 0;
    int tempLow = 0;
    unsigned int pressure = 0u;
    unsigned int moisture = 0u;
    unsigned int rainfall = 0u;


    int res = fscanf(file, "%d %d %d %u %u %u", &averageTemp, &tempHigh, &tempLow, &pressure, &moisture, &rainfall);
    if (res != AMOUNT_OF_WEATHER_VARS)
    {
        fprintf(stderr, "Invalid array.\n");
        exit(EXIT_FAILURE);
    }

    weather._average_temp = averageTemp;
    weather._max_temp = tempHigh;
    weather._min_temp = tempLow;
    weather._moisture = moisture;
    weather._pressure = pressure;
    weather._rainfall = rainfall;

    return weather;
}

void weather_to_file(FILE *file, Weather weather)
{
    fprintf(file, EXPECTED_WEATHER_FILE_FORMAT, weather._average_temp,
          weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
