workspace(name = "OSM_A_star_search")

new_local_repository(
    name = "cairo",
    build_file = "cairo.BUILD",
    path = "/usr",
)

new_local_repository(
    name = "graphicsmagick",
    build_file = "graphicsmagick.BUILD",
    path = "/usr",
)

new_local_repository(
    name = "turbojpeg",
    build_file = "turbojpeg.BUILD",
    path = "/usr",
)

new_local_repository(
    name = "io2d",
    build_file = "io2d.BUILD",
    path = "thirdparty/P0267_RefImpl",
)

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "pugixml",
    build_file = "//:pugixml.BUILD",
    sha256 = "d156d35b83f680e40fd6412c4455fdd03544339779134617b9b28d19e11fdba6",
    strip_prefix = "pugixml-1.9",
    urls = ["https://github.com/zeux/pugixml/releases/download/v1.9/pugixml-1.9.tar.gz"],
)

#http_archive(
#    name = "io2d",
#    build_file = "//:io2d.BUILD",
#    strip_prefix = "P0267_RefImpl-P0267R6",
#    urls = ["https://github.com/cpp-io2d/P0267_RefImpl/archive/P0267R6.tar.gz"],
#)
