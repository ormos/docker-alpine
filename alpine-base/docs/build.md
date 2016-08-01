# Build

A convenience `build` script is included that builds the image and runs basic tests against the resulting image tags. The script can be used in the continuous integration process or you can run this script locally to build your own images. Be sure to check out the environment variables that can be tweaked at the top of the `build` script file.

## Image

### Builder

The image is built using a builder Docker container based on the `debian` image. This builder image lives in the `builder` sub-directory of the project and uses a `mkimage-alpine.sh` script to generate an Alpine Linux `rootfs.tar.gz` file. This file then gets copied to the root of the project so we can build the main Alpine Linux image by just using the `ADD` command to automatically untar the components to the resulting image.

### Options

The build script takes a glob of `options` files as an argument. Each of these files lives in a folder that describes the version of Alpine Linux to build. Each line of the `options` file are the options that will be applied to the resulting image. By default, we use the included glob of `versions/**/options`.

### Example

To build all the images simply run:

```console
$ ./build-image
```

Pass version files to the `build` script to build specific versions:

```console
$ ./build-image version/elvido-3.4/options versions/elvido-edge/options
```

With `parallel` available you can speed up building a bit:

```console
$ parallel -m ./build-image ::: versions/**/options
```
