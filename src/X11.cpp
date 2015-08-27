/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2013, Institute for Artificial Intelligence,
 *  Universität Bremen.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Institute for Artificial Intelligence,
 *     Universität Bremen, nor the names of its contributors may be
 *     used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/** \author Jan Winkler */


#include <iostream>
#include <X11/Xlib.h>
#include <Globals.h>


void verifyLibraryLoaded() {
  if(!vdX11lib) {
    vdX11lib = dlopen("/usr/lib/x86_64-linux-gnu/libX11.so", RTLD_NOW);
  }
}


Window XCreateSimpleWindow(Display* dpy, Window win, int x, int y, unsigned int w, unsigned int h, unsigned int border_width, unsigned long border, unsigned long background) {
  verifyLibraryLoaded();
  
  std::cout << "XCreateSimpleWindow" << std::endl;
  
  Window (*x11XCreateSimpleWindow)(Display*, Window, int, int, unsigned int, unsigned int, unsigned int, unsigned long, unsigned long);
  x11XCreateSimpleWindow = (Window (*)(Display*, Window, int, int, unsigned int, unsigned int, unsigned int, unsigned long, unsigned long))dlsym(vdX11lib, "XCreateSimpleWindow");
  
  return x11XCreateSimpleWindow(dpy, win, x, y, w, h, border_width, border, background);
}


Window XCreateWindow(Display* dpy, Window win, int x, int y, unsigned int w, unsigned int h, unsigned int border_width, int depth, unsigned int cls, Visual* vsl, unsigned long valuemask, XSetWindowAttributes* attribs) {
  verifyLibraryLoaded();
  
  std::cout << "XCreateWindow" << std::endl;
  
  Window (*x11XCreateWindow)(Display*, Window, int, int, unsigned int, unsigned int, unsigned int, int, unsigned int, Visual*, unsigned long, XSetWindowAttributes*);
  x11XCreateWindow = (Window (*)(Display*, Window, int, int, unsigned int, unsigned int, unsigned int, int, unsigned int, Visual*, unsigned long, XSetWindowAttributes*))dlsym(vdX11lib, "XCreateWindow");
  
  std::cout << "Class = " << cls << ", x = " << x << ", y = " << y << std::endl;
  
  return x11XCreateWindow(dpy, win, x, y, w, h, border_width, depth, cls, vsl, valuemask, attribs);
}
