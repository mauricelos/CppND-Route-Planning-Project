cc_library(
    name = "lib",
    srcs = [
        "src/model.cpp",
        "src/render.cpp",
        "src/route_model.cpp",
        "src/route_planner.cpp",
    ],
    hdrs = [
        "src/model.h",
        "src/render.h",
        "src/route_model.h",
        "src/route_planner.h",
    ],
    data = glob([
        "map.osm",
        "map.png",
    ]),
    strip_include_prefix = "src",
    visibility = ["//visibility:public"],
    deps = [
        "@cairo",
        "@graphicsmagick",
        "@io2d",
        "@pugixml",
    ],
)

cc_binary(
    name = "main",
    srcs = ["src/main.cpp"],
    deps = ["//:lib"],
)

cc_binary(
    name = "test",
    srcs = ["test/utest_rp_a_star_search.cpp"],
    deps = ["//:lib"],
)
