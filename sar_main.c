/*
  Simple Ascii Renderer
  Copyright (C) 2016 Thomas Guyot <thomasguyot@outlook.com>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "sar.h"

//------------------------------------------------------------------------------

typedef struct tile
{
    SDL_Texture * texture;
    SDL_Rect src; // part of the texture
    SDL_Rect dest; // rendering target, can do scaling
    int w;
    int h;
} tile;

typedef struct char_data
{
    int x;
    int y;  
} char_data;

//------------------------------------------------------------------------------

static SDL_Window * window = NULL;
static SDL_Renderer * renderer = NULL;
static struct tile char_tile;

// Globals
int SAR_TILE_WIDTH = 0;
int SAR_TILE_HEIGHT = 0;

//------------------------------------------------------------------------------

static char_data sar_get_ascii(long c)
{
    char_data chr;
    chr.x = c % 16; chr.x = chr.x * SAR_TILE_WIDTH;
    chr.y = c / 16; chr.y = chr.y * SAR_TILE_HEIGHT;
    return chr;
}

//------------------------------------------------------------------------------

bool sar_init(const char * caption, int w, int h)
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    
    window = SDL_CreateWindow(caption,
                            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                            w, h, SDL_WINDOW_SHOWN);
    
    if (window == NULL)
    {
        printf("Failed to create SDL window: %s\n", SDL_GetError());
        return false;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    if (renderer == NULL)
    {
        printf("Failed to create SDL renderer: %s\n", SDL_GetError());
        return false;
    }
    
    puts("Successfully initialized SAR.");
    return true;
}

//------------------------------------------------------------------------------

void sar_close(void)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    puts("Successfully closed SAR.");
}

//------------------------------------------------------------------------------

bool sar_load_texture(const char * path)
{
    char_tile.texture = IMG_LoadTexture(renderer, path);
    
    if (char_tile.texture == NULL)
    {
        printf("Failed to load texture: %s\n", path);
        return false;
    }
    else
    {
        printf("Texture %s loaded.\n", path);
        return true;
    }
}

//------------------------------------------------------------------------------

int sar_get_events(sar_event * event)
{
    return SDL_PollEvent(event);
}

//------------------------------------------------------------------------------

void sar_begin_rendering(sar_color clear_color)
{
    SDL_RenderClear(renderer);
    
    SDL_SetRenderDrawColor(renderer, clear_color.r, clear_color.g, clear_color.b, clear_color.a);
}

//------------------------------------------------------------------------------

void sar_end_rendering(void)
{
    SDL_RenderPresent(renderer);
}

//------------------------------------------------------------------------------

void sar_render_tile(long c, int x, int y, sar_color bg_color, sar_color tile_color)
{
    char_data chars;
    
    if (char_tile.texture == NULL)
    {
        puts("You must load the texture png BEFORE trying to render anything.");
        exit(-1);
    }
    
    SDL_QueryTexture(char_tile.texture, NULL, NULL, &char_tile.w, &char_tile.h);
    SAR_TILE_WIDTH = char_tile.w / 16;
    SAR_TILE_HEIGHT = char_tile.h / 16;
    
    // Position of the block tile
    SDL_Rect bg =
    {
        SAR_TILE_WIDTH * 11,
        SAR_TILE_HEIGHT * 13,
        SAR_TILE_WIDTH,
        SAR_TILE_HEIGHT
    };
    
    chars = sar_get_ascii(c);
    
    // Which part of the texture is gonna be rendered
    char_tile.src.x = chars.x;
    char_tile.src.y = chars.y;
    char_tile.src.w = SAR_TILE_WIDTH;
    char_tile.src.h = SAR_TILE_HEIGHT;

    // Where its gonna be rendered
    char_tile.dest.x = x;
    char_tile.dest.y = y;
    char_tile.dest.w = SAR_TILE_WIDTH;
    char_tile.dest.h = SAR_TILE_HEIGHT;
    
    // Background tile color
    SDL_SetTextureColorMod(char_tile.texture, bg_color.r, bg_color.g,
        bg_color.b);
        
    SDL_RenderCopy(renderer, char_tile.texture, &bg, &char_tile.dest);
    
    // Character (foreground) color
    SDL_SetTextureColorMod(char_tile.texture, tile_color.r, tile_color.g,
        tile_color.b);
        
    SDL_RenderCopy(renderer, char_tile.texture, &char_tile.src,
        &char_tile.dest);
}

//------------------------------------------------------------------------------

void sar_render_string(const char * str, int x, int y, sar_color bg_color, sar_color tile_color)
{
    int len = strlen(str);
    
    for (int i = 0; i < len; i++)
    {
        sar_render_tile(str[i], x + SAR_TILE_WIDTH * i, y, bg_color, tile_color);
    }
}

