#ifndef GUARD_WEATHER_CLIMATE_H
#define GUARD_WEATHER_CLIMATE_H

u8 GetRegionalWeather(u8 mapSecId, u8 mapType);
void RollDailyWeatherPattern(void);
void NoteResolvedWeather(u8 weather);
void TryUpdateDynamicWeather(void);

#endif // GUARD_WEATHER_CLIMATE_H