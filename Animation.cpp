/*
 * Animation.cpp
 *
 *  Created on: 16 gru 2022
 *      Author: Daniel Wielanek
 *		E-mail: daniel.wielanek@gmail.com
 *		Warsaw University of Technology, Faculty of Physics
 */
#include "Animation.h"

Animation::Animation() {
  // TODO Auto-generated constructor stub
}

void Animation::wait(int milliseconds) {
#ifdef _WIN32
  Sleep(milliseconds);
#else
  usleep(milliseconds * 1000);  // takes microseconds
#endif
}
/**
 * czyści terminal
 */
void Animation::clear() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
/**
 * printuje pojedynczy znak w jednym z kolorów 0-7, w przeciwnym razie
 * zamiast drukować kolorowy znak drukuje numer koloru
 * @param col
 * @param ch
 */
void Animation::drawPixel(int col, char ch) {
#ifdef _WIN32
  switch (col) {
    case 0: system("Color 01"); break; // red
    case 1: system("Color 02"); break; // green
    case 3: system("Color 03"); break; // olive
    case 4: system("Color 04"); break; // magenta
    case 5: system("Color 05"); break; // 
    case 6: system("Color 06"); break;
    case 7: system("Color 06"); break;
  }
  std::cout << ch << std::endl;
#else
  switch (col) {
    case 0: cout << "\x1B[31m" << ch << "\033[0m"; break;
    case 1: cout << "\x1B[32m" << ch << "\033[0m"; break;
    case 2: cout << "\x1B[33m" << ch << "\033[0m"; break;
    case 3: cout << "\x1B[34m" << ch << "\033[0m"; break;
    case 4: cout << "\x1B[35m" << ch << "\033[0m"; break;
    case 5: cout << "\x1B[36m" << ch << "\033[0m"; break;
    case 6: cout << "\x1B[37m" << ch << "\033[0m"; break;
    case 7: cout << "\x1B[90m" << ch << "\033[0m"; break;
    default: cout << col; break;
  }
#endif
}
void Animation::drawLine(int col, std::string str){
    for(int i=0;i<str.size();i++){
        drawPixel(col,str[i]);
    }
}
Animation::~Animation() {}
