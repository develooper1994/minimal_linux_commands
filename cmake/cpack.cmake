# MIT License Copyright (c) 2023-Today Mustafa Selçuk Çağlar
#
# Packaging

# vendor
set(CPACK_PACKAGE_VENDOR "Mustafa Selçuk Çağlar")
# package version is same as source version!
set(CPACK_PACKAGE_VERSION_MAJOR "${CMAKE_PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${CMAKE_PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${CMAKE_PROJECT_VERSION_PATCH}")

# package type
set(CPACK_GENERATOR "TAR;TGZ")
set(CPACK_STRIP_FILES "TRUE")

include(CPack)
