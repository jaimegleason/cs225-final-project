file(REMOVE_RECURSE
  "libsrc.a"
  "libsrc.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/src.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
