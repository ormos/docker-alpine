# Alpine Linux Docker Image

Welcome to the documentation for the Alpine Linux Docker Image. Here we explain a bit about the motivations behind this image, how you typically use it, the build process, and how to make great minimalist containers!

## About

The heart of this image is [Alpine Linux][alpine]. The image is only 5 MB and has access to a package repository that is much more complete than other minimal base images. Learn more [about this image][about], musl libc, BusyBox, and why the Docker Alpine Linux image makes a great base for your Docker projects.

## Official

This image is really similar to the [official Alpine Linux image in the Docker Library][library]. The build process for `ormos/alpine` is based on the official `alpine` image. However, different build options are used. Check out [the build page][build] for more information on differences.

## Motivations

Docker images today are big. Usually much larger than they need to be. There are a lot of ways to make them smaller. But you need to start with a small base. There are great size savings to be had when compared to base images such as `ubuntu`, `centos`, and `debian`.

## Usage

You use the `apk` command to manage packages. We don't ship the image with a package index (since that can go stale fairly quickly), so you need to add the `--update` flag to `apk` when installing. An example installing the `nginx` package would be `apk add --update nginx`. Check out [the usage page][usage] for more advanced usage and `Dockerfile` examples.

## Caveats

The musl libc implementation may work a little different than you are used to. One example of this is with DNS. musl libc does not use `domain` or `search` in the `/etc/resolv.conf` file. It also queries name servers in parallel which can be problematic if your first name server has a different DNS view (such as service discovery through DNS). We have [a page dedicated to the caveats][caveats] you should be aware of.

## Build

This image is built and tested in a continuous integration environment using the `build-image` script. We then push the resulting images directly to Docker Hub. Check out [the page on building and testing][build] the images for more information.


[about]: ./about
[usage]: ./usage
[build]: ./build
[caveats]: ./caveats
[alpine]: http://alpinelinux.org/
[library]: https://github.com/docker-library/official-images/blob/master/library/alpine
[hub]: https://hub.docker.com/r/ormos/alpine/
