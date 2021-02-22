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
#ifndef ABSTRACTPLAYER_H_INCLUDED
#define ABSTRACTPLAYER_H_INCLUDED
#include "audio.h"

class AbstractPlayer : public AudioAbstract {
protected:
   typedef short Sample16;
   typedef signed char Sample8;

   volatile AudioSample *_queue, *_queueEnd; // Begin/end of queue memory
   volatile AudioSample * volatile _queueFirst;  // First sample
   volatile AudioSample * volatile _queueLast; // Last sample

   void InitializeQueue(unsigned long queueSize); // Create Queue
   void FillQueue(void); // Fill it up
   long FromQueue(Sample8 *pDest,long bytes);
   long FromQueue(Sample16 *pDest,long bytes);
private:
   void DataToQueue(long); // Used by FillQueue
   void DataFromQueue(Sample8 *,long); // Used by FromQueue(Sample8...)
   void DataFromQueue(Sample16 *,long); // Used by FromQueue(Sample16...)
private:
   size_t GetSamples(AudioSample *,size_t) { exit(1); return 0; };
protected:
   bool _endOfSource; // true -> last data read from source
   bool _endOfQueue; // true -> last data read from queue
public:
   AbstractPlayer(AudioAbstract *a);
   ~AbstractPlayer();
   virtual void Play() = 0;  // Actually play the sound source
};
#endif
