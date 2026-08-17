#include "global.h"
#include "event_data.h"
#include "overworld.h"
#include "random.h"
#include "weather_climate.h"
#include "constants/map_types.h"
#include "constants/region_map_sections.h"
#include "constants/vars.h"
#include "constants/weather.h"

// Odds out of 100 for each day's pattern. Must sum to 100.
static const u8 sDailyPatternWeights[NUM_WEATHER_PATTERNS] =
{
    [WEATHER_PATTERN_CLEAR]     = 30,
    [WEATHER_PATTERN_FAIR]      = 20,
    [WEATHER_PATTERN_OVERCAST]  = 20,
    [WEATHER_PATTERN_RAINY]    = 15,
    [WEATHER_PATTERN_DRIZZLY]   = 10,
    [WEATHER_PATTERN_STORMY]    = 5,
};

// How each climate interprets the day's pattern. This table is where all
// regional logic lives -- Kanto is drier and warmer than Johto, the coast
// is rainy, mountains have snow instead of rain.
static const u8 sClimateWeather[NUM_CLIMATES][NUM_WEATHER_PATTERNS] =
{
    // CLIMATE_NONE omitted: zero-filled to WEATHER_NONE, also guarded anyways.
    [CLIMATE_JOHTO_INLAND_WARM] = {
        [WEATHER_PATTERN_CLEAR]     = WEATHER_SUNNY,
        [WEATHER_PATTERN_FAIR]      = WEATHER_SUNNY,
        [WEATHER_PATTERN_OVERCAST]  = WEATHER_SUNNY_CLOUDS,
        [WEATHER_PATTERN_RAINY]     = WEATHER_RAIN,
        [WEATHER_PATTERN_DRIZZLY]   = WEATHER_RAIN,
        [WEATHER_PATTERN_STORMY]    = WEATHER_RAIN_THUNDERSTORM,
    },
    [CLIMATE_JOHTO_INLAND_COLD] = {
        [WEATHER_PATTERN_CLEAR]     = WEATHER_SUNNY,
        [WEATHER_PATTERN_FAIR]      = WEATHER_SHADE,
        [WEATHER_PATTERN_OVERCAST]  = WEATHER_RAIN,
        [WEATHER_PATTERN_RAINY]     = WEATHER_DOWNPOUR,
        [WEATHER_PATTERN_DRIZZLY]   = WEATHER_RAIN,
        [WEATHER_PATTERN_STORMY]    = WEATHER_RAIN_THUNDERSTORM,
    },
    [CLIMATE_JOHTO_COAST_WARM] = {
        [WEATHER_PATTERN_CLEAR]     = WEATHER_SUNNY,
        [WEATHER_PATTERN_FAIR]      = WEATHER_SUNNY,
        [WEATHER_PATTERN_OVERCAST]  = WEATHER_SUNNY_CLOUDS,
        [WEATHER_PATTERN_RAINY]     = WEATHER_RAIN,
        [WEATHER_PATTERN_DRIZZLY]   = WEATHER_RAIN,
        [WEATHER_PATTERN_STORMY]    = WEATHER_RAIN_THUNDERSTORM,
    },
    [CLIMATE_JOHTO_COAST_COLD] = {
        [WEATHER_PATTERN_CLEAR]     = WEATHER_SUNNY,
        [WEATHER_PATTERN_FAIR]      = WEATHER_SUNNY_CLOUDS,
        [WEATHER_PATTERN_OVERCAST]  = WEATHER_RAIN,
        [WEATHER_PATTERN_RAINY]     = WEATHER_DOWNPOUR,
        [WEATHER_PATTERN_DRIZZLY]   = WEATHER_RAIN,
        [WEATHER_PATTERN_STORMY]    = WEATHER_RAIN_THUNDERSTORM,
    },
    [CLIMATE_KANTO_INLAND] = {
        [WEATHER_PATTERN_CLEAR]     = WEATHER_SUNNY,
        [WEATHER_PATTERN_FAIR]      = WEATHER_SUNNY,
        [WEATHER_PATTERN_OVERCAST]  = WEATHER_SUNNY_CLOUDS,
        [WEATHER_PATTERN_RAINY]     = WEATHER_RAIN,
        [WEATHER_PATTERN_DRIZZLY]   = WEATHER_SHADE,
        [WEATHER_PATTERN_STORMY]    = WEATHER_RAIN_THUNDERSTORM,
    },
    [CLIMATE_KANTO_COAST] = {
        [WEATHER_PATTERN_CLEAR]     = WEATHER_SUNNY,
        [WEATHER_PATTERN_FAIR]      = WEATHER_SUNNY_CLOUDS,
        [WEATHER_PATTERN_OVERCAST]  = WEATHER_SHADE,
        [WEATHER_PATTERN_RAINY]     = WEATHER_RAIN,
        [WEATHER_PATTERN_DRIZZLY]   = WEATHER_SHADE,
        [WEATHER_PATTERN_STORMY]    = WEATHER_DOWNPOUR,
    },
    [CLIMATE_MOUNTAIN] = {
        [WEATHER_PATTERN_CLEAR]     = WEATHER_SUNNY,
        [WEATHER_PATTERN_FAIR]      = WEATHER_SUNNY_CLOUDS,
        [WEATHER_PATTERN_OVERCAST]  = WEATHER_SHADE,
        [WEATHER_PATTERN_RAINY]     = WEATHER_SNOW,
        [WEATHER_PATTERN_DRIZZLY]   = WEATHER_RAIN,
        [WEATHER_PATTERN_STORMY]    = WEATHER_SNOW,
    },
    [CLIMATE_FOREST] = {
        [WEATHER_PATTERN_CLEAR]     = WEATHER_SUNNY_CLOUDS,
        [WEATHER_PATTERN_FAIR]      = WEATHER_SHADE,
        [WEATHER_PATTERN_OVERCAST]  = WEATHER_FOG_HORIZONTAL,
        [WEATHER_PATTERN_RAINY]     = WEATHER_RAIN,
        [WEATHER_PATTERN_DRIZZLY]   = WEATHER_SHADE,
        [WEATHER_PATTERN_STORMY]    = WEATHER_DOWNPOUR,
    },
};

