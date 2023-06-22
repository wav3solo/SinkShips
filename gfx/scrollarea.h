// NCurses side-scrolling area
// (c) 2020 by Stefan Roettger

#pragma once

#include "gfx.h"

//! set the drawing window
//! * stdscr is used by default
void set_drawing_window(WINDOW *w);

//! create a scrollable canvas area
//! * with sx columns and sy rows
//! * the canvas area may contain a single ASCII character per cell
//! * by default the canvas area is empty (filled with spaces)
//! * after canvas area creation we need to
//!  * define the screen window size via set_window_size
//!  * define the contents of the canvas area via set_cell, flood_fill etc.
//!  * and finally render the canvas via redraw_window or center_window
void set_area_size(int sx, int sy);

//! is a scrollable canvas area available?
bool has_area();

//! get the width of the scrollable area
int get_area_width();

//! get the height of the scrollable area
int get_area_height();

//! set the size of the displayed window
void set_window_size(int sx, int sy);

//! is a displayed window available?
bool has_window();

//! get the width of the displayed window
int get_window_width();

//! get the height of the displayed window
int get_window_height();

//! set the offset of the displayed window
void set_window_offset(int ox, int oy);

//! clear the scrollable area
//! * "ch" is the character used to clear the area
void clear_area(int ch = ' ');

//! set the border of the scrollable area
//! * "ch" is the character used for the area border
void set_area_border(int ch = ACS_CKBOARD);

//! set the border of the displayed window
//! * "ch" is the character used for the window border
void set_window_border(int ch = ACS_CKBOARD);

//! get the cell character at position (x, y) of the canvas area
int get_cell(int x, int y);

//! set the cell at position (x, y) to character ch of the canvas area
void set_cell(int x, int y, int ch);

//! set the cell coordinate offset
//! * the coordinate offset is applied both to get_cell and set_cell
void set_cell_offset(int x = 0, int y = 0);

//! set the cell modification mode
//! * in retain mode only spaces will be overwritten
void set_cell_mode(bool retain = false);

//! get the cell area at top-left position (x, y) with size (sx, sy)
//! * "ch" is the character that represents transparent areas
//! * returns a newly allocated array of respective size
int *get_cell_area(int x, int y,
                   int sx, int sy,
                   int ch = -1);

//! fill a cell area at top-left position (x, y) with size (sx, sy)
//! * "ch" is the character used to fill the area
//!  * by default ACS_CKBOARD is used as character
void fill_cell_area(int x, int y,
                    int sx, int sy,
                    int ch = -1);

//! render a cell area at top-left position (x, y) with size (sx, sy)
void render_cell_area(int x, int y,
                      int sx, int sy,
                      const int *data);

//! render a text area at top-left position (x, y)
//! * return value is the number of rendered text lines
int render_text_area(int x, int y,
                     const char *text);

//! render a formatted text at position (x, y)
//! * return value is the number of rendered text lines
int render_text_format(int x, int y,
                       const char *format, ...);

//! render a grid font character at top-left position (x, y)
void render_grid_char(int x, int y, int ch);

//! render a text string with grid font characters at top-left position (x, y)
void render_grid_text(int x, int y,
                      const char *text);

//! render a line from position (x1, y1) to (x2, y2)
//! * "ch" is the character used to render the line
//!  * by default graphical characters are used
void render_line(int x1, int y1, int x2, int y2,
                 int ch = -1);

//! render a frame from position (x1, y1) to (x2, y2)
//! * "ch" is the character used to render the frame
//!  * by default graphical characters are used
void render_frame(int x1, int y1, int x2, int y2,
                  int ch = -1);

//! render a circle at center position (xc, yc) with radius r
//! * "ch" is the character used to render the circle
//!  * by default graphical characters are used
void render_circle(int xc, int yc, int r,
                   int ch = -1, double aspect = 2);

// render a ellipse at center position (xc, yc) with principle axis ax and ay
//! * "ch" is the character used to render the ellipse
//!  * by default graphical characters are used
void render_ellipse(int xc, int yc, int ax, int ay,
                    int ch = -1, double aspect = 2);

