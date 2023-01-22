from conans import ConanFile, CMake
from os import environ


class DataConan(ConanFile):
    name = "data-tools"
    license = "MIT"
    author = "Daniel Krawisz"
    url = "https://github.com/Gigamonkey-BSV/data-tools"
    description = "Functional data structures and high-level programming constructs in c++."
    topics = ("structures", "functional")
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    generators = "cmake"
    exports_sources = "*"
    #requires = "boost/1.80.0", "gtest/1.12.1"

    def set_version(self):
        if "CIRCLE_TAG" in environ:
            self.version = environ.get("CIRCLE_TAG")[1:]
        if "CURRENT_VERSION" in environ:
            self.version = environ['CURRENT_VERSION']
        else:
            self.version = "0.0.0"

    def configure_cmake(self):
        cmake = CMake(self)
        cmake.definitions["PACKAGE_TESTS"] = "Off"
        cmake.configure()
        return cmake

    def config_options(self):
        if self.settings.os == "Linux":
            del self.options.fPIC

    def build(self):
        cmake = self.configure_cmake()
        cmake.build()

    def package(self):
        self.copy("*.h", dst="include", src="include")
        self.copy("*.hpp", dst="include", src="include")
        self.copy("*libdata.a", dst="lib", keep_path=False)

    def package_info(self):
        self.cpp_info.libs = ["data-tools"]