static const u8 sMapSecClimates[MAPSEC_SAFARI_ZONE_AREA6 + 1] =
{
    // Johto 
    [MAPSEC_NEW_BARK_TOWN]      = CLIMATE_JOHTO_INLAND_WARM,
    [MAPSEC_CHERRYGROVE_CITY]   = CLIMATE_JOHTO_COAST_WARM,
    [MAPSEC_VIOLET_CITY]        = CLIMATE_JOHTO_INLAND_WARM,
    [MAPSEC_AZALEA_TOWN]        = CLIMATE_JOHTO_INLAND_WARM,
    [MAPSEC_GOLDENROD_CITY]     = CLIMATE_JOHTO_COAST_WARM,
    [MAPSEC_ECRUTEAK_CITY]      = CLIMATE_JOHTO_INLAND_WARM,
    [MAPSEC_OLIVINE_CITY]       = CLIMATE_JOHTO_COAST_WARM,
    [MAPSEC_CIANWOOD_CITY]      = CLIMATE_JOHTO_COAST_COLD,
    [MAPSEC_MAHOGANY_TOWN]      = CLIMATE_MOUNTAIN,
    [MAPSEC_LAKE_OF_RAGE]       = CLIMATE_JOHTO_INLAND_COLD,
    [MAPSEC_BLACKTHORN_CITY]    = CLIMATE_MOUNTAIN,
    [MAPSEC_MT_SILVER]          = CLIMATE_MOUNTAIN,

    [MAPSEC_ROUTE_29]           = CLIMATE_JOHTO_INLAND_WARM,
    [MAPSEC_ROUTE_30]           = CLIMATE_JOHTO_COAST_WARM,
    [MAPSEC_ROUTE_31]           = CLIMATE_JOHTO_INLAND_WARM,
    [MAPSEC_ROUTE_32]           = CLIMATE_JOHTO_INLAND_WARM,
    [MAPSEC_ROUTE_33]           = CLIMATE_JOHTO_INLAND_WARM,
    [MAPSEC_ROUTE_34]           = CLIMATE_JOHTO_COAST_WARM,
    [MAPSEC_ROUTE_35]           = CLIMATE_JOHTO_COAST_WARM,
    [MAPSEC_ROUTE_36]           = CLIMATE_FOREST,
    [MAPSEC_ROUTE_37]           = CLIMATE_FOREST,
    [MAPSEC_ROUTE_38]           = CLIMATE_JOHTO_INLAND_WARM,
    [MAPSEC_ROUTE_39]           = CLIMATE_JOHTO_COAST_WARM,
    [MAPSEC_ROUTE_40]           = CLIMATE_JOHTO_COAST_WARM,
    [MAPSEC_ROUTE_41]           = CLIMATE_JOHTO_COAST_COLD,
    [MAPSEC_ROUTE_42]           = CLIMATE_JOHTO_INLAND_COLD,
    [MAPSEC_ROUTE_43]           = CLIMATE_JOHTO_INLAND_COLD,
    [MAPSEC_ROUTE_44]           = CLIMATE_MOUNTAIN,
    [MAPSEC_ROUTE_45]           = CLIMATE_MOUNTAIN,
    [MAPSEC_ROUTE_46]           = CLIMATE_JOHTO_INLAND_COLD,
    [MAPSEC_ROUTE_47]           = CLIMATE_JOHTO_COAST_COLD,
    [MAPSEC_ROUTE_48]           = CLIMATE_JOHTO_COAST_COLD,
    [MAPSEC_NATIONAL_PARK]      = CLIMATE_FOREST,

    // Kanto
    [MAPSEC_PALLET_TOWN]        = CLIMATE_KANTO_COAST,
    [MAPSEC_VIRIDIAN_CITY]      = CLIMATE_KANTO_INLAND,
    [MAPSEC_PEWTER_CITY]        = CLIMATE_KANTO_INLAND,
    [MAPSEC_CERULEAN_CITY]      = CLIMATE_KANTO_INLAND,
    [MAPSEC_VERMILION_CITY]     = CLIMATE_KANTO_COAST,
    [MAPSEC_LAVENDER_TOWN]      = CLIMATE_KANTO_INLAND,
    [MAPSEC_CELADON_CITY]       = CLIMATE_KANTO_INLAND,
    [MAPSEC_SAFFRON_CITY]       = CLIMATE_KANTO_INLAND,
    [MAPSEC_FUCHSIA_CITY]       = CLIMATE_KANTO_COAST,
    [MAPSEC_CINNABAR_ISLAND]    = CLIMATE_KANTO_COAST,
    
    [MAPSEC_ROUTE_1]            = CLIMATE_KANTO_COAST,
    [MAPSEC_ROUTE_2]            = CLIMATE_KANTO_INLAND,
    [MAPSEC_ROUTE_3]            = CLIMATE_KANTO_INLAND,
    [MAPSEC_ROUTE_4]            = CLIMATE_KANTO_INLAND,
    [MAPSEC_ROUTE_5]            = CLIMATE_KANTO_INLAND,
    [MAPSEC_ROUTE_6]            = CLIMATE_KANTO_INLAND,
    [MAPSEC_ROUTE_7]            = CLIMATE_KANTO_INLAND,
    [MAPSEC_ROUTE_8]            = CLIMATE_KANTO_INLAND,
    [MAPSEC_ROUTE_9]            = CLIMATE_KANTO_INLAND,
    [MAPSEC_ROUTE_10]           = CLIMATE_KANTO_INLAND,
    [MAPSEC_ROUTE_11]           = CLIMATE_KANTO_INLAND,
    [MAPSEC_ROUTE_12]           = CLIMATE_KANTO_COAST,
    [MAPSEC_ROUTE_13]           = CLIMATE_KANTO_COAST,
    [MAPSEC_ROUTE_14]           = CLIMATE_KANTO_COAST,
    [MAPSEC_ROUTE_15]           = CLIMATE_KANTO_COAST,
    [MAPSEC_ROUTE_16]           = CLIMATE_KANTO_INLAND,
    [MAPSEC_ROUTE_17]           = CLIMATE_KANTO_COAST,
    [MAPSEC_ROUTE_18]           = CLIMATE_KANTO_COAST,
    [MAPSEC_ROUTE_19]           = CLIMATE_KANTO_COAST,
    [MAPSEC_ROUTE_20]           = CLIMATE_KANTO_COAST,
    [MAPSEC_ROUTE_21]           = CLIMATE_KANTO_COAST,
    [MAPSEC_ROUTE_22]           = CLIMATE_KANTO_INLAND,
    [MAPSEC_ROUTE_23]           = CLIMATE_MOUNTAIN,
    [MAPSEC_ROUTE_24]           = CLIMATE_KANTO_INLAND,
    [MAPSEC_ROUTE_25]           = CLIMATE_KANTO_COAST,
    [MAPSEC_ROUTE_26]           = CLIMATE_KANTO_INLAND,
    [MAPSEC_ROUTE_27]           = CLIMATE_KANTO_INLAND,
    [MAPSEC_ROUTE_28]           = CLIMATE_MOUNTAIN,
};

u8 GetRegionalWeather(u8 mapSecId, u8 mapType)
{
    u8 climate, pattern;

    // Indoor, cave and underwater maps never get outdoor weather.
    if (!MapHasNaturalLight(mapType))
        return WEATHER_NONE;
    if (mapSecId >= ARRAY_COUNT(sMapSecClimates))
        return WEATHER_NONE;

    climate = sMapSecClimates[mapSecId];
    if (climate == CLIMATE_NONE)
        return WEATHER_NONE;

    pattern = VarGet(VAR_WEATHER_PATTERN);
    if (pattern >= NUM_WEATHER_PATTERNS)
        pattern = WEATHER_PATTERN_CLEAR;

    return sClimateWeather[climate][pattern];
}

void RollDailyWeatherPattern(void)
{
    u32 roll = Random() % 100;
    u32 i;

    for (i = 0; i < NUM_WEATHER_PATTERNS; i++)
    {
        if (roll < sDailyPatternWeights[i])
        {
            VarSet(VAR_WEATHER_PATTERN, i);
            return;
        }
        roll -= sDailyPatternWeights[i];
    }

    VarSet(VAR_WEATHER_PATTERN, WEATHER_PATTERN_CLEAR);
}