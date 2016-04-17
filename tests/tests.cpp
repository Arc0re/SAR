#include "../sar.h"
#include <iostream>

int main(int argc, char * argv[])
{
    sar_event event;
    sar_color white = { 255, 255, 255 };
    sar_color black = { 0, 0, 0 };
    sar_color blue = { 0, 0, 255 };
    sar_color green = { 0, 255, 0 };
    sar_color red = { 255, 0, 0 };
    
    sar_init("test window", 800, 600, false);
    
    sar_load_texture("curses_640x300ALPHA.png");
    
    long g = 128;
    while (1)
    {
        sar_get_events(&event);
        
        if (event.type == SDL_QUIT)
            break;
        
        sar_begin_rendering(blue);

        for (int i=99;i<255;i++)
        {
            sar_render_tile(i, (i-98)*SAR_TILE_WIDTH, 0, white, green);
        }

        sar_render_tile(128, 40, 20, blue, red);
        sar_render_str("Hellooooo 03483", 200, 100, black, white);
        sar_render_tile(g, 215, 200, black, white);
        
        sar_end_rendering();
    }
    
    
    sar_close();
    std::cout << "c++ test" << std::endl;
    return 0;
}