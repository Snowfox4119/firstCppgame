#pragma once

//1. Trick the preprocessor into renaming the X11 typedefs
#define Font X11Font
#define Window X11Window

//2. Explicitly pull in X11 to consume the renamed definitions
#include <X11/Xlib.h>

//3. Clear the macro overrides so the names are fresh
#undef Font
#undef Window

//4. Include raylib cleanly
#include "raylib.h" // IWYU pragma: export