/*
  @file weather_utils.c
  @brief Weather Utils method implementation
*/

#include <stdlib.h>

#include "weather_utils.h"

int minHistoricTemp(WeatherTable a){
    int res = a[0][0][0]._min_temp;
    for (unsigned int i=0; i < YEARS; i++){
        for (unsigned int j=0; j < MONTHS; j++){
            for (unsigned int k=0; k < DAYS; k++){
                if (res > a[i][j][k]._min_temp){
                    res = a[i][j][k]._min_temp;
                }
            }
        }
    }
    return res;
}

void annualMaxTemp(WeatherTable a, int output[YEARS]){
    for (unsigned int i=0; i < YEARS; i++){
        output[i] = a[i][0][0]._max_temp;
        for (unsigned int j=0; j < MONTHS; j++){
            for (unsigned int k=0; k < DAYS; k++){
                if (output[i] < a[i][j][k]._max_temp){
                    output[i] = a[i][j][k]._max_temp;
                }
            }
        }
    }
}

void monthWithMorePrec(WeatherTable a, month_t output[YEARS]){
    for (unsigned int i=0; i < YEARS; i++){
        unsigned int maxPrecMensual;
        output[i] = january;
        for (month_t j = january; j <= december; j++){
            unsigned int sumPrecMensual = 0u;
            for (unsigned int k=0; k < DAYS; k++){
                sumPrecMensual += a[i][j][k]._rainfall;
            }
            if (j == january){
                maxPrecMensual = sumPrecMensual;
            } else if (maxPrecMensual < sumPrecMensual){
                maxPrecMensual = sumPrecMensual;
                output[i] = j;
            }
        }
    }
}