//! flood-fill a cell area starting at position (x, y)
//! * "ch" is the character used to fill the area
//!  * by default ACS_CKBOARD is used as character
void flood_fill(int x, int y, int ch = -1);

//! flood-fill everything but a cell area starting at position (x, y)
//! * "ch" is the character used to fill the area
//!  * by default ACS_CKBOARD is used as character
void inverse_flood_fill(int x, int y, int ch = -1);

//! scroll the content of the canvas area up
void scroll_area_up();

//! scroll the content of the canvas area down
void scroll_area_down(int num);

//! scroll the content of the canvas area left
void scroll_area_left(int num);

//! scroll the content of the canvas area right
void scroll_area_right(int num);

// get the number of available sprite overlays
int get_sprite_num();

//! enable a sprite overlay
//! * "num" is the number of the sprite
//! * "sx" and "sy" is the cell area size of the sprite
//! * "window" determines if the sprite position is area or window relative
//! * "own" determines that the data is provided by set_sprite_data and is owned by the user
//! * by default the sprite is fully transparent
void enable_sprite(int num,
                   int sx, int sy,
                   bool window = false,
                   bool own = false);

//! is a sprite overlay enabled?
//! * "num" is the number of the sprite
bool is_sprite_enabled(int num);

//! get the width of a sprite
//! * "num" is the number of the sprite
int get_sprite_width(int num);

//! get the height of a sprite
//! * "num" is the number of the sprite
int get_sprite_height(int num);

//! clear a sprite
//! * "num" is the number of the sprite
//! * "ch" is the character to be set
//! * by default the sprite is made fully transparent
void clear_sprite(int num, int ch = -1);

//! set the sprite data
//! * transparent areas are represented by negative cell values
void set_sprite_data(int num, int sx, int sy, int *data);

//! get the sprite data
//! * transparent areas are represented by negative cell values
int *get_sprite_data(int num);

//! set the sprite data by text string
//! * "ch" is the character that represents transparent areas
//! * "interprete":
//!  * ^ as overscore
//!  * # as checker board
//!  * B as bold attribute
//!  * digits as color attributes
//!  * 0 to clear attributes
void set_sprite_text(int num, const char *text,
                     int ch = -1, bool interprete = false);

//! fill a sprite cell area
//! * "num" is the number of the sprite
//! * "x" and "y" is the top-left position (x, y) of the sub-area to be cleared
//! * "sx" and "sy" is the size of the sub-area to be cleared
//! * "ch" is the character to be copied into the sub-area
//!  * by default ACS_CKBOARD is used as character
void fill_sprite_area(int num, int x, int y, int sx, int sy, int ch = -1);

//! set a sprite cell area
//! * "num" is the number of the sprite
//! * "x" and "y" is the top-left position (x, y) of the sub-area to be set
//! * "sx" and "sy" is the size of the sub-area to be set
//! * "data" is the data to be copied into the sub-area
//! * negative data values are not copied having a transparency effect
void set_sprite_area(int num, int x, int y, int sx, int sy, const int *data);

//! print a sprite text area
//! * "num" is the number of the sprite
//! * "x" and "y" is the top-left position (x, y) of the text to be printed
//! * "text" is the string to be printed
//! * return value is the number of printed text lines
int print_sprite_text(int num,
                      int x, int y,
                      const char *text);

//! print a sprite grid font character
//! * "num" is the number of the sprite
//! * "x" and "y" is the top-left position (x, y) of the character to be printed
//! * "ch" is the character to be printed
void print_sprite_grid_char(int num,
                            int x, int y,
                            int ch);

//! print a sprite text string with grid font characters
//! * "num" is the number of the sprite
//! * "x" and "y" is the top-left position (x, y) of the text to be printed
//! * "text" is the string to be printed
void print_sprite_grid_text(int num,
                            int x, int y,
                            const char *text);

//! mirror the sprite horizontally
//! * "num" is the number of the sprite
//! * "flip" determines whether a slash is replaced with a backslash or vice versa
void mirror_sprite_horizontal(int num, bool flip = true);

