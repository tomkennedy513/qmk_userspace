#pragma once

// Enable one-shot mod timeout
// This applies to OSM(MOD_LSFT), OSM(MOD_LCTL), etc.
#define ONESHOT_TIMEOUT 3000  // 3 seconds (3000ms)

// Optional: Configure one-shot layer timeout separately
// (Used by custom implementation in tomkennedy513.c)
#define ONESHOT_LAYER_TIMEOUT 3000  // 3 seconds (3000ms)
