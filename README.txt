===========================
SAR - Simple Ascii Renderer
===========================

Shared/dynamic library, a set of functions to render character based tiles (like Dwarf Fortress',
by the way its tilesets (.png) should be fully compatible).

** THE .PNG FILE IN THE TESTS/ FOLDER IS FULLY USABLE. ALSO LOOK FOR ANY DWARF FORTRESS TILESET .PNG **

** THIS IS MOSTLY OLD MESSY CODE, RIPPED OFF A GAME I WAS MAKING. DON'T EXPECT IT TO LOOK GOOD, IT JUST WORKS. **

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
		bool sar_init(const char * caption, int w, int h, bool resizable);
		void sar_close(void);
		
	* Image/file loading:
		bool sar_load_texture(const char * path);
	
	* Events handling:
		int sar_get_events(sar_event * event);
		
	* Rendering:
		void sar_begin_rendering(sar_color clear_color)
		void sar_end_rendering(void);
		void sar_render_tile(long c, int x, int y, sar_color bg_color, sar_color tile_color);
		void sar_render_str(const char * str, int x, int y, sar_color bg_color, sar_color tile_color);

Samples: You can find one in the 'tests' folder.
-------

To do:
-----
	- Windows build
	- Linux build
	- Static library (?)

License:
-------
	zlib (http://www.gzip.org/zlib/zlib_license.html)

Author: Thomas "Arc0re" Guyot <thomasguyot@outlook.com> <paperboycheero@yahoo.com>