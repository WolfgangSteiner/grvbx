#include "grv/grvbld.h"

int main(int argc, char** argv) {
    GRV_CHECK_AND_REBUILD();    
    grvbld_config_t* config =  grvbld_config_new(argc, argv);
    //config->cc = "tcc";
    //config->use_ccache = false;
    grvbld_strarr_push(&config->warnings, "-Wextra -Wpedantic");
    grvbld_config_add_include_directory(config, "grv/include");
    grvbld_config_add_library_directory(config, "grv/build");

    system("cd grv; ./bld");

    grvbld_target_t* grvbx = grvbld_target_create_executable("grvbx");
    grvbld_target_add_src(grvbx, "src/main.c");
    grvbld_target_link_library(grvbx, "grv");
    grvbld_target_link_library(grvbx, "grvgfx");
    grvbld_build_target(config, grvbx);

    return 0;
}

