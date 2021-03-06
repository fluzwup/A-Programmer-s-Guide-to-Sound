/*
   Copyright 1997 Tim Kientzle.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
      This product includes software developed by Tim Kientzle
      and published in ``The Programmer's Guide to Sound.''
4. Neither the names of Tim Kientzle nor Addison-Wesley
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL TIM KIENTZLE OR ADDISON-WESLEY BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/*
* Player class for Win32
*/
#ifndef WIN_PLAYER_H_INCLUDED
#define WIN_PLAYER_H_INCLUDED
#include "audio.h"
#include "aplayer.h"
#include <windows.h>
#include <mmsystem.h>

#define winBufferSize 10000  // Number of samples per buffer

class WinPlayer : public AbstractPlayer {
private:
   HWAVEOUT _device;   // Windows audio device to open
   volatile bool _paused; // true -> device is paused
   int   _sampleWidth; // width of data to output

   int SelectDevice(void); // Open a suitable device

   // Allow the callback to see our members 
   friend void CALLBACK WaveOutCallback(HWAVEOUT hwo, UINT uMsg,
               DWORD dwInstance, DWORD dwParam1, DWORD dwParam2);

   // The callback function defined above is just a wrapper that
   // invokes this method
   void NextBuff(WAVEHDR *);
public:
   WinPlayer(AudioAbstract *a): AbstractPlayer(a) {
      _device = 0;
      _paused = true;
      _sampleWidth = 0;
   };
   ~WinPlayer() {};

   void Play();  // Actually play the sound source
};
#endif
