// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here

typedef struct {

	unsigned short start_marker;

	unsigned char block_size[2];

	unsigned char source_des;

	unsigned char group_num;

	bool service_avail;

	bool ass_health;

	unsigned char lowest_seq[4];

}ebp_header_t;


