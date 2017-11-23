file(REMOVE_RECURSE
  "include/runtime_codelet_c.h"
  "include/runtime_codelet_s.h"
  "include/runtime_codelet_z.h"
  "include/runtime_codelet_d.h"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/runtime_starpu_include.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
