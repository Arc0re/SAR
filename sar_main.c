//------------------------------------------------------------------------------
// SAR (Simple Ascii Renderer) library
// deps: SDL2, SDL2_image
// Arc0re -- https://github.com/Arc0re/SAR/ -- 2016
//------------------------------------------------------------------------------

#include "sar.h"

//------------------------------------------------------------------------------

struct tile
{
    SDL_Texture * texture;
    SDL_Rect src; // part of the texture
    SDL_Rect dest; // rendering target, can do scaling
    int w;
    int h;
};

struct char_data
{
    int x;
    int y;  
};

//------------------------------------------------------------------------------

static SDL_Window * window = NULL;
static SDL_Renderer * renderer = NULL;
static int tile_width;
static int tile_height;
static struct tile char_tile;

//------------------------------------------------------------------------------

static struct char_data sar_get_ascii_c(char c)
{
    struct char_data chr;
    chr.x = c % 16; chr.x = chr.x * tile_width;
    chr.y = c / 16; chr.y = chr.y * tile_height;
    return chr;
}

static struct char_data sar_get_ascii_char(enum ascii_characters c)
{
    struct char_data chr;
    chr.x = c % 16; chr.x = chr.x * tile_width;
    chr.y = c / 16; chr.y = chr.y * tile_height;
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

void sar_get_events(sar_event * ev)
{
    SDL_PollEvent(ev);
}

//------------------------------------------------------------------------------

void sar_begin_rendering(void)
{
    SDL_RenderClear(renderer);
    
    // Set screen to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}

//------------------------------------------------------------------------------

void sar_end_rendering(void)
{
    SDL_RenderPresent(renderer);
}

//------------------------------------------------------------------------------

void sar_render_tile_c(char c, int x, int y, SDL_Color bg_color, SDL_Color tile_color)
{
    struct char_data chars;
    
    if (char_tile.texture == NULL)
    {
        puts("You must load the texture png BEFORE trying to render anything.");
        exit(-1);
    }
    
    SDL_QueryTexture(char_tile.texture, NULL, NULL, &char_tile.w, &char_tile.h);
    tile_width = char_tile.w / 16;
    tile_height = char_tile.h / 16;
    
    // Position of the block tile
    SDL_Rect bg =
    {
        tile_width * 11,
        tile_height * 13,
        tile_width,
        tile_height
    };
    
    chars = sar_get_ascii_c(c);
    
    // Which part of the texture is gonna be rendered
    char_tile.src.x = chars.x;
    char_tile.src.y = chars.y;
    char_tile.src.w = tile_width;
    char_tile.src.h = tile_height;

    // Where its gonna be rendered
    char_tile.dest.x = x;
    char_tile.dest.y = y;
    char_tile.dest.w = tile_width;
    char_tile.dest.h = tile_height;
    
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

void sar_render_tile_char(enum ascii_characters c, int x, int y, SDL_Color bg_color, SDL_Color tile_color)
{
        struct char_data chars;
    
    if (char_tile.texture == NULL)
    {
        puts("You must load the texture png BEFORE trying to render anything.");
        exit(-1);
    }
    
    SDL_QueryTexture(char_tile.texture, NULL, NULL, &char_tile.w, &char_tile.h);
    tile_width = char_tile.w / 16;
    tile_height = char_tile.h / 16;
    
    // Position of the block tile
    SDL_Rect bg =
    {
        tile_width * 11,
        tile_height * 13,
        tile_width,
        tile_height
    };
    
    chars = sar_get_ascii_char(c);
    
    // Which part of the texture is gonna be rendered
    char_tile.src.x = chars.x;
    char_tile.src.y = chars.y;
    char_tile.src.w = tile_width;
    char_tile.src.h = tile_height;

    // Where its gonna be rendered
    char_tile.dest.x = x;
    char_tile.dest.y = y;
    char_tile.dest.w = tile_width;
    char_tile.dest.h = tile_height;
    
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

void sar_render_string(const char * str, int x, int y, SDL_Color bg_color, SDL_Color tile_color)
{
    int len = strlen(str);
    
    for (int i = 0; i < len; i++)
    {
        sar_render_tile_c(str[i], x + tile_width * i, y, bg_color, tile_color);
    }
}

