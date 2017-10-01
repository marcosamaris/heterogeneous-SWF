file(REMOVE_RECURSE
  "testing_cauxiliary.h"
  "testing_sauxiliary.h"
  "testing_zauxiliary.h"
  "testing_dauxiliary.h"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/testing_include.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
