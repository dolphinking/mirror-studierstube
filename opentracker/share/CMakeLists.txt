INSTALL(DIRECTORY . DESTINATION ${CMAKE_INSTALL_DATADIR}/opentracker
  PATTERN "*Make*" EXCLUDE
  PATTERN ".svn" EXCLUDE
  PATTERN "cmake*" EXCLUDE
)
