#pragma once

#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdlib>   

#ifdef WIN32
#include <time.h>
#else
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>
#endif

#include "udp.h"
#include "stun.h"
