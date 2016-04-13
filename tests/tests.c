#include "../sar_main.h"

int main(int argc, char * argv[])
{
    sar_event event;
    sar_color white = { 255, 255, 255 };
    sar_color black = { 0, 0, 0 };
    sar_color blue = { 0, 0, 255 };
    sar_color green = { 0, 255, 0 };
    sar_color red = { 255, 0, 0 };
    
    sar_init("test window", 800, 600);
    
    sar_load_texture("curses_640x300ALPHA.png");
    
    while (1)
    {
        sar_get_events(&event);
        
        if (event.type == SDL_QUIT)
            break;
        
        sar_begin_rendering();
        sar_render_string("It works", 100, 200, white, green);
        sar_render_tile_c('!', 0, 10, red, blue);
        sar_render_tile_char(char_infinity, 0, 20, green, white);
        sar_end_rendering();
    }
    
    sar_close();
    return 0;
}