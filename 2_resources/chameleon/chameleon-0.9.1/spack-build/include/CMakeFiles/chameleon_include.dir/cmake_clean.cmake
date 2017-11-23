file(REMOVE_RECURSE
  "morse_s.h"
  "morse_c.h"
  "morse_z.h"
  "morse_d.h"
  "morse_ds.h"
  "morse_zc.h"
  "runtime_s.h"
  "runtime_c.h"
  "runtime_z.h"
  "runtime_d.h"
  "runtime_ds.h"
  "runtime_zc.h"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/chameleon_include.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
