file(REMOVE_RECURSE
  "compute_c.h"
  "compute_s.h"
  "compute_z.h"
  "compute_d.h"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/control_include.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
