https://github.com/thbkrkr/docker-toolbox
https://github.com/thbkrkr/dops

## Alpine microcontainer with Java

This is a micro docker container based on Alpine 3.4 with different version 1.8 of Oracle java

### Examples

This images are build on ormos/glibc which are a modified version of Alpine including glibc.

#### starting the container and showing the java version

	docker run -ti ormos/alpine-java java -v

This will start the container with a normal shell, no cron or other systems are started

### Loading different versions of java

The different version is determined with the TAG 

### TAGs

This image contains the following versions of java, the container names are
ormos/alpine-java:<tag> where tag is

| Tag    | OpenJDK version             | Alpine Version |
| ------ | ----------------------------| ---------------|
| latest |  Oracle Java version 8 JDK  | latest         |
| 3.4    |  Oracle Java version 8 JDK  | 3.4            |
