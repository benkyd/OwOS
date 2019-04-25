cmake_minimum_required(VERSION 3.9)
project(OwOS)

enable_language(ASM)

set(CMAKE_ASM_COMPILER "i686-elf-as")
set(CMAKE_C_COMPILER "i686-elf-gcc")
set(CMAKE_CXX_COMPILER "i686-elf-g++")

set(CMAKE_CXX_FLAGS  "-ffreestanding -O2 -fno-rtti -Wno-write-strings -Wno-multichar -Wno-unused-parameter -Wno-overflow -Wno-narrowing -fno-exceptions -Wno-trigraphs ${CMAKE_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS  "-T ../linker.ld -ffreestanding -O2 -nostdlib -lgcc -Wwrite-strings ${CMAKE_EXE_LINKER_FLAGS}")

include_directories(OwOS "./")


# Kernel source
file(GLOB KERN_SRC        "*.asm" "*.cpp") 
file(GLOB KERN_LIB_SRC    "kernel/*.cpp" "kernel/*.asm") 

# Driver source
file(GLOB DRIV_DISP_VGA  "kernel/drivers/terminal/*.cpp" "kernel/drivers/terminal/*.asm")

# Lib source
file(GLOB LIB_STD        "lib/std/*.cpp" "lib/std/*.asm")



add_executable(OwOS ${KERN_SRC} ${KERN_LIB_SRC}
                    ${DRIV_DISP_VGA} 
                    ${LIB_STD})

set_target_properties(OwOS PROPERTIES OUTPUT_NAME "OwOS.bin")

add_custom_target(iso COMMAND cp OwOS.bin ../iso/boot/OwOS.bin && grub-mkrescue -o OwOS.iso ../iso)
add_dependencies(iso OwOS)
