#pragma once

// Enable one-shot mod timeout
// This applies to OSM(MOD_LSFT), OSM(MOD_LCTL), etc.
#define ONESHOT_TIMEOUT 1000 // 1 second (1000ms)

// Optional: Configure one-shot layer timeout separately
// (Used by custom implementation in tomkennedy513.c)
#define ONESHOT_LAYER_TIMEOUT 300 // .3 seconds (300ms)
