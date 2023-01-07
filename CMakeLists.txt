add_library(MicroNetworkCommon INTERFACE)
add_subdirectory(Src/MicroNetwork/Common)
target_include_directories(MicroNetworkCommon INTERFACE Src)