//! mirror the sprite vertically
//! * "num" is the number of the sprite
//! * "flip" determines whether
//!  * a slash is replaced with a backslash or vice versa
//!  * an underscore is replaced with an overscore or vice versa
void mirror_sprite_vertical(int num, bool flip = true);

//! scroll the sprite up
//! * "num" is the number of the sprite
void scroll_sprite_up(int num);

//! scroll the sprite down
//! * "num" is the number of the sprite
void scroll_sprite_down(int num);

//! scroll the sprite left
//! * "num" is the number of the sprite
void scroll_sprite_left(int num);

//! scroll the sprite right
//! * "num" is the number of the sprite
void scroll_sprite_right(int num);

//! set the sprite position
//! * "num" is the number of the sprite
//! * "x" and "y" is the top-left position (x, y) of the sprite
void set_sprite_position(int num, int x, int y);

//! center the sprite position
//! * "num" is the number of the sprite
//! * "x" and "y" is the center position of the sprite
void center_sprite_position(int num, int x, int y);

//! get the sprite position
//! * "num" is the number of the sprite
//! * "x" and "y" will be the top-left position (x, y) of the sprite
void get_sprite_position(int num, int *x, int *y);

//! hide a sprite
//! * "num" is the number of the sprite
void hide_sprite(int num);

//! show a sprite
//! * "num" is the number of the sprite
void show_sprite(int num);

//! make background sprite
//! * "num" is the number of the sprite
//! * a background sprite only shows where the canvas area is empty
//! * an empty area is filled with spaces
void background_sprite(int num);

//! make parallax sprite
//! * "num" is the number of the sprite
//! * a parallax sprite scrolls relative to the viewing coordinates
//! * "dx" and "dy" define the amount of parallax scrolling
void parallax_sprite(int num, float dx, float dy);

//! detect a sprite collision with a non-empty canvas area
//! * "num" is the number of the sprite
//! * "ch" is the character that represents empty areas
//! * empty areas are represented by space by default
bool detect_area_collision(int num, int ch = -1);

//! detect a sprite touch with a non-empty canvas area
//! * "num" is the number of the sprite
//! * (dx, dy) is the direction vector of the touch detection
//! * "ch" is the character that represents empty areas
//! * non-empty areas are represented by anything but space by default
bool detect_area_touch(int num, int dx, int dy, int ch = -1);

//! detect a sprite collision with a non-transparent area of another sprite
//! * "num" is the number of the sprite
//! * "spr" is the number of the other sprite
//! * non-transparent areas are represented by positive cell values
bool detect_sprite_collision(int num, int spr);

//! detect a sprite touch with a non-transparent area of another sprite
//! * "num" is the number of the sprite
//! * "spr" is the number of the other sprite
//! * non-transparent areas are represented by positive cell values
bool detect_sprite_touch(int num, int dx, int dy, int spr);

//! bake the sprite into the canvas area
//! * "num" is the number of the sprite
void bake_sprite(int num);

//! disable a sprite
//! * "num" is the number of the sprite
void disable_sprite(int num);

//! disable all sprites
void disable_sprites();

//! redraw the displayed window at top-left position (x, y)
//! * it is assumed that the displayed window area has been cleared once
//! * subsequent calls will only update modifications to the canvas area
void redraw_window(int x, int y);

//! position the displayed window at center position (x, y)
//! * it is assumed that the displayed window area has been cleared once
//! * subsequent calls will only update modifications to the canvas area
void position_window(int x, int y);

//! scroll the displayed window to top-left position (x, y)
//! * "deltax" and "deltay" is the position delta that triggers scrolling
//! * "stop" determines if scrolling should stop at the edges of the scrollable area
void scroll_window(int x, int y, int deltax = 0, int deltay = 0, bool stop = true);

//! scroll the displayed window to center position (x, y)
//! * "deltax" and "deltay" is the position delta that triggers scrolling
//! * "stop" determines if scrolling should stop at the edges of the scrollable area
void center_window(int x, int y, int deltax = 0, int deltay = 0, bool stop = true);

//! get the top-left position (x, y) of the scrolled window
void get_window(int *x, int *y);

//! release allocated memory
void release_area();
