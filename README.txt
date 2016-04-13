===========================
SAR - Simple Ascii Renderer
===========================

Shared/dynamic library set of functions to render character based tiles (like Dwarf Fortress',
by the way its tilesets (.png) should be fully compatible).

Dependancies: SDL2, SDL2_image. All rights reserved.
------------

Docs:
----

Enumerations:
	ascii_characters # all the 255 ASCII characters, named.

Types:
	sar_event # SDL_Event, any window/keyboard event.
	sar_color # SDL_Color, 3 values of 255 max.

Functions:
	* Initialization and shutdown:
		bool sar_init(const char * caption, int w, int h);
		void sar_close(void);
		
	* Image/file loading:
		bool sar_load_texture(const char * path);
	
	* Events handling:
		void sar_get_events(sar_event * ev);
		
	* Rendering:
		void sar_begin_rendering(void);
		void sar_end_rendering(void);
		void sar_render_tile_c(char c, int x, int y, sar_color bg_color, sar_color tile_color);
		void sar_render_tile_char(enum ascii_characters c, int x, int y, sar_color bg_color, sar_color tile_color);
		void sar_render_string(const char * str, int x, int y, sar_color bg_color, sar_color tile_color);

Samples: You can find one in the 'tests' folder.
-------

To do:
-----
	- Windows build
	- Linux build
	- Static library

Author: Arc0re (paperboycheero@yahoo.com)