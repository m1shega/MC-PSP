#pragma once

#include "Perlin.h"
#include "Chunk.h"
#include <glm/glm.hpp>
namespace Minecraft::Terrain{

    struct NoiseParameters{
        double octaves;
        double amplitude;
        double smoothness;
        double heightOffset;
        double roughness;
    };

    enum BiomeTypes {
        BIOME_DEFAULT = 0,
        BIOME_OCEAN = 1,
        BIOME_RIVER = 2,
        BIOME_FOREST = 3,
        BIOME_WOODLAND_HILLS = 4,
        BIOME_FLOWER_FOREST = 5,
        BIOME_BIRCH_FOREST = 6,
        BIOME_BIRCH_FOREST_HILLS = 7,
        BIOME_TALL_BIRCH_FOREST = 8,
        BIOME_TALL_BIRCH_FOREST_HILLS = 9,
        BIOME_DARK_FOREST_HILLS = 10,
        BIOME_JUNGLE = 11,
        BIOME_JUNGLE_HILLS = 12,
        BIOME_JUNGLE_EDGE = 13,
        BIOME_TAIGA = 14,
        BIOME_Taiga_Hills = 15,
        BIOME_Taiga_Mountains = 16,
        BIOME_Snowy_Taiga_Hills = 17,
        BIOME_Snowy_Taiga_Mountains = 18,
        BIOME_Giant_Tree_Taiga = 19,
        BIOME_Giant_Tree_Taiga_Hills = 20,
        BIOME_Giant_Spruce_Taiga = 21,
        BIOME_Giant_Spruce_Taiga_Hills = 22,
        BIOME_Mushroom_Fields = 23,
        BIOME_Mushroom_Fields_Shore = 24,
        BIOME_Swamp = 25,
        BIOME_Swamp_Hills = 26,
        BIOME_Savanna = 27,
        BIOME_Savanna_Plateau = 28,
        BIOME_Shattered_Savanna = 29,
        BIOME_Shattered_Savanna_Plateau = 30,
        BIOME_Plains = 31,
        BIOME_Sunflower_Plains = 32,
        BIOME_Desert = 33,
        BIOME_Desert_Hills = 34,
        BIOME_Desert_Lakes = 35,
        BIOME_Snowy_Tundra = 36,
        BIOME_Snow_Mountains = 37,
        BIOME_Ice_Spikes = 38,
        BIOME_Mountains = 39,
        BIOME_Wooded_Mountains = 40,
        BIOME_Gravelly_Mountains = 41,
        BIOME_Badlands = 42,
        BIOME_Badlands_Plateau = 43,
        BIOME_Eroded_Badlands = 44
    };

    struct BiomeProfile{
        BiomeTypes type;
        NoiseParameters params;

        ChunkBlock topBlock;
        ChunkBlock midBlock;

        ChunkBlock underBlock;
    };

    extern BiomeProfile defaultBiome;

    class Chunk;
    class WorldProvider{
        public:

        static void generate(Chunk* chunk);

        static int seed;
        static FastNoise* noise;
    };

    extern NoiseParameters defaultNoiseParams;

}