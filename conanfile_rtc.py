from conans import ConanFile


class EnttConan(ConanFile):
    name = "entt"
    version = "2.7.3"
    url = "https://github.com/Esri/entt/blob/runtimecore"
    license = "https://github.com/Esri/entt/blob/runtimecore/LICENSE"
    description = (
        "EnTT is a header-only, tiny and easy to use entity-component system (and much more) written in modern C++."
    )

    # Use the OS default to get the right line endings
    settings = "os"

    def package(self):
        base = self.source_folder + "/"
        relative = "3rdparty/entt/"

        # headers
        self.copy("*.h*", src=base + "src/entt", dst=relative + "src/entt")

    def package_id(self):
        self.info.header_only()
