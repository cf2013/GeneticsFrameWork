// Defines common functions and macros 
#ifndef COMMON_H
#define COMMON_H

// Include Common Libraries
#ifdef WINDOWS
#include "windows.h"
#include <tchar.h>
#endif

#ifdef LINUX
#include <DataTypes.h>
#endif

//we are using stl, so update this list according
#include <sys/stat.h> 
#include <sys/types.h>
#include <stdlib.h>
#include <malloc.h>//maybe substituted for dlmalloc or pbrt matt pharr and greg
#include <memory.h>
#include <stdio.h>
#include <utility>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>
#include <cassert>


// Constant Variables
const bool TRUE = 0;
const bool FALSE = 1;

// Safe Release Macro
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(P) if (P!=NULL){P->Release();P=NULL;}
#endif

// Safe Delete Macro
#ifndef SAFE_DELETE
#define SAFE_DELETE(P) if (P!=NULL){delete[] P;P=NULL;}
#endif

#endif