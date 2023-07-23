// Copyright (c) 2023 -	Sergio Gosalvez
// Use of this source code is governed by a GPLv3 license that can be found in the LICENSE file.
#include <string>
#include <WiFi.h>

extern unsigned char paige_pressed;
extern int paige_buttons[7];
extern int paige_newline;
extern int paige_backspace;
extern int paige_space;

extern uint32_t paige_file_start_time;
extern uint32_t paige_restore_start_time;
extern int paige_file_open;
extern int paige_file_closed;
extern std::string paige_file;
extern std::string paige_file_send;

extern std::string illegal_chars;