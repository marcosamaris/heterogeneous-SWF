file(REMOVE_RECURSE
  "timing_cauxiliary.h"
  "timing_sauxiliary.h"
  "timing_zauxiliary.h"
  "timing_dauxiliary.h"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/timing_include.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
