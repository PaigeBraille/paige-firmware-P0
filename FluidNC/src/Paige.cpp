// Copyright (c) 2023 -	Sergio Gosalvez
// Use of this source code is governed by a GPLv3 license that can be found in the LICENSE file.

#include "Paige.h"
#include <string>
#include <WiFi.h>

unsigned char paige_pressed           = 0;
int paige_buttons[7]    = {0,0,0,0,0,0,0};
int paige_newline                     = 0;
int paige_backspace                   = 0;
int paige_space                       = 0;


uint32_t paige_file_start_time = millis(); 
int paige_file_open                   = 0;
int paige_file_closed                 = 1;
std::string paige_file              = " ";
std::string paige_file_send         = " ";