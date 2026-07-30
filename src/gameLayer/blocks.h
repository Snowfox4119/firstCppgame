#pragma once
#include <X11/Xdefs.h>
#include <cstdint>

struct Block
{
    enum
    {
        air = 0,
        dirt,
        grassBlock,
        stone,
        grass,
        sand,
        sandRuby,
        sandStone,
        woodPlank,
        stoneBricks,
        clay,
        woodLog,
        leaves,
        copper,
        iron,
        gold,
        copperBlock,
        ironBlock,
        goldBlock,
        bricks,
        snow,
        ice,
        rubyBlock,
        platform,
        workBench,
        glass,
        furnace,
        painting,
        sappling,
        snowBlueRuby,
        blueRubyBlock,
        door,
        jar,
        table,
        wordrobe,
        bookShelf,
        snowBricks,
        iceTable,
        iceWordrobe,
        iceBookshelf,
        icePlatform,
        sandTable,
        sandWordrobe,
        sandBookShelf,
        sandPlatform,
        woodenChest,
        iceChest,
        sandChest,
        boneChest,
        boneBrick,
        boneBench,
        boneWordrobe,
        boneBookShelf,
        bonePlatform,

        BLOCKS_COUNT,

    };

    std::uint16_t type = 0;
};