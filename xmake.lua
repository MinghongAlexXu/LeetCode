-- `xmake project -k compile_commands` generates compile_commands.json

set_languages("c++20")
set_config("buildir", "./out/cxx")
set_toolchains("clang-14")

add_requireconfs("*", {configs = {shared = true}})
add_requires("gtest")
add_requires("benchmark")  -- Cannot complie. Use apt::libbenchmark-dev instead.

for _, path2cxx in ipairs(os.files("src/*/*.cxx")) do
    target(string.match(path.directory(path2cxx), "#(%d+)"))
        set_kind("binary")
        add_files(path2cxx)
        add_packages("gtest")
        add_packages("benchmark")
end