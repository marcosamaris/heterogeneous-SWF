file(REMOVE_RECURSE
  "coreblas_c.h"
  "coreblas_s.h"
  "coreblas_z.h"
  "coreblas_d.h"
  "coreblas_ds.h"
  "coreblas_zc.h"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/coreblas_include.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
