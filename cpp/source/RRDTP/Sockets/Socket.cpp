/*==============================================================================
The MIT License (MIT)

Copyright (c) 2016 Tanner Mickelson

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
==============================================================================*/
#include "RRDTP/Sockets/Socket.h"
#include "RRDTP/Platform.h"

#if defined(RRDTP_PLATFORM_WINDOWS)
#include "RRDTP/Sockets/WinsockSocket.h"
#elif defined(RRDTP_PLATFORM_LINUX)
#include "RRDTP/Sockets/BSDSocket.h"
#endif

using namespace rrdtp;

Socket* Socket::Create(DataRecievedCallback dataRecievedCallback, void* userPtr, ConnectionAcceptedCallback connectionAcceptedCallback)
{
	#if defined(RRDTP_PLATFORM_WINDOWS)
	return new WinsockSocket(dataRecievedCallback, userPtr, connectionAcceptedCallback);
	#elif defined(RRDTP_PLATFORM_LINUX)
	return new BSDSocket(dataRecievedCallback, userPtr, connectionAcceptedCallback);
	#endif
}
