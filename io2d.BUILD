package(default_visibility = ["//visibility:public"])

cc_library(
    name = "io2d",
    srcs = glob(["Debug/**/libio2d*.a"]),
    hdrs = glob([
        "P0267_RefImpl/**/*.h",
        "P0267_RefImpl/**/*.cpp",
    ]),
    includes = ["include/io2d"],
    strip_include_prefix = "P0267_RefImpl",
    deps = [
        "@cairo",
        "@graphicsmagick",
        "@turbojpeg",
    ],
)
