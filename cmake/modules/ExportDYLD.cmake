function(CheckForExportDYLD)

  message(STATUS "Checking Platform: ${CMAKE_SYSTEM_NAME}")
    
  if(${APPLE})

    set(bashProfileName "$ENV{HOME}/.bash_profile")

    message(STATUS "APPLE?... really?... ok then...")
    message(STATUS "Checking if ${bashProfileName} exists and already contains the export command for DYLD_LIBRARY_PATH")

    if(EXISTS "${bashProfileName}")

      file(STRINGS "${bashProfileName}" testStrs)

      foreach(line ${testStrs})
      
      string(REGEX MATCH "export DYLD_LIBRARY_PATH=\"[$]DYLD_LIBRARY_PATH:${CMAKE_SOURCE_DIR}/exec\"" foundDYLDExport ${line})
  
	if(foundDYLDExport)
  
	  message(STATUS "Found ${bashProfileName} and the export DYLD_LIBRARY_PATH line...")
	  return()
	
	endif()

      endforeach()
      
      message(STATUS "Found ${bashProfileName} but the export DYLD_LIBRARY_PATH line is missing. Adding it...")
      
      file(APPEND "${bashProfileName}" "\n")
      file(APPEND "${bashProfileName}" "#Export DYLD_LIBRARY_PATH for goddess_daq\n")
      file(APPEND "${bashProfileName}" "export DYLD_LIBRARY_PATH=\"$DYLD_LIBRARY_PATH:${CMAKE_SOURCE_DIR}/exec\"")

    else()
  
      message(STATUS "${bashProfileName} does not exist... Creating it...")
  
      file(WRITE "${bashProfileName}" "#Export DYLD_LIBRARY_PATH for goddess_daq\n")
      file(APPEND "${bashProfileName}" "export DYLD_LIBRARY_PATH=\"$DYLD_LIBRARY_PATH:${CMAKE_SOURCE_DIR}/exec\"")
  
    endif()

  else()
    
      message(STATUS "Congratulation for using a decent OS")
    
  endif()

endfunction()