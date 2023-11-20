/*
 * Animation.h
 *
 *  Created on: 16 gru 2022
 *      Author: Daniel Wielanek
 *		E-mail: daniel.wielanek@gmail.com
 *		Warsaw University of Technology, Faculty of Physics
 */
#ifndef KOLO_ANIMATION_H_
#define KOLO_ANIMATION_H_

#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#else
#include <stdlib.h>
#include <unistd.h>
#endif
using namespace std;

class Animation {

public:
  Animation();
  /**
   * czeka milisekundy
   * @param milliseconds
   */
  static void wait(int milliseconds);
  /**
   * czyści terminal
   */
  static void clear();
  /**
   * printuje pojedynczy znak w jednym z kolorów 0-7, w przeciwnym razie
   * zamiast drukować kolorowy znak drukuje numer koloru
   * @param col
   * @param ch
   */
  static void drawPixel(int col, char ch);
  static void drawLine(int col, std::string str);
  virtual ~Animation();
};


#endif /* KOLO_ANIMATION_H_ */
