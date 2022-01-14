#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*pkg_output_func)(void *arg, const char* msg, ...);
typedef void (*pkg_error_func)(void *arg, const char* msg, ...);
typedef void (*pkg_output_progress_init_func)(void *arg, uint64_t size);
typedef void (*pkg_output_progress_func)(void *arg, uint64_t progress);

int pkg_dec(const char *pkgname, const char *target_dir, const char *zrif);
void pkg_disable_output();
void pkg_enable_sys_output();
void pkg_set_func(pkg_output_func out, pkg_error_func err,
                 pkg_output_progress_init_func proginit,
                 pkg_output_progress_func prog, void *arg);

#ifdef __cplusplus
}
#endif